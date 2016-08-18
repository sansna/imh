#ifndef _DATATYPE_H
#define _DATATYPE_H

const int nMaxID = 15;
const int nMaxName = 30;
const int nMaxTime = 26;
const int nMaxOmo = 10;
const int nDateLen = 11;

typedef struct STRJIQUN{
    char *lpstrId;
    char *lpstrScner;
    char *lpstrSctime;
    char *lpstrRctime;
    char *lpstrSder;
    char *lpstrOmo;
    STRJIQUN *pNextStrJiqun;
}strJiqun,*pstrJiqun;

typedef struct STRZHDIAN{
    char *lpstrId;
    STRZHDIAN *pNextStrZhdian;
}strZhdian,*pstrZhdian;

typedef struct STRDONE{
    pstrJiqun pj;
    bool bMark;
    STRDONE *pNextStrDone;
}strDone,*pstrDone;

typedef struct STRRESORTBYSDER{
    char *lpstrSder;
    pstrDone pd;
    STRRESORTBYSDER *pNextResortBySder;
}strResortBySder,*pstrResortBySder;

#endif
