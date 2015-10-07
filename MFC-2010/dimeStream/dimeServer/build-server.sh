rm -rf client/dimeclient
rm -rf dimeserver

soapcpp2 dime.h
g++ -o dimeserver dimeserver.cpp stdsoap2.cpp soapC.cpp soapServer.cpp ${CFLAGS} ${LDFLAGS} ${LIBS}
g++ -o dimeclient dimeclient.cpp stdsoap2.cpp soapC.cpp soapClient.cpp ${CFLAGS} ${LDFLAGS} ${LIBS}

mkdir client
cp -rf dimeclient client
