/*
 *  ThoMoServerStub.h
 *  ThoMoNetworkingFramework
 *
 *  Created by Thorsten Karrer on 28.9.09.
 *  Copyright 2009 media computing group - RWTH Aachen University. All rights reserved.
 *
 */

#import "ThoMoServerDelegateProtocol.h"

@interface ThoMoServerStub : NSObject
{
}

/// Delegate accessor
/**
 Accessor for the server stubs delegate. Must be compliant to ThoMoServerDelegateProtocol.
 */
@property (assign) id<ThoMoServerDelegateProtocol> delegate;



/// Designated initializer
/**
 Initializes the Stub with a protocol identifier string. When started, this server stub will automatically connect to all client stubs (ThoMoClientStub) on the local network that use the same protocol identifier. The server stub will listen on a random free port for client connections.
 
 \param[in] theProtocolIdentifier A user-definable string of maximum 14 characters length. Determines which client stubs this server stub connects to.
 
 \throws ThoMoInvalidArgumentException if theProtocolIdentifier exceeds 14 characters in length.
 */
-(id)initWithProtocolIdentifier:(NSString *)theProtocolIdentifier;



/// Starts the server stub
/**
 Starts the server stub on a background thread. The stub will auto-connect to each client with the same protocol identifier. May be called only once during the lifetime of the stub.
 
 \throws ThoMoStubAlreadyRunningException if the server stub had already been started before.
 */
-(void) start;



/// Stops the server stub
/**
 Stops the server stub and cancels the associated network thread. This will close all open connections. May be called only once during the lifetime of the stub.
 */
-(void) stop;



/// Returns an array of the connected clients
/**
 Returns an array of id-strings for all clients that are currently connected to the server stub. You can use these id-strings to send objects to any of the clients by calling -send:toClient:.
 
 \returns an array of id-strings for all connected clients.
 */
-(NSArray *)connectedClients;



/// Sends an object to a connected client
/**
 Sends anObject to the client designated by theClientIdString. 
 \note Note that actually a copy of the object is being created on the other side of the connection. Altering the internal state of the object on either side of the connection is not reflected on the other side!
 
 \param[in] anObject An NSCoding compliant object that will be copied and re-created at the client stub.
 \param[in] theServerIdString A string the client to send the object to. Must be taken from the array returned by connectedClients.
 
 \throws ThoMoInvalidArgumentException if theServerIdString does not designate a client the stub is connected to.
 */
-(void)send:(id<NSCoding>)anObject toClient:(NSString *)theClientIdString;



/// Sends an object to all connected clients
/**
 Sends anObject to all clients in the array returned by connectedClients.
 \note Note that actually a copy of the object is being created on the other sides of the connections. Altering the internal state of the object on either side of the connections is not reflected on the other sides!
 
 \param[in] anObject An NSCoding compliant object that will be copied and re-created at the client stubs.
 */
-(void)sendToAllClients:(id<NSCoding>)theData;



-(void)sendData:(id<NSCoding>)theData toClient:(NSString *)theClientIdString DEPRECATED_ATTRIBUTE;
@end