//
//  FLCStringFragment.h
//  FishLampCore
//
//  Created by Mike Fullerton on 3/18/13.
//  Copyright (c) 2013 GreenTongue Software LLC, Mike Fullerton. 
//  The FishLamp Framework is released under the MIT License: http://fishlamp.com/license 
//

#import "FishLampRequired.h"

typedef struct {
    const char* string;
    size_t length;
} FLCStringFragment;

extern FLCStringFragment FLParseFragmentFromCString(const char* string, char stopChar);

NS_INLINE 
const char* FLCStringCopyWithLength(const char* str, size_t len) {
    char* copy = malloc(len + 1);
    memcpy(copy, str, len);
    copy[len] = 0;
    return copy;
}

NS_INLINE 
const char* FLCStringCopy(const char* str) {
    return FLCStringCopyWithLength(str, strlen(str));
}

NS_INLINE
const char* FLCopyCStringInFragment(FLCStringFragment charString) {
    return FLCStringCopyWithLength(charString.string, charString.length);
}


@interface NSString (FLCStringFragment)
- (id) initWithCStringFragment:(FLCStringFragment) charString;
+ (NSString*) stringWithCStringFragment:(FLCStringFragment) charString;
@end