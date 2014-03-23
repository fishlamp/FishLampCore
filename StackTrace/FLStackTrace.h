//
//  FLStackTrace_t.h
//  FishLamp
//
//  Created by Mike Fullerton on 9/3/12.
//  Copyright (c) 2013 GreenTongue Software LLC, Mike Fullerton.. 
//  The FishLamp Framework is released under the MIT License: http://fishlamp.com/license 
//

#import "FishLampRequired.h"
#import "FLStackTrace_t.h"

@interface FLStackTrace : NSObject {
@private
    FLStackTrace_t _stackTrace;
}

// use FLCreateStackTrace instead of this method
+ (FLStackTrace*) stackTrace:(FLStackTrace_t) willTakeOwnershipOfTrace;
+ (FLStackTrace*) stackTraceWithException:(NSException*) ex;

// where the stack trace was made
@property (readonly, strong, nonatomic) NSString* fileName;
@property (readonly, strong, nonatomic) NSString* filePath;
@property (readonly, strong, nonatomic) NSString* function;

@property (readonly, assign, nonatomic) int lineNumber;

@property (readonly, assign, nonatomic) FLCallStack_t callStack;

@property (readonly, assign, nonatomic) int stackDepth;
- (const char*) stackEntryAtIndex:(int) idx;
@end



#define FLCreateStackTrace(__WITH_STACK_TRACE__) \
            [FLStackTrace stackTrace:FLStackTraceToHere(__WITH_STACK_TRACE__)]



