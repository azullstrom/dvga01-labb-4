#include "labb4file.h"

//Funktionsdeklarationer 
extern void addVehicle(vehicle vehicle_info[]);
extern void rmVehicle(vehicle vehicle_info[]);
extern void sortVehicleBrand(vehicle vehicle_info[]);
extern void checkVehicle(vehicle vehicle_info[]);
extern void printVehicleRegister(vehicle vehicle_info[]);
extern void getAllOfOneOwnersVehicles(vehicle vehicle_info[]);
extern void getOwnerOfCertainVehicle(vehicle vehicle_info[]);
extern void getOneVehicleProperty(vehicle vehicle_info[]);
extern void getComboVehicleProperty(vehicle vehicle_info[]);
extern void exitProgram(vehicle vehicle_info[]);
extern int getFirstFreeIndex(vehicle vehicle_info[]);
extern int safeInputInt();

//Funktionsdefitioner
void addVehicle(vehicle vehicle_info[]) {
    int ctrl = 1, ctrl2 = 1, next_owner = OWNER_TWO;
    long svar;
    int y = getFirstFreeIndex(vehicle_info);
    if (y == ARRAY_10) {
        printf("Fordonsregistret fullt!\n");
    }
    else {
        printf("För- och efternamn på ägaren?\n");
        fgets(vehicle_info[y].person.name, 50, stdin);  
        printf("Ålder på ägare?\n");
        fgets(vehicle_info[y].person.age, 50, stdin);
        //Extrauppgift 1: Lägga till ytterligare ägare
        printf("Lägga till ytterligare ägare?\n1. Ja\n2. Nej \n");
        svar = safeInputInt();
        while (ctrl) {
            switch (svar) {
                case 1:
                    if (next_owner == OWNER_TWO) {
                        printf("För- och efternamn på ägare %d?\n", next_owner + 1);
                        fgets(vehicle_info[y].person2.name, 50, stdin);
                        printf("Ålder på ägare?\n");
                        fgets(vehicle_info[y].person2.age, 50, stdin);
                        vehicle_info[y].person2.exist = 1;
                        printf("Lägga till ytterligare ägare?\n1. Ja\n2. Nej \n");
                        svar = safeInputInt();
                        if (svar == 1) {
                            next_owner++;
                            break;     
                        }
                        if (svar == 2) {
                            printf("Ingen ytterligare ägare tillagd\n");
                            ctrl = 0;
                            break;
                        }
                        if (svar != 1 || svar != 2) {
                            printf("Felaktigt alternativ, ytterligare ägare ej tillagd\n");
                            ctrl = 0;
                            break;
                        }                     
                    }
                    if (next_owner == OWNER_THREE) {
                        printf("För- och efternamn på ägare %d?\n", next_owner + 1);
                        fgets(vehicle_info[y].person3.name, 50, stdin);
                        printf("Ålder på ägare?\n");
                        fgets(vehicle_info[y].person3.age, 50, stdin);
                        vehicle_info[y].person3.exist = 1;
                        next_owner++;
                        break;
                    }
                    if (next_owner == OWNER_LIMIT) {
                        printf("Tre ägare tillagda, maximalt antal ägare inlagda i systemet\n");
                        ctrl = 0;
                        break;
                    }
                case 2:
                    printf("Ingen ytterligare ägare tillagd\n");
                    ctrl = 0;
                    break;    
                default: 
                    printf("Felaktigt alternativ\n");
                    break;
            }
        }              
        //Extrauppgift slut
        printf("Fordonstyp?\n");
        fgets(vehicle_info[y].vehicle_type, 50, stdin);
        printf("Bilmärke?\n");
        fgets(vehicle_info[y].vehicle_brand, 50, stdin);
        printf("Registeringsnummer?\n");
        fgets(vehicle_info[y].number_plate, 50, stdin);   
        vehicle_info[y].car_found = 1;    
    }        
}

void rmVehicle(vehicle vehicle_info[]) {
    char null_str[ARRAY_10] = {0};
    long pos;
    printf("Ange en position i registret mellan 1-10 som du vill ta bort: ");
    pos = safeInputInt();
    if (pos == FIRST_ELEMENT || pos > ARRAY_10) {
        printf("Felaktigt alternativ\n");
    }
    else {
        if (vehicle_info[pos-1].car_found) {
            printf("Fordon %li borttaget från registret\n", pos);
            strcpy(vehicle_info[pos-1].person.name, null_str);
            strcpy(vehicle_info[pos-1].person2.name, null_str);
            strcpy(vehicle_info[pos-1].person3.name, null_str);   
            strcpy(vehicle_info[pos-1].person.age, null_str);
            strcpy(vehicle_info[pos-1].person2.age, null_str);
            strcpy(vehicle_info[pos-1].person3.age, null_str);
            strcpy(vehicle_info[pos-1].vehicle_type, null_str);
            strcpy(vehicle_info[pos-1].vehicle_brand, null_str);
            strcpy(vehicle_info[pos-1].number_plate, null_str);
            vehicle_info[pos-1].car_found = 0;
            vehicle_info[pos-1].person2.exist = 0;
            vehicle_info[pos-1].person3.exist = 0;
        }
        else {
            printf("Det finns inget fordon registrerat på denna plats\n");    
        }
    }
}

void sortVehicleBrand(vehicle vehicle_info[]) {
    int x, y;
    vehicle temp_vehicle_info[ARRAY_10] = {0};
    for (x = 0; x < ARRAY_10; x++) {
        for (y = x + 1; y < ARRAY_10; y++) {
            if (strncasecmp(vehicle_info[x].vehicle_brand, vehicle_info[y].vehicle_brand, 50) > 0 && vehicle_info[y].car_found != 0) {
                temp_vehicle_info[x] = vehicle_info[x];
                vehicle_info[x] = vehicle_info[y];
                vehicle_info[y] = temp_vehicle_info[x];
            }
        }
    }
    printf("Fordonsregistret är nu sorterat\n");
}

void checkVehicle(vehicle vehicle_info[]) {
    long pos;
    printf("Ange en position i registret mellan 1-10 som du vill söka efter: ");
    pos = safeInputInt();
    if (pos == 0 || pos > ARRAY_10) {
        printf("Felaktigt alternativ\n");
    }
    else {
        if (vehicle_info[pos-1].car_found) {
            printf("Den angivna positionens registrerade fordon:\n");
            //Om bara 3 ägare
            if (vehicle_info[pos-1].person2.exist && vehicle_info[pos-1].person3.exist) {
                printf("Ägare 1: %sÄgare 2: %sÄgare 3: %sÅlder ägare 1: %sÅlder ägare 2: %sÅlder ägare 3: %sFordonstyp: %sBilmärke: %sRegistreringsnummer: %s", 
                vehicle_info[pos-1].person.name, 
                vehicle_info[pos-1].person2.name, 
                vehicle_info[pos-1].person3.name, 
                vehicle_info[pos-1].person.age, 
                vehicle_info[pos-1].person2.age, 
                vehicle_info[pos-1].person3.age,
                vehicle_info[pos-1].vehicle_type, 
                vehicle_info[pos-1].vehicle_brand, 
                vehicle_info[pos-1].number_plate);
            }
            //Om bara 2 ägare
            if (vehicle_info[pos-1].person2.exist && !vehicle_info[pos-1].person3.exist) {
                printf("Ägare 1: %sÄgare 2: %sÅlder ägare 1: %sÅlder ägare 2: %sFordonstyp: %sBilmärke: %sRegistreringsnummer: %s", 
                vehicle_info[pos-1].person.name, 
                vehicle_info[pos-1].person2.name, 
                vehicle_info[pos-1].person.age, 
                vehicle_info[pos-1].person2.age, 
                vehicle_info[pos-1].vehicle_type, 
                vehicle_info[pos-1].vehicle_brand, 
                vehicle_info[pos-1].number_plate);
            }
            //Om bara 1 ägare
            if (!vehicle_info[pos-1].person2.exist && !vehicle_info[pos-1].person3.exist) {
                printf("Ägare 1: %sÅlder ägare 1: %sFordonstyp: %sBilmärke: %sRegistreringsnummer: %s", 
                vehicle_info[pos-1].person.name, 
                vehicle_info[pos-1].person.age, 
                vehicle_info[pos-1].vehicle_type, 
                vehicle_info[pos-1].vehicle_brand, 
                vehicle_info[pos-1].number_plate);
            }
        }
        else {
            printf("Det finns inget fordon registrerat på denna plats\n");
        }
    }
}

void printVehicleRegister(vehicle vehicle_info[]) {
    int x;
    for (x = 0; x < ARRAY_10; x++) {
        //Om car_found = 1 (true)
        if (vehicle_info[x].car_found) {
            //Om bara 3 ägare
            if (vehicle_info[x].person2.exist && vehicle_info[x].person3.exist) {
                printf("Fordon %d:\n\tÄgare 1: %s\tÄgare 2: %s\tÄgare 3: %s\tÅlder ägare 1: %s\tÅlder ägare 2: %s\tÅlder ägare 3: %s\tFordonstyp: %s\tBilmärke: %s\tRegistreringsnummer: %s", 
                x + 1, 
                vehicle_info[x].person.name, 
                vehicle_info[x].person2.name, 
                vehicle_info[x].person3.name, 
                vehicle_info[x].person.age,
                vehicle_info[x].person2.age,
                vehicle_info[x].person3.age, 
                vehicle_info[x].vehicle_type, 
                vehicle_info[x].vehicle_brand, 
                vehicle_info[x].number_plate);
            }
            //Om bara 2 ägare
            if (vehicle_info[x].person2.exist && !vehicle_info[x].person3.exist) {
                printf("Fordon %d:\n\tÄgare 1: %s\tÄgare 2: %s\tÅlder ägare 1: %s\tÅlder ägare 2: %s\tFordonstyp: %s\tBilmärke: %s\tRegistreringsnummer: %s", 
                x + 1, 
                vehicle_info[x].person.name, 
                vehicle_info[x].person2.name, 
                vehicle_info[x].person.age,
                vehicle_info[x].person2.age,
                vehicle_info[x].vehicle_type, 
                vehicle_info[x].vehicle_brand, 
                vehicle_info[x].number_plate);
            }
            //Om bara 1 ägare
            if (!vehicle_info[x].person2.exist && !vehicle_info[x].person3.exist) {
                printf("Fordon %d:\n\tÄgare 1: %s\tÅlder ägare 1: %s\tFordonstyp: %s\tBilmärke: %s\tRegistreringsnummer: %s", 
                x + 1, 
                vehicle_info[x].person.name, 
                vehicle_info[x].person.age,
                vehicle_info[x].vehicle_type, 
                vehicle_info[x].vehicle_brand, 
                vehicle_info[x].number_plate);
            }
        }
    }
}
//Extrauppgift 2:
void getAllOfOneOwnersVehicles(vehicle vehicle_info[]) {
    int x, has_vehicle = 0;
    char name[ARRAY_50];
    printf("För- och efternamn på ägaren?\n");
    fgets(name, 50, stdin);
    printf("Alla fordon som har %ssom ägare:\n", name);
    for (x = 0; x < ARRAY_10; x++) {
        if (strncasecmp(name, vehicle_info[x].person.name, 50) == 0) {
            printf("Fordon %d:\n\tFordonstyp: %s\tBilmärke: %s\tRegistreringsnummer: %s", 
            x + 1,
            vehicle_info[x].vehicle_type, 
            vehicle_info[x].vehicle_brand, 
            vehicle_info[x].number_plate);
            has_vehicle = 1;
        }
    }
    for (x = 0; x < ARRAY_10; x++) {
        if (strncasecmp(name, vehicle_info[x].person2.name, 50) == 0) {
            printf("Fordon %d:\n\tFordonstyp: %s\tBilmärke: %s\tRegistreringsnummer: %s", 
            x + 1,
            vehicle_info[x].vehicle_type, 
            vehicle_info[x].vehicle_brand, 
            vehicle_info[x].number_plate);
            has_vehicle = 1;
        }
    }
    for (x = 0; x < ARRAY_10; x++) {
        if (strncasecmp(name, vehicle_info[x].person3.name, 50) == 0) {
            printf("Fordon %d:\n\tFordonstyp: %s\tBilmärke: %s\tRegistreringsnummer: %s", 
            x + 1,
            vehicle_info[x].vehicle_type, 
            vehicle_info[x].vehicle_brand, 
            vehicle_info[x].number_plate);
            has_vehicle = 1;
        }
    }
    if (!has_vehicle) {
        printf("Personen du sökte efter har inga registrerade fordon\n");
    }
}
//Extrauppgift 3:
void getOwnerOfCertainVehicle(vehicle vehicle_info[]) {
    int x, has_owner = 0;
    char reg_number[ARRAY_50];
    printf("Skriv registreringsnumret till fordonet du vill veta ägare för: ");
    fgets(reg_number, 50, stdin);
    for (x = 0; x < ARRAY_10; x++) {
        if (strncasecmp(reg_number, vehicle_info[x].number_plate, 50) == 0) {
            //Om bara 3 ägare
            if (vehicle_info[x].person2.exist && vehicle_info[x].person3.exist) {
                printf("Ägare 1: %sÄgare 2: %sÄgare 3: %s", 
                vehicle_info[x].person.name,  
                vehicle_info[x].person2.name, 
                vehicle_info[x].person3.name);
                has_owner = 1;
            }
            //Om bara 2 ägare
            if (vehicle_info[x].person2.exist && !vehicle_info[x].person3.exist) {
                printf("Ägare 1: %sÄgare 2: %s", 
                vehicle_info[x].person.name,  
                vehicle_info[x].person2.name);
                has_owner = 1;
            }
            //Om bara 1 ägare
            if (!vehicle_info[x].person2.exist && !vehicle_info[x].person3.exist) {
                printf("Ägare 1: %s", 
                vehicle_info[x].person.name);
                has_owner = 1;
            }
        }
    }
    if (!has_owner) {
        printf("Det finns ingen ägare för det registreringsnumret du angav\n");
    }
}
//Extrauppgift 4:
void getOneVehicleProperty(vehicle vehicle_info[]) {
    int x, vehicle, has_owner = 0;
    char reg_number[ARRAY_50];
    long property;
    printf("Skriv registreringsnumret till fordonet du vill veta en egenskap för: ");
    fgets(reg_number, 50, stdin);
    for (x = 0; x < ARRAY_10; x++) {
        if (strncasecmp(reg_number, vehicle_info[x].number_plate, 50) == 0) {
            printf("Fordon hittat! Vilken egenskap vill du veta?\n\t1. Fordonstyp\n\t2. Fordonsmärke\n");
            vehicle = x;
            has_owner = 1;
        }
    }
    if (!has_owner) {
        printf("Det finns ingen ägare för det registreringsnumret du angav\n");
    }
    else {
        printf("Skriv ditt alternativ: ");
        property = safeInputInt();
        switch (property) {
            case 1: 
                printf("Fordonstyp: %s", vehicle_info[vehicle].vehicle_type);
                break;
            case 2:
                printf("Fordonstyp: %s", vehicle_info[vehicle].vehicle_brand);
                break;
            default:
                printf("Felaktigt alternativ\n");
                break;
        }
    }
}
//Extrauppgift 5:
void getComboVehicleProperty(vehicle vehicle_info[]) {
    int x, vehicle, has_owner = 0;
    char reg_number[ARRAY_50];
    long property, answer;
    printf("Skriv registreringsnumret till fordonet du vill veta några egenskaper för: ");
    fgets(reg_number, 50, stdin);
    for (x = 0; x < ARRAY_10; x++) {
        if (strncasecmp(reg_number, vehicle_info[x].number_plate, 50) == 0) {
            printf("Fordon hittat! Vilka egenskaper vill du veta?\n\t1. Fordonstyp\n\t2. Fordonsmärke\n");
            vehicle = x;
            has_owner = 1;
        }
    }
    if (!has_owner) {
        printf("Det finns ingen ägare för det registreringsnumret du angav\n");
    }
    else {
        printf("Skriv ditt alternativ: ");
        property = safeInputInt();
        switch (property) {
            case 1: 
                printf("Fordonstyp: %s\n", vehicle_info[vehicle].vehicle_type);
                printf("Vill du även veta bilmärke?\n\t1. Ja\n\t2. Nej\n");
                answer = safeInputInt();
                if (answer == 1) {
                    printf("Bilmärke: %s\n", vehicle_info[vehicle].vehicle_brand);    
                }
                if (answer == 2) {
                    printf("Skriver inte ut bilmärke\n");
                }
                if (answer != 1 && answer != 2) {
                    printf("Felaktigt alternativ\n");
                }
                break;
            case 2:
                printf("Bilmärke: %s\n", vehicle_info[vehicle].vehicle_brand);
                printf("Vill du även veta fordonstyp?\n\t1. Ja\n\t2. Nej\n");
                answer = safeInputInt();
                if (answer == 1) {
                    printf("Fordonstyp: %s\n", vehicle_info[vehicle].vehicle_type);    
                }
                if (answer == 2) {
                    printf("Skriver inte ut bilmärke\n");
                }
                if (answer != 1 && answer != 2) {
                    printf("Felaktigt alternativ\n");
                }
                break;
            default:
                printf("Felaktigt alternativ\n");
                break;
        }
    }
}

void exitProgram(vehicle vehicle_info[]) {
    int x;
    FILE *fp;
    fp = fopen("fordonsregister.bin", "wb");
    for (x = 0; x < ARRAY_10; x++) {
        fwrite(&vehicle_info[x], sizeof(vehicle_info[x]), 1, fp);     
    }
    fclose(fp);   
    exit(0); 
}

int getFirstFreeIndex(vehicle vehicle_info[]) {
    int y = 0;
    while (1) { 
        //Om car_found = 1 (true) och inte 10
        if(vehicle_info[y].car_found && y != ARRAY_10) {
            y++;
        }
        else {
            if (y != ARRAY_10) {
                printf("Plats %d ledig\n", y + 1);
                break;
            }
            else {
                break;
            }
        }    
    }
    return y; 
}

int safeInputInt() {
    char *end_ptr;
    char str_in[ARRAY_50];
    long number;
    int base = 10;
    fgets(str_in, 50, stdin);
    number = strtol(str_in, &end_ptr, base);

    return number;
}
