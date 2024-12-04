//
// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import <AmazonIVSBroadcast/IVSBase.h>
#import <AmazonIVSBroadcast/IVSLocalAudioStats.h>
#import <AmazonIVSBroadcast/IVSLocalVideoStats.h>
#import <AmazonIVSBroadcast/IVSRemoteAudioStats.h>
#import <AmazonIVSBroadcast/IVSRemoteVideoStats.h>

@class IVSStageStream;
@protocol IVSDevice;

NS_ASSUME_NONNULL_BEGIN

IVS_EXPORT
API_AVAILABLE(ios(14))
/// A delegate that provides information about the associated `IVSStageStream`.
@protocol IVSStageStreamDelegate <NSObject>

@optional
/// The mute status of the associated media stream has changed.
/// @param stream The associated media stream.
- (void)streamDidChangeIsMuted:(IVSStageStream *)stream;

/// The requested RTC stats have been produced.
/// @param stream The stream associated with the RTC stats.
/// @param stats The RTC stats.
- (void)stream:(IVSStageStream *)stream didGenerateRTCStats:(NSDictionary<NSString *, NSDictionary<NSString *, NSString *> *> *)stats;

/// The RTC stats request has produced local audio stats
/// @param stream The stream associated with the RTC stats.
/// @param stats The local audio stats.
- (void)stream:(IVSStageStream *)stream didGenerateLocalAudioStats:(IVSLocalAudioStats *)stats;

/// The RTC stats request has produced local video stats
/// @param stream The stream associated with the RTC stats.
/// @param stats The local video stats. There is a stat object for each published video stream if there are multiple..
- (void)stream:(IVSStageStream *)stream didGenerateLocalVideoStats:(NSArray<IVSLocalVideoStats *> *)stats;

/// The RTC stats request has produced remote audio stats
/// @param stream The stream associated with the RTC stats.
/// @param stats The remote audio stats.
- (void)stream:(IVSStageStream *)stream didGenerateRemoteAudioStats:(IVSRemoteAudioStats *)stats;

/// The RTC stats request has produced remote video stats
/// @param stream The stream associated with the RTC stats.
/// @param stats The remote video stats.
- (void)stream:(IVSStageStream *)stream didGenerateRemoteVideoStats:(IVSRemoteVideoStats *)stats;

@end

IVS_EXPORT
API_AVAILABLE(ios(14))
/// A media stream that contains a single `IVSDevice` and a single type of media data (audio or video).
@interface IVSStageStream : NSObject

IVS_INIT_UNAVAILABLE

/// A delegate that can provide updates about this stream.
@property (nonatomic, weak) id<IVSStageStreamDelegate> delegate;

/// The device associated with this stream.
@property (nonatomic, strong, readonly) id<IVSDevice> device;

/// The mute state for this stream. This state applies to the Stage itself, not the local rendering. If this is `true`, nobody can render this stream.
@property (nonatomic, readonly) BOOL isMuted;

/// Request Real Time Communication stats from this stream.
/// @param outError On input, a pointer to an error object. If an error occurs, the pointer is an NSError object that describes the error. If you don’t want error information, pass in nil.
- (BOOL)requestRTCStatsWithError:(NSError *__autoreleasing *)outError;

/// Request quality stats from this stream.
/// @param outError On input, a pointer to an error object. If an error occurs, the pointer is an NSError object that describes the error. If you don’t want error information, pass in nil.
- (BOOL)requestQualityStatsWithError:(NSError *__autoreleasing *)outError;

@end

NS_ASSUME_NONNULL_END
