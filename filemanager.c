#include "filemanager.h"

int readFile(vehicle vehicle_info[]) {
    int x = 0;
    FILE *fp;
    if ((fp = fopen("fordonsregister.bin", "rb")) == NULL) {
        printf("Fordonsregistret kunde inte hittas. Skapar register...\n");
    }
    else {
        while (fread(&vehicle_info[x], sizeof(vehicle_info[x]), 1, fp)) {
            x++;
        }  
    }
    fclose(fp);

    return x;
}

void writeFile(vehicle vehicle_info[], int n) {
    int x;
    FILE *fp;
    fp = fopen("fordonsregister.bin", "wb");
    if (fp == NULL) {
        printf("Filsystemsfel\n");
        exit(0);
    }
    for (x = 0; x < n; x++) {
        fwrite(&vehicle_info[x], sizeof(vehicle_info[x]), 1, fp);     
    }
    fclose(fp); 
      
    exit(0); 
}