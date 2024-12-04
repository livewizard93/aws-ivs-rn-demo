//
// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import <AmazonIVSBroadcast/IVSBase.h>

NS_ASSUME_NONNULL_BEGIN

/// Enum that represents the network condition for either local audio, local video, remote audio or remote video
typedef NS_ENUM(NSInteger, IVSStageStreamNetworkQuality) {
    /// Network quality is excellent and users do not experience any media latency
    IVSStageStreamNetworkQualityExcellent,
    /// Network quality is good but users experience media latency rarely
    IVSStageStreamNetworkQualityGood,
    /// Network quality is normal and users experience media freeze sometimes
    IVSStageStreamNetworkQualityNormal,
    /// Network quality is poor and users often experience media freeze
    IVSStageStreamNetworkQualityPoor,
    /// Network quality is down and users usually experience media freeze
    IVSStageStreamNetworkQualityDown,
};

NS_ASSUME_NONNULL_END
