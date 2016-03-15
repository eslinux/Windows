CPPSRCS+= 	status/statusconnection.cpp \
status/statusdlg.cpp \
status/statusipsecvpn.cpp \
status/statusnettraffic.cpp \
status/statusnetworkexternal.cpp \
status/statusnetworkinternal.cpp \
status/statusnetworkother.cpp \
status/statusservices.cpp \
status/statussslvpn.cpp \
status/statussystem.cpp
 		  
CSRCS+=

HDRS+= $(wildcard status/*.h)
HDRS+= $(wildcard status/*.hpp)
