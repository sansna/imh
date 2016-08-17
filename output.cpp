#include "predefine.h"
#include "datatype.h"
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
