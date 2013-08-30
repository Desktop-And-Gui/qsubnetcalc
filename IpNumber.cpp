/**
 * IpNumber.cpp -- Implements Class IpNumber
 *
 * Copyright (c) 2002 Thomas Woehlke
 * Licensed under the GNU GPL. For full terms see the file COPYRIGHT.
 *
 * http://qsubnetcalc.sourceforge.net
 *
 * $Id: IpNumber.cpp,v 1.1.1.1 2002/11/26 21:01:35 rubycon Exp $
 */
 
#include "IpNumber.h"

#include <qregexp.h>
#include <qvalidator.h>

IpNumber::IpNumber()
{
	a[0]=0;
	a[1]=0;
	a[2]=0;
	a[3]=0;
}

IpNumber::IpNumber(int in0,int in1,int in2,int in3)
{
	a[0]=in0;
	a[1]=in1;
	a[2]=in2;
	a[3]=in3;
}

IpNumber::~IpNumber()
{}

int IpNumber::get(int position)
{
	switch(position)
	{
		case 0: 
		case 1: 
		case 2: 
		case 3: return a[position];
		default: return -1;
	}
}

void IpNumber::set(int in0,int in1,int in2,int in3)
{
	a[0]=in0;
	a[1]=in1;
	a[2]=in2;
	a[3]=in3;
}

void IpNumber::_and(IpNumber i)
{
	for (int j=0;j<4;j++)
	{
		a[j] = a[j] & i.get(j);
	}
}

void IpNumber::_or(IpNumber i)
{
	for (int j=0;j<4;j++)
	{
		a[j] = a[j] | i.get(j);
	}
}

void IpNumber::_not()
{
	for (int j=0;j<4;j++)
	{
		a[j] = a[j] ^ 255;
	}
}

void IpNumber::_xor(IpNumber i)
{
	for (int j=0;j<4;j++)
	{
		a[j] = a[j] ^ i.get(j);
	}
}

QString IpNumber::toString()
{
	 QString retValue("");
	 for (int j=0;j<4;j++)
	 {		 
	 		retValue.append(TWInteger::int2QString(a[j])); 
			if (j<3) 
			{ 
				retValue.append("."); 
			}
	 }
	 return retValue;
}

QString IpNumber::toBitString()
{
	 QString retValue("");
	 for (int j=0;j<4;j++)
	 {		 
	 		retValue.append(byteToBitString(a[j])); 
			if (j<3) 
			{ 
				retValue.append("."); 
			}
	 }
	 return retValue;
}

QString IpNumber::byteToBitString(int x)
{
	QString retValue("");
	x %=256;
	int counter=128;
	while (counter>=1)
	{
		if ((x / counter)==1)
		{
			x-=counter;
			retValue.append("1");
		}
		else
		{
			retValue.append("0");
		} 
		if (counter == 1)
		{
			counter = 0;
		}
		else
		{
			counter /= 2;
		}
	}
	return retValue; 
}

bool IpNumber::set(QString ipnumber)
{
	QRegExp ipRegExp("^([0-9]{1,3})\\.([0-9]{1,3})\\.([0-9]{1,3})\\.([0-9]{1,3})$");
	int pos = ipRegExp.indexIn(ipnumber);
	bool retValue,flag;
	QString actual;
	if (pos > -1)
	{
		for (int j=0; j<4; j++)
		{
			actual=ipRegExp.cap(j+1);
			a[j]=(actual.toInt(&flag,10)) % 256;
			retValue &= flag;
		}
	}
	else
	{
		retValue=false;
	}
	return retValue;
}	
