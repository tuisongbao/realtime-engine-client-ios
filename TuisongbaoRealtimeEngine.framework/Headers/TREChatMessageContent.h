#import "TREObject.h"

extern NSString *const kTREChatMessageContentTypeText;
extern NSString *const kTREChatMessageContentTypeImage;
extern NSString *const kTREChatMessageContentTypeVoice;
extern NSString *const kTREChatMessageContentTypeVideo;
extern NSString *const kTREChatMessageContentTypeLocation;

/**
 *  Chat 消息内容基类。
 */
@interface TREChatMessageContent : TREObject

/**
 *  内容类型。
 *
 *  可选值如下：
 *
 *  - kTREChatMessageContentTypeText ：文本内容。
 *  - kTREChatMessageContentTypeImage ：图片内容。
 *  - kTREChatMessageContentTypeVoice ：语音内容。
 *  - kTREChatMessageContentTypeVideo ：视频内容（暂不支持）。
 *  - kTREChatMessageContentTypeLocation ：地理位置内容。
 *
 */
@property (nonatomic) NSString *type;
/**
 *  内容附加信息，用来实现应用自定义业务逻辑。
 */
@property (nonatomic) NSDictionary *extra;

- (instancetype)initWithType:(NSString *)type;

@end
