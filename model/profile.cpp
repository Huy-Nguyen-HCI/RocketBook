#include "profile.h"

int Profile::idCnt;

Profile::Profile()
{
    id = idCnt ++;
    scrapBook = new Scrapbook();
}




