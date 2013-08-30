/**
 * ComputeSubnetData.cpp -- implements Class ComputeSubnetData
 *
 * Copyright (c) 2002 Thomas Woehlke
 * Licensed under the GNU GPL. For full terms see the file COPYRIGHT.
 *
 * http://qsubnetcalc.sourceforge.net
 *
 * $Id: ComputeSubnetData.cpp,v 1.1.1.1 2002/11/26 21:01:36 rubycon Exp $
 */


#include "ComputeSubnetData.h"
#include "IpNumber.h"
#include "TWInteger.h"
#include <QString>
	
ComputeSubnetData::ComputeSubnetData()
{
	hostAddress.set(10,16,242,18);
	netMask.set(255,255,240,0);
	computed=false;
}

void ComputeSubnetData::setSubnetMask(int in0,int in1,int in2,int in3)
{
		netMask.set(in0,in1,in2,in3);
		computed=false;
}

QString ComputeSubnetData::getSubnetMask()
{
	return netMask.toString();
}

QString ComputeSubnetData::getSubnetMaskBits()
{
	return netMask.toBitString();
}

void ComputeSubnetData::setHostAddress(int in0,int in1,int in2,int in3)
{
		hostAddress.set(in0,in1,in2,in3);
		computed=false;
}

QString ComputeSubnetData::getHostAddress()
{
	return hostAddress.toString();
}

QString ComputeSubnetData::getHostAddressBits()
{
	return hostAddress.toBitString();
}

void ComputeSubnetData::compute()
{
	computed=true;
	computeNetworkAddress();
	computeBroadcastAddress();
	computeDefaultClassType();		
	computeHostId();
	computeNetAddressSize();
	computeHostAddressSize();
}

void ComputeSubnetData::computeNetworkAddress()
{
	networkAddress.set(hostAddress.get(0),hostAddress.get(1),
	                  hostAddress.get(2),hostAddress.get(3));
	networkAddress._and(netMask);
}

QString ComputeSubnetData::getNetworkAddress()
{
	if (!computed) { compute(); }
	return networkAddress.toString();
}

QString ComputeSubnetData::getNetworkAddressBits()
{
	if (!computed) { compute(); }
	return networkAddress.toBitString();
}

void ComputeSubnetData::computeBroadcastAddress()
{
	broadcastAddress.set(netMask.get(0),netMask.get(1),
											netMask.get(2),netMask.get(3));
	broadcastAddress._not();
	broadcastAddress._or(hostAddress);
}

QString ComputeSubnetData::getBroadcastAddress()
{
	if (!computed) { compute(); }
	return broadcastAddress.toString();
}

QString ComputeSubnetData::getBroadcastAddressBits()
{
	if (!computed) { compute(); }
	return broadcastAddress.toBitString();
}

void ComputeSubnetData::computeDefaultClassType()
{
	defaultClassType="";
	if (netMask.get(0)==255)
	{
		defaultClassType.append("A");
		if (netMask.get(1)==255)
		{
			defaultClassType.replace(0,1,"B");
			if (netMask.get(2)==255)
			{
				defaultClassType.replace(0,1,"C");
			}
		}
	}
}

QString ComputeSubnetData::getDefaultClassType()
{
	if (!computed) { compute(); }
	return defaultClassType;
}

int ComputeSubnetData::bitCounter(int bits)
{
	int counter=128;
	int retValue=0;
	bits %= 256;
	while (counter>=1)
	{
		if ((bits/counter)==1)
		{
			retValue++;
			bits-=counter;
			counter/=2;
		}
		else
		{
			counter=0;
		}
	}
	return retValue;
}

void ComputeSubnetData::computeNetAddressSize()
{
	if (netMask.get(0)==255)
	{
		if (netMask.get(1)==255)
		{
			if (netMask.get(2)==255)
			{
				netAddressSize=24+bitCounter(netMask.get(3));;
			}
			else
			{
				netAddressSize=16+bitCounter(netMask.get(2));
			} 
		} 
		else
		{ 
			netAddressSize=8+bitCounter(netMask.get(1));
		}
	}
	else 
	{	
		netAddressSize=bitCounter(netMask.get(0));
	}
}

QString ComputeSubnetData::getNetAddressSize()
{
	if (!computed) { compute(); }
	return (TWInteger::int2QString(netAddressSize));
}

void ComputeSubnetData::computeHostAddressSize()
{
	hostAddressSize=32-netAddressSize;
}

QString ComputeSubnetData::getHostAddressSize()
{
	if (!computed) { compute(); }
	return (TWInteger::int2QString(hostAddressSize));
}

void ComputeSubnetData::computeHostId()
{
	hostId.set(netMask.get(0),netMask.get(1),netMask.get(2),netMask.get(3));
	hostId._not();
	hostId._and(hostAddress);
}

QString ComputeSubnetData::getHostId()
{
	if (!computed) { compute(); }
	return hostId.toString();
}

QString ComputeSubnetData::getHostIdBits()
{
	if (!computed) { compute(); }
	return hostId.toBitString();
}
