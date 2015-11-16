/**
 *  图片处理帮助类。
 */
@interface TREImageConverter : NSObject

/**
 *  限制图片最大宽度进行等比缩放。
 *
 *  @param image    原图片。
 *  @param maxWidth 最大宽度。
 *
 *  @return 调整后的图片。
 */
+ (UIImage *)resize:(UIImage *)image withMaxWidth:(CGFloat)maxWidth;

@end
