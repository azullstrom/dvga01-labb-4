#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "labb4file.h"

//Funktionsdeklarationer
//Läsa från fil
int readFile(vehicle vehicle_info[]);

//Skriva till fil
void writeFile(vehicle vehicle_info[], int n);

#endif