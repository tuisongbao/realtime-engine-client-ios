#import "TREChatMessageFileContent.h"

/**
 *  Chat 消息语音内容。
 */
@interface TREChatMessageVoiceContent : TREChatMessageFileContent

/**
 *  语音时长。
 */
@property (nonatomic) NSUInteger duration;

/**
 *  使用文件路径初始化，文件内容会自动填充到 `data` 属性上。
 *
 *  @param path 文件路径。
 *
 *  @return 新实例。
 */
- (instancetype)initWithPath:(NSString *)path;

@end
