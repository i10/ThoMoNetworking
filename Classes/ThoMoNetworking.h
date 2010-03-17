/*
 *  ThoMoNetworking.h
 *  ThoMoNetworkingFramework
 *
 *  Created by Thorsten Karrer on 16.3.10.
 *  Copyright 2010 media computing group - RWTH Aachen University. All rights reserved.
 *
 */

#import <ThoMoNetworking/ThoMoClientStub.h>
#import <ThoMoNetworking/ThoMoServerStub.h>
#import <ThoMoNetworking/ThoMoClientDelegateProtocol.h>
#import <ThoMoNetworking/ThoMoServerDelegateProtocol.h>

/// Debugging pList key.
/**
 If a string is set for this key in the current defaults domain the string will be prepended to the protocol id string.
 This can be handy when a fully connected bipartite graph is not desirable, e.g., for debugging purposes.
 
 \note Note that the prepended string plus a delimiter ('-') both count towards the length limit for protocol identifier strings of 14 characters!
 */
extern  NSString *const kThoMoNetworkPrefScopeSpecifierKey;