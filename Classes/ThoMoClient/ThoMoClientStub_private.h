//
//  ClientStub.h
//  StringDisplayServer
//
//  Created by Thorsten Karrer on 29.6.09.
//  Copyright 2009 media computing group - RWTH Aachen University. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ThoMoClientDelegateProtocol.h"
#import "ThoMoNetworkStub.h"

#ifdef MAC_OS_X_VERSION_10_6
@interface ThoMoClientStub : ThoMoNetworkStub <NSNetServiceBrowserDelegate>
#else
@interface ThoMoClientStub : ThoMoNetworkStub
#endif
{	
	NSNetServiceBrowser *browser;
	
	NSMutableArray		*offeredNetServices;	// offered
	NSMutableDictionary *connectedNetServices;	// connected
	
	id<ThoMoClientDelegateProtocol> delegate; 	
}

@property (assign) id<ThoMoClientDelegateProtocol> delegate; 
@property (retain) NSMutableArray *offeredNetServices;
@property (retain) NSMutableDictionary *connectedNetServices;


-(NSArray *)connectedServers;

-(void)sendData:(id<NSCoding>)theData toServer:(NSString *)theServerIdString DEPRECATED_ATTRIBUTE;
-(void)sendBytes:(NSData *)theBytes toServer:(NSString *)theServerIdString;

-(void)send:(id<NSCoding>)anObject toServer:(NSString *)theServerIdString;
-(void)sendToAllServers:(id<NSCoding>)anObject;

@end
