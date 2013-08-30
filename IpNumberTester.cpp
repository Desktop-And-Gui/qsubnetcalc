/**
 * IpNumberTester.cpp -- Program for Testing Class IpNumber
 *
 * Copyright (c) 2002 Thomas Woehlke
 * Licensed under the GNU GPL. For full terms see the file COPYRIGHT.
 *
 * http://qsubnetcalc.sourceforge.net
 *
 * $Id: IpNumberTester.cpp,v 1.1.1.1 2002/11/26 21:01:35 rubycon Exp $
 */

#include "IpNumber.h"
#include <iostream>

using namespace std;

void out(QString x, IpNumber a)
{
	cout << x << "  " << a.toBitString() << "  " << a.toString() << endl;
}
	
void myendl()
{
	cout << endl;
}

void line()
{
	cout << "-------------------------------------------" << endl;
}

int main (int , char * [])
{
	IpNumber a(192,168,1,9);
	IpNumber b(255,255,255,0);
	IpNumber c(0,0,0,0);
	IpNumber d(255,255,255,255);
	line();
	out("  a",a);
	out("  b",b);
	out("  c",c);
	out("  d",d);
	line();
	IpNumber x(255,255,255,255);
	IpNumber y(255,255,255,255); out("  a",a); out("  b",b);
	x._and(a); x._or(b);  out("a|b",x); x._or(y); myendl(); out("  a",a); out("  b",b); 
	x._and(a); x._and(b);	out("a&b",x); x._or(y); myendl(); out("  a",a); out("  b",b);
	x._and(a); x._xor(b); out("a^b",x); x._or(y); myendl(); out("  a",a); 
	x._and(a); x._not();  out(" !a",x); x._or(y); myendl(); out("  b",b);
	x._and(b); x._not();  out(" !b",x); x._or(y);
	IpNumber tw;
	tw.set("192.168.1.9");
	out("tw1",tw);
	tw.set("255.255.255.0");
	out("tw1",tw);
	line();
}
