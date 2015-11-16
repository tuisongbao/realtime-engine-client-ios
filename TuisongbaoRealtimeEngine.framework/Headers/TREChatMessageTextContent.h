#import "TREChatMessageContent.h"

/**
 *  Chat 消息文本内容。
 */
@interface TREChatMessageTextContent : TREChatMessageContent

/**
 *  文本值。
 */
@property (nonatomic) NSString *text;

/**
 *  初始化并设置文本值。
 *
 *  @param text 文本值。
 *
 *  @return 新实例。
 */
- (instancetype)initWithText:(NSString *)text;

@end
