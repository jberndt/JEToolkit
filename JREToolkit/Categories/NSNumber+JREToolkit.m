//
//  NSNumber+JREToolkit.m
//  JREToolkit
//
//  Created by John Rommel Estropia on 2013/09/15.
//  Copyright (c) 2013 John Rommel Estropia. All rights reserved.
//

#import "NSNumber+JREToolkit.h"

@implementation NSNumber (JREToolkit)

#pragma mark - private

+ (NSNumberFormatter *)decimalFormatter
{
	static NSNumberFormatter *formatter;
	static dispatch_once_t onceToken;
	dispatch_once(&onceToken, ^{
		
		formatter = [[NSNumberFormatter alloc] init];
		[formatter setNumberStyle:NSNumberFormatterDecimalStyle];
		
	});
	return formatter;
}


#pragma mark - public

#pragma mark Conversion

+ (NSNumber *)numberFromValue:(id)valueOrNil
{
    if (valueOrNil)
    {
        if ([valueOrNil isKindOfClass:self])
        {
            return valueOrNil;
        }
        if ([valueOrNil isKindOfClass:[NSString class]])
        {
            return ([[self decimalFormatter] numberFromString:valueOrNil]
                    ?: @([(NSString *)valueOrNil doubleValue]));
        }
        if ([valueOrNil isKindOfClass:[NSDate class]])
        {
            return @([(NSDate *)valueOrNil timeIntervalSince1970]);
        }
    }
    return nil;
}

#pragma mark Displaying to user

- (NSString *)displayString
{
    return [[NSNumber decimalFormatter] stringFromNumber:self];
}


@end
