/**
 * main.cpp -- Applications main()-function
 *
 * Copyright (c) 2002 Thomas Woehlke
 * Licensed under the GNU GPL. For full terms see the file COPYRIGHT.
 *
 * http://qsubnetcalc.sourceforge.net
 *
 * $Id: main.cpp,v 1.1.1.1 2002/11/26 21:01:35 rubycon Exp $
 */

#include "QSubnetCalc.h"
#include <qapplication.h>

int main(int ac, char **av)
{
	QApplication a(ac, av);
	QWidget * mainWidget = new QSubnetCalc(0, "QSubnetCalc");
	a.setMainWidget(mainWidget);
	mainWidget->show();
	a.exec();
}
