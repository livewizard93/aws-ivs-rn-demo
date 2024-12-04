//
// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import <AmazonIVSBroadcast/IVSBase.h>
#import <AmazonIVSBroadcast/IVSStageStreamNetworkQuality.h>

NS_ASSUME_NONNULL_BEGIN

IVS_EXPORT
API_AVAILABLE(ios(14))
/// A quality stats class that represents local audio
@interface IVSLocalAudioStats : NSObject

/// The network quality associates with publishing local audio
@property (nonatomic, readonly) IVSStageStreamNetworkQuality networkQuality;
/// The NACK count received by SDK for sending audio
@property (nonatomic, readonly) NSInteger nackCount;
/// The number of audio packets sent
@property (nonatomic, readonly) NSInteger packetsSent;
/// The number of audio packets retransmitted
@property (nonatomic, readonly) NSInteger retransmittedPacketsSent;
/// The total number of audio bytes sent, and it includes retransmissions
@property (nonatomic, readonly) NSInteger bytesSent;
/// The number of RTP header bytes sent
@property (nonatomic, readonly) NSInteger headerBytesSent;
/// The number of retransmitted bytes
@property (nonatomic, readonly) NSInteger retransmittedBytesSent;
/// The total number of seconds that packets have bufferered locally
@property (nonatomic, readonly) NSInteger totalPacketSendDelay;
/// Mime type
@property (nonatomic, strong, readonly) NSString *mime;

@end

NS_ASSUME_NONNULL_END
