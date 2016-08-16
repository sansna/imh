#include "datatype.h"
#include "predefine.h"
#include "original.h"

int INIT_STRJIQUN(pstrJiqun &p)
{
    p = (pstrJiqun)malloc(sizeof(strJiqun));
    p->lpstrSder=(char *)malloc(nMaxName);
    p->lpstrOmo =(char *)malloc(nMaxOmo);
    p->lpstrScner = (char *)malloc(nMaxName);
    p->lpstrSctime=(char *)malloc(nMaxTime);
    p->lpstrRctime = (char *)malloc(nMaxTime);
    p->lpstrId = (char *)malloc(nMaxID);
    p->pNextStrJiqun = NULL;
    return 0;
}

int INIT_STRZHDIAN(pstrZhdian &p)
{
    p = (pstrZhdian)malloc(sizeof(strZhdian));
    p->lpstrId = (char *)malloc(nMaxID);
    p->pNextStrZhdian = NULL;
    return 0;
}

int READ_STRJIQUN(FILE *pFile,pstrJiqun p)
{
    fseek(pFile,0,SEEK_END);
    int len = ftell(pFile);
    fseek(pFile,55,SEEK_SET);
    while (len - ftell(pFile) > 10)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\r]\r\n",p->lpstrId,p->lpstrScner,p->lpstrSctime,p->lpstrRctime,p->lpstrSder,p->lpstrOmo);
        INIT_STRJIQUN(p->pNextStrJiqun);
        p = p->pNextStrJiqun;
    }

    return 0;
}

int READ_STRZHDIAN(FILE *pFile,pstrZhdian p)
{
    fseek(pFile,0,SEEK_END);
    int len = ftell(pFile);
    fseek(pFile,10,SEEK_SET);
    while (len - ftell(pFile) > 10) 
    {
        fscanf(pFile,"%[^\r]\r\n",p->lpstrId);
        INIT_STRZHDIAN(p->pNextStrZhdian);
        p = p->pNextStrZhdian;
    }
    
    return 0;
}

//int main()
//{
//    FILE *p1,*p2;
//    pstrJiqun pj = NULL;
//    pstrZhdian pz = NULL;
//    p1 = fopen("/usr/mf/sto/stodata/send-2.csv","r");
//    p2 = fopen("/usr/mf/sto/stodata/recv.csv","r");
//    if (p1 != NULL && p2 != NULL);
//    else perror("file open error");
//    INIT_STRJIQUN(pj);
//    INIT_STRZHDIAN(pz);
//    READ_STRJIQUN(p1,pj);
//    READ_STRZHDIAN(p2,pz);
//    printf("%s,%s,%s,%s,%s,%s,%s\n",pj->lpstrId,pj->lpstrSder,pj->lpstrScner,pj->lpstrRctime,pj->lpstrSctime,pj->lpstrOmo,pz->lpstrId);
//    return 0;
//}
