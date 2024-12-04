//
// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import <AmazonIVSBroadcast/IVSBase.h>
#import <AmazonIVSBroadcast/IVSStageStreamNetworkQuality.h>

NS_ASSUME_NONNULL_BEGIN

IVS_EXPORT
API_AVAILABLE(ios(14))
/// A quality stats class that represents remote video
@interface IVSRemoteVideoStats : NSObject

/// The network quality associates with subscribing remote video
@property (nonatomic, readonly) IVSStageStreamNetworkQuality networkQuality;
/// Represents the width of the last decoded frame
@property (nonatomic, readonly) NSInteger frameWidth;
/// Represents the height of the last decoded frame
@property (nonatomic, readonly) NSInteger frameHeight;
/// The number of decoded frames during the last second
@property (nonatomic, readonly) double framesPerSecond;
/// The NACK count sent by SDK for receiving video
@property (nonatomic, readonly) NSInteger nackCount;
/// The number of video RTP packets received
@property (nonatomic, readonly) NSInteger packetsReceived;
/// The number of video RTP packets lost
@property (nonatomic, readonly) NSInteger packetsLost;
/// The total number of bytes received including retransmissions
@property (nonatomic, readonly) NSInteger bytesReceived;
/// The number of RTP header bytes received
@property (nonatomic, readonly) NSInteger headerBytesReceived;
/// Represents the sum of time in seconds that packets buffered in jitter buffer
@property (nonatomic, readonly) double jitterBufferDelay;
/// The total number of video frames being received
@property (nonatomic, readonly) NSInteger framesReceived;
/// The total number of video frames correctly being decoded
@property (nonatomic, readonly) NSInteger framesDecoded;
/// The total number of video key frames correctly being decoded
@property (nonatomic, readonly) NSInteger keyFramesDecoded;
/// The total number of video frames dropped prior to decode
@property (nonatomic, readonly) NSInteger framesDropped;
/// The total number of Full Intra Request(FIR) packets sent
@property (nonatomic, readonly) NSInteger firCount;
/// The total number of Picture Loss Indication(PLI) packets sent
@property (nonatomic, readonly) NSInteger pliCount;
/// The total number of video pauses experienced by receiver
@property (nonatomic, readonly) NSInteger pauseCount;
/// The total duration of pauses in seconds
@property (nonatomic, readonly) double totalPausesDuration;
/// The total number of video freezes experienced by receiver
@property (nonatomic, readonly) NSInteger freezeCount;
/// The total duration of rendered frames which are considered frozen
@property (nonatomic, readonly) double totalFreezesDuration;
/// Mime type
@property (nonatomic, strong, readonly) NSString *mime;

@end

NS_ASSUME_NONNULL_END
