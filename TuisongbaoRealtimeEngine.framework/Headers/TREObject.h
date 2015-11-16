#import "TREEventEmitter.h"

/**
 *  SDK 通用基类。
 */
@interface TREObject : TREEventEmitter

/**
 *  预留扩展字段，方便开发者在实例上添加额外信息。
 */
@property (nonatomic) id extension;

- (void)refreshWithData:(NSDictionary *)data;

@end
