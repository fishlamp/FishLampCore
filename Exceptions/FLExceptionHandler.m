//
//  FLExceptionHandler.m
//  FishLampCore
//
//  Created by Mike Fullerton on 11/8/13.
//  Copyright (c) 2013 Mike Fullerton. All rights reserved.
//

#import "FLExceptionHandler.h"
//#import "FishLampRequired.h"

#import "FLDeclareDefaultProperty.h"

@implementation FLExceptionHandler

FLSynthesizeDefaultProperty(id, defaultExceptionHandler);

- (void) handleException:(NSException*) exception
              completion:(FLExceptionHandlerBlock) completion {

//    FLDebugLog(@"Unhandled exception: %@", [exception description]);

    if(completion) {
        completion(NO);
    }
}


@end
