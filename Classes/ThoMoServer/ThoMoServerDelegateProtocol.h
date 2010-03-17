/*
 *  ThoMoServerDelegateProtocol.h
 *  PeaceTracker
 *
 *  Created by Thorsten Karrer on 6/8/09.
 *  Copyright 2009 media computing group - RWTH Aachen University. All rights reserved.
 *
 */

@class ThoMoServerStub;



@protocol ThoMoServerDelegateProtocol <NSObject>

@optional

/// Connection notification (optional)
- (void)server:(ThoMoServerStub *)theServer acceptedConnectionFromClient:(NSString *)aClientIdString;


/// Disconnection notification (optional)
- (void)server:(ThoMoServerStub *)theServer lostConnectionToClient:(NSString *)aClientIdString errorMessage:(NSString *)errorMessage;


/// Bonjour problem notification (optional)
- (void)netServiceProblemEncountered:(NSString *)errorMessage onServer:(ThoMoServerStub *)theServer;


/// Client shutdown notification (optional)
- (void)serverDidShutDown:(ThoMoServerStub *)theServer;



@required

/// Data received notification (required)
/**
 Sent to its delegate by the server stub on the main thread whenever it received data from a client.
 
 \param[in] theServer The server stub that received the data.
 \param[in] theData The object that was bein received.
 \param[in] aClientIdString A string designating the client that sent the data.
 */
-(void)server:(ThoMoServerStub *)theServer didReceiveData:(id)theData fromClient:(NSString *)aClientIdString;

@end
