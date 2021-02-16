#include <time.h>
#include "date.h"
#include "livre.h"

void lireDateSysteme(T_Emp *E) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    E->lannee = tm.tm_year;
    E->ledate = tm.tm_mday;

    switch (tm.tm_yday) {
        case 1:
            E->lejour = lu;
            break;
        case 2:
            E->lejour = ma;
            break;
        case 3:
            E->lejour = me;
            break;
        case 4:
            E->lejour = je;
            break;
        case 5:
            E->lejour = ve;
            break;
        case 6:
            E->lejour = sa;
            break;
        case 7:
            E->lejour = di;
            break;
    }    

    switch (tm.tm_mon) {
        case 1:
            E->lemois = janv;
            break;
        case 2:
            E->lemois = fevr;
            break;
        case 3:
            E->lemois = mars;
            break;
        case 4:
            E->lemois = avri;
            break;
        case 5:
            E->lemois = mai;
            break;
        case 6:
            E->lemois = juin;
            break;
        case 7:
            E->lemois = juil;
            break;
        case 8:
            E->lemois = aout;
            break;
        case 9:
            E->lemois = sept;
            break;
        case 10:
            E->lemois = octo;
            break;
        case 11:
            E->lemois = nove;
            break;
        case 12:
            E->lemois = dece;
            break;
    }
}