//
//  ExampleClient.h
//  ThoMoNetworkingExample
//
//  Created by Thorsten Karrer on 17.3.10.
//  Copyright 2010 media computing group - RWTH Aachen University. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ThoMoNetworking/ThoMoNetworking.h>

@interface ExampleClient : NSObject <ThoMoClientDelegateProtocol> 
{
	ThoMoClientStub			*clientStub;
	
	IBOutlet NSTextField	*outTextField;
	IBOutlet NSTextField	*inTextField;
}

-(IBAction)send:(id)sender;

@end
