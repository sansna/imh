#include "predefine.h"
#include "datatype.h"
#include <string.h>
#include "resort.h"

int INIT_STRDONE(pstrDone &p)
{
    p = (pstrDone)malloc(sizeof(strDone));
    p->pj = NULL;
    p->bMark = false;
    p->pNextStrDone = NULL;

    return 0;
}

int INIT_STRRESORTBYSDER(pstrResortBySder &p)
{
    p = (pstrResortBySder)malloc(sizeof(strResortBySder));
    p->lpstrSder = (char *)malloc(nMaxName);
    p->pd = NULL;
    INIT_STRDONE(p->pd);
    p->pNextResortBySder = NULL;
    
    return 0;
}

pstrResortBySder FIND_SDER(char *lpstr, pstrResortBySder prh)
{
    while (prh->pNextResortBySder != NULL)
    {
        if(!strcmp(lpstr,prh->lpstrSder))
            return prh;
        prh = prh->pNextResortBySder;
    }
    strcpy(prh->lpstrSder, lpstr);
    INIT_STRRESORTBYSDER(prh->pNextResortBySder);
    return prh;
}

int RESORT_BY_SDER(pstrJiqun pj, pstrZhdian pz, pstrResortBySder pr)
{
    pstrZhdian pzh = pz;
    //pstrResortBySder prh = pr;
    bool bMark = false;
    while (pj->pNextStrJiqun != NULL)
    {
        while (pz->pNextStrZhdian != NULL)
        {
            if (!strcmp(pj->lpstrId,pz->lpstrId))
            {
                bMark = true;
                break;
            }
            pz = pz->pNextStrZhdian;
        }
        pstrResortBySder prT = FIND_SDER(pj->lpstrSder,pr);

        pstrDone pdT = NULL;
        INIT_STRDONE(pdT);
        pdT->pj = pj;
        pdT->bMark = bMark;
        pdT->pNextStrDone = prT->pd;

        prT->pd = pdT;

        pz = pzh;
        pj = pj->pNextStrJiqun;
        bMark = false;
    }

    return 0;
}
