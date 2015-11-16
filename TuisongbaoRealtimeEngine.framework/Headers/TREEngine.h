@class TREConnection;
@class TREChannelManager;
@class TREChatManager;

#pragma mark - Error domains

/**
 *  SDK 参数检查错误。
 */
extern NSString *const kTREErrorDomainClient;
/**
 *  服务端返回的错误。
 */
extern NSString *const kTREErrorDomainServer;

#pragma mark - Client error code

/**
 *  客户端错误码。
 */
typedef NS_ENUM(NSInteger, TREClientErrorCode) {
    /**
     *  参数无效。
     */
    TREClientErrorCodeBadParameter = 0,
    /**
     *  认证回调失败。
     */
    TREClientErrorCodeAuthFailed,
    /**
     *  无可用连接。
     */
    TREClientErrorCodeNoConnection,
    /**
     *  Chat 未登录。
     */
    TREClientErrorCodeChatUnauthorized,
    /**
     *  Chat 多媒体文件上传失败。
     */
    TREClientErrorCodeChatUploadFailed
};

#pragma mark - Option keys

extern NSString *const kTREEngineOptionAuthEndpoint;
extern NSString *const kTREEngineOptionAuthData;

#pragma mark - TREEngine

/**
 *  实时引擎功能入口。
 *
 *  通常应全局共享一个实例，各子模块功能的管理类均作为它的属性来使用。
 */
@interface TREEngine : NSObject

/**
 *  初始化时设置的 `appId` 。
 */
@property (nonatomic, readonly) NSString *appId;
/**
 *  初始化时设置的 `options` 。
 */
@property (nonatomic, readonly) NSDictionary *options;
/**
 *  连接管理类实例。
 */
@property (nonatomic, readonly) TREConnection *connection;
/**
 *  Channel 管理类实例。
 */
@property (nonatomic, readonly) TREChannelManager *channelManager;
/**
 *  Chat 管理类实例。
 */
@property (nonatomic, readonly) TREChatManager *chatManager;

/**
 *  初始化实例。
 *
 *  @param appId   在推送宝的应用唯一标识。
 *  @param options 初始化选项，如下：
 *
 *  - `kTREEngineOptionAuthEndpoint` (NSString *) ：用户认证回调地址，使用用户认证机制时必填。
 *  - `kTREEngineOptionAuthData` (NSString *) ：用户认证回调所要携带的数据，使用用户认证机制时可选。
 *
 *  @return 新实例。
 */
- (instancetype)initWithAppID:(NSString *)appId options:(NSDictionary *)options;

@end
