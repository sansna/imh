#ifndef _DATATYPE_H
#define _DATATYPE_H

typedef struct STRJIQUN{
    char *lpstrId;
    char *lpstrScner;
    char *lpstrSctime;
    char *lpstrRctime;
    char *lpstrSder;
    double lfOmo;
    STRJIQUN *pNextStrJiqun;
}strJiqun,*pstrJiqun;

typedef struct STRZHDIAN{
    char *lpstrId;
    STRZHDIAN *pNextStrZhdian;
}strZhdian,*pstrZhdian;

typedef struct STRDONE{
    pstrJiqun pj;
    int nMark;
    STRDONE *pNextStrDone;
}strDone,*pstrDone;

typedef struct STRRESORTBYSDER{
    char *lpstrSder;
    int nTotal;
    int nUnsent;
    double lfSentOmoTotal;
    double lfLeftOmoTotal;
    pstrDone pd;
    STRRESORTBYSDER *pNextResortBySder;
}strResortBySder,*pstrResortBySder;

#endif
