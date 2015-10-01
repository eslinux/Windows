
cp -rf /home/ninhld/Zynq706/Project/FIREWALL/soft-admin/gsoap-2.8-host/gsoap/samples/calc++/calc.h ./
cp -rf /home/ninhld/Zynq706/Project/FIREWALL/soft-admin/gsoap-2.8-host/gsoap/samples/calc++/calcserver.cpp ./

soapcpp2 -i calc.h
arm-xilinx-linux-gnueabi-g++ -o calcserver calcserver.cpp stdsoap2.cpp soapC.cpp soapcalcService.cpp ${CFLAGS} ${LDFLAGS} ${LIBS}

cp -rf calcserver /home/ninhld/Zynq706/Project/FIREWALL/user/example/ssl
