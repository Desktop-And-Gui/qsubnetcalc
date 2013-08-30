/**
 * IpNumber.h -- A Small Workarout to Convert an int to QString
 *
 * Copyright (c) 2002 Thomas Woehlke
 * Licensed under the GNU GPL. For full terms see the file COPYRIGHT.
 *
 * http://qsubnetcalc.sourceforge.net
 *
 * $Id: TWInteger.h,v 1.1.1.1 2002/11/26 21:01:36 rubycon Exp $
 */

#ifndef __TWInteger__
#define __TWInteger__

#include <QString>

class TWInteger
{
	public:
		TWInteger();
		~TWInteger();
		QString int2QString(int i);
};

#endif
