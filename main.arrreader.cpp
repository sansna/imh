#include "predefine.h"
#include "datatype.h"
#include "accratioresultreader.h"
#include "original.h"
#include "resort.h"
#include "output.h"
#include "date.h"

int main_tst()
{
    pstrJiqun p;
    pstrResortBySder pr;
    char *c = NULL;
    INIT_STRJIQUN(p);
    INIT_STRRESORTBYSDER(pr);
    arrreader((char *)"/home/pi/QtProjects/imhqt/g2016-08-10",p,pr);
    c = getDate(p);
    FOUTPUT_ALL(c,pr);
    return 0;
}
