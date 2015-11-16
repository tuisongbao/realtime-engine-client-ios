#import "TREObject.h"
#import "TREChatUser.h"
#import "TREChatGroupManager.h"
#import "TREChatConversationManager.h"

extern NSString *const kTREEventChatLoginSucceeded;
extern NSString *const kTREEventChatLoginFailed;
extern NSString *const kTREEventChatNewMessage;
extern NSString *const kTREEventChatPresenceChanged;

/**
 *  ChatManager 状态。
 */
typedef NS_ENUM(NSInteger, TREChatManagerState) {
    /**
     *  初始状态。
     */
    TREChatManagerStateInitialized = 0,
    /**
     *  登录中。
     */
    TREChatManagerStateLoggingIn,
    /**
     *  已登录。
     */
    TREChatManagerStateLoggedIn,
    /**
     *  登录失败。
     */
    TREChatManagerStateFailed,
    /**
     *  已退出登录。
     */
    TREChatManagerStateLoggedOut
};

/**
 Chat 管理类，相关功能入口。

 可监听如下事件：

 - `kTREEventChatLoginSucceeded`
 ：用户登录成功时触发，包括网络断开后自动重连也会触发，建议在此事件的处理方法中进行加载群组列表、会话列表等操作。此事件不传递参数给处理方法。
 - `kTREEventChatLoginFailed` ：用户登录失败时触发，处理方法可接收 `NSError` 类型参数。
 - `kTREEventChatNewMessage` ：收到任何会话的新消息时触发，处理方法可接收 `TREChatMessage` 类型参数。
 - `kTREEventChatPresenceChanged` ：可见用户（好友或同组用户）上下线时触发，处理方法可接收 `NSDictionary`
 类型参数，结构如下：
    - `userId` (NSString *) ：用户的唯一标识。
    - `changedTo` (NSString *) ：该用户现在的在线状态， `kTREChatUserPresenceOnline` 或 `kTREChatUserPresenceOffline`
 。
 */
@interface TREChatManager : TREObject

/**
 *  当前用户。
 *
 *  @warning 该属性在认证用户回调成功时即被赋值，要判断用户是否处于登录状态请使用 `state` 属性。
 */
@property (nonatomic, readonly) TREChatUser *user;
/**
 *  当前用户登录状态。
 */
@property (nonatomic, readonly) TREChatManagerState state;
/**
 *  群组管理类的实例。
 */
@property (nonatomic, readonly) TREChatGroupManager *groupManager;
/**
 *  会话管理类的实例。
 */
@property (nonatomic, readonly) TREChatConversationManager *conversationManager;

/**
 *  用户登录。
 *
 *  @param authOptions 可选，用户认证选项，如下：
 *
 *  - `kTREEngineOptionAuthEndpoint` (NSString *) ：用户认证回调地址。
 *  - `kTREEngineOptionAuthData` (NSString *) ：用户认证回调所要携带的数据。
 *
 *  未提供时将使用初始化 `TREEngine` 时所提供的相应选项。
 */
- (void)loginWithAuthOptions:(NSDictionary *)authOptions;

/**
 *  用户登出。
 *
 *  @param callback 结果回调。
 */
- (void)logoutWithCallback:(void (^)(NSError *error))callback;

@end
