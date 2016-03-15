CPPSRCS+= 	network/networkconnectionscheduler.cpp \
network/networkdhcpserver.cpp \
network/networkdlg.cpp \
network/networkdnsforwarding.cpp \
network/networkdnsserver.cpp \
network/networkedithosts.cpp \
network/networkrouting.cpp \
network/networkurlfilter.cpp \
network/networkwebproxy.cpp
 		  
CSRCS+=

HDRS+= $(wildcard network/*.h)
HDRS+= $(wildcard network/*.hpp)
