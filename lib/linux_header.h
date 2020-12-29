#ifndef _LINUX_HEADER_
#define _LINUX_HEADER_

#include <sys/types.h>  /* Type definitions used by many programs */
#include <stdio.h>      /* Standard I/O functions */
#include <stdlib.h>     /* Prototypes of commonly used library functions,
                           plus EXIT_SUCCESS and EXIT_FAILURE constants */
#include <unistd.h>     /* Prototypes for many system calls */
#include <errno.h>      /* Declares errno and defines error constants */
#include <string.h>     /* Commonly used string-handling functions */
#include <stdbool.h>    /* 'bool' type plus 'true' and 'false' constants */

#include "get_num.h"    /* Declares our functions for handling numeric
                           arguments (getInt(), getLong()) */
#include "error_functions.h"  /* Declares our error-handling functions */

/* Unfortunately some UNIX implementations define FALSE and TRUE - here we'll undefine them */
// 下面的代码会C++报错
//#ifdef TRUE
//#undef TRUE
//#endif
//
//#ifdef FALSE
//#undef FALSE
//#endif
//
//#define min(m,n) ((m) < (n) ? (m) : (n))
//#define max(m,n) ((m) > (n) ? (m) : (n))

#endif
