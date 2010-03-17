/*
 *  ThoMoTCPConnectionDelegateProtocol.h
 *  StringDisplayServer
 *
 *  Created by Thorsten Karrer on 1.7.09.
 *  Copyright 2009 media computing group - RWTH Aachen University. All rights reserved.
 *
 */

@class ThoMoTCPConnection;

@protocol ThoMoTCPConnectionDelegateProtocol

-(void)didReceiveData:(NSData *)theData onConnection:(ThoMoTCPConnection *)theConnection;

-(void)streamsDidOpenOnConnection:(ThoMoTCPConnection *)theConnection;

-(void)streamEndEncountered:(NSStream *)theStream onConnection:(ThoMoTCPConnection *)theConnection;
-(void)streamErrorEncountered:(NSStream *)theStream onConnection:(ThoMoTCPConnection *)theConnection;

@end
