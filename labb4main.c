#include "labb4file.h"

//Externa funktioner
extern void addVehicle();
extern void rmVehicle();
extern void sortVehicleBrand();
extern void checkVehicle();
extern void printVehicleRegister();
extern void exitProgram();
extern void getAllOfOneOwnersVehicles();
extern void getOwnerOfCertainVehicle();

//Start av programmet
int main() { 
    char choice; 
    int x;
    vehicle vehicle_info[ARRAY_10] = {0};

    //Läser in sparad data från .bin-fil
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

    while (1) {   
        //Meny
        printf("\033[035m\n");
        printf("--------------------------MENY---------------------------\n");
        printf("|\033[032m 1. Lägg till ett fordon\033[035m\t\t\t\t|\n");
        printf("|\033[032m 2. Ta bort ett fordon\033[035m\t\t\t\t\t|\n");
        printf("|\033[032m 3. Sortering efter bilmärke\033[035m\t\t\t\t|\n");
        printf("|\033[032m 4. Skriv ut information om ett fordon\033[035m\t\t\t|\n");
        printf("|\033[032m 5. Skriv ut hela fordonsregistret\033[035m\t\t\t|\n");
        printf("|\033[032m 6. Sök efter en persons registrerade fordon\033[035m\t\t|\n");
        printf("|\033[032m 7. Sök efter ett specifikt fordons ägare\033[035m\t\t|\n");
        printf("|\033[032m 8. Sök efter någon av ett fordons egenskaper\033[035m\t\t|\n");
        printf("|\033[032m 9. Sök efter kombinationer om ett fordons egenskaper\033[035m\t|\n");
        printf("|\033[032m 0. Avsluta\033[035m\t\t\t\t\t\t|\n");
        printf("---------------------------------------------------------\n");
        printf("\033[0m\n");
        printf("Ange ditt alternativ: ");
        scanf(" %c", &choice);
    
        switch (choice) {
            case '1': 
                addVehicle(vehicle_info);
                break;
            case '2':
                rmVehicle(vehicle_info);
                break;
            case '3':
                sortVehicleBrand(vehicle_info);
                break;
            case '4':
                checkVehicle(vehicle_info);
                break;
            case '5':
                printVehicleRegister(vehicle_info);
                break;
            case '6':
                getAllOfOneOwnersVehicles(vehicle_info);
                break;
            case '7':
                getOwnerOfCertainVehicle(vehicle_info);
                break;
            case '8':
                getOneVehicleProperty(vehicle_info);
                break;
            case '9':
                getComboVehicleProperty(vehicle_info);
                break;
            case '0':
                exitProgram(vehicle_info);
                break;
            default:
                printf("Felaktigt alternativ\n");
                break;        
        }
    }   
}
