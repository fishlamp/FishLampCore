//
//  FLQueableAsyncOperation.h
//  FishLampCore
//
//  Created by Mike Fullerton on 11/5/13.
//  Copyright (c) 2013 Mike Fullerton. All rights reserved.
//

#import "FishLampCore.h"

#import "FLPromisedResult.h"
#import "FLAsyncBlockTypes.h"

@class FLFinisher;
@protocol FLAsyncQueue;

/*!
 *  This object encapsulates the object that is queued in a FLAsyncQueue.
 *  Unless you're creating a new type of object that is queueable, you don't need to know about this.
 */
@protocol FLQueueableAsyncOperation <NSObject>

- (void) startAsyncOperationInQueue:(id<FLAsyncQueue>) queue finisher:(FLFinisher*) finisher;

- (void) runSynchronousOperationInQueue:(id<FLAsyncQueue>) queue finisher:(FLFinisher*) finisher;

@end

