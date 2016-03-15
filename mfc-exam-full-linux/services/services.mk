CPPSRCS+= 	services/servicesdlg.cpp \
services/servicesdynamicdns.cpp \
services/servicesids.cpp \
services/servicesipsecvpn.cpp \
services/servicesqos.cpp \
services/servicessslvpn.cpp \
services/servicestimeserver.cpp
 		  
CSRCS+=

HDRS+= $(wildcard services/*.h)
HDRS+= $(wildcard services/*.hpp)
