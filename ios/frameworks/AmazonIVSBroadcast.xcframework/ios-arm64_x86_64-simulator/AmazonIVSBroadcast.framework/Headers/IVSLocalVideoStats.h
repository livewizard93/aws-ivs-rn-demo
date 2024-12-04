//
// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import <AmazonIVSBroadcast/IVSBase.h>
#import <AmazonIVSBroadcast/IVSStageStreamNetworkQuality.h>

NS_ASSUME_NONNULL_BEGIN

IVS_EXPORT
API_AVAILABLE(ios(14))
/// A quality stats class that represents local video
@interface IVSLocalVideoStats : NSObject

/// The network quality associates with publishing local video
@property (nonatomic, readonly) IVSStageStreamNetworkQuality networkQuality;
/// The indication if SDK is actively sending local video or not
@property (nonatomic, readonly) BOOL active;
/// Represents the width of the last encoded frame
@property (nonatomic, readonly) NSInteger frameWidth;
/// Represents the height of the last encoded frame
@property (nonatomic, readonly) NSInteger frameHeight;
/// The number of encoded frames during the last second
@property (nonatomic, readonly) double framesPerSecond;
/// Represents the layer used by simulcast, and
/// it is not empty only when simulcast is enabled
@property (nonatomic, strong, readonly) NSString *rid;
/// The NACK count received by SDK for sending video
@property (nonatomic, readonly) NSInteger nackCount;
/// The number of video RTP packets sent
@property (nonatomic, readonly) NSInteger packetsSent;
/// The number of video RTP packets retransmitted
@property (nonatomic, readonly) NSInteger retransmittedPacketsSent;
/// The total number of video bytes sent, and it includes retransmissions
@property (nonatomic, readonly) NSInteger bytesSent;
/// The number of RTP header bytes sent
@property (nonatomic, readonly) NSInteger headerBytesSent;
/// The number of retransmitted bytes
@property (nonatomic, readonly) NSInteger retransmittedBytesSent;
/// The total number of seconds that RTP packets have bufferered locally
@property (nonatomic, readonly) NSInteger totalPacketSendDelay;
/// The total number of Full Intra Request(FIR) packets received
@property (nonatomic, readonly) NSInteger firCount;
/// The total number of Picture Loss Indication(PLI) packets received
@property (nonatomic, readonly) NSInteger pliCount;
/// The number of video frames encoded
@property (nonatomic, readonly) NSInteger framesEncoded;
/// The number of video key frames encoded
@property (nonatomic, readonly) NSInteger keyFramesEncoded;
/// The total number of seconds that has been spent encoding video frames
@property (nonatomic, readonly) NSInteger totalEncodeTime;
/// The value is increaed by the target frame size in bytes every time a frame has been encoded
@property (nonatomic, readonly) NSInteger totalEncodedBytesTarget;
/// Represents the total number of frames sent
@property (nonatomic, readonly) NSInteger framesSent;
/// Represents the total number of huge frames sent
@property (nonatomic, readonly) NSInteger hugeFramesSent;
/// The current reason for limiting the resolution and/or framerate
@property (nonatomic, strong, readonly) NSString *qualityLimitationReason;
/// The total number of seconds that SDK has spent in each quality limitation state
@property (nonatomic, readonly) NSInteger qualityLimitationResolutionChanges;
/// Mime type
@property (nonatomic, strong, readonly) NSString *mime;

@end

NS_ASSUME_NONNULL_END
