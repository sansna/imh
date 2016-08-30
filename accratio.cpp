#include "predefine.h"
#include "datatype.h"
#include "original.h"
#include "resort.h"
#include "output.h"
#include "date.h"
#include "accratio.h"

int DoAccRatio(__IN__ char *lpstrFs, __IN__ char *lpstrFr, __OUT__ pstrResortBySder &prh)
{
    FILE *p1,*p2;
    pstrJiqun pj = NULL;
    pstrZhdian pz = NULL;
    p1 = fopen(lpstrFs,"r");
    p2 = fopen(lpstrFr,"r");
    if (p1 != NULL && p2 != NULL);
    else perror("file open error");
    READ_STRJIQUN(p1,pj);
    READ_STRZHDIAN(p2,pz);

    char *date = NULL;
    date = getDate(pj);
    
    INIT_STRRESORTBYSDER(prh);

    RESORT_BY_SDER(pj,pz,prh);

    //OUTPUT_QUANTITY(prh);
    FOUTPUT_ALL(date,prh);
    return 0;
}
