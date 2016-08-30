#ifndef _RESORT_H
#define _RESORT_H

#include "predefine.h"
#include "datatype.h"


int INIT_STRDONE(__OUT__ pstrDone &p);
int INIT_STRRESORTBYSDER(__OUT__ pstrResortBySder &p);
__OUT__ pstrResortBySder FIND_SDER(__IN__ char *lpstr, __IN__ pstrResortBySder prh);
int RESORT_BY_SDER(__IN__ pstrJiqun pj, __IN__ pstrZhdian pz, __OUT__ pstrResortBySder pr);

#endif
