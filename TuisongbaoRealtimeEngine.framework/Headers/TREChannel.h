#import "TREObject.h"
#import "TREEngine.h"

extern NSString *const kTREEventChannelSubscriptionSucceeded;
extern NSString *const kTREEventChannelSubscriptionError;

/**
 *  普通 Channel 。
 *
 *  可监听如下事件：
 *
 *  - `kTREEventChannelSubscriptionSucceeded` ：订阅成功时触发，此事件不传递参数给处理方法。
 *  - `kTREEventChannelSubscriptionError` ：订阅失败时触发，处理方法可接收 `NSError` 类型参数。
 *
 */
@interface TREChannel : TREObject

/**
 *  Channel 名称。
 */
@property (nonatomic, readonly) NSString *name;
/**
 *  Channel 是否已订阅成功。
 */
@property (nonatomic, readonly) BOOL subscribed;

- (instancetype)initWithName:(NSString *)name engine:(TREEngine *)engine;

@end
