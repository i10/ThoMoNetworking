//
//  main.m
//  iPhoneOSUniversal
//
//  Created by Thorsten Karrer on 26.5.10.
//  Copyright media computing group - RWTH Aachen University 2010. All rights reserved.
//

#import <UIKit/UIKit.h>

int main(int argc, char *argv[]) {
    
    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
    int retVal = UIApplicationMain(argc, argv, nil, nil);
    [pool release];
    return retVal;
}
