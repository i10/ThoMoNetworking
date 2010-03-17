//
//  ServerStub.h
//  StringDisplayServer
//
//  Created by Thorsten Karrer on 29.6.09.
//  Copyright 2009 media computing group - RWTH Aachen University. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ThoMoServerDelegateProtocol.h"
#import "ThoMoNetworkStub.h"

@interface ThoMoServerStub : ThoMoNetworkStub {
	
	id<ThoMoServerDelegateProtocol> delegate; 
	
	uint16_t			listenPort;
	CFSocketRef			listenSocket;
	NSNetService		*netService;
	
}

@property (assign) id<ThoMoServerDelegateProtocol> delegate;

-(NSArray *)connectedClients;

-(void)sendData:(id<NSCoding>)theData toClient:(NSString *)theClientIdString DEPRECATED_ATTRIBUTE;
-(void)sendBytes:(NSData *)theBytes toClient:(NSString *)theClientIdString;

-(void)send:(id<NSCoding>)anObject toClient:(NSString *)theClientIdString;
-(void)sendToAllClients:(id<NSCoding>)theData;

@end