//
//  FLUserPreferences.m
//  FishLampCocoa
//
//  Created by Mike Fullerton on 10/5/13.
//  Copyright (c) 2013 Mike Fullerton. All rights reserved.
//

#import "FLUserPreferences.h"
#import "NSBundle+FLVersion.h"
#import "FishLampSimpleLogger.h"

//#import "NSUserDefaults+FLAdditions.h"

#define kAppVersion @"app-version"

@interface FLUserPreferences()
@property (readonly, strong, nonatomic) NSUserDefaults* userDefaults;
- (void) checkVersion;
@end

@implementation FLUserPreferences

- (id) init {	
	self = [super init];
	if(self) {
		[self checkVersion];
	}
	return self;
}

+ (NSString*) appSpecificKey:(NSString*) key {
    return [key hasPrefix:[NSBundle bundleIdentifier]] ? key : [NSString stringWithFormat:@"%@.%@", [NSBundle bundleIdentifier], key];
}

+ (BOOL) isAppSpecificKey:(NSString*) key {
    return [key hasPrefix:[NSBundle bundleIdentifier]];
}

- (NSUserDefaults*) userDefaults {
    return [NSUserDefaults standardUserDefaults];
}

- (NSString*) readAppVersion {
    return [[self userDefaults] stringForKey:[self getKey:kAppVersion]];
}

- (void) writeAppVersion {
    [[self userDefaults] setObject:[NSBundle appVersionString] forKey:[self getKey:kAppVersion]];
}

- (void) deleteAllIfVersionChanged {
    if(FLStringsAreNotEqual(self.readAppVersion, [NSBundle appVersionString])) {
        FLDebugLog(@"removing prefs: %@ to %@", self.readAppVersion, [NSBundle appVersionString]);
        NSString *appDomain = [[NSBundle mainBundle] bundleIdentifier];
        [[NSUserDefaults standardUserDefaults] removePersistentDomainForName:appDomain];
    }
}

- (void) checkVersion {
    if(!_loaded) {
        _loaded = YES;
        [self deleteAllIfVersionChanged];
        [self writeAppVersion];
    }
}

- (NSString*) getKey:(NSString*) key {
    return [FLUserPreferences appSpecificKey:key];
}

- (void)removeObjectForKey:(id)aKey {
    [[self userDefaults] removeObjectForKey:[self getKey:aKey]];
}

- (id) objectForKey:(id) key {
    return [[self userDefaults] objectForKey:[self getKey:key]];
}

- (BOOL)boolForKey:(NSString *)key {
    return [[self userDefaults] boolForKey:[self getKey:key]];
}

- (void)setBool:(BOOL)value forKey:(NSString *)key {
    [[self userDefaults] setBool:value forKey:[self getKey:key]];
}

- (void) setObject:(id) object forKey:(id) key {
    [[self userDefaults] setObject:object forKey:[self getKey:key]];
}

- (void) synchronize {
    [self.userDefaults synchronize];
}

- (void) deleteAll {

    NSDictionary* prefs = [[NSUserDefaults standardUserDefaults] dictionaryRepresentation];

    for(id key in prefs) {
        if([FLUserPreferences isAppSpecificKey:key]) {
            [[NSUserDefaults standardUserDefaults] removeObjectForKey:key];
            FLDebugLog(@"removed key: %@", key);
        }
    }

    [[NSUserDefaults standardUserDefaults] synchronize];


}

- (void) restoreAppState {

}


@end
