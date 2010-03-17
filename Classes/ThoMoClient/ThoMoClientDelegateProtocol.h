/*
 *  ThoMoClientDelegateProtocol.h
 *  PeaceTracker
 *
 *  Created by Thorsten Karrer on 6/8/09.
 *  Copyright 2009 media computing group - RWTH Aachen University. All rights reserved.
 *
 */

@class ThoMoClientStub;



@protocol ThoMoClientDelegateProtocol <NSObject>

@optional

/// Connection notification (optional)
- (void)client:(ThoMoClientStub *)theClient didConnectToServer:(NSString *)aServerIdString;


/// Disconnection notification (optional)
- (void)client:(ThoMoClientStub *)theClient didDisconnectFromServer:(NSString *)aServerIdString errorMessage:(NSString *)errorMessage;


/// Bonjour problem notification (optional)
- (void)netServiceProblemEncountered:(NSString *)errorMessage onClient:(ThoMoClientStub *)theClient;


/// Client shutdown notification (optional)
- (void)clientDidShutDown:(ThoMoClientStub *)theClient;



@required

/// Data received notification (required)
/**
 Sent to its delegate by the client stub on the main thread whenever it received data from a server.
 
 \param[in] theClient The client stub that received the data.
 \param[in] theData The object that was bein received.
 \param[in] aServerIdString A string designating the server that sent the data.
 */
-(void)client:(ThoMoClientStub *)theClient didReceiveData:(id)theData fromServer:(NSString *)aServerIdString;

@end
