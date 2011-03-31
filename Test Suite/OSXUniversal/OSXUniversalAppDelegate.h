//
//  OSXUniversalAppDelegate.h
//  OSXUniversal
//
//  Created by Thorsten Karrer on 26.5.10.
//  Copyright 2010 media computing group - RWTH Aachen University. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ThoMoNetworking/ThoMoNetworking.h>

@interface OSXUniversalAppDelegate : NSObject <NSApplicationDelegate, ThoMoClientDelegateProtocol, ThoMoServerDelegateProtocol>
{
    NSWindow *window;
	
	ThoMoClientStub *client;
	ThoMoServerStub *server;
}

@property (assign) IBOutlet NSWindow *window;

@end
