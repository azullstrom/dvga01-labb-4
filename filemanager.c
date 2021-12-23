#include "filemanager.h"

void readFile(vehicle vehicle_info[]) {
    int x;
    FILE *fp;
    if ((fp = fopen("fordonsregister.bin", "rb")) == NULL) {
        printf("Filen ''fordonsregister.bin'' kunde inte öppnas. Programmet stängs...\n");
        exit(0);
    }
    else {
        for (x = 0; x < ARRAY_10; x++) {
            fread(&vehicle_info[x], sizeof(vehicle_info[x]), 1, fp);
        }
    }
    fclose(fp);
}

void writeFile(vehicle vehicle_info[]) {
    int x;
    FILE *fp;
    fp = fopen("fordonsregister.bin", "wb");
    for (x = 0; x < ARRAY_10; x++) {
        fwrite(&vehicle_info[x], sizeof(vehicle_info[x]), 1, fp);     
    }
    fclose(fp);   
    exit(0); 
}