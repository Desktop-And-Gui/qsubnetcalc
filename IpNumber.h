/**
 * IpNumber.h -- Class for an IP Address Object
 *
 * Copyright (c) 2002 Thomas Woehlke
 * Licensed under the GNU GPL. For full terms see the file COPYRIGHT.
 *
 * http://qsubnetcalc.sourceforge.net
 *
 * $Id: IpNumber.h,v 1.1.1.1 2002/11/26 21:01:35 rubycon Exp $
 */

#ifndef __IPNUMBER_H__
#define __IPNUMBER_H__

#include "TWInteger.h"
#include <QString>

class IpNumber:TWInteger
{
	private: 
		int a[4];
		
	public:
		IpNumber();
		IpNumber(int in0,int in1,int in2,int in3);
		~IpNumber();
		void set(int in0,int in1,int in2,int in3);
		bool set(QString ipnumber); 
		int get(int position);
		void _and(IpNumber i);
		void _or(IpNumber i);
		void _not();
		void _xor(IpNumber i);
		QString toString();
		QString toBitString();
	private:
		QString byteToBitString(int x);
		QString int2QString(int i);
		bool isIp(QString ipnumber);
};

#endif
