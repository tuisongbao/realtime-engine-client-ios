typedef void (^TREEventEmitterHandler)();
typedef void (^TREEventEmitterDataHandler)(id data);

/**
 *  事件发射器，用于实现基于 `trigger` 和 `bind` 的本地 Pub/Sub 模式。
 *
 *  @warning 内部实现使用强引用，所以 `bind` 、 `unbind` 一般需成对使用。
 */
@interface TREEventEmitter : NSObject

/**
 *  为指定事件绑定处理方法，该处理方法不接收参数。
 *
 *  @param eventName 事件名称。
 *  @param handler   处理方法。
 */
- (void)bind:(NSString *)eventName handler:(TREEventEmitterHandler)handler;

/**
 *  为指定事件绑定一次性处理方法，该处理方法不接收参数。
 *
 *  @param eventName 事件名称。
 *  @param handler   处理方法。
 */
- (void)bindOnce:(NSString *)eventName handler:(TREEventEmitterHandler)handler;

/**
 *  为指定事件绑定处理方法，该处理方法接收一个参数。
 *
 *  @param eventName 事件名称。
 *  @param handler   处理方法。
 */
- (void)bind:(NSString *)eventName dataHandler:(TREEventEmitterDataHandler)handler;

/**
 *  为指定事件绑定一次性处理方法，该处理方法接收一个参数。
 *
 *  @param eventName 事件名称。
 *  @param handler   处理方法。
 */
- (void)bindOnce:(NSString *)eventName dataHandler:(TREEventEmitterDataHandler)handler;

/**
 *  使用 *Target-Action* 模式绑定事件处理方法。
 *
 *  @param eventName 事件名称。
 *  @param target    target。
 *  @param aSelector aSelector。
 */
- (void)bind:(NSString *)eventName target:(id)target selector:(SEL)aSelector;

/**
 *  使用 *Target-Action* 模式绑定一次性事件处理方法。
 *
 *  @param eventName 事件名称。
 *  @param target    target。
 *  @param aSelector aSelector。
 */
- (void)bindOnce:(NSString *)eventName target:(id)target selector:(SEL)aSelector;

/**
 *  将指定处理方法从指定事件上解绑。
 *
 *  对于存在多次重复绑定的情况，每调用一次只会解除一次绑定。
 *
 *  @param eventName 事件名称。
 *  @param handler   处理方法。
 */
- (void)unbind:(NSString *)eventName handler:(id)handler;

/**
 *  将指定 `target` 和 `selector` 从指定事件上解绑。
 *
 *  对于存在多次重复绑定的情况，每调用一次只会解除一次绑定。
 *
 *  @param eventName 事件名称。
 *  @param target    target。
 *  @param aSelector aSelector。
 */
- (void)unbind:(NSString *)eventName target:(id)target selector:(SEL)aSelector;

/**
 *  将指定 `target` 的所有关联绑定解除。
 *
 *  @param target target。
 */
- (void)unbindTarget:(id)target;

/**
 *  解绑指定事件的所有处理方法。
 *
 *  @warning 请谨慎调用此方法，确保不会影响其它地方的绑定。
 *
 *  @param eventName 事件名称。
 */
- (void)unbind:(NSString *)eventName;

/**
 *  解绑该对象上的所有事件的所有处理方法。
 *
 *  @warning 请谨慎调用此方法，确保不会影响其它地方的绑定。
 */
- (void)unbind;

/**
 *  触发指定事件，不传递参数给处理方法。
 *
 *  @param eventName 事件名称。
 */
- (void)trigger:(NSString *)eventName;

/**
 *  触发指定事件，并传递一个参数给处理方法。
 *
 *  @param eventName 时间名称。
 *  @param data      要传递的参数。
 */
- (void)trigger:(NSString *)eventName data:(id)data;

/**
 *  从另一个对象上复制所有绑定，覆盖到当前对象。
 *
 *  @param from 要复制的对象。
 */
- (void)copyBindings:(TREEventEmitter *)from;

@end
