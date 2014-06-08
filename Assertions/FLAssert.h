//
//  FLAssert.h
//  FishLampCore
//
//  Created by Mike Fullerton on 9/3/13.
//  Copyright (c) 2013 Mike Fullerton. All rights reserved.
//

#import "FishLampRequired.h"
#import "FishLampExceptions.h"
#import "NSError+FLStackTrace.h"
#import "FLAssertionFailureErrorDomain.h"
#import "FLAssertionHandler.h"

#ifndef FL_ASSERTIONS
    #if DEBUG
    #define FL_ASSERTIONS 1
    #endif
#endif

#if FL_ASSERTIONS
    #define FLHandleAssertionFailure(CODE, NAME, DESCRIPTION, CONTEXT) \
                do { \
                    NSException* __EX = [[FLAssertionHandler sharedHandler] assertionFailed:FLAssertionFailureErrorDomain \
                                                                                       code:CODE \
                                                                 stackTrace:FLStackTraceMake(FLCurrentFileLocation(), YES) \
                                                                       name:NAME \
                                                                description:[NSString stringWithFormat:@"%@: %@", CONTEXT, DESCRIPTION]]; \
                    if(__EX) { \
                        FLThrowException(__EX);  \
                    } \
                } \
                while (0)


    #define FLAssertFailed(DESCRIPTION...) \
                FLHandleAssertionFailure(FLAssertionFailureCondition, \
                    @"Assertion Failed", \
                    ([NSString stringWithFormat:@"" DESCRIPTION]), \
                    NSStringFromClass([self class]))

    #define FLCAssertFailed(DESCRIPTION...) \
                FLHandleAssertionFailure(FLAssertionFailureCondition, \
                    @"Assertion Failed", \
                    ([NSString stringWithFormat:@"" DESCRIPTION]), \
                    @"")


    #define FLAssert(CONDITION, DESCRIPTION...) \
                do { \
                    if(!(CONDITION)) { \
                        FLHandleAssertionFailure(FLAssertionFailureCondition, \
                            ([NSString stringWithFormat:@"Asserting \"%s\" Failed", #CONDITION]), \
                            ([NSString stringWithFormat:@"" DESCRIPTION]), \
                            NSStringFromClass([self class])); \
                    } \
                } \
                while(0)

    #define FLCAssert(CONDITION, DESCRIPTION...) \
                do { \
                    if(!(CONDITION)) { \
                        FLHandleAssertionFailure(FLAssertionFailureCondition, \
                            ([NSString stringWithFormat:@"Asserting \"%s\" Failed", #CONDITION]), \
                            ([NSString stringWithFormat:@"" DESCRIPTION]), \
                            @""); \
                    } \
                } \
                while(0)

    #define FLAssertNil(REFERENCE, DESCRIPTION...)  \
                do { \
                    if(nil != (REFERENCE)) { \
                        FLHandleAssertionFailure(FLAssertionFailureCondition, \
                            ([NSString stringWithFormat:@"Asserting '%s == nil' Failed", #REFERENCE]), \
                            ([NSString stringWithFormat:@"" DESCRIPTION]), \
                            NSStringFromClass([self class])); \
                    } \
                } \
                while(0)

    #define FLAssertNotNil(REFERENCE, DESCRIPTION...) \
                do { \
                    if(nil == (REFERENCE)) { \
                        FLHandleAssertionFailure(FLAssertionFailureCondition, \
                            ([NSString stringWithFormat:@"Asserting '%s != nil' Failed", #REFERENCE]), \
                            ([NSString stringWithFormat:@"" DESCRIPTION]), \
                            NSStringFromClass([self class])); \
                    } \
                } \
                while(0)

    #define FLCAssertNil(REFERENCE, DESCRIPTION...)  \
                do { \
                    if(nil != (REFERENCE)) { \
                        FLHandleAssertionFailure(FLAssertionFailureCondition, \
                            ([NSString stringWithFormat:@"Asserting '%s == nil' Failed", #REFERENCE]), \
                            ([NSString stringWithFormat:@"" DESCRIPTION]), \
                            @""); \
                    } \
                } \
                while(0)

    #define FLCAssertNotNil(REFERENCE, DESCRIPTION...) \
                do { \
                    if(nil == (REFERENCE)) { \
                        FLHandleAssertionFailure(FLAssertionFailureCondition, \
                            ([NSString stringWithFormat:@"Asserting '%s != nil' Failed", #REFERENCE]), \
                            ([NSString stringWithFormat:@"" DESCRIPTION]), \
                            @""); \
                    } \
                } \
                while(0)

    #define FLAssertNonZeroNumber(NUMBER, DESCRIPTION...) \
                do { \
                    if((NUMBER) == 0) { \
                        FLHandleAssertionFailure(FLAssertionFailureCondition, \
                            ([NSString stringWithFormat:@"Asserting '%s != 0' Failed", #NUMBER]), \
                            ([NSString stringWithFormat:@"" DESCRIPTION]), \
                            NSStringFromClass([self class])); \
                    } \
                } \
                while(0)

    #define FLAssertZeroNumber(NUMBER, DESCRIPTION...) \
                do { \
                    if((NUMBER) != 0) { \
                        FLHandleAssertionFailure(FLAssertionFailureCondition, \
                            ([NSString stringWithFormat:@"Asserting '%s != 0' Failed", #NUMBER]), \
                            ([NSString stringWithFormat:@"" DESCRIPTION]), \
                            NSStringFromClass([self class])); \
                    } \
                } \
                while(0)


    #define FLAssertNonNilPointer(POINTER, DESCRIPTION...) \
                do { \
                    if((POINTER) == nil) { \
                        FLHandleAssertionFailure(FLAssertionFailureCondition, \
                            ([NSString stringWithFormat:@"Asserting '%s != nil' Failed", #POINTER]), \
                            ([NSString stringWithFormat:@"" DESCRIPTION]), \
                            NSStringFromClass([self class])); \
                    } \
                } \
                while(0)

    #define FLAssertNilPointer(POINTER, DESCRIPTION...) \
                do { \
                    if((POINTER) != nil) { \
                        FLHandleAssertionFailure(FLAssertionFailureCondition, \
                            ([NSString stringWithFormat:@"Asserting '%s == nil' Failed", #POINTER]), \
                            ([NSString stringWithFormat:@"" DESCRIPTION]), \
                            NSStringFromClass([self class])); \
                    } \
                } \
                while(0)

    #define FLAssertStringIsNotEmpty(STRING, DESCRIPTION...) \
                do { \
                    if(FLStringIsEmpty(STRING) == YES) { \
                        FLHandleAssertionFailure(FLAssertionFailureCondition, \
                            ([NSString stringWithFormat:@"Asserting String is not empty for '%s' Failed", #STRING]), \
                            ([NSString stringWithFormat:@"" DESCRIPTION]), \
                            NSStringFromClass([self class])); \
                    } \
                } \
                while(0)


    #define FLAssertStringIsEmpty(STRING, DESCRIPTION...) \
                do { \
                    if(FLStringIsEmpty(STRING) == NO) { \
                        FLHandleAssertionFailure(FLAssertionFailureCondition, \
                            ([NSString stringWithFormat:@"Asserting String is empty for '%s' Failed", #STRING]), \
                            ([NSString stringWithFormat:@"" DESCRIPTION]), \
                            NSStringFromClass([self class])); \
                    } \
                } \
                while(0)


    #define FLCAssertNonZeroNumber(NUMBER, DESCRIPTION...) \
                do { \
                    if((NUMBER) == 0) { \
                        FLHandleAssertionFailure(FLAssertionFailureCondition, \
                            ([NSString stringWithFormat:@"Asserting '%s != 0' Failed", #NUMBER]), \
                            ([NSString stringWithFormat:@"" DESCRIPTION]), \
                            NSStringFromClass([self class])); \
                    } \
                } \
                while(0)

    #define FLCAssertZeroNumber(NUMBER, DESCRIPTION...) \
                do { \
                    if((NUMBER) != 0) { \
                        FLHandleAssertionFailure(FLAssertionFailureCondition, \
                            ([NSString stringWithFormat:@"Asserting '%s != 0' Failed", #NUMBER]), \
                            ([NSString stringWithFormat:@"" DESCRIPTION]), \
                            @""); \
                    } \
                } \
                while(0)


    #define FLCAssertNonNilPointer(POINTER, DESCRIPTION...) \
                do { \
                    if((POINTER) == nil) { \
                        FLHandleAssertionFailure(FLAssertionFailureCondition, \
                            ([NSString stringWithFormat:@"Asserting '%s != nil' Failed", #POINTER]), \
                            ([NSString stringWithFormat:@"" DESCRIPTION]), \
                            @""); \
                    } \
                } \
                while(0)

    #define FLCAssertNilPointer(POINTER, DESCRIPTION...) \
                do { \
                    if((POINTER) != nil) { \
                        FLHandleAssertionFailure(FLAssertionFailureCondition, \
                            ([NSString stringWithFormat:@"Asserting '%s == nil' Failed", #POINTER]), \
                            ([NSString stringWithFormat:@"" DESCRIPTION]), \
                            @""); \
                    } \
                } \
                while(0)



    #define FLCAssertStringIsNotEmpty(STRING, DESCRIPTION...) \
                do { \
                    if(FLStringIsEmpty(STRING) == YES) { \
                        FLHandleAssertionFailure(FLAssertionFailureCondition, \
                            ([NSString stringWithFormat:@"Asserting String is not empty for '%s' Failed", #STRING]), \
                            ([NSString stringWithFormat:@"" DESCRIPTION]), \
                            @""); \
                    } \
                } \
                while(0)


    #define FLCAssertStringIsEmpty(STRING, DESCRIPTION...) \
                do { \
                    if(FLStringIsEmpty(STRING) == NO) { \
                        FLHandleAssertionFailure(FLAssertionFailureCondition, \
                            ([NSString stringWithFormat:@"Asserting String is empty for '%s' Failed", #STRING]), \
                            ([NSString stringWithFormat:@"" DESCRIPTION]), \
                            @""); \
                    } \
                } \
                while(0)



    #define FLAssertStringsAreEqual(a,b, DESCRIPTION...) \
                FLAssert(FLStringsAreEqual(a,b), @"" DESCRIPTION);

    #define FLAssertStringsNotEqual(a,b, DESCRIPTION...) \
                FLAssert(!FLStringsAreEqual(a,b), @"" DESCRIPTION);

    #define FLAssertIsKindOfClass(OBJECT, CLASS, DESCRIPTION...) \
                do { \
                    id __OBJ__ = OBJECT; \
                    FLAssert([__OBJ__ isKindOfClass:[CLASS class]], \
                                @"expecting %@ but got %@ - %@", \
                                NSStringFromClass([CLASS class]), \
                                NSStringFromClass([__OBJ__ class]), \
                                @"" DESCRIPTION);  \
                } while(0)

    #define FLAssertConformsToProtocol(__OBJ__, __PROTOCOL__, DESCRIPTION...) \
                FLAssert([__OBJ__ conformsToProtocol:@protocol(__PROTOCOL__)], @"" DESCRIPTION)


#define FLAssertionFailed \
            FLAssertFailed

#else
    #define FLAssert(...) 
    #define FLAssertFailed(...)
    #define FLAssertNil(...)
    #define FLAssertNotNil(...)
    #define FLAssertStringIsNotEmpty(...)
    #define FLAssertStringIsEmpty(...)
    #define FLAssertIsKindOfClass(...)
    #define FLAssertNonZeroNumber(...)
    #define FLAssertZeroNumber(...)
    #define FLAssertNonNilPointer(...)
    #define FLAssertNilPointer(...)
    #define FLAssertionFailed(...)
    #define FLAssertStringsAreEqual(...)
    #define FLAssertStringsNotEqual(...)
    #define FLAssertIsKindOfClass(...)
    #define FLAssertConformsToProtocol(...)

    #define FLCAssert(...)
    #define FLCAssertFailed(...)
    #define FLCAssertNil(REFERENCE, DESCRIPTION...)
    #define FLCAssertNotNil(REFERENCE, DESCRIPTION...)
    #define FLCAssertNonZeroNumber(NUMBER, DESCRIPTION...)
    #define FLCAssertZeroNumber(NUMBER, DESCRIPTION...)
    #define FLCAssertNonNilPointer(POINTER, DESCRIPTION...)
    #define FLCAssertNilPointer(POINTER, DESCRIPTION...)
    #define FLCAssertStringIsNotEmpty(STRING, DESCRIPTION...)
    #define FLCAssertStringIsEmpty(STRING, DESCRIPTION...)


#endif







