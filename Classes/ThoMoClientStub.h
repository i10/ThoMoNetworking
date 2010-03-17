/*
 *  ThoMoClientStub.h
 *  ThoMoNetworkingFramework
 *
 *  Created by Thorsten Karrer on 28.9.09.
 *  Copyright 2009 media computing group - RWTH Aachen University. All rights reserved.
 *
 */
#import "ThoMoClientDelegateProtocol.h"

#ifdef MAC_OS_X_VERSION_10_6
@interface ThoMoClientStub : NSObject <NSNetServiceBrowserDelegate>
#else
@interface ThoMoClientStub : NSObject
#endif
{	
}

/// Delegate accessor
/**
 Accessor for the client stubs delegate. Must be compliant to ThoMoClientDelegateProtocol.
 */
@property (assign) id<ThoMoClientDelegateProtocol> delegate; 


/// Designated initializer
/**
 Initializes the Stub with a protocol identifier string. When started, this client stub will automatically connect to all server stubs (ThoMoServerStub) on the local network that use the same protocol identifier.
 
 \param[in] theProtocolIdentifier A user-definable string of maximum 14 characters length. Determines which server stubs this client stub connects to.
 
 \throws ThoMoInvalidArgumentException if theProtocolIdentifier exceeds 14 characters in length.
 */
-(id)initWithProtocolIdentifier:(NSString *)theProtocolIdentifier;



/// Starts the client stub
/**
 Starts the client stub on a background thread. The stub will auto-connect to each server with the same protocol identifier. May be called only once during the lifetime of the client stub.
 
 \throws ThoMoStubAlreadyRunningException if the client stub had already been started before.
 */
-(void) start;



/// Stops the client stub
/**
 Stops the client stub and cancels the associated network thread. This will close all open connections. May be called only once during the lifetime of the client stub.
 */
-(void) stop;



/// Returns an array of the connected servers
/**
 Returns an array of id-strings for all servers that the client stub is currently connected to. You can use these id-strings to send objects to any of the servers by calling -send:toServer:.
 
 \returns an array of id-strings for all connected servers.
 */
-(NSArray *)connectedServers;



/// Sends an object to a connected server
/**
 Sends anObject to the server designated by theServerIdString. 
 \note Note that actually a copy of the object is being created on the other side of the connection. Altering the internal state of the object on either side of the connection is not reflected on the other side!
 
 \param[in] anObject An NSCoding compliant object that will be copied and re-created at the server stub.
 \param[in] theServerIdString A string the server to send the object to. Must be taken from the array returned by connectedServers.
 
 \throws ThoMoInvalidArgumentException if theServerIdString does not designate a server the client stub is connected to.
 */
-(void)send:(id<NSCoding>)anObject toServer:(NSString *)theServerIdString;



/// Sends an object to all connected servers
/**
 Sends anObject to all servers in the array returned by connectedServers.
 \note Note that actually a copy of the object is being created on the other sides of the connections. Altering the internal state of the object on either side of the connections is not reflected on the other sides!
 
 \param[in] anObject An NSCoding compliant object that will be copied and re-created at the server stubs.
 */
-(void)sendToAllServers:(id<NSCoding>)anObject;



-(void)sendData:(id<NSCoding>)theData toServer:(NSString *)theServerIdString DEPRECATED_ATTRIBUTE;

@end
