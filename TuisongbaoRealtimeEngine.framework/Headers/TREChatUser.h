#import "TREChatUser.h"
#import "TREUser.h"
#import "TREChatGroup.h"

extern NSString *const kTREChatUserPresenceOnline;
extern NSString *const kTREChatUserPresenceOffline;

/**
 *  Chat 用户。
 */
@interface TREChatUser : TREUser

/**
 *  用户昵称。
 */
@property (nonatomic) NSString *nickname;
/**
 *  表示该次登录是否创建了新用户（之前该 `userId` 不存在），仅用于已登录的当前用户。
 */
@property (nonatomic) BOOL isNew;
/**
 *  在线状态， `kTREChatUserPresenceOnline` 或 `kTREChatUserPresenceOffline` 。
 */
@property (nonatomic) NSString *presence;

@end
