// 
// Copyright 2020 The Matrix.org Foundation C.I.C
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import <Foundation/Foundation.h>
#import "MXCallHangupEventContent.h"

typedef NS_ENUM(NSInteger, MXCallRejectReplacementReason)
{
    MXCallRejectReplacementReasonDeclined,
    MXCallRejectReplacementReasonFailedRoomInvite,
    MXCallRejectReplacementReasonFailedCallInvite,
    MXCallRejectReplacementReasonFailedCall
} NS_REFINED_FOR_SWIFT;

typedef NSString * MXCallRejectReplacementReasonString NS_REFINED_FOR_SWIFT;

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString *const kMXCallRejectReplacementReasonStringDeclined;
FOUNDATION_EXPORT NSString *const kMXCallRejectReplacementReasonStringFailedRoomInvite;
FOUNDATION_EXPORT NSString *const kMXCallRejectReplacementReasonStringFailedCallInvite;
FOUNDATION_EXPORT NSString *const kMXCallRejectReplacementReasonStringFailedCall;

/**
 `MXCallRejectReplacementEventContent` represents the content of an `m.call.reject_replacement` event.
 */
@interface MXCallRejectReplacementEventContent : MXCallEventContent

/**
 An identifier for the call replacement itself, generated by the transferor.
 */
@property (nonatomic) NSString *replacementId;

/**
 The reason a replacement is being rejected.
 */
@property (nonatomic) MXCallRejectReplacementReasonString reason;

/**
 Mapped reason of the reject event.
 */
@property (nonatomic) MXCallRejectReplacementReason reasonType;

/**
 May be present if `reason` is failedCall, in which case it gives the reason field from the replacement call's hangup event.
 @seealso reasonType
 */
@property (nonatomic, nullable) MXCallHangupReasonString callFailureReason;

/**
 Mapped call failure reason of the reject event.
 */
@property (nonatomic, assign) MXCallHangupReason callFailureReasonType;

@end

NS_ASSUME_NONNULL_END
