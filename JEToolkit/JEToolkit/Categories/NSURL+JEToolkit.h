//
//  NSURL+JEToolkit.h
//  JEToolkit
//
//  Copyright (c) 2013 John Rommel Estropia
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

#import <Foundation/Foundation.h>

#import "JECompilerDefines.h"


@interface NSURL (JEToolkit)

#pragma mark - Directories

/*! Convenience method to get the app Application Support URL
 */
+ (NSURL *)applicationSupportDirectory JE_CONST;

/*! Convenience method to get the app Caches URL
 */
+ (NSURL *)cachesDirectory JE_CONST;

/*! Convenience method to get the app Documents URL
 */
+ (NSURL *)documentsDirectory JE_CONST;

/*! Convenience method to get the app Downloads URL
 */
+ (NSURL *)downloadsDirectory JE_CONST;

/*! Convenience method to get the app Library URL
 */
+ (NSURL *)libraryDirectory JE_CONST;

/*! Convenience method to get the app Temporary URL
 */
+ (NSURL *)temporaryDirectory JE_CONST;


#pragma mark - Inspecting URLs

/*! Returns the known UTI for the receiver
 */
- (NSString *)UTI;

/*! Returns the known mimetype for the receiver, or "application/octet-stream" if a known mimetype was not found
 */
- (NSString *)mimeType;

/*! Checks if the reciever is an assets library URL
 */
- (BOOL)isAssetsLibraryURL;

/*! Checks if the reciever is a data URL
 */
- (BOOL)isDataURL;


#pragma mark - Extended Attributes

/*! Reads the extended attribute of a file URL referred to by key. Note anything other than file system URLs will be ignored.
 @param extendedAttribute The destination address of the read attribute
 @param key The key for the extended attribute
 @param error The error if the process failed
 @return YES if the attribute was read successfully, NO otherwise.
 */
- (BOOL)getExtendedAttribute:(NSString **)extendedAttribute
                      forKey:(NSString *)key
                       error:(NSError **)error;

/*! Sets an extended attribute on the file refered by the receiver. Note anything other than file system URLs will be ignored.
 @param extendedAttribute The value for the extended attribute
 @param key The key for the extended attribute
 @param error The error if the process failed
 @return YES if the attribute was set successfully, NO otherwise.
 */
- (BOOL)setExtendedAttribute:(NSString *)extendedAttribute
                      forKey:(NSString *)key
                       error:(NSError **)error;


@end
