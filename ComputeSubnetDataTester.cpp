/**
 * ComputeSubnetDataTester.cpp  -- Small Program for testing Class ComputeSubnetData
 *
 * Copyright (c) 2002 Thomas Woehlke
 * Licensed under the GNU GPL. For full terms see the file COPYRIGHT.
 *
 * http://qsubnetcalc.sourceforge.net
 *
 * $Id: ComputeSubnetDataTester.cpp,v 1.1.1.1 2002/11/26 21:01:35 rubycon Exp $
 */
 
#include "ComputeSubnetData.h"
#include <iostream>

using namespace std;
	
void out(const QString explanation,const QString bits,const  QString ip)
{
	cout << explanation << ": " << bits << " " << ip << endl;
}

void endl()
{
	cout << endl;
}

void fullOut(ComputeSubnetData calc)
	{
		endl();
		out("HostAddress     ",calc.getHostAddressBits(),calc.getHostAddress());
		out("NetMask        ",calc.getSubnetMaskBits(),calc.getSubnetMask());
		out("HostID         ",calc.getHostIdBits(),calc.getHostId());
		out("NetAddress      ",calc.getNetworkAddressBits(),calc.getNetworkAddress());
		out("BroadcastAddress",calc.getBroadcastAddressBits(),calc.getBroadcastAddress());		
		cout << "ClassType :      " << calc.getDefaultClassType() << endl;
		cout << "NetAddressSize   :" << calc.getNetAddressSize() << endl;
		cout << "HostAddressSize  :" << calc.getHostAddressSize() << endl;
		endl();
	}

int main (int,char*[])
{
	ComputeSubnetData calc;
		
	fullOut(calc);
	calc.setHostAddress(192,168,1,129);
	calc.setSubnetMask(255,255,255,128);
	fullOut(calc);
	IpNumber a;
	a.set("192.168.1.129");
	calc.setHostAddress(a.get(0),a.get(1),a.get(2),a.get(3));
	a.set("255.255.255.128");
	calc.setSubnetMask(a.get(0),a.get(1),a.get(2),a.get(3));	
	fullOut(calc);		
}
