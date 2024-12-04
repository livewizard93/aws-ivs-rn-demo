//
// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import <AmazonIVSBroadcast/IVSBase.h>

NS_ASSUME_NONNULL_BEGIN

IVS_EXPORT
API_AVAILABLE(ios(14))
/// A configuration object describing the desired format of the published audio track associated the `IVSStageStream`.
@interface IVSLocalStageStreamAudioConfiguration : NSObject

/// The max bitrate for the publishing audio stream.
/// By default this is `64,000`.
@property (nonatomic, readonly) NSInteger maxBitrate;

/// Sets the bitrate for the publishing audio stream. This value must be between 12k and 128k
/// If the provided bitrate falls outside this range, bitrate will not be set and the provided outError will be set.
/// @param bitrate the  bitrate for the publishing audio stream
/// @param outError On input, a pointer to an error object. If an error occurs, the pointer is an NSError object that describes the error. If you don’t want error information, pass in nil.
/// @return if the set operation is successful or not.
- (BOOL)setMaxBitrate:(NSInteger)maxBitrate error:(NSError* __autoreleasing*)outError;

@end

NS_ASSUME_NONNULL_END
