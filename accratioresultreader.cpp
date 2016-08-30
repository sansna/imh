#include "accratioresultreader.h"
#include "original.h"
#include "resort.h"

int arrreader(__IN__ char *lpstrfilename, __OUT__ pstrJiqun &ph, __OUT__ pstrResortBySder &prh)
{
    INIT_STRJIQUN(ph);
    INIT_STRRESORTBYSDER(prh);
    pstrJiqun p = ph;
    pstrResortBySder pr = prh;

    FILE *pFile = NULL;
    char *lpstrC = (char *)malloc(nMaxName);
    strcpy(lpstrC,"\0");
    pFile = fopen(lpstrfilename,"r");
    fseek(pFile,0,SEEK_END);
    int nLen = ftell(pFile);
    fseek(pFile,0,SEEK_SET);
    while (nLen - ftell(pFile) > nMaxID)
    {
        int nMark;
        bool ret = true;
        fscanf(pFile," %[^,],",pr->lpstrSder);
        fscanf(pFile," %d",&pr->nTotal);
        fgetc(pFile);
        fscanf(pFile," %d",&pr->nUnsent);
        fgetc(pFile);
        fscanf(pFile," %lf",&pr->lfSentOmoTotal);
        fgetc(pFile);
        fscanf(pFile," %lf",&pr->lfLeftOmoTotal);
        fgetc(pFile);
        do
        {
            strcpy(p->lpstrSder,pr->lpstrSder);

            pstrDone pdtmp = NULL;
            INIT_STRDONE(pdtmp);
            pdtmp->pNextStrDone = pr->pd;
            pr->pd = pdtmp;
            pr->pd->pj = p;

            fscanf(pFile,"%[^,]",p->lpstrId);
            fgetc(pFile);
            fscanf(pFile,"%[^,]",p->lpstrScner);
            fgetc(pFile);
            fscanf(pFile,"%[^,]",p->lpstrSctime);
            fgetc(pFile);
            fscanf(pFile,"%[^,]",p->lpstrRctime);
            fgetc(pFile);
            fscanf(pFile,"%lf",&p->lfOmo);
            fgetc(pFile);
            fscanf(pFile,"%d",&nMark);
            fgetc(pFile);

            pr->pd->nMark = nMark;

            INIT_STRJIQUN(p->pNextStrJiqun);
            p = p->pNextStrJiqun;

            fscanf(pFile,"%[\r]",lpstrC);
            if (!strcmp(lpstrC,"\r"))
                ret = false;
        }while (ret);
        ret = true;
        strcpy(lpstrC,"\0");
        INIT_STRRESORTBYSDER(pr->pNextResortBySder);
        pr = pr->pNextResortBySder;
    }

    fclose(pFile);
    return 0;
}
