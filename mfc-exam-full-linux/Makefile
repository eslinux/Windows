
# Straight forward Makefile to compile all examples in a row
APPNAME=CenticFirewallApp


INCDIR= -I./ \
		-I./firewall \
		-I./gSoapEngine \
		-I./gSoapEngine/import \
		-I./login \
		-I./logs \
		-I./network \
		-I./runtime \
		-I./services \
		-I./settings \
		-I./status \
		-I./system \
		-I./util



-include ./firewall/firewall.mk
-include ./gSoapEngine/gSoapEngine.mk
-include ./login/login.mk
-include ./logs/logs.mk
-include ./network/network.mk
-include ./runtime/runtime.mk
-include ./services/services.mk
-include ./settings/settings.mk
-include ./status/status.mk
-include ./system/system.mk
-include ./util/util.mk

CPPSRCS+= CenticFirewallApp.cpp

LIBS=-lm -lssl -lcrypto -lpthread

ifeq ('$(ARCH)', 'arm')
    BINDIR=./build/bin-arm
    OBJSDIR:=./build/objs-arm
else
    BINDIR=./build/bin
    OBJSDIR:=./build/objs
endif


OBJS:= $(patsubst %.cpp, $(OBJSDIR)/%.o, $(CPPSRCS))
OBJS+= $(patsubst %.c, $(OBJSDIR)/%.o, $(CSRCS))

GSOAPDIR=gSoapEngine

ifeq ('$(ARCH)', 'arm')
	CFLAGS += -L$(ROOTFS)/usr/include -L$(ROOTFS)/usr/local/include -DWITH_OPENSSL -g 
    LDFLAGS += -L$(ROOTFS)/usr/lib -L$(ROOTFS)/usr/local/lib -L${DEPEND_LIB_DIR}/lib
	INCDIR += -I${DEPEND_LIB_DIR}/include
	LIBS+=
	INSTALLDIR:= $(ROOTFS)/usr/sbin
	CERTDIR:= cert
	CC=arm-xilinx-linux-gnueabi-gcc
	CXX=arm-xilinx-linux-gnueabi-g++
else
	CFLAGS += -I/usr/include -I/usr/local/include -DWITH_OPENSSL -g 
    LDFLAGS += -L/usr/lib -L/usr/local/lib -L${DEPEND_LIB_DIR}/lib   
	INCDIR += -I${DEPEND_LIB_DIR}/include
	LIBS+=
	INSTALLDIR:= install
	CERTDIR:= cert
	CC=gcc
	CXX=g++
endif


#MAKE
default: all
all: $(BINDIR)/$(APPNAME)

$(OBJSDIR)/%.o: %.c $(HDRS)
	@echo " [CC]   $@"
	@mkdir -p $(shell dirname $@)
	@$(CC) -c $< -o $@ $(CFLAGS) ${INCDIR}

$(OBJSDIR)/%.o: %.cpp $(HDRS)
	@echo " [CXX]  $@"
	@mkdir -p $(shell dirname $@)
	@$(CXX) -c $< -o $@ $(CFLAGS) ${INCDIR}
	
$(BINDIR)/$(APPNAME) : $(OBJS)
	@echo " [LINK] $@"
	@mkdir -p $(shell dirname $@)
	@$(CXX) $(OBJS) -o $@ $(LDFLAGS) ${LIBS}
	
soap:
	$(MAKE) -C $(GSOAPDIR)
	
allsoap: soap all install

	
install: all
	@cp -rf $(BINDIR)/$(APPNAME) $(INSTALLDIR)
	@cp -rf $(CERTDIR)/* $(INSTALLDIR)

clean: 
	@echo "rm -rf $(BINDIR)/$(APPNAME) $(OBJS)"
	@rm -rf $(BINDIR)/$(APPNAME) $(OBJS)
cleanall:
	@echo "rm -rf ./build/bin* ./build/objs*"
	@rm -rf ./build/bin* ./build/objs*
