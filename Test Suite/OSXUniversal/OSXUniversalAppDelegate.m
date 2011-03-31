//
//  OSXUniversalAppDelegate.m
//  OSXUniversal
//
//  Created by Thorsten Karrer on 26.5.10.
//  Copyright 2010 media computing group - RWTH Aachen University. All rights reserved.
//

#import "OSXUniversalAppDelegate.h"

@implementation OSXUniversalAppDelegate

@synthesize window;

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
	// Insert code here to initialize your application 
	server = [[ThoMoServerStub alloc] initWithProtocolIdentifier:@"test01"];
	client = [[ThoMoClientStub alloc] initWithProtocolIdentifier:@"test02"];
}

@end
