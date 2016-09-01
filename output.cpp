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
            if (!pdh->nMark)
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
    strncpy(filename+1+10,".csv",4);
    strncpy(ufilename+1+10,".csv",4);

    FILE *pFile = NULL;
    pstrResortBySder pr = prh;
    pFile = fopen(filename,"w");
    while (pr->pNextResortBySder != NULL)
    {
        //note the , ; shall be replaced with chinese punctuations.
        fprintf(pFile,"%s,",pr->lpstrSder);
        fprintf(pFile,"%d,",pr->nTotal);
        fprintf(pFile,"%d,",pr->nUnsent);
        fprintf(pFile,"%lf,",pr->lfSentOmoTotal);
        fprintf(pFile,"%lf,",pr->lfLeftOmoTotal);
        pstrDone pd = pr->pd;
        while (pd->pNextStrDone != NULL)
        {
            //fprintf(pFile,"%s,%s,%s,%s,%lf,%d;",pd->pj->lpstrId,pd->pj->lpstrScner,pd->pj->lpstrSctime,pd->pj->lpstrRctime,pd->pj->lfOmo,pd->nMark);
            fprintf(pFile,"%s,%s,%s,%s,",pd->pj->lpstrId,pd->pj->lpstrScner,pd->pj->lpstrSctime,pd->pj->lpstrRctime);
            if (pd->pj->lfOmo < 0)
                fprintf(pFile,",%d;",pd->nMark);
            else
                fprintf(pFile,"%lf,%d;",pd->pj->lfOmo,pd->nMark);
            pd = pd->pNextStrDone;
        }
        fprintf(pFile,"\n");

        pr = pr->pNextResortBySder;
    }

    fclose(pFile);
    return 0;
}
