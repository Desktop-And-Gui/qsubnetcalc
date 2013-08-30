/**
 * ComputeSubnetData.h -- Class for the IP Address Subnetting Calculations
 *
 * Copyright (c) 2002 Thomas Woehlke
 * Licensed under the GNU GPL. For full terms see the file COPYRIGHT.
 *
 * http://qsubnetcalc.sourceforge.net
 *
 * $Id: ComputeSubnetData.h,v 1.1.1.1 2002/11/26 21:01:35 rubycon Exp $
 */

#ifndef __COMPUTESUBNETDATA__
#define __COMPUTESUBNETDATA__

#include "IpNumber.h"
#include "TWInteger.h"
#include <qstring.h>

class ComputeSubnetData:TWInteger
{
	private:
		IpNumber hostAddress;
		IpNumber netMask;
		IpNumber networkAddress;
		IpNumber broadcastAddress;
		IpNumber hostId;
		QString defaultClassType;
		int netAddressSize;
		int hostAddressSize;
		bool computed;
	public:	
		ComputeSubnetData();
		void setSubnetMask(int in0,int in1,int in2,int in3);		
		QString getSubnetMask();	
		QString getSubnetMaskBits();
		void setHostAddress(int in0,int in1,int in2,int in3);		
		QString getHostAddress();
		QString getHostAddressBits();
		QString getNetworkAddress();
		QString getNetworkAddressBits();
		QString getBroadcastAddress();
		QString getBroadcastAddressBits();
		QString getDefaultClassType();
		QString getNetAddressSize();
		QString getHostAddressSize();
		QString getHostId();	
		QString getHostIdBits();
	
	private:
		void compute();
		void computeNetworkAddress();
		void computeBroadcastAddress();
		void computeDefaultClassType();
		int bitCounter(int bits);
		void computeHostAddressSize();
		void computeNetAddressSize();			
		void computeHostId();		
};

#endif
