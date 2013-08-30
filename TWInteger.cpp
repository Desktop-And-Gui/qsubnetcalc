/**
 * TWInteger.cpp -- Implements Class TWInteger
 *
 * Copyright (c) 2002 Thomas Woehlke
 * Licensed under the GNU GPL. For full terms see the file COPYRIGHT.
 *
 * http://qsubnetcalc.sourceforge.net
 *
 * $Id: TWInteger.cpp,v 1.1.1.1 2002/11/26 21:01:36 rubycon Exp $
 */

#include "TWInteger.h"
#include <math.h>

TWInteger::TWInteger()
{}

TWInteger::~TWInteger()
{}


QString TWInteger::int2QString(int i)
{
	 QString retValue("");
	 if (i==0)
	 {
	 		retValue.append("0"); 
	 }
	 else
	 {	 
		 int digits=(int) floor(log10((double)i));
		 int u = i;
		 for (int count=0; count<=digits; count++)
		 {
	 			switch(u % 10)
				{
					case 0: retValue.prepend("0"); break;
					case 1: retValue.prepend("1"); break;
					case 2: retValue.prepend("2"); break;
					case 3: retValue.prepend("3"); break;
					case 4: retValue.prepend("4"); break;
					case 5: retValue.prepend("5"); break;
					case 6: retValue.prepend("6"); break;
					case 7: retValue.prepend("7"); break;
					case 8: retValue.prepend("8"); break;
					case 9: retValue.prepend("9"); break;				
				}
				u /= 10;					
		 }		 
	 }
	 return retValue;	 
}
