#include "date.h"
#include <string.h>

char *getDate(pstrJiqun p)
{
    char *date = (char *)malloc(nDateLen);
    strncpy(date,p->lpstrSctime,nDateLen - 1);
    date[10] = '\0';
    return date;
}
