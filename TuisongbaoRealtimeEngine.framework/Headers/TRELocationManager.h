#import "CoreLocation/CoreLocation.h"

/**
 *  地理位置获取帮助类。
 */
@interface TRELocationManager : NSObject

/**
 *  获取单例。
 *
 *  @return 单例。
 */
+ (instancetype)sharedInstance;

/**
 *  获取当前地理位置。
 *
 *  @warning 注意，对于 iOS 8 ， `TRELocationManager` 内部使用 `requestWhenInUseAuthorization` 请求权限，请在
 *`info.plist` 中配置 `NSLocationWhenInUseUsageDescription`
 *，具体请参考[这里](http://nevan.net/2014/09/core-location-manager-changes-in-ios-8/)
 *
 *  @param callback 结果回调。
 */
- (void)currentLocationWithCallback:(void (^)(BOOL isSuccessful, CLLocation *location))callback;

@end
