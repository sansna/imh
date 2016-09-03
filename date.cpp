#include "date.h"
#include <string.h>

//return date inside pstrJiqun as char*
char *getDate(pstrJiqun p)
{
    char *date = (char *)malloc(nDateLen);
    strncpy(date,p->lpstrSctime,nDateLen - 1);
    date[10] = '\0';
    return date;
}

//normalize cd's date format
int PROC_DATE(char *cD)
{
    string szDate(cD);
    int nF = szDate.find_first_of('-');
    int nL = szDate.find_last_of('-');
    int nM = atoi(szDate.substr(nF + 1,nL-nF).c_str());
    int nD = atoi(szDate.substr(nL + 1,szDate.length()).c_str());
    ostringstream oszDate;
    oszDate<<szDate.substr(0,nF)<<'-';
    if(nM<10)
        oszDate<<'0'<<nM;
    else oszDate<<nM;
    oszDate<<'-';
    if(nD<10)
        oszDate<<'0'<<nD;
    else oszDate<<nD;
    strcpy_s(cD,oszDate.str().length() + 1,oszDate.str().c_str());

    return  0;
}

//input normal format of date cd, output year, month & date
int SZDATE_PROC(__IN__ char *cD, __OUT__ int& nT,__OUT__ int& nM,__OUT__ int &nK)
{
	char cT[5] = "";
	char cM[3] = "";
	char cK[3] = "";
	strncpy_s(cT,cD,4);
	nT = atoi(cT);
	strncpy_s(cM,cD + 5,2);
	nM = atoi(cM);
	strncpy_s(cK,cD + 8,2);
	nK = atoi(cK);
	if(nT&&nM&&nK)
		return 0;
	return 1;
}

//input a normal formatted date cd, compare with DateBenchMark's date
//where DateBenchMark = year *12 + month
//ret -1 means earlier than DBM
//ret 1 means later than DBM
//ret 0 means actually the DBM's first day
int SZDATE_COMPARE(char* cD)
{
	int nT=0;
	int nM = 0;
	int nK = 0;
	SZDATE_PROC(cD,nT,nM,nK);
	if(nT * 12 + nM < DateBenchmark)
		return -1;
	else if(nT * 12 + nM > DateBenchmark)
		return 1;
	else if (nK != 1)
		return 1;

	return 0;
}

//return yesterday of cd in char * normal format
int SZDATE_YESTERDAY(__IN__ char* cD, __OUT__ char*cDy)
{
	int nT = 0;
	int nM = 0;
	int nK = 0;
	SZDATE_PROC(cD,nT,nM,nK);
	if(nK > 1)
		nK --;
	else if(nM == 1)
	{
		nT --;
		nM = 12;
		nK = 30;
	}
	else
	{
		nM --;
		switch(nM)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			nK = 31;
		case 2:
			if(nT%4==0 && nT%40!=0 || nT%400==0)
				nK = 29;
			else
				nK = 28;
		default:
			nK = 30;
		}
	}
	ostringstream szY;
	if(nT < 10)
		szY<<'0'<<nT;
	else
		szY<<nT;
	szY<<'-';
	if(nM < 10)
		szY<<'0'<<nM;
	else
		szY<<nM;
	szY<<'-';
	if(nK < 10)
		szY<<'0'<<nK;
	else
		szY<<nK;
	strcpy_s(cDy,szY.str().length() + 1,szY.str().c_str());
	return 0;
}

//input nYear and nMonth,
//ret 1 if sys not earlier than input date
//ret 0 if later or right the date
int SYSDATE_COMPARE(__IN__ int nYear, __IN__ int nMonth)
{
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    int year = aTime->tm_year + 1900;
    int month = aTime->tm_mon + 1;
    int day = aTime->tm_mday;
    int hour = aTime->tm_hour;
    int min = aTime->tm_min;
    int sec = aTime->tm_sec;

    if(year > nYear)
        return 1;
    else if (year == nYear)
        if (month >= nMonth)
            return 1;
        
    return 0;
}
