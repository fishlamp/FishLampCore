//
//  NSString+MiscUtils.h
//  FishLampCocoa
//
//  Created by Mike Fullerton on 2/11/13.
//  Copyright (c) 2013 GreenTongue Software LLC, Mike Fullerton. 
//  The FishLamp Framework is released under the MIT License: http://fishlamp.com/license 
//

#import "FishLampCore.h"

@interface NSString (MiscUtils)

+ (NSString*) localizedStringForByteSize:(UInt64) size;

+ (NSString*) localizedStringForTime:(NSTimeInterval) seconds;

@end
