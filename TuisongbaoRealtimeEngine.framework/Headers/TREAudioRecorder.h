#import <AVFoundation/AVFoundation.h>

/**
 *  音频录制帮助类。
 *
 *  每次录制会产生一个临时文件用来保存录音数据。
 */
@interface TREAudioRecorder : NSObject

/**
 *  获取单例。
 *
 *  @return 单例。
 */
+ (instancetype)sharedInstance;

/**
 *  查询是否正在录制。
 *
 *  @return 是否正在录制。
 */
- (BOOL)isRecording;

/**
 *  启动录音。
 *
 *  @param maxDuration      可选，录音最大时长，超出将自动停止。
 *  @param progressCallback 可选，进度回调，接收两个参数：
 *
 *  - `progress` (float) ：设置了 `maxDuration` 时可用来提示录制进度或剩余时间，取值 0 - 1.0，未设置 `maxDuration`
 *时始终为 0 。
 *  - `peakPower` (float) ：可用来做录音音量提示。
 *
 *  @param doneCallback     结果回调。
 *
 *  @return 录制是否开始。
 */
- (BOOL)startWithMaxDuration:(NSNumber *)maxDuration
            progressCallback:(void (^)(float progress, float peakPower))progressCallback
                doneCallback:(void (^)(BOOL isSuccessful, NSString *recordFilePath))doneCallback;

/**
 *  停止录制。
 */
- (void)stop;

/**
 *  取消录制，临时文件将被自动删除。
 */
- (void)cancel;

/**
 *  清除所有录制产生的临时文件。
 */
- (void)removeAllFiles;

@end
