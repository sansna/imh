#include "datatype.h"
#include "predefine.h"
#include "original.h"

int INIT_STRJIQUN(pstrJiqun &p)
{
    p = (pstrJiqun)malloc(sizeof(strJiqun));
    p->lpstrSder=(char *)malloc(nMaxName);
    p->lfOmo =0.0L;
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

int READ_STRJIQUN(FILE *pFile,pstrJiqun &ph)
{
    INIT_STRJIQUN(ph);
    pstrJiqun p = ph;

    fseek(pFile,0,SEEK_END);
    int len = ftell(pFile);
    fseek(pFile,0,SEEK_SET);
    char *szLine = (char *)malloc(nMaxCmdLine);
    fscanf(pFile,"%[^\n]",szLine);
    while (len - ftell(pFile) > 10)
    {
        //fscanf(pFile," %[^,],%[^,],%[^,],%[^,],%[^,],%lf ",p->lpstrId,p->lpstrScner,p->lpstrSctime,p->lpstrRctime,p->lpstrSder,&p->lfOmo);
        fscanf(pFile," %[^,]",p->lpstrId);
        fgetc(pFile);
        fscanf(pFile,"%[^,]",p->lpstrScner);
        fgetc(pFile);
        fscanf(pFile,"%[^,]",p->lpstrSctime);
        fgetc(pFile);
        fscanf(pFile,"%[^,]",p->lpstrRctime);
        fgetc(pFile);
        fscanf(pFile,"%[^,]",p->lpstrSder);
        fgetc(pFile);
        char c;
        fscanf(pFile,"%c",&c);
        if (c == '\n')
        {
            p->lfOmo = -1.0L;
            fseek(pFile,-1,SEEK_CUR);
        }
        else{
            fseek(pFile,-1,SEEK_CUR);
            fscanf(pFile,"%lf",&p->lfOmo);
        }
        INIT_STRJIQUN(p->pNextStrJiqun);
        p = p->pNextStrJiqun;
    }

    return 0;
}

int READ_STRZHDIAN(FILE *pFile,pstrZhdian &ph)
{
    INIT_STRZHDIAN(ph);
    pstrZhdian p = ph;
    fseek(pFile,0,SEEK_END);
    int len = ftell(pFile);
    fseek(pFile,10,SEEK_SET);
    while (len - ftell(pFile) > 10) 
    {
        fscanf(pFile,"%[^\n]\n",p->lpstrId);
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
//    printf("%s,%s,%s,%s,%s,%lf,%s\n",pj->lpstrId,pj->lpstrSder,pj->lpstrScner,pj->lpstrRctime,pj->lpstrSctime,&pj->lfOmo,pz->lpstrId);
//    return 0;
//}
