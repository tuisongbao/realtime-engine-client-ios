#import <CoreLocation/CoreLocation.h>

#import "TREChatMessageContent.h"

/**
 *  Chat 消息地理位置内容。
 */
@interface TREChatMessageLocationContent : TREChatMessageContent

/**
 *  纬度。
 */
@property (nonatomic) double latitude;
/**
 *  经度。
 */
@property (nonatomic) double longitude;
/**
 *  兴趣点，即坐标所处地名。
 */
@property (nonatomic) NSString *pointOfInterest;

/**
 *  初始化实例。
 *
 *  @param latitude        纬度。
 *  @param longitude       经度。
 *  @param pointOfInterest 可选，兴趣点，不提供时将由服务端调用百度地图服务获取。
 *
 *  @return 新实例。
 */
- (instancetype)initWithLatitude:(double)latitude
                       longitude:(double)longitude
                 pointOfInterest:(NSString *)pointOfInterest;

@end
