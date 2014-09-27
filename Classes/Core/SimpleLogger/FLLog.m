//
//	FLLog.m
//	FishLamp
//
//	Created by Mike Fullerton on 9/15/10.
//	Copyright (c) 2013 GreenTongue Software LLC, Mike Fullerton. 
//  The FishLamp Framework is released under the MIT License: http://fishlamp.com/license 
//

#import "FLLog.h"

#import <execinfo.h>
#import <stdio.h>
#import <libkern/OSAtomic.h>

#import "FLConsoleLogSink.h"
#import "FLExceptionThrowing.h"

NSException* FLWillThrowExceptionHandlerForLogger(NSException *exception);

NSException* FLWillThrowExceptionHandlerForLogger(NSException *exception) {
    [[FLLogLogger instance] logObject:exception];
    return exception;
}

@implementation FLLogLogger 

FLSynthesizeSingleton(FLLogLogger);

+ (void) initialize {

    static BOOL s_initialized = NO;
    if(!s_initialized) {
        s_initialized = YES;

        FLSetWillThrowExceptionHandler(FLWillThrowExceptionHandlerForLogger);
    }
}

- (id) init {
    self = [super init];
    if(self) {

        FLLogSinkBehavior* behavior = [FLLogSinkBehavior logSinkBehavior];
        behavior.outputLocation = YES;
        behavior.outputStackTrace = YES;

        [self addLoggerSink:[FLConsoleLogSink consoleLogSink:behavior]];
    }
    
    return self;
}

@end

