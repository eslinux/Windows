
#=======================================================================
# gsoap-2.8
# Dependency: openssl
#=======================================================================
DEPEND_LIB_DIR=/home/ninhld/Zynq706/Project/FIREWALL/user
export CFLAGS=-I${DEPEND_LIB_DIR}/include
export CPPFLAGS=-I${DEPEND_LIB_DIR}/include
export LDFLAGS=-L${DEPEND_LIB_DIR}/lib
export PKG_CONFIG_PATH=${DEPEND_LIB_DIR}/lib/pkgconfig
export LD_LIBRARY_PATH=${DEPEND_LIB_DIR}/lib
export PATH=$PATH:${DEPEND_LIB_DIR}/bin:${DEPEND_LIB_DIR}/sbin

"buid soapcpp2 for host"
./configure
make CC=gcc CXX=g++ -C gsoap/src



./configure --prefix=$PREFIX --host=${HOST} \
CC=${CROSS}gcc \
CXX=${CROSS}g++ \
--with-openssl=${DEPEND_LIB_DIR}

"Modify config.h which have just is generated
comment #define malloc rpl_malloc
Note: fixbug ::malloc has not been declared
"

make 
make install


#build example

DEPEND_LIB_DIR=/home/ninhld/Zynq706/Project/FIREWALL/soft-admin/gsoap-2.8-host/install
export CFLAGS="-I${DEPEND_LIB_DIR}/include -DWITH_OPENSSL"
export CPPFLAGS=-I${DEPEND_LIB_DIR}/include
export LDFLAGS=-L${DEPEND_LIB_DIR}/lib
export PKG_CONFIG_PATH=${DEPEND_LIB_DIR}/lib/pkgconfig
export LD_LIBRARY_PATH=${DEPEND_LIB_DIR}/lib
export PATH=$PATH:${DEPEND_LIB_DIR}/bin:${DEPEND_LIB_DIR}/sbin
export LIBS="-lm -lssl -lcrypto -lpthread"
STDSOAP2_PATH=/home/ninhld/Zynq706/Project/FIREWALL/soft-admin/gsoap-2.8-host/gsoap

soapcpp2 -c calc.h
gcc -o calcclient calcclient.c ${STDSOAP2_PATH}/stdsoap2.c soapC.c soapClient.c ${CFLAGS} ${LDFLAGS} ${LIBS}
gcc -o calcserver calcserver.c ${STDSOAP2_PATH}/stdsoap2.c soapC.c soapServer.c ${CFLAGS} ${LDFLAGS} ${LIBS}



soapcpp2 -c ssl.h
gcc -DWITH_OPENSSL -o sslclient sslclient.c ${STDSOAP2_PATH}/stdsoap2.c soapC.c soapClient.c ${CFLAGS} ${LDFLAGS} ${LIBS}
gcc -DWITH_OPENSSL -o sslserver sslserver.c ${STDSOAP2_PATH}/stdsoap2.c soapC.c soapServer.c ${CFLAGS} ${LDFLAGS} ${LIBS}

Compilation in C (see samples/calc):
    soapcpp2 -c calc.h
    cc -o calcclient calcclient.c stdsoap2.c soapC.c soapClient.c
    cc -o calcserver calcserver.c stdsoap2.c soapC.c soapServer.c

Compilation in C++ (see samples/calc++):
    soapcpp2 -i calc.h
    cc -o calcclient++ calcclient.cpp stdsoap2.cpp soapC.cpp soapcalcProxy.cpp
    cc -o calcserver++ calcserver.cpp stdsoap2.cpp soapC.cpp soapcalcService.cpp

