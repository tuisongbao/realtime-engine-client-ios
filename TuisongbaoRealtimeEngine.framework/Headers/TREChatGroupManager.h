#import "TREObject.h"
#import "TREChatGroup.h"

extern NSString *const kTREChatGroupOptionIsPublic;
extern NSString *const kTREChatGroupOptionUserCanInvite;

/**
 *  Chat 群组管理类。
 */
@interface TREChatGroupManager : TREObject

/**
 *  从服务端加载群组列表。
 *
 *  @param groupId  可选，过滤条件，群组唯一标识。
 *  @param callback 结果回调。
 */
- (void)loadWithGroupId:(NSString *)groupId callback:(void (^)(NSArray *groups, NSError *error))callback;

/**
 *  创建群组。
 *
 *  @param userIds  群组初始用户的 `userId` 数组。
 *  @param options  群组属性选项，如下：
 *
 *  - `kTREChatGroupOptionIsPublic` (BOOL) ：可选，是否任何用户的加群请求都会直接通过，无需审核，默认 `YES` 。
 *  - `kTREChatGroupOptionUserCanInvite` (BOOL) ：可选，除创建者（ `owner`
 *）外，其他群用户是否也可以发送加群邀请，默认 `YES` 。
 *
 *  @param callback 结果回调。
 */
- (void)createWithUserIds:(NSArray *)userIds
                  options:(NSDictionary *)options
                 callback:(void (^)(TREChatGroup *group, NSError *error))callback;

@end
