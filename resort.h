#ifndef _RESORT_H
#define _RESORT_H

#include "predefine.h"
#include "datatype.h"


int INIT_STRDONE(pstrDone &p);
int INIT_STRRESORTBYSDER(pstrResortBySder &p);
pstrResortBySder FIND_SDER(char *lpstr, pstrResortBySder prh);
int RESORT_BY_SDER(pstrJiqun pj, pstrZhdian pz, pstrResortBySder pr);

#endif
