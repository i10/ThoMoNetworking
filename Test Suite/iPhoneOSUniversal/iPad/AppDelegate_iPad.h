//
//  AppDelegate_iPad.h
//  iPhoneOSUniversal
//
//  Created by Thorsten Karrer on 26.5.10.
//  Copyright media computing group - RWTH Aachen University 2010. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ThoMoNetworking/ThoMoNetworking.h>

@interface AppDelegate_iPad : NSObject <UIApplicationDelegate, ThoMoClientDelegateProtocol, ThoMoServerDelegateProtocol>
{
    UIWindow *window;
	
	ThoMoClientStub *client;
	ThoMoServerStub *server;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;

@end

