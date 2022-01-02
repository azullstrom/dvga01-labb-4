#include "labb4file.h"

//Externa funktioner
extern void addVehicle(vehicle vehicle_info[], int n);
extern int rmVehicle(vehicle vehicle_info[], int n);
extern void sortVehicleBrand(vehicle vehicle_info[], int n);
extern void checkVehicle(vehicle vehicle_info[], int n);
extern void printVehicleRegister(vehicle vehicle_info[], int n);
extern void exitProgram(vehicle vehicle_info[], int n);
extern void getAllOfOneOwnersVehicles(vehicle vehicle_info[]);
extern void getOwnerOfCertainVehicle(vehicle vehicle_info[]);
extern int readFile(vehicle vehicle_info[]);
extern int safeInputInt();

//Start av programmet
int main() { 
    vehicle vehicle_info[ARRAY_10] = {0};
    long choice; 
    int x;
    int register_size = readFile(vehicle_info);

    //Läser in sparad data från .bin-fil
    readFile(vehicle_info);

    while (1) {   
        //Meny
        printMenu();
        choice = safeInputInt();
    
        switch (choice) {
            case 1: 
                if (register_size < ARRAY_10) {
                    addVehicle(vehicle_info, register_size);
                    register_size++;
                }
                else {
                    printf("Fordonsregistret fullt!\n");
                }
                break;
            case 2:
                if (rmVehicle(vehicle_info, register_size)) {
                    register_size--;
                } else {
                    printf("Det finns inget fordon registrerat på denna plats\n");
                }
                break;
            case 3:
                sortVehicleBrand(vehicle_info, register_size);
                break;
            case 4:
                checkVehicle(vehicle_info, register_size);
                break;
            case 5:
                printVehicleRegister(vehicle_info, register_size);
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
                exitProgram(vehicle_info, register_size);
                break;
            default:
                printf("Felaktigt alternativ\n");
                break;        
        }
        printf("\033[033mTryck Enter för att fortsätta... \033[0m");
        while(getchar() != '\n'); 
    }   
}
