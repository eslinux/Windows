source /opt/Xilinx/14.3/ISE_DS/settings64.sh
export HOST=arm-xilinx-linux-gnueabi
export CROSS=arm-xilinx-linux-gnueabi-
export ARCH=arm

export DEPEND_LIB_DIR=/home/ninhld/Zynq706/Project/FIREWALL/user
export PKG_CONFIG_PATH=${DEPEND_LIB_DIR}/lib/pkgconfig
export LD_LIBRARY_PATH=${DEPEND_LIB_DIR}/lib
export PATH=$PATH:${DEPEND_LIB_DIR}/bin:${DEPEND_LIB_DIR}/sbin
