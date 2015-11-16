#import "TREChatMessageContent.h"

/**
 *  Chat 文件类型消息内容的基类。
 */
@interface TREChatMessageFileContent : TREChatMessageContent

/**
 *  初始化时指定的文件路径，或者从服务端下载的本地缓存路径。
 */
@property (nonatomic) NSString *path;
/**
 *  初始化时传入的数据或使用 `loadDataWithProgressCallback:doneCallback:` 方法从服务端加载的数据。
 */
@property (nonatomic) NSData *data;
/**
 *  文件名称。
 */
@property (nonatomic) NSString *name;
/**
 *  文件大小，单位字节。
 */
@property (nonatomic) NSUInteger size;
/**
 *  文件 ETAG 。
 */
@property (nonatomic) NSString *etag;
/**
 *  文件 MIME 类型。
 */
@property (nonatomic) NSString *mimeType;
/**
 *  文件服务端地址。
 */
@property (nonatomic) NSString *url;

- (instancetype)initWithType:(NSString *)type data:(NSData *)data;

- (instancetype)initWithType:(NSString *)type path:(NSString *)path;

/**
 *  根据 url 下载文件缓存到本地，并设置 `data` 和 `path` 属性。
 *
 *  第二次调用将直接从缓存读取数据。
 *
 *  @param progressCallback 可选，进度回调，可用来提示下载进度。
 *  @param doneCallback     结果回调，请访问 `data` 或者 `path` 属性获取加载完的数据。
 */
- (void)loadDataWithProgressCallback:(void (^)(float progress))progressCallback
                        doneCallback:(void (^)(NSError *error))doneCallback;

@end
