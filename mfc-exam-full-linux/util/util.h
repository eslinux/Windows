#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>

#if 1
#define DBG(x...) {printf("\e[033;34m%s<%d> \e[0m",__FUNCTION__,__LINE__); printf(x);}
#define FATAL(x...) {printf("\e[033;31m%s<%d> \e[0m",__FUNCTION__,__LINE__); printf(x);}
#else
#define DBG(x...)
#define FATAL(x...)
#endif


#define FREEX(x) {if((x)) printf("free((x))"); (x)=NULL;}

#endif // UTIL_H
