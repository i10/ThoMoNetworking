//
//  ThoMoNetworkStub.h
//  StringDisplayServer
//
//  Created by Thorsten Karrer on 2.7.09.
//  Copyright 2009 media computing group - RWTH Aachen University. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "ThoMoTCPConnectionDelegateProtocol.h"


/// Mixin class that encapsulates the network worker thread and the handling of ThoMoTCPConnections.
/**
	You should never instantiate a ThoMoNetworkStub directly. Instead, you should use its subclasses ThoMoServerStub and ThoMoClientStub.
	Note: the implementation of this class is Bonjour-agnostic and should remain so.
 */

#ifdef MAC_OS_X_VERSION_10_6
@interface ThoMoNetworkStub : NSObject <ThoMoTCPConnectionDelegateProtocol, NSNetServiceDelegate>
#else
@interface ThoMoNetworkStub : NSObject <ThoMoTCPConnectionDelegateProtocol>
#endif
{
	NSMutableDictionary	*connections;
	NSString			*protocolIdentifier;
	NSThread			*networkThread;
}

-(id)initWithProtocolIdentifier:(NSString *)theProtocolIdentifier;

-(void) start;
-(void) stop;

-(NSArray *)activeConnections;

-(void)send:(id<NSCoding>)theData toConnection:(NSString *)theConnectionIdString;
-(void)sendByteData:(NSData *)theData toConnection:(NSString *)theConnectionIdString;






// protected
-(BOOL)setup;
-(void)teardown;
-(NSString *)keyStringFromAddress:(NSData *)addr;
/// Returns the key for theConnection from the connections dictionary.
-(NSString *)keyForConnection:(ThoMoTCPConnection *)theConnection;
-(void) openNewConnection:(NSString *)theConnectionKey inputStream:(NSInputStream *)istr outputStream:(NSOutputStream *)ostr;



@end

NSString *const kThoMoNetworkInfoKeyUserMessage;
NSString *const kThoMoNetworkInfoKeyData;
NSString *const kThoMoNetworkInfoKeyRemoteConnectionIdString;
NSString *const kThoMoNetworkInfoKeyLocalNetworkStub;
