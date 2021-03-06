//
//  FLNonretainedObjectProxy.h
//  FishLampiOS-Lib
//
//  Created by Mike Fullerton on 2/5/12.
//  Copyright (c) 2013 GreenTongue Software LLC, Mike Fullerton. 
//  The FishLamp Framework is released under the MIT License: http://fishlamp.com/license 
//

#import "FishLampCore.h"
#import "FLAbstractObjectProxy.h"

@interface FLNonretainedObjectProxy : FLAbstractObjectProxy {
@private
    FL_WEAK id _containedObject;
}
@property (readonly, weak) id containedObject;

+ (id) nonretainedObjectProxy:(id) object;
@end

@interface NSObject (FLNonretainedObjectProxy)
- (id) nonretained_fl;
@end
