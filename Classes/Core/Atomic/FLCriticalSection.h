//
//  FLCriticalSection.h
//  FishLamp
//
//  Created by Mike Fullerton on 12/26/13.
//
//

#import "FishLampRequired.h"
#if defined(__cplusplus)
    extern "C" {
#endif /* defined(__cplusplus) */

typedef void (^FLCriticalSectionBlock)();

extern void FLCriticalSection(void* shared_addr, FLCriticalSectionBlock block);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */
