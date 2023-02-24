#include "freeDrives.h"
#include <windows.h>

#define MAX_DOS_DRIVES 26

QList<QString> freeDrives(){
    QList<QString> d;
    DWORD dwDriveMap =  GetLogicalDrives();
    char drive;
    for(drive =0 ; drive<MAX_DOS_DRIVES ; drive++){
        if (!(dwDriveMap & (1<<drive)))        {

//            std::cout << char('A'+drive) << ":" << std::endl;
            d<<QString(char('A'+drive));
        }
    }
    return d;
}
