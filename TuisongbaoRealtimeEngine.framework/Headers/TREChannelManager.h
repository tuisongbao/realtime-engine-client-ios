#import "TREObject.h"
#import "TREChannel.h"

/**
 *  Channel 管理类。
 */
@interface TREChannelManager : TREObject

/**
 *  订阅 Channel 。
 *
 *  @param channelName Channel 名称。
 *
 *  @return Channel 。
 */
- (TREChannel *)subscribe:(NSString *)channelName;

/**
 *  取消订阅。
 *
 *  @param channelName Channel 名称。
 */
- (void)unsubscribe:(NSString *)channelName;

/**
 *  根据名称获取已订阅的 Channel 。
 *
 *  @param channelName Channel 名称。
 *
 *  @return Channel 。
 */
- (TREChannel *)find:(NSString *)channelName;

/**
 *  获取全部已订阅的 Channel 。
 *
 *  @return Channel 数组。
 */
- (NSArray *)all;

@end
