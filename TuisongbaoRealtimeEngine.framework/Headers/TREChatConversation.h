#import "TREObject.h"
#import "TREChatMessage.h"

extern NSString *const kTREChatConversationTypeSingleChat;
extern NSString *const kTREChatConversationTypeGroupChat;

/**
 *  Chat 会话。
 *
 *  可监听如下事件：
 *
 *  - `kTREEventChatNewMessage` ：收到该会话的新消息时触发，处理方法可接收 `TREChatMessage` 类型参数。
 *
 */
@interface TREChatConversation : TREObject

/**
 *  类型， `kTREChatConversationTypeSingleChat` （单聊） 或 `kTREChatConversationTypeGroupChat` （群聊）。
 */
@property (nonatomic) NSString *type;
/**
 *  跟谁， `userId` 或 `groupId` 。
 */
@property (nonatomic) NSString *target;
/**
 *  未读消息数。
 */
@property (nonatomic) NSUInteger unreadMessageCount;
/**
 *  最新的一条消息。
 */
@property (nonatomic) TREChatMessage *lastMessage;
/**
 *  上次活动时间。
 */
@property (nonatomic) NSDate *lastActiveAt;

/**
 *  从服务端加载历史消息。
 *
 *  @param startMessageId 可选，起始消息 Id ，默认为最新消息的 Id 。
 *  @param endMessageId   可选，结束消息 Id 。
 *  @param limit          可选，限制返回条数，默认 20，最多 100 。
 *  @param callback       结果回调。
 */
- (void)loadMessagesWithStartMessageId:(NSNumber *)startMessageId
                          endMessageId:(NSNumber *)endMessageId
                                 limit:(NSNumber *)limit
                              callback:(void (^)(NSArray *messages, NSError *error))callback;

/**
 *  删除会话。
 *
 *  @param callback 结果回调。
 */
- (void)deleteWithCallback:(void (^)(NSError *error))callback;

/**
 *  重置未读消息数。
 */
- (void)resetUnread;

/**
 *  发送消息。
 *
 *  @param content          消息内容。
 *  @param progressCallback 可选，进度回调，发送文件类的消息（图片、语音）时，可用来实现上传进度提示。
 *  @param doneCallback     结果回调。
 *
 *  @return 构造好的消息实例，可立即用于 UI 显示。
 */
- (TREChatMessage *)sendMessage:(TREChatMessageContent *)content
           withProgressCallback:(void (^)(float progress))progressCallback
                   doneCallback:(void (^)(NSError *error))doneCallback;

@end
