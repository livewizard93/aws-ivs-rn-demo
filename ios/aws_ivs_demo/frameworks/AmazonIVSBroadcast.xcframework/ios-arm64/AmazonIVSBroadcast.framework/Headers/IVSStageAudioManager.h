//
// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import <AmazonIVSBroadcast/IVSErrorSource.h>
#import <AmazonIVSBroadcast/IVSBase.h>

NS_ASSUME_NONNULL_BEGIN

/// These values map to the same name `AVAudioSessionCategory` values.
typedef NS_ENUM(NSInteger, IVSStageAudioManagerCategory) {
    /// Maps to `AVAudioSessionCategoryAmbient`
    IVSStageAudioManagerCategoryAmbient,

    /// Maps to `AVAudioSessionCategoryPlayAndRecord`
    IVSStageAudioManagerCategoryPlayAndRecord,

    /// Maps to `AVAudioSessionCategoryPlayback`
    IVSStageAudioManagerCategoryPlayback,

    /// Maps to `AVAudioSessionCategorySoloAmbient`
    IVSStageAudioManagerCategorySoloAmbient,
} NS_SWIFT_NAME(IVSStageAudioManager.Category);

/// These values map to the same name `AVAudioSessionCategoryOptions` values.
typedef NS_OPTIONS(NSInteger, IVSStageAudioManagerCategoryOptions) {
    /// Maps to `IVSStageAudioManagerCategoryOptionMixWithOthers`
    IVSStageAudioManagerCategoryOptionsMixWithOthers = 1 << 0,

    /// Maps to `IVSStageAudioManagerCategoryOptionDuckOthers`
    IVSStageAudioManagerCategoryOptionsDuckOthers = 1 << 1,

    /// Maps to `IVSStageAudioManagerCategoryOptionInterruptSpokenAudioAndMixWithOthers`
    IVSStageAudioManagerCategoryOptionsInterruptSpokenAudioAndMixWithOthers = 1 << 2,

    /// Maps to `IVSStageAudioManagerCategoryOptionAllowBluetooth`
    IVSStageAudioManagerCategoryOptionsAllowBluetooth = 1 << 3,

    /// Maps to `IVSStageAudioManagerCategoryOptionAllowBluetoothA2DP`
    IVSStageAudioManagerCategoryOptionsAllowBluetoothA2DP = 1 << 4,

    /// Maps to `IVSStageAudioManagerCategoryOptionAllowAirPlay`
    IVSStageAudioManagerCategoryOptionsAllowAirPlay = 1 << 5,

    /// Maps to `IVSStageAudioManagerCategoryOptionDefaultToSpeaker`
    IVSStageAudioManagerCategoryOptionsDefaultToSpeaker = 1 << 6,

    /// Maps to `IVSStageAudioManagerCategoryOptionOverrideMutedMicrophoneInterruption`
    IVSStageAudioManagerCategoryOptionsOverrideMutedMicrophoneInterruption API_AVAILABLE(ios(14.5)) = 1 << 7,
} NS_SWIFT_NAME(IVSStageAudioManager.CategoryOptions);

/// These values map to the same name `AVAudioSessionMode` values.
typedef NS_ENUM(NSInteger, IVSStageAudioManagerMode) {
    /// Maps to `AVAudioSessionModeDefault`
    IVSStageAudioManagerModeDefault,

    /// Maps to `AVAudioSessionModeMoviePlayback`
    IVSStageAudioManagerModeMoviePlayback,

    /// Maps to `AVAudioSessionModeSpokenAudio`
    IVSStageAudioManagerModeSpokenAudio,

    /// Maps to `AVAudioSessionModeVideoChat`
    IVSStageAudioManagerModeVideoChat,

    /// Maps to `AVAudioSessionModeVoiceChat`
    IVSStageAudioManagerModeVoiceChat,
} NS_SWIFT_NAME(IVSStageAudioManager.Mode);

/// Presets for common Stage use cases that set tested combinations of category, categoryOptions, and mode.
typedef NS_ENUM(NSInteger, IVSStageAudioManagerUseCasePreset) {
    /// This is the default preset that is active if nothing is set on `IVSStageAudioManager`.
    /// This is the recommended preset when using bidirectional communication between multiple participants.
    /// iOS may restrict the number of possible input and output devices when this preset is used.
    /// When using this mode the system will treat the conversation as a phone call, so call volume will be used
    /// instead of media volume.
    /// It uses the category `playAndRecord`.
    /// It uses the category options, `allowBluetooth`, `allowBluetoothA2DP`, `defaultToSpeaker`, `mixWithOthers`.
    /// It uses the mode `videoChat`.
    /// Echo cancellation is enabled when using this preset.
    IVSStageAudioManagerUseCasePresetVideoChat,

    /// This is the recommended preset when users are only subscribing to remote participants but not publishing.
    /// It will improve audio quality compared to the `videoChat` preset.
    ///
    /// @note using this preset while a microphone is attached will cause problems with the underlying `AVAudioEngine`.
    /// Only use this mode if no microphone will be attached.
    ///
    /// It uses the category `playback`.
    /// It uses the category options, `mixWithOthers`.
    /// It uses the mode `moviePlayback`.
    /// Echo cancellation is disabled when using this preset.
    IVSStageAudioManagerUseCasePresetSubscribeOnly,

    /// This is the recommended preset when using bidirectional communication between multiple participants
    /// but it is important that audio quality remain as high as possible. This preset is only recommended when
    /// it is known that users will be using hardware that prevents echo, such as the combination of a headset
    /// and an external studio mic.
    ///
    /// This mode can be used for a scenario where a "main broadcaster" is bringing other participants
    /// onto their broadcast as a guest. If the "main broadcaster" is using external audio equipment, they can
    /// use `.studio` while the guest that is joining uses `.videoChat`.
    ///
    /// It uses the category `playAndRecord`.
    /// It uses the category options, `allowBluetooth`, `allowBluetoothA2DP`, `defaultToSpeaker`, `mixWithOthers`.
    /// It uses the mode `default`.
    /// Echo cancellation is disabled when using this preset.
    IVSStageAudioManagerUseCasePresetStudio,
} NS_SWIFT_NAME(IVSStageAudioManager.UseCasePreset);

/// Use this class to manage the `AVAudioSession` instance used by the SDK while in a stage.
///
/// @note Calling any of these APIs can change the available microphones and output devices at runtime, and will reset the
/// selected input source on an IVSMicrophone instance, falling back to the default device. It is recommended to
/// setup the audio manager before creating an `IVSStage`. If you need to call these APIs while an `IVSStage` is active,
/// make sure to validate the devices you expect to be used can still be used by the system.
IVS_EXPORT
API_AVAILABLE(ios(14))
@interface IVSStageAudioManager : NSObject <IVSErrorSource>

IVS_INIT_UNAVAILABLE

/// The most recently set `IVSStageAudioManagerCategory`
@property (atomic, readonly) IVSStageAudioManagerCategory category;

/// The most recently set `IVSStageAudioManagerCategoryOptions`
@property (atomic, readonly) IVSStageAudioManagerCategoryOptions options;

/// The most recently set `IVSStageAudioManagerMode`
@property (atomic, readonly) IVSStageAudioManagerMode mode;

/// Indicates whether echo cancellation is enabled on the microphone device. By default this is `YES`.
///
/// @note Changing this property while the microphone is in use may result in momentary audio loss. Setting
///       this property to a value of `YES` may require microphone permissions.
///       echoCancellation is incompatible with the `record` category and will not be enabled.
///
@property (nonatomic, getter=isEchoCancellationEnabled) BOOL echoCancellationEnabled API_AVAILABLE(ios(13.0));

/// The shared instance of `IVSStageAudioManager`.
+ (instancetype)sharedInstance;

/// Set a new preset for the audio session configuration.
- (void)setPreset:(IVSStageAudioManagerUseCasePreset)preset;

/// Manually specify the category, options, and mode for the audio session configuration.
- (void)setCategory:(IVSStageAudioManagerCategory)categoroy
            options:(IVSStageAudioManagerCategoryOptions)options
               mode:(IVSStageAudioManagerMode)mode;

@end

NS_ASSUME_NONNULL_END
