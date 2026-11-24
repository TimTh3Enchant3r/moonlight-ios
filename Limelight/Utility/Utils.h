//
//  Utils.h
//  Moonlight
//
//  Created by Diego Waxemberg on 10/20/14.
//  Copyright (c) 2014 Moonlight Stream. All rights reserved.
//

@interface Utils : NSObject

typedef NS_ENUM(int, PairState) {
    PairStateUnknown,
    PairStateUnpaired,
    PairStatePaired
};

typedef NS_ENUM(int, State) {
    StateUnknown,
    StateOffline,
    StateOnline
};

FOUNDATION_EXPORT NSString *const deviceName;

+ (NSData*) randomBytes:(NSInteger)length;
+ (NSString*) bytesToHex:(NSData*)data;
+ (NSData*) hexToBytes:(NSString*) hex;
+ (void) addHelpOptionToDialog:(UIAlertController*)dialog;
+ (BOOL) isActiveNetworkVPN;
+ (BOOL) parseAddressPortString:(NSString*)addressPort address:(NSRange*)address port:(NSRange*)port;
+ (NSString*) addressPortStringToAddress:(NSString*)addressPort;
+ (unsigned short) addressPortStringToPort:(NSString*)addressPort;
+ (NSString*) addressAndPortToAddressPortString:(NSString*)address port:(unsigned short)port;

#if !TARGET_OS_TV
+ (void) launchUrl:(NSString*)urlString;
#endif

// Native resolution modes, remembered so a "native" choice follows the
// screen in use (e.g. iPhone Duo inner vs. outer display) at stream start.
typedef NS_ENUM(NSInteger, NativeResolutionMode) {
    NativeResolutionModeNone = 0,
    NativeResolutionModeSafeArea = 1,
    NativeResolutionModeFullScreen = 2,
};

// Returns the physical pixel resolution of the window's current screen,
// in landscape orientation and rounded down to even dimensions. Uses
// nativeBounds/nativeScale, so it is correct with Display Zoom enabled
// and on foldables where the active screen changes.
+ (CGSize) nativeStreamResolutionForWindow:(UIWindow*)window safeAreaOnly:(BOOL)safeAreaOnly;
+ (NativeResolutionMode) savedNativeResolutionMode;
+ (void) setSavedNativeResolutionMode:(NativeResolutionMode)mode;

@end

@interface NSString (NSStringWithTrim)

- (NSString*) trim;

@end
