#import "TREChatMessageFileContent.h"

/**
 *  Chat 消息视频内容。
 */
@interface TREChatMessageVideoContent : TREChatMessageFileContent

/**
 *  视频高度。
 */
@property (nonatomic) NSUInteger height;
/**
 *  视频宽度。
 */
@property (nonatomic) NSUInteger width;
/**
 *  视频时长。
 */
@property (nonatomic) NSUInteger duration;
/**
 *  首帧缩略图数据。
 */
@property (nonatomic) NSData *thumbData;
/**
 *  首帧缩略图服务端地址。
 */
@property (nonatomic) NSString *thumbUrl;
/**
 *  从服务端下载的缩略图本地缓存路径.
 */
@property (nonatomic) NSString *thumbPath;

/**
 *  使用文件路径初始化，文件内容会自动填充到 `data` 属性上。
 *
 *  @param path 文件路径。
 *
 *  @return 新实例。
 */
- (instancetype)initWithPath:(NSString *)path;

/**
 *  根据 thumbUrl 下载文件缓存到本地磁盘，并设置 `thumbData` 和 `thumbPath` 属性。
 *
 *  第二次调用将直接从缓存读取数据。
 *
 *  @param progressCallback 可选，进度回调，可用来提示下载进度。
 *  @param doneCallback     结果回调，请访问 `thumbData` 或者 `thumbPath` 属性获取加载完的数据。
 */
- (void)loadThumbDataWithProgressCallback:(void (^)(float progress))progressCallback
                             doneCallback:(void (^)(NSError *error))doneCallback;

@end
