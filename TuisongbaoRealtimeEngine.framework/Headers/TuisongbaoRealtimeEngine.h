#import <UIKit/UIKit.h>

//! Project version number for TuisongbaoRealtimeEngine.
FOUNDATION_EXPORT double TuisongbaoRealtimeEngineVersionNumber;

//! Project version string for TuisongbaoRealtimeEngine.
FOUNDATION_EXPORT const unsigned char TuisongbaoRealtimeEngineVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import
// <TuisongbaoRealtimeEngine/PublicHeader.h>

// Didn't use the format above because of this https://forums.developer.apple.com/thread/8816

#import "TREEventEmitter.h"
#import "TREDebug.h"
#import "TREObject.h"

#import "TREEngine.h"
#import "TREConnection.h"
#import "TREUser.h"

#import "TREChannelManager.h"
#import "TREChannel.h"
#import "TREPrivateChannel.h"
#import "TREPresenceChannel.h"
#import "TREPresenceChannelUser.h"

#import "TREChatManager.h"
#import "TREChatGroupManager.h"
#import "TREChatGroup.h"
#import "TREChatUser.h"
#import "TREChatConversationManager.h"
#import "TREChatConversation.h"
#import "TREChatMessage.h"
#import "TREChatMessageContent.h"
#import "TREChatMessageTextContent.h"
#import "TREChatMessageFileContent.h"
#import "TREChatMessageImageContent.h"
#import "TREChatMessageVoiceContent.h"
#import "TREChatMessageVideoContent.h"
#import "TREChatMessageLocationContent.h"

#import "TREAudioRecorder.h"
#import "TREAudioPlayer.h"
#import "TREImageConverter.h"
#import "TRELocationManager.h"
