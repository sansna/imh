#ifndef _DATE_H
#define _DATE_H

#include "predefine.h"
#include "datatype.h"
#include "time.h"
#include <string>
#include <sstream>
using namespace std;

const int DateBenchmark = 2019 * 12 + 9;

__OUT__ char *getDate(__IN__ pstrJiqun p);
int PROC_DATE(char *cD);
int SZDATE_PROC(__IN__ char *cD, __OUT__ int& nT,__OUT__ int& nM,__OUT__ int &nK);
int SZDATE_COMPARE(char* cD);
int SZDATE_YESTERDAY(__IN__ char* cD, __OUT__ char*cDy);
int SYSDATE_COMPARE(__IN__ int nYear, __IN__ int nMonth);

#endif
