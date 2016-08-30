#include "fileconverter.h"

int convfenc(char *lpstrfiles, char *lpstrfrom, char *lpstrto)
{
    char *lpstrfiled = (char*)malloc(MAX_PATH);
    char *lpstrcmd = (char *)malloc(2*MAX_PATH);
    switch(lpstrto[0])
    {
        case 'g':strcpy(lpstrfiled,"g\0");break;
        case 'u':strcpy(lpstrfiled,"u\0");break;
        default: return 1;
    }
    strcpy(lpstrfiled,&lpstrfiles[1]);
    strcpy(lpstrcmd,"iconv -f ");
    strcpy(&lpstrcmd[9],lpstrfrom);
    strcpy(&lpstrcmd[9 + strlen(lpstrfrom)]," -t ");
    strcpy(&lpstrcmd[14 + strlen(lpstrfrom)],lpstrto);
    strcpy(&lpstrcmd[14 + strlen(lpstrfrom)+strlen(lpstrto)]," -o ");
    strcpy(&lpstrcmd[18 + strlen(lpstrfrom)+strlen(lpstrto)],lpstrfiled);
    strcpy(&lpstrcmd[18 + strlen(lpstrfrom)+strlen(lpstrto)+strlen(lpstrfiled)],"\0");
    system(lpstrcmd);
    return 0;
}
