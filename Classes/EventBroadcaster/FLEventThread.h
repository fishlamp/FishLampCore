//
//  FLReceiveEvent.h
//  Pods
//
//  Created by Mike Fullerton on 2/1/14.
//
//

#import "FishLampCore.h"

typedef NS_ENUM(NSUInteger, FLReceiveEvent) {
    FLScheduleMessagesInMainThreadOnly,
    FLRecieveEventInCurrentThread
};
