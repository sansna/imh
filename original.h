#ifndef _ORIGINAL_H
#define _ORIGINAL_H

#include "predefine.h"
#include "datatype.h"

int INIT_STRJIQUN(__OUT__ pstrJiqun &);
int INIT_STRZHDIAN(__OUT__ pstrZhdian &p);
int READ_STRJIQUN(__IN__ FILE *,__OUT__ pstrJiqun &);
int READ_STRZHDIAN(__IN__ FILE *,__OUT__ pstrZhdian &);

#endif
