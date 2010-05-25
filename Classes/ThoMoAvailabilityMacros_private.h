/*
 *  ThoMoAvailabilityMacros.h
 *  ThoMoNetworking
 *
 *  Created by Thorsten Karrer on 25.5.10.
 *  Copyright 2010 media computing group - RWTH Aachen University. All rights reserved.
 *
 */

// ---------------------------------------------------------------------------------------------------------------------
#pragma mark -
#pragma mark X-Platform Preprocessor Macros
// ---------------------------------------------------------------------------------------------------------------------
// Empty formal protocols to satisfy iPhone and pre-10.6 compiles

// code only compiled when targeting Mac OS X and not iPhone
#ifdef __MAC_OS_X_VERSION_MIN_REQUIRED
	// pre-10.6
	#if __MAC_OS_X_VERSION_MIN_REQUIRED < 1060 // note use of 1060 instead of __MAC_10_6
		@protocol NSNetServiceBrowserDelegate <NSObject> @end
		@protocol NSNetServiceDelegate <NSObject> @end
		@protocol NSStreamDelegate <NSObject> @end
	#else
		// code here can assume Snow Leopard or later
		#define THOMO_PTHREAD_NAMING_AVAILABLE
	#endif
#endif

// iPhone 
#ifdef __IPHONE_OS_VERSION_MIN_REQUIRED
	// pre-4.0
	#if __IPHONE_OS_VERSION_MIN_REQUIRED < 40000 // note use of 40000 instead of __IPHONE_4_0
		@protocol NSNetServiceBrowserDelegate <NSObject> @end
		@protocol NSNetServiceDelegate <NSObject> @end
		@protocol NSStreamDelegate <NSObject> @end
	#else
		// code here can assume iPhone OS 4.0 or later
	#endif
#endif

// =====================================================================================================================
