#ThoMoNetworking
##Simple Networking for Your Cocoa and iPhone Apps - Out of the Box

---

Writing network code for Cocoa or iPhone/iPad apps isn't terribly difficult - but it's not very exciting either.

Want to exchange objects between two processes, on the same machine or remotely, without having to dig down into the C API of Core Foundation? Then *ThoMoNetworking* is for you.

ThoMoNetworking gives you client and server classes that connect automatically via Bonjour - nothing to do on your side. Pass an object to the server, and it will pop out at the client, and vice versa. If you want, have your object distributed to all connected clients in one go. It couldn't be much simpler.

'Nuff said - let's have a look at the code:

###Setting up a ThoMoServerStub
	-(void)setupServer
	{
		// Assume myServer exists
   		myServer = [[ThoMoServerStub alloc] initWithProtocolIdentifier:@"helloThoMo"];
 	
		[myServer start];
	}

	// Send a string to all our clients
	-(void)sendString:(NSString *)aString
	{
		[myServer sendToAllClients:aString];
	}


###Setting up a ThoMoClientStub
	-(void)setupClient
	{
		// Assume myClient exists
		myClient = [[ThoMoClientStub alloc] initWithProtocolIdentifier:@"helloThoMo"];
		[myClient setDelegate:self];
		[myClient start];
	}

	// This is our delegate method where we receive data from our server
	-(void)client:(ThoMoClientStub *)theClient didReceiveData:(id)theData fromServer:(NSString *)aServerIdString;
	{
		NSLog(@"%@ sent me a message: %@", aServerIdString, theData);
	}


Yep, that's it - as long as your client and server use the same protocol identifier string, they'll find each other automatically via Bonjour and build up a network connection.

Of course, instead of NSStrings you can also send around objects of any of your classes that implement the NSCoding protocol. Most Foundation classes do so anyway, and it's pretty easy to do for your own classes.


##Perks

But wait, there's more that you get for free with ThoMoNetworking without having to worry about it ever again:
- Sockets - we use them so you don't have to
- Bonjour - your servers and clients will find each other on the local network automatically, no need to mess with IP addresses and port numbers
- Handling dropped connections - ThoMoNetworking will immediately reconnect or notify you if the other side is no longer available on the network
- Asynchronous network calls - we handle all the threading for you so that your main thread does not have to wait for the network
- All your base are belong to us - works out-of-the-box on OS X, iPhone, and iPad


##Limitations

There is no such thing as a free lunch. Well, although ThoMoNetworking kind of is, there are a couple things that it's not designed for. This is the price you pay for the two-lines-of-code-and-I-am-done ease of use.
- If you need your objects on one side of the connection to react to methods sent to them on the other side we cannot help you. ThoMoNetworking actually sends an independent copy of your object over the network. Apple provides Distributed Objects which you might want to use in that case (but as of this writing, they don't seem very reliable).
- If you need to control threading yourself, specify ports and IP addresses directly, or handle your delegate callbacks on another run loop than the main one, then AsyncSocket may be just right for you (but it's more complex to set up, of course - no Bonjour wrapping, for example).
- If you want to run multiple instances of your app on the same local network but do not want every client to make out with every server, use different protocol identifier strings for different connection groups. Otherwise ThoMoNetworking will form a maximally connected bipartite graph between all clients and servers.


##Known Problems

Although for most people ThoMoNetworking works like a charm, we also occasionally receive reports of problems an bugs. The ones that aren't fixed yet are listed below:
- Some people have problems receiving network messages on the iPhone while their app is in the background (even with the VoIP-flag being set on the I/O-streams).
- ThoMoNetworking does not support older Power-PC based Macs.
We are working on these issues and appreciate any feedback that helps us to track down these problems.


##License

We put ThoMoNetworking under an MIT-like license so you can use it in almost any way you want. The full license text is included in the repository.


##Who's behind it?

Us, that's Tho and Mo. If you have any problems using ThoMoNetworking or experience any crashes, please let us know!
Big thanks also go to Chat and Leo who helped a great deal when building the iPhone version of the framework!
