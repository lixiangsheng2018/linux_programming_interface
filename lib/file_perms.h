/*
 * file_perms.h
 *
 *  Created on: 2021年1月6日
 *      Author: lxs
 */

#ifndef LIB_FILE_PERMS_H_
#define LIB_FILE_PERMS_H_

#include <sys/types.h>

namespace myc {
#define FP_SPECIAL 1            /* Include set-user-ID, set-group-ID, and sticky
                                   bit information in returned string */

char *filePermStr(mode_t perm, int flags);

}

#endif /* LIB_FILE_PERMS_H_ */
