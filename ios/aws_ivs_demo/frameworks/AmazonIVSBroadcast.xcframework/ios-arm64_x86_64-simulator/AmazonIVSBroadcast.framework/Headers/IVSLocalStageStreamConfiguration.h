//
// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import <AmazonIVSBroadcast/IVSBase.h>

NS_ASSUME_NONNULL_BEGIN

@class IVSLocalStageStreamAudioConfiguration;
@class IVSLocalStageStreamVideoConfiguration;

IVS_EXPORT
API_AVAILABLE(ios(14))
/// An object  that describes the media configuration for the `IVSStageStream`.
@interface IVSLocalStageStreamConfiguration : NSObject

/// This describes the audio configuration for the `IVSStageStream`
@property (nonatomic, strong) IVSLocalStageStreamAudioConfiguration *audio;

/// This describes the video configuration for the `IVSStageStream`
@property (nonatomic, strong) IVSLocalStageStreamVideoConfiguration *video;

@end

NS_ASSUME_NONNULL_END
