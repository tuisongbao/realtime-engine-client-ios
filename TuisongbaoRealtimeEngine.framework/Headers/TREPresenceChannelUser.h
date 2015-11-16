#import "TREUser.h"

/**
 *  Presence Channel 在线用户。
 */
@interface TREPresenceChannelUser : TREUser

/**
 *  用户信息。
 */
@property (nonatomic, readonly) NSString *userInfo;

@end
