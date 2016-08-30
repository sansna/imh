#include "accratio.h"
#include "accratioresultreader.h"

int tmain()
{
    pstrResortBySder pr = NULL;
    DoAccRatio((char *)"bufs.csv",(char *)"bufr.csv",pr);
    return 0;
}

int main()
{
    pstrJiqun pj = NULL;
    pstrResortBySder pr = NULL;
    arrreader((char *)"g2016-08-10.csv",pj,pr);
    return 0;
}
