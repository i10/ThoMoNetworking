//
//  ServerStubConnection.h
//  StringDisplayServer
//
//  Created by Thorsten Karrer on 30.6.09.
//  Copyright 2009 media computing group - RWTH Aachen University. All rights reserved.
//

#import "ThoMoTCPConnectionDelegateProtocol.h"

typedef enum ServerStubSubPackets {
	kServerStubSubPacketHeader,
	kServerStubSubPacketData,
	kServerStubSubPacketCount
} ServerStubSubPacket;

@class ThoMoServerStub;

@interface ThoMoTCPConnection : NSObject <NSStreamDelegate>
{
	id <ThoMoTCPConnectionDelegateProtocol>		delegate;
	
	NSInputStream	*inStream;
	NSOutputStream	*outStream;
	
	BOOL			inReady;
	BOOL			outReady;
	
	BOOL			streamsCanOpen;
	
	BOOL			openCallbackSent;
	
	// receiving
	ServerStubSubPacket	nextExpectedSubpacket;
	uint32_t		bytesMissingForNextSubpacket;
	uint8_t			*dataBuffer;
	uint8_t			*dataBufferCursor;
	
	//sending
	NSMutableArray	*sendObjectsQueue;
	NSMutableData	*currentSendObject;
	uint32_t			bytesRemainingToSend;
	uint8_t			*sendBuffer;
	uint8_t			*sendBufferCursor;
	BOOL			outStreamHasSpaceAvailableEventIgnored;
	
	//keepalive
	NSTimer			*keepaliveSendTimer;	
	
	// reentrancy tracking
	BOOL threadIsPresentInMethod;
}

@property (assign) id <ThoMoTCPConnectionDelegateProtocol>		delegate;

-(id)initWithDelegate:(id <ThoMoTCPConnectionDelegateProtocol>)theDelegate inputStream:(NSInputStream *)theInStream outputStream:(NSOutputStream *)theOutStream;

-(void)open;
-(void)close;

-(void)setupKeepalive;
-(void)teardownKeepalive;

-(void)enqueueNextSendObject:(NSData *)theData;

@end
