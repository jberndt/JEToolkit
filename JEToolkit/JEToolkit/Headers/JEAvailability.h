//
//  JEAvailability.h
//  JEToolkit
//
//  Copyright (c) 2014 John Rommel Estropia
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.
//

#ifndef JEToolkit_JEAvailability_h
#define JEToolkit_JEAvailability_h


#import <Availability.h>

#ifdef DEBUG // Start fix for LLVM

#import <Foundation/NSObjCRuntime.h>

// http://stackoverflow.com/questions/4676000/is-there-a-way-for-xcode-to-warn-about-new-api-calls/19704587#19704587

#undef CF_AVAILABLE
#define CF_AVAILABLE(_mac, _ios) __OSX_AVAILABLE_STARTING(__MAC_##_mac, __IPHONE_##_ios)

#undef CF_AVAILABLE_MAC
#define CF_AVAILABLE_MAC(_mac) __OSX_AVAILABLE_STARTING(__MAC_##_mac, __IPHONE_NA)

#undef CF_AVAILABLE_IOS
#define CF_AVAILABLE_IOS(_ios) __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_##_ios)

#undef CF_DEPRECATED
#define CF_DEPRECATED(_macIntro, _macDep, _iosIntro, _iosDep, ...) \
    __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_##_macIntro, __MAC_##_macDep, __IPHONE_##_iosIntro, __IPHONE_##_iosDep)

#undef CF_DEPRECATED_MAC
#define CF_DEPRECATED_MAC(_macIntro, _macDep, ...) \
    __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_##_macIntro, __MAC_##_macDep, __IPHONE_NA, __IPHONE_NA)

#undef CF_DEPRECATED_IOS
#define CF_DEPRECATED_IOS(_iosIntro, _iosDep, ...) \
    __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_NA, __MAC_NA, __IPHONE_##_iosIntro, __IPHONE_##_iosDep)

#undef CF_ENUM_AVAILABLE
#define CF_ENUM_AVAILABLE(_mac, _ios) CF_AVAILABLE(_mac, _ios)

#undef CF_ENUM_AVAILABLE_MAC
#define CF_ENUM_AVAILABLE_MAC(_mac) CF_AVAILABLE_MAC(_mac)

#undef CF_ENUM_AVAILABLE_IOS
#define CF_ENUM_AVAILABLE_IOS(_ios) CF_AVAILABLE_IOS(_ios)

#undef CF_ENUM_DEPRECATED
#define CF_ENUM_DEPRECATED(_macIntro, _macDep, _iosIntro, _iosDep, ...) \
    CF_DEPRECATED(_macIntro, _macDep, _iosIntro, _iosDep, __VA_ARGS__)

#undef CF_ENUM_DEPRECATED_MAC
#define CF_ENUM_DEPRECATED_MAC(_macIntro, _macDep, ...) \
    CF_DEPRECATED_MAC(_macIntro, _macDep, __VA_ARGS__)

#undef CF_ENUM_DEPRECATED_IOS
#define CF_ENUM_DEPRECATED_IOS(_iosIntro, _iosDep, ...) \
    CF_DEPRECATED_IOS(_iosIntro, _iosDep, __VA_ARGS__)

#undef NS_AVAILABLE
#define NS_AVAILABLE(_mac, _ios) CF_AVAILABLE(_mac, _ios)

#undef NS_AVAILABLE_MAC
#define NS_AVAILABLE_MAC(_mac) CF_AVAILABLE_MAC(_mac)

#undef NS_AVAILABLE_IOS
#define NS_AVAILABLE_IOS(_ios) CF_AVAILABLE_IOS(_ios)

#undef NS_DEPRECATED
#define NS_DEPRECATED(_macIntro, _macDep, _iosIntro, _iosDep, ...) \
    CF_DEPRECATED(_macIntro, _macDep, _iosIntro, _iosDep, __VA_ARGS__)

#undef NS_DEPRECATED_MAC
#define NS_DEPRECATED_MAC(_macIntro, _macDep, ...) \
    CF_DEPRECATED_MAC(_macIntro, _macDep, __VA_ARGS__)

#undef NS_DEPRECATED_IOS
#define NS_DEPRECATED_IOS(_iosIntro, _iosDep, ...) \
    CF_DEPRECATED_IOS(_iosIntro, _iosDep, __VA_ARGS__)

#undef NS_ENUM_AVAILABLE
#define NS_ENUM_AVAILABLE(_mac, _ios) CF_ENUM_AVAILABLE(_mac, _ios)

#undef NS_ENUM_AVAILABLE_MAC
#define NS_ENUM_AVAILABLE_MAC(_mac) CF_ENUM_AVAILABLE_MAC(_mac)

#undef NS_ENUM_AVAILABLE_IOS
#define NS_ENUM_AVAILABLE_IOS(_ios) CF_ENUM_AVAILABLE_IOS(_ios)

#undef NS_ENUM_DEPRECATED
#define NS_ENUM_DEPRECATED(_macIntro, _macDep, _iosIntro, _iosDep, ...) \
    CF_ENUM_DEPRECATED(_macIntro, _macDep, _iosIntro, _iosDep, __VA_ARGS__)

#undef NS_ENUM_DEPRECATED_MAC
#define NS_ENUM_DEPRECATED_MAC(_macIntro, _macDep, ...) \
    CF_ENUM_DEPRECATED_MAC(_macIntro, _macDep, __VA_ARGS__)

#undef NS_ENUM_DEPRECATED_IOS
#define NS_ENUM_DEPRECATED_IOS(_iosIntro, _iosDep, ...) \
    CF_ENUM_DEPRECATED_IOS(_iosIntro, _iosDep, __VA_ARGS__)

#undef NS_AVAILABLE_IPHONE
#define NS_AVAILABLE_IPHONE(_ios) CF_AVAILABLE_IOS(_ios)

#undef NS_DEPRECATED_IPHONE
#define NS_DEPRECATED_IPHONE(_iosIntro, _iosDep) CF_DEPRECATED_IOS(_iosIntro, _iosDep)

#undef NS_CLASS_AVAILABLE
#define NS_CLASS_AVAILABLE(_mac, _ios) \
    __attribute__((visibility("default"))) NS_AVAILABLE(_mac, _ios)

#undef NS_CLASS_DEPRECATED
#define NS_CLASS_DEPRECATED(_mac, _macDep, _ios, _iosDep, ...) \
    __attribute__((visibility("default"))) NS_DEPRECATED(_mac, _macDep, _ios, _iosDep, __VA_ARGS__)

#undef NS_CLASS_AVAILABLE_IOS
#define NS_CLASS_AVAILABLE_IOS(_ios) NS_CLASS_AVAILABLE(NA, _ios)

#undef NS_CLASS_AVAILABLE_MAC
#define NS_CLASS_AVAILABLE_MAC(_mac) NS_CLASS_AVAILABLE(_mac, NA)

#undef NS_CLASS_DEPRECATED_MAC
#define NS_CLASS_DEPRECATED_MAC(_macIntro, _macDep, ...) \
    NS_CLASS_DEPRECATED(_macIntro, _macDep, NA, NA, __VA_ARGS__)

#undef NS_CLASS_DEPRECATED_IOS
#define NS_CLASS_DEPRECATED_IOS(_iosIntro, _iosDep, ...) \
    NS_CLASS_DEPRECATED(NA, NA, _iosIntro, _iosDep, __VA_ARGS__)

#endif // End fix for LLVM


#import "JECompilerDefines.h"

#define JE_PRAGMA_PUSH_IGNORE_AVAILABILITY \
    JE_PRAGMA_PUSH \
    JE_PRAGMA_IGNORE("-Wdeprecated-declarations")

#define __JE_AVAILABILITY_WARN_REGRESSION(ver) \
    __attribute__((deprecated("API not available before iOS " ver "!"))) \
    __attribute__((weak_import))

#ifndef JE_AVAILABILITY_MAX_REQUIRED_VERSION
#define JE_AVAILABILITY_MAX_REQUIRED_VERSION __IPHONE_OS_VERSION_MIN_REQUIRED
#endif

#if JE_AVAILABILITY_MAX_REQUIRED_VERSION < __IPHONE_OS_VERSION_MIN_REQUIRED
#error You cannot ask for a soft max version which is less than the deployment target
#endif

#if JE_AVAILABILITY_MAX_REQUIRED_VERSION < __IPHONE_2_0
#undef __AVAILABILITY_INTERNAL__IPHONE_2_0
#define __AVAILABILITY_INTERNAL__IPHONE_2_0 __JE_AVAILABILITY_WARN_REGRESSION("2.0")
#endif

#if JE_AVAILABILITY_MAX_REQUIRED_VERSION < __IPHONE_2_1
#undef __AVAILABILITY_INTERNAL__IPHONE_2_1
#define __AVAILABILITY_INTERNAL__IPHONE_2_1 __JE_AVAILABILITY_WARN_REGRESSION("2.1")
#endif

#if JE_AVAILABILITY_MAX_REQUIRED_VERSION < __IPHONE_2_2
#undef __AVAILABILITY_INTERNAL__IPHONE_2_2
#define __AVAILABILITY_INTERNAL__IPHONE_2_2 __JE_AVAILABILITY_WARN_REGRESSION("2.2")
#endif

#if JE_AVAILABILITY_MAX_REQUIRED_VERSION < __IPHONE_3_0
#undef __AVAILABILITY_INTERNAL__IPHONE_3_0
#define __AVAILABILITY_INTERNAL__IPHONE_3_0 __JE_AVAILABILITY_WARN_REGRESSION("3.0")
#endif

#if JE_AVAILABILITY_MAX_REQUIRED_VERSION < __IPHONE_3_1
#undef __AVAILABILITY_INTERNAL__IPHONE_3_1
#define __AVAILABILITY_INTERNAL__IPHONE_3_1 __JE_AVAILABILITY_WARN_REGRESSION("3.1")
#endif

#if JE_AVAILABILITY_MAX_REQUIRED_VERSION < __IPHONE_3_2
#undef __AVAILABILITY_INTERNAL__IPHONE_3_2
#define __AVAILABILITY_INTERNAL__IPHONE_3_2 __JE_AVAILABILITY_WARN_REGRESSION("3.2")
#endif

#if JE_AVAILABILITY_MAX_REQUIRED_VERSION < __IPHONE_4_0
#undef __AVAILABILITY_INTERNAL__IPHONE_4_0
#define __AVAILABILITY_INTERNAL__IPHONE_4_0 __JE_AVAILABILITY_WARN_REGRESSION("4.0")
#endif

#if JE_AVAILABILITY_MAX_REQUIRED_VERSION < __IPHONE_4_1
#undef __AVAILABILITY_INTERNAL__IPHONE_4_1
#define __AVAILABILITY_INTERNAL__IPHONE_4_1 __JE_AVAILABILITY_WARN_REGRESSION("4.1")
#endif

#if JE_AVAILABILITY_MAX_REQUIRED_VERSION < __IPHONE_4_2
#undef __AVAILABILITY_INTERNAL__IPHONE_4_2
#define __AVAILABILITY_INTERNAL__IPHONE_4_2 __JE_AVAILABILITY_WARN_REGRESSION("4.2")
#endif

#if JE_AVAILABILITY_MAX_REQUIRED_VERSION < __IPHONE_4_3
#undef __AVAILABILITY_INTERNAL__IPHONE_4_3
#define __AVAILABILITY_INTERNAL__IPHONE_4_3 __JE_AVAILABILITY_WARN_REGRESSION("4.3")
#endif

#if JE_AVAILABILITY_MAX_REQUIRED_VERSION < __IPHONE_5_0
#undef __AVAILABILITY_INTERNAL__IPHONE_5_0
#define __AVAILABILITY_INTERNAL__IPHONE_5_0 __JE_AVAILABILITY_WARN_REGRESSION("5.0")
#endif

#if JE_AVAILABILITY_MAX_REQUIRED_VERSION < __IPHONE_5_1
#undef __AVAILABILITY_INTERNAL__IPHONE_5_1
#define __AVAILABILITY_INTERNAL__IPHONE_5_1 __JE_AVAILABILITY_WARN_REGRESSION("5.1")
#endif

#if JE_AVAILABILITY_MAX_REQUIRED_VERSION < __IPHONE_6_0
#undef __AVAILABILITY_INTERNAL__IPHONE_6_0
#define __AVAILABILITY_INTERNAL__IPHONE_6_0 __JE_AVAILABILITY_WARN_REGRESSION("6.0")
#endif

#if JE_AVAILABILITY_MAX_REQUIRED_VERSION < __IPHONE_6_1
#undef __AVAILABILITY_INTERNAL__IPHONE_6_1
#define __AVAILABILITY_INTERNAL__IPHONE_6_1 __JE_AVAILABILITY_WARN_REGRESSION("6.1")
#endif

#if JE_AVAILABILITY_MAX_REQUIRED_VERSION < __IPHONE_7_0
#undef __AVAILABILITY_INTERNAL__IPHONE_7_0
#define __AVAILABILITY_INTERNAL__IPHONE_7_0 __JE_AVAILABILITY_WARN_REGRESSION("7.0")
#endif

#if JE_AVAILABILITY_MAX_REQUIRED_VERSION < __IPHONE_7_1
#undef __AVAILABILITY_INTERNAL__IPHONE_7_1
#define __AVAILABILITY_INTERNAL__IPHONE_7_1 __JE_AVAILABILITY_WARN_REGRESSION("7.1")
#endif

#if JE_AVAILABILITY_MAX_REQUIRED_VERSION < __IPHONE_8_0
#undef __AVAILABILITY_INTERNAL__IPHONE_8_0
#define __AVAILABILITY_INTERNAL__IPHONE_8_0 __JE_AVAILABILITY_WARN_REGRESSION("8.0")
#endif


#endif
