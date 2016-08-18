#include "predefine.h"
#include "datatype.h"
#include <string.h>
#include "output.h"

int OUTPUT_QUANTITY(pstrResortBySder prh)
{
    while (prh->pNextResortBySder != NULL)
    {
        printf("%s:",prh->lpstrSder);
        int nCount = 0;
        pstrDone pdh = prh->pd;
        while (pdh->pNextStrDone != NULL)
        {
            if (!pdh->bMark)
                nCount ++;
            pdh = pdh->pNextStrDone;
        }
        printf("%d\n",nCount);
        prh = prh->pNextResortBySder;
    }

    return 0;
}

int FOUTPUT_ALL(char *date, pstrResortBySder prh)
{
    char *filename = (char *)malloc(nMaxTime);
    char *ufilename = (char *)malloc(nMaxTime);
    strncpy(filename,"g",1);
    strncpy(ufilename,"u",1);
    strncpy(filename+1,date,nDateLen);
    strncpy(ufilename+1,date,nDateLen);

    FILE *pFile = NULL;
    pstrResortBySder pr = prh;
    pFile = fopen(filename,"w");
    while (pr->pNextResortBySder != NULL)
    {
        fprintf(pFile,"%s,",pr->lpstrSder);
        pstrDone pd = pr->pd;
        while (pd->pNextStrDone != NULL)
        {
            fprintf(pFile,"%s,%s,%s,%s,%s,%d;",pd->pj->lpstrId,pd->pj->lpstrScner,pd->pj->lpstrSctime,pd->pj->lpstrRctime,pd->pj->lpstrOmo,pd->bMark);
            pd = pd->pNextStrDone;
        }
        fprintf(pFile,"\r");

        pr = pr->pNextResortBySder;
    }

    fclose(pFile);
    return 0;
}
