//
//  ExampleServer.m
//  ThoMoNetworkingExample
//
//  Created by Thorsten Karrer on 17.3.10.
//  Copyright 2010 media computing group - RWTH Aachen University. All rights reserved.
//

#import "ExampleServer.h"


@implementation ExampleServer

// ---------------------------------------------------------------------------------------------------------------------
#pragma mark -
#pragma mark life cycle
// ---------------------------------------------------------------------------------------------------------------------

-(void)awakeFromNib;
{
	serverStub = [[ThoMoServerStub alloc] initWithProtocolIdentifier:@"exampleProtId"];
	[serverStub setDelegate:self];
	[serverStub start];
}

- (void) dealloc
{
	[serverStub stop];
	[serverStub release];
	[super dealloc];
}


// ---------------------------------------------------------------------------------------------------------------------
#pragma mark -
#pragma mark actions
// ---------------------------------------------------------------------------------------------------------------------

-(IBAction)send:(id)sender;
{
	[serverStub sendToAllClients:[inTextField stringValue]];
}


// ---------------------------------------------------------------------------------------------------------------------
#pragma mark -
#pragma mark ThoMoServerDelegateProtocol
// ---------------------------------------------------------------------------------------------------------------------

-(void)server:(ThoMoServerStub *)theServer didReceiveData:(id)theData fromClient:(NSString *)aClientIdString;
{
	[outTextField setStringValue:theData];
}

@end
