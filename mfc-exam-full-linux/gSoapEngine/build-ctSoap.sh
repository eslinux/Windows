rm -rf client/dimeclient
rm -rf dimeserver

soapcpp2 ctSoap.h
g++ -o dimeserver dimeserver.cpp stdsoap2.cpp soapC.cpp soapServer.cpp ${CFLAGS} ${LDFLAGS} ${LIBS}
g++ -o dimeclient dimeclient.cpp stdsoap2.cpp soapC.cpp soapClient.cpp ${CFLAGS} ${LDFLAGS} ${LIBS}

mkdir client
cp -rf dimeclient client


#soapcpp2 -I/home/ninhld/Zynq706/Project/FIREWALL/soft-admin/gsoap-2.8-host/gsoap:/home/ninhld/Zynq706/Project/FIREWALL/soft-admin/gsoap-2.8-host/gsoap/import ctSoap.h
