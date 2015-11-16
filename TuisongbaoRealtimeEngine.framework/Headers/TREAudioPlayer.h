#import <AVFoundation/AVAudioPlayer.h>

#import "TREObject.h"

/**
 *  音频播放帮助类。
 */
@interface TREAudioPlayer : TREObject

/**
 *  获取单例。
 *
 *  @return 单例。
 */
+ (instancetype)sharedInstance;

/**
 *  查看是否正在播放。
 *
 *  @return 是否正在播放。
 */
- (BOOL)isPlaying;

/**
 *  播放指定文件。
 *
 *  @param path     文件路径。
 *  @param callback 结果回调。
 */
- (void)startWithFile:(NSString *)path callback:(void (^)(BOOL isSuccessful))callback;

/**
 *  播放指定 `NSData` 。
 *
 *  @param data     音频数据。
 *  @param callback 结果回调。
 */
- (void)startWithData:(NSData *)data callback:(void (^)(BOOL isSuccessful))callback;

/**
 *  停止播放。
 */
- (void)stop;

@end