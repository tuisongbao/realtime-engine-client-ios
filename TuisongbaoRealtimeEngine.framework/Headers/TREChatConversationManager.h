#import "TREObject.h"
#import "TREChatConversation.h"
#import "TREChatUser.h"
#import "TREChatGroup.h"

extern NSString *const kTREEventChatConversationsChanged;

/**
 *  Chat 会话管理类。
 */
@interface TREChatConversationManager : TREObject

/**
 *  由该 Manager 在本地实时维护的会话列表，方便开发者直接绑定到 UI 上。
 *
 *  内部会做以下事情：
 *
 *  - 有新消息时，自动更新会话的 `unreadMessageCount`。
 *  - 自动维护每个会话的 `lastMessage` 。
 *  - 自动根据 `lastActiveAt` 对会话进行降序排序 。
 *  - 被删除的会话会自动从此数组移除。
 *  - 新创建的会话会自动添加到此数组。
 *
 *  该数组变化时会触发 `kTREEventChatConversationsChanged` *Event* 。
 */
@property (nonatomic) NSMutableArray *conversations;
/**
 *  由该 Manager 在本地实时维护的所有会话未读消息数总和。
 *
 *  该属性变化时会触发 `kTREEventChatConversationsChanged` *Event* 。
 */
@property (nonatomic) NSUInteger totalUnreadMessageCount;

/**
 *  从服务端加载会话列表。
 *
 *  @param type     可选，过滤条件，会话类型，`kTREChatConversationTypeSingleChat` （单聊） 或
 *`kTREChatConversationTypeGroupChat` （群聊）。
 *
 *  @param target   可选，过滤条件，对方的唯一标识，`userId` 或 `groupId` 。
 *  @param callback 结果回调。
 */
- (void)loadWithType:(NSString *)type
              target:(NSString *)target
            callback:(void (^)(NSArray *conversations, NSError *error))callback;

/**
 *  获取与指定用户的会话，没有则创建。
 *
 *  @param user 对方用户。
 *
 *  @return 会话。
 */
- (TREChatConversation *)conversationWithUser:(TREChatUser *)user;

/**
 *  获取与指定群组的会话，没有则创建。
 *
 *  @param group 群组。
 *
 *  @return 会话。
 */
- (TREChatConversation *)conversationWithGroup:(TREChatGroup *)group;

/**
 *  根据消息获取会话，通常用于收到新消息时查询对应会话。
 *
 *  @param message 消息。
 *
 *  @return 会话。
 */
- (TREChatConversation *)conversationWithMessage:(TREChatMessage *)message;

/**
 *  根据会话类型及对方唯一标识获取会话。
 *
 *  @param type   会话类型，`kTREChatConversationTypeSingleChat` （单聊） 或
 *`kTREChatConversationTypeGroupChat` 。
 *  @param target 对方的唯一标识，`userId` 或 `groupId` 。
 *
 *  @return 会话。
 */
- (TREChatConversation *)conversationWithType:(NSString *)type target:(NSString *)target;

@end
