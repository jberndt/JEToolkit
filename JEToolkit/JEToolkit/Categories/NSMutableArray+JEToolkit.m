//
//  NSMutableArray+JEToolkit.m
//  JEToolkit
//
//  Created by John Rommel Estropia on 2013/09/15.
//  Copyright (c) 2013 John Rommel Estropia. All rights reserved.
//

#import "NSMutableArray+JEToolkit.h"

@implementation NSMutableArray (JEToolkit)

#pragma mark - Public

- (void)shuffle {
    
    for (NSInteger idx = ((NSInteger)[self count] - 1); idx > 0; --idx) {
        
        [self
         exchangeObjectAtIndex:arc4random_uniform((u_int32_t)idx + 1)
         withObjectAtIndex:idx];
    }
}

@end
