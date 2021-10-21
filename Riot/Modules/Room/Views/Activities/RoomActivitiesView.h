/*
 Copyright 2015 OpenMarket Ltd
 Copyright 2017 Vector Creations Ltd

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import <MatrixKit/MatrixKit.h>


/**
 `RoomExtraInfosInfoView` instance is a view used to display extra information
 */
@interface RoomActivitiesView : MXKRoomActivitiesView <UITextViewDelegate, UIGestureRecognizerDelegate>

@property (weak, nonatomic) IBOutlet UIView *separatorView;
@property (weak, nonatomic) IBOutlet UIImageView *iconImageView;
@property (weak, nonatomic) IBOutlet UILabel *messageLabel;
@property (weak, nonatomic) IBOutlet UITextView *messageTextView;

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *mainHeightConstraint;

@property (weak, nonatomic) IBOutlet UIView *unsentMessagesContentView;
@property (weak, nonatomic) IBOutlet UIButton *resendButton;
@property (weak, nonatomic) IBOutlet UIButton *deleteButton;
@property (weak, nonatomic) IBOutlet UILabel *unsentMessagesTitleLabel;
@property (weak, nonatomic) IBOutlet UILabel *unsentMessagesInfoLabel;

@property (weak, nonatomic) IBOutlet UIView *unsentErrorContainer;
@property (weak, nonatomic) IBOutlet UILabel *unsentErrorLabel;

/**
 Notify that some messages are not sent.
 Replace the current notification if any.
 
 @param notification the notification message to display.
 @param onResendLinkPressed block called when user selects the resend link.
 @param onCancelLinkPressed block called when user selects the cancel link.
 @param onIconTapGesture block called when user taps on notification icon.
 */
- (void)displayUnsentMessagesNotification:(NSString*)notification withResendLink:(void (^)(void))onResendLinkPressed andCancelLink:(void (^)(void))onCancelLinkPressed andIconTapGesture:(void (^)(void))onIconTapGesture;

/**
 Show the a reason that a message failed to send using the error passed in.
 Overlaid on top of the unsent messages notification, must be removed manually
 by calling `hideUnsentMessageError`.
 @param error The error to display to the user.
 */
- (void)displayUnsentMessageError:(NSError *)error;

/**
 Hide the overlay showing the reason that a message failed to send.
*/
- (void)hideUnsentMessageError;

/**
 Display network error.
 Replace the current notification if any.
 
 @param labelText the notification message
 */
- (void)displayNetworkErrorNotification:(NSString*)labelText;

/**
 Notify that the a room is obsolete and a replacement room is available.
 
 @param onRoomReplacementLinkTapped block called when user selects the room replacement link.
 */
- (void)displayRoomReplacementWithRoomLinkTappedHandler:(void (^)(void))onRoomReplacementLinkTapped;

/**
 Display a kMXErrCodeStringResourceLimitExceeded error received during a /sync request.

 @param errorDict the error data.
 @param onAdminContactTapped a callback indicating if the user wants to contact their admin.
 */
- (void)showResourceLimitExceededError:(NSDictionary *)errorDict onAdminContactTapped:(void (^)(NSURL *adminContact))onAdminContactTapped;

/**
 Display a usage limit notice sent in a system alert room.

 @param usageLimit the usage limit data.
 @param onAdminContactTapped a callback indicating if the user wants to contact their admin.
 */
- (void)showResourceUsageLimitNotice:(MXServerNoticeContent *)usageLimit onAdminContactTapped:(void (^)(NSURL *adminContact))onAdminContactTapped;

/**
 Remove any displayed information.
 */
- (void)reset;

@end
