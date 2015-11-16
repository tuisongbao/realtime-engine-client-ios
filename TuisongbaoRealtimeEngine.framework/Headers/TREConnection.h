#import "TREObject.h"

/**
 *  Connection 状态。
 */
typedef NS_ENUM(NSInteger, TREConnectionState) {
    /**
     *  初始状态。
     */
    TREConnectionStateInitialized = 0,
    /**
     *  已连接。
     */
    TREConnectionStateConnected,
    /**
     *  已主动断开连接。
     */
    TREConnectionStateDisconnected,
    /**
     *  连接中。
     */
    TREConnectionStateConnecting,
    /**
     *  连接失败。
     */
    TREConnectionStateFailed
};

extern NSString *const kTREEventConnectionStateChanged;
extern NSString *const kTREEventConnectionConnectingIn;
extern NSString *const kTREEventConnectionError;

/**
 网络连接管理类。

 可监听如下事件：

 - `kTREEventConnectionStateChanged` ：连接状态变化时触发，处理方法可接收 `NSDictionary` 类型参数，结构如下：
    - `previous` (TREConnectionState) ：之前的状态。
    - `current` (TREConnectionState) ：现在的状态。
 - `kTREEventConnectionConnectingIn` ：通知下次重连是在多久以后，处理方法可接收 `NSUInteger` 类型参数。

 */
@interface TREConnection : TREObject

/**
 *  当前连接状态。
 */
@property (nonatomic, readonly) TREConnectionState state;
@property (nonatomic, readonly) NSString *socketId;

/**
 *  建立连接。
 *
 *  仅用于调用 `disconnect` 后恢复连接，初始化 `TREEngine` 时不需要调用此方法，是自动的。
 */
- (void)connect;

/**
 *  断开连接。
 */
- (void)disconnect;

@end
