//
//  ExampleClient.m
//  ThoMoNetworkingExample
//
//  Created by Thorsten Karrer on 17.3.10.
//  Copyright 2010 media computing group - RWTH Aachen University. All rights reserved.
//

#import "ExampleClient.h"


@implementation ExampleClient

// ---------------------------------------------------------------------------------------------------------------------
#pragma mark -
#pragma mark life cycle
// ---------------------------------------------------------------------------------------------------------------------

-(void)awakeFromNib;
{
	clientStub = [[ThoMoClientStub alloc] initWithProtocolIdentifier:@"exampleProtId"];
	[clientStub setDelegate:self];
	[clientStub start];
}

- (void) dealloc
{
	[clientStub stop];
	[clientStub release];
	[super dealloc];
}


// ---------------------------------------------------------------------------------------------------------------------
#pragma mark -
#pragma mark actions
// ---------------------------------------------------------------------------------------------------------------------

-(IBAction)send:(id)sender;
{
	[clientStub sendToAllServers:[inTextField stringValue]];
}


// ---------------------------------------------------------------------------------------------------------------------
#pragma mark -
#pragma mark ThoMoClientDelegateProtocol
// ---------------------------------------------------------------------------------------------------------------------

-(void)client:(ThoMoClientStub *)theClient didReceiveData:(id)theData fromServer:(NSString *)aServerIdString;
{
	[outTextField setStringValue:theData];
}

@end
