/*
 * ugid_functions.h
 *
 *  Created on: 2021年1月4日
 *      Author: lxs
 */

#ifndef CHP_08_UGID_FUNCTIONS_H_
#define CHP_08_UGID_FUNCTIONS_H_
#include <linux_header.h>

char *userNameFromId(uid_t uid);
uid_t userIdFromName(const char *name);
char *groupNameFromId(gid_t gid);
gid_t groupIdFromName(const char *name);

#endif /* CHP_08_UGID_FUNCTIONS_H_ */
