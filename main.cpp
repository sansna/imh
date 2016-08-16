#include "predefine.h"
#include "datatype.h"
#include "original.h"
#include "resort.h"
#include "output.h"

int main()
{
    FILE *p1,*p2;
    pstrJiqun pj = NULL;
    pstrZhdian pz = NULL;
    p1 = fopen("/usr/mf/sto/stodata/send-2.csv","r");
    p2 = fopen("/usr/mf/sto/stodata/recv.csv","r");
    if (p1 != NULL && p2 != NULL);
    else perror("file open error");
    INIT_STRJIQUN(pj);
    INIT_STRZHDIAN(pz);
    READ_STRJIQUN(p1,pj);
    READ_STRZHDIAN(p2,pz);
    //printf("%s,%s,%s,%s,%s,%s,%s\n",pj->lpstrId,pj->lpstrSder,pj->lpstrScner,pj->lpstrRctime,pj->lpstrSctime,pj->lpstrOmo,pz->lpstrId);
    
    pstrResortBySder prh = NULL;
    INIT_STRRESORTBYSDER(prh);

    RESORT_BY_SDER(pj,pz,prh);

    OUTPUT_QUANTITY(prh);
    return 0;
}