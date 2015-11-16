#import "TREObject.h"
#import "TREChatMessageContent.h"

/**
 *  Chat 消息状态。
 */
typedef NS_ENUM(NSInteger, TREChatMessageState) {
    /**
     *  初始状态。
     */
    TREChatMessageStateInitialized = 0,
    /**
     *  发送中。
     */
    TREChatMessageStateSending,
    /**
     *  发送成功。
     */
    TREChatMessageStateSendSucceeded,
    /**
     *  发送失败。
     */
    TREChatMessageStateSendFailed
};

/**
 *  Chat 消息。
 */
@interface TREChatMessage : TREObject

/**
 *  Conversation 中的自增 Id 。
 */
@property (nonatomic) NSUInteger messageId;
/**
 *  `kTREChatConversationTypeSingleChat` （单聊） 或 `kTREChatConversationTypeGroupChat` （群聊）。
 */
@property (nonatomic) NSString *type;
/**
 *  来自谁， `userId` 或 `groupId` 。
 */
@property (nonatomic) NSString *from;
/**
 *  发给谁， `userId` 或 `groupId` 。
 */
@property (nonatomic) NSString *to;
/**
 *  消息内容。
 */
@property (nonatomic) TREChatMessageContent *content;
/**
 *  消息状态。
 */
@property (nonatomic) TREChatMessageState state;
/**
 *  创建时间。
 */
@property (nonatomic) NSDate *createdAt;

- (instancetype)initWithType:(NSString *)type
                        from:(NSString *)from
                          to:(NSString *)to
                     content:(TREChatMessageContent *)content;

@end
