/**
 * QSubnetCalc.cpp -- Implements Class QSubnetCalc
 *
 * Copyright (c) 2002 Thomas Woehlke
 * Licensed under the GNU GPL. For full terms see the file COPYRIGHT.
 *
 * http://qsubnetcalc.sourceforge.net
 *
 * $Id: QSubnetCalc.cpp,v 1.1.1.1 2002/11/26 21:01:35 rubycon Exp $
 */

#include "QSubnetCalc.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <q3whatsthis.h>

QSubnetCalc::QSubnetCalc( QWidget* parent, const char* name, Qt::WFlags fl ):QSCMainWindow(parent,name,fl)
{
	calc = new ComputeSubnetData();
}

QSubnetCalc::~QSubnetCalc()
{ 
	delete (calc);  
}

void QSubnetCalc::calculate()
{
    IpNumber ipnr;
    ipnr.set(tHostAddress->text());		        calc->setHostAddress(ipnr.get(0),ipnr.get(1),ipnr.get(2),ipnr.get(3));
    ipnr.set(tNetMask->text());
    calc->setSubnetMask(ipnr.get(0),ipnr.get(1),ipnr.get(2),ipnr.get(3));	
    tHostId->setText(calc->getHostId());
    tNetAddress->setText(calc->getNetworkAddress());
    tBroadcastAddressBits->setText(calc->getBroadcastAddressBits());
    tNetAddressBits->setText(calc->getNetworkAddressBits());
    tHostIdBits->setText(calc->getHostIdBits());
    tNetMaskBits->setText(calc->getSubnetMaskBits());
    tHostAddressBits->setText(calc->getHostAddressBits());
    tHostAddress->setText(calc->getHostAddress());
    tBroadcastAddress->setText(calc->getBroadcastAddress());
    tNetAddressSize->setText(calc->getNetAddressSize());
    tHostAddressSize->setText(calc->getHostAddressSize());
    tClass->setText(calc->getDefaultClassType());
    tNetMask->setText(calc->getSubnetMask());
}

void QSubnetCalc::clear()
{
  tHostId->setText("");
  tNetAddress->setText("");
  tBroadcastAddressBits->setText("");
  tNetAddressBits->setText("");
  tHostIdBits->setText("");
  tNetMaskBits->setText("");
  tHostAddressBits->setText("");
  tHostAddress->setText("");
  tBroadcastAddress->setText("");
  tNetAddressSize->setText("");
  tHostAddressSize->setText("");
  tClass->setText("");
  tNetMask->setText("");
}
