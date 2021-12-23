#include "labb4file.h"

//Externa funktioner
extern void readFile(vehicle vehicle_info[]);
extern void addVehicle(vehicle vehicle_info[]);
extern void rmVehicle(vehicle vehicle_info[]);
extern void sortVehicleBrand(vehicle vehicle_info[]);
extern void checkVehicle(vehicle vehicle_info[]);
extern void printVehicleRegister(vehicle vehicle_info[]);
extern void exitProgram(vehicle vehicle_info[]);
extern void getAllOfOneOwnersVehicles(vehicle vehicle_info[]);
extern void getOwnerOfCertainVehicle(vehicle vehicle_info[]);
extern int safeInputInt();

//Start av programmet
int main() { 
    long choice; 
    int x;
    vehicle vehicle_info[ARRAY_10] = {0};

    //Läser in sparad data från .bin-fil
    readFile(vehicle_info);

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
        printf("|\033[032m 10. Avsluta\033[035m\t\t\t\t\t\t|\n");
        printf("---------------------------------------------------------\n");
        printf("\033[0m\n");
        printf("Ange ditt alternativ: ");
        choice = safeInputInt();
    
        switch (choice) {
            case 1: 
                addVehicle(vehicle_info);
                break;
            case 2:
                rmVehicle(vehicle_info);
                break;
            case 3:
                sortVehicleBrand(vehicle_info);
                break;
            case 4:
                checkVehicle(vehicle_info);
                break;
            case 5:
                printVehicleRegister(vehicle_info);
                break;
            case 6:
                getAllOfOneOwnersVehicles(vehicle_info);
                break;
            case 7:
                getOwnerOfCertainVehicle(vehicle_info);
                break;
            case 8:
                getOneVehicleProperty(vehicle_info);
                break;
            case 9:
                getComboVehicleProperty(vehicle_info);
                break;
            case 10:
                exitProgram(vehicle_info);
                break;
            default:
                printf("Felaktigt alternativ\n");
                break;        
        }
        printf("\033[033mTryck Enter för att fortsätta... \033[0m");
        while(getchar() != '\n'); 
    }   
}
