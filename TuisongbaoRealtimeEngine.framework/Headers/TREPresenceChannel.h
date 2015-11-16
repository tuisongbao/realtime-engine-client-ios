#import "TREPrivateChannel.h"

extern NSString *const kTREEventPresenceChannelUserAdded;
extern NSString *const kTREEventPresenceChannelUserRemoved;

/**
 *  Presence Channel 。
 *
 *  继承 `TREChannel` 的可监听事件，此外：
 *
 *  - `kTREEventChannelSubscriptionSucceeded` ：处理方法可接收 `NSArray` 类型参数，值为该 Presence Channel
 *当前的在线用户数组。
 *  - `kTREEventPresenceChannelUserAdded` ：新用户上线时触发，处理方法可接收 `TREPresenceChannelUser` 类型参数。
 *  - `kTREEventPresenceChannelUserRemoved` ：用户下线时触发，处理方法可接收 `TREPresenceChannelUser` 类型参数。
 *
 */
@interface TREPresenceChannel : TREPrivateChannel

/**
 *  获取当前所有在线用户。
 *
 *  @return 用户数组。
 */
- (NSArray *)allUsers;

@end
