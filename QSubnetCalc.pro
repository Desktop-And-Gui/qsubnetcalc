SOURCES=TWInteger.cpp IpNumber.cpp ComputeSubnetData.cpp QSubnetCalc.cpp main.cpp
HEADERS=TWInteger.h IpNumber.h ComputeSubnetData.h QSubnetCalc.h
#The following line was changed from FORMS to FORMS3 by qt3to4
FORMS3=QSCMainWindow.ui
CONFIG+=qt warn_on release x11 stdc
TARGET=qsubnetcalc
#The following line was inserted by qt3to4
#QT +=  qt3support
#The following line was inserted by qt3to4
CONFIG += uic3

