//
// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import <AmazonIVSBroadcast/IVSBase.h>
#import <AmazonIVSBroadcast/IVSStageStreamNetworkQuality.h>

NS_ASSUME_NONNULL_BEGIN

IVS_EXPORT
API_AVAILABLE(ios(14))
/// A quality stats class that represents remote audio
@interface IVSRemoteAudioStats : NSObject

/// The network quality associates with subscribing remote audio
@property (nonatomic, readonly) IVSStageStreamNetworkQuality networkQuality;
/// The NACK count sent by SDK for receiving audio
@property (nonatomic, readonly) NSInteger nackCount;
/// The number of audio RTP packets received
@property (nonatomic, readonly) NSInteger packetsReceived;
/// The number of audio RTP packets lost
@property (nonatomic, readonly) NSInteger packetsLost;
/// The total number of bytes received including retransmissions
@property (nonatomic, readonly) NSInteger bytesReceived;
/// The number of RTP header bytes received
@property (nonatomic, readonly) NSInteger headerBytesReceived;
/// Represents the sum of time in seconds that packets buffered in jitter buffer
@property (nonatomic, readonly) double jitterBufferDelay;
/// The total number of samples that have been received
@property (nonatomic, readonly) NSInteger totalSamplesReceived;
/// The total number of samples that are concealed samples
@property (nonatomic, readonly) NSInteger concealedSamples;
/// This is the counter of audio samples inserted to slow down playout
@property (nonatomic, readonly) NSInteger insertedSamplesForDeceleration;
/// This is the counter of audio samples removed to speed up palyout
@property (nonatomic, readonly) NSInteger removedSamplesForAcceleration;
/// Represents the audio level of receiving audio, and the value is between 0 and 1
@property (nonatomic, readonly) double audioLevel;
/// Mime type
@property (nonatomic, strong, readonly) NSString *mime;

@end

NS_ASSUME_NONNULL_END
