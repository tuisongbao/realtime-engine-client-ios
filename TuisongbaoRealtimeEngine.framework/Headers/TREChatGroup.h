#import "TREObject.h"

/**
 *  Chat 群组。
 */
@interface TREChatGroup : TREObject

/**
 *  唯一标识。
 */
@property (nonatomic) NSString *groupId;
/**
 *  创建者 `userId`。
 */
@property (nonatomic) NSString *owner;
/**
 *  是否任何用户的加群请求都会直接通过，无需审核。
 */
@property (nonatomic) BOOL isPublic;
/**
 *  除创建者（ `owner` ）外，其他群用户是否也可以发送加群邀请。
 */
@property (nonatomic) BOOL userCanInvite;
/**
 *  当前群用户数。
 */
@property (nonatomic) NSUInteger userCount;
/**
 *  群用户数上限。
 */
@property (nonatomic) NSUInteger userCountLimit;

/**
 *  从服务端加载群组的用户列表。
 *
 *  @param callback 结果回调。
 */
- (void)loadUsersWithCallback:(void (^)(NSArray *users, NSError *error))callback;

/**
 *  发送加群邀请。
 *
 *  @param userIds  要发送给的用户的 `userId` 数组。
 *  @param callback 结果回调。
 */
- (void)sendJoinInvitationWithUserIds:(NSArray *)userIds callback:(void (^)(NSError *error))callback;

/**
 *  删除用户。
 *
 *  @param userIds  要删除的用户的 `userId` 数组。
 *  @param callback 结果回调。
 */
- (void)removeUsersWithUserIds:(NSArray *)userIds callback:(void (^)(NSError *error))callback;

/**
 *  主动退出群组。
 *
 *  @param callback 结果回调。
 */
- (void)leaveWithCallback:(void (^)(NSError *error))callback;

@end
