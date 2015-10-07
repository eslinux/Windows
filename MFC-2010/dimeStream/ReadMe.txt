- Sử dụng soapcpp2 dime.h để dùng gSOAP C trong file source CPP
- Stream file qua ssl sử dụng phương thức dime
- dimeServer folder for linux server
  
	DEPEND_LIB_DIR=/home/ninhld/Zynq706/Project/FIREWALL/soft-admin/gsoap-2.8-host/install
	export CFLAGS="-I${DEPEND_LIB_DIR}/include  -DWITH_OPENSSL"
	export CPPFLAGS=-I${DEPEND_LIB_DIR}/include
	export LDFLAGS=-L${DEPEND_LIB_DIR}/lib
	export PKG_CONFIG_PATH=${DEPEND_LIB_DIR}/lib/pkgconfig
	export LD_LIBRARY_PATH=${DEPEND_LIB_DIR}/lib
	export PATH=$PATH:${DEPEND_LIB_DIR}/bin:${DEPEND_LIB_DIR}/sbin
	export LIBS="-lm -lssl -lcrypto -lpthread"
	
	./build-server.sh
