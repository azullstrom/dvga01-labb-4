#include "labb4file.h"

//Funktionsdefitioner
void addVehicle(vehicle vehicle_info[]) {
    char svar;
    int ctrl = 1, ctrl2 = 1, next_owner = OWNER_TWO, age_ctrl;
    int y = getFirstFreeIndex(vehicle_info);
    if (y == ARRAY_10) {
        printf("Fordonsregistret fullt!\n");
    }
    else {
        printf("För- och efternamn på ägaren?\n");
        scanf("%s %s", vehicle_info[y].person.name, vehicle_info[y].person.last_name);     
        printf("Ålder på ägare?\n");
        scanf("%s", vehicle_info[y].person.age);
        //Extrauppgift 1: Lägga till ytterligare ägare
        printf("Lägga till ytterligare ägare?\n1. Ja\n2. Nej \n");
        scanf(" %c", &svar);
        while (ctrl) {
            switch (svar) {
                case '1':
                    if (next_owner == OWNER_TWO) {
                        printf("För- och efternamn på ägare %d?\n", next_owner + 1);
                        scanf("%s %s", vehicle_info[y].person2.name, vehicle_info[y].person2.last_name); 
                        printf("Ålder på ägare?\n");
                        scanf("%s", vehicle_info[y].person2.age);
                        printf("Lägga till ytterligare ägare?\n1. Ja\n2. Nej \n");
                        scanf(" %c", &svar);
                        if (svar == '1') {
                            next_owner++;
                            break;     
                        }
                        if (svar == '2') {
                            printf("Ingen ytterligare ägare tillagd\n");
                            ctrl = 0;
                            break;
                        }
                        if (svar != '1' || svar != '2') {
                            printf("Felaktigt alternativ, ytterligare ägare ej tillagd\n");
                            ctrl = 0;
                            break;
                        }                     
                    }
                    if (next_owner == OWNER_THREE) {
                        printf("För- och efternamn på ägare %d?\n", next_owner + 1);
                        scanf("%s %s", vehicle_info[y].person3.name, vehicle_info[y].person3.last_name); 
                        printf("Ålder på ägare?\n");
                        scanf("%s", vehicle_info[y].person3.age);
                        next_owner++;
                        break;
                    }
                    if (next_owner == OWNER_LIMIT) {
                        printf("Tre ägare tillagda, maximalt antal ägare inlagda i systemet\n");
                        ctrl = 0;
                        break;
                    }
                case '2':
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
        scanf("%s", vehicle_info[y].vehicle_type);
        printf("Bilmärke?\n");
        scanf("%s", vehicle_info[y].vehicle_brand);
        printf("Registeringsnummer?\n");
        scanf("%s", vehicle_info[y].number_plate);   
        vehicle_info[y].car_found = 1;    
    }        
}

void rmVehicle(vehicle vehicle_info[]) {
    int pos;
    char null_str[ARRAY_10] = {0};
    char term;
    printf("Ange en position i registret mellan 1-10 som du vill ta bort: ");
    //Safe input för int-variabel pos
    if (scanf("%d%c", &pos, &term) != TWO || term != '\n' || pos == FIRST_ELEMENT || pos > ARRAY_10) {
        printf("Felaktigt alternativ\n");
    }
    else {
        if (vehicle_info[pos-1].car_found) {
            printf("Fordon %d borttaget från registret\n", pos);
            strcpy(vehicle_info[pos-1].person.name, null_str);
            strcpy(vehicle_info[pos-1].person2.name, null_str);
            strcpy(vehicle_info[pos-1].person3.name, null_str);
            strcpy(vehicle_info[pos-1].person.last_name, null_str);  
            strcpy(vehicle_info[pos-1].person2.last_name, null_str); 
            strcpy(vehicle_info[pos-1].person3.last_name, null_str);   
            strcpy(vehicle_info[pos-1].person.age, null_str);
            strcpy(vehicle_info[pos-1].person2.age, null_str);
            strcpy(vehicle_info[pos-1].person3.age, null_str);
            strcpy(vehicle_info[pos-1].vehicle_type, null_str);
            strcpy(vehicle_info[pos-1].vehicle_brand, null_str);
            strcpy(vehicle_info[pos-1].number_plate, null_str);
            vehicle_info[pos-1].car_found = 0;
        }
        else {
            printf("Det finns inget fordon registrerat på denna plats\n");    
        }
    }
}

void sortVehicleBrand(vehicle vehicle_info[]) {
    int x, y;
    char temp[ARRAY_50];
    int int_temp;
    for (x = 0; x < ARRAY_10; x++) {
        for (y = x + 1; y < ARRAY_10; y++) {
            if (strcmp(vehicle_info[x].vehicle_brand, vehicle_info[y].vehicle_brand) > 0 && vehicle_info[y].car_found != 0) {
                strcpy(temp, vehicle_info[x].vehicle_brand); 
                strcpy(vehicle_info[x].vehicle_brand, vehicle_info[y].vehicle_brand); 
                strcpy(vehicle_info[y].vehicle_brand, temp); 
 
                strcpy(temp, vehicle_info[x].vehicle_type); 
                strcpy(vehicle_info[x].vehicle_type, vehicle_info[y].vehicle_type); 
                strcpy(vehicle_info[y].vehicle_type, temp); 

                strcpy(temp, vehicle_info[x].number_plate); 
                strcpy(vehicle_info[x].number_plate, vehicle_info[y].number_plate); 
                strcpy(vehicle_info[y].number_plate, temp); 

                strcpy(temp, vehicle_info[x].person.age); 
                strcpy(vehicle_info[x].person.age, vehicle_info[y].person.age); 
                strcpy(vehicle_info[y].person.age, temp); 

                strcpy(temp, vehicle_info[x].person2.age); 
                strcpy(vehicle_info[x].person2.age, vehicle_info[y].person2.age); 
                strcpy(vehicle_info[y].person2.age, temp); 

                strcpy(temp, vehicle_info[x].person3.age); 
                strcpy(vehicle_info[x].person3.age, vehicle_info[y].person3.age); 
                strcpy(vehicle_info[y].person3.age, temp); 

                strcpy(temp, vehicle_info[x].person.name); 
                strcpy(vehicle_info[x].person.name, vehicle_info[y].person.name); 
                strcpy(vehicle_info[y].person.name, temp); 

                strcpy(temp, vehicle_info[x].person2.name); 
                strcpy(vehicle_info[x].person2.name, vehicle_info[y].person2.name); 
                strcpy(vehicle_info[y].person2.name, temp); 

                strcpy(temp, vehicle_info[x].person3.name); 
                strcpy(vehicle_info[x].person3.name, vehicle_info[y].person3.name); 
                strcpy(vehicle_info[y].person3.name, temp); 

                strcpy(temp, vehicle_info[x].person.last_name); 
                strcpy(vehicle_info[x].person.last_name, vehicle_info[y].person.last_name); 
                strcpy(vehicle_info[y].person.last_name, temp); 

                strcpy(temp, vehicle_info[x].person2.last_name); 
                strcpy(vehicle_info[x].person2.last_name, vehicle_info[y].person2.last_name); 
                strcpy(vehicle_info[y].person2.last_name, temp); 
                
                strcpy(temp, vehicle_info[x].person3.last_name); 
                strcpy(vehicle_info[x].person3.last_name, vehicle_info[y].person3.last_name); 
                strcpy(vehicle_info[y].person3.last_name, temp); 

                int_temp = vehicle_info[x].car_found; 
                vehicle_info[x].car_found = vehicle_info[y].car_found; 
                vehicle_info[y].car_found = int_temp;
            }
        }
    }
    printf("Fordonsregistret är nu sorterat\n");
}

void checkVehicle(vehicle vehicle_info[]) {
    int pos;
    char term;
    printf("Ange en position i registret mellan 1-10 som du vill söka efter: ");
    //Safe input för int-variabel 
    if (scanf("%d%c", &pos, &term) != 2 || term != '\n' || pos == 0 || pos > ARRAY_10) {
        printf("Felaktigt alternativ\n");
    }
    else {
        if (vehicle_info[pos-1].car_found) {
            printf("Den angivna positionens registrerade fordon:\n");
            printf("Ägare: %s %s    %s %s    %s %s\nÅlder: %s    %s    %s\nFordonstyp: %s\nBilmärke: %s\nRegistreringsnummer: %s\n", 
            vehicle_info[pos-1].person.name, 
            vehicle_info[pos-1].person.last_name, 
            vehicle_info[pos-1].person2.name, 
            vehicle_info[pos-1].person2.last_name,
            vehicle_info[pos-1].person3.name, 
            vehicle_info[pos-1].person3.last_name, 
            vehicle_info[pos-1].person.age, 
            vehicle_info[pos-1].person2.age, 
            vehicle_info[pos-1].person3.age,
            vehicle_info[pos-1].vehicle_type, 
            vehicle_info[pos-1].vehicle_brand, 
            vehicle_info[pos-1].number_plate);
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
            printf("Fordon %d:\n\tÄgare: %s %s    %s %s    %s %-15s\n\tÅlder: %s    %s    %-5s\n\tFordonstyp: %-10s\n\tBilmärke: %-10s\n\tRegistreringsnummer: %-10s\n", 
            x + 1, 
            vehicle_info[x].person.name, 
            vehicle_info[x].person.last_name, 
            vehicle_info[x].person2.name, 
            vehicle_info[x].person2.last_name, 
            vehicle_info[x].person3.name, 
            vehicle_info[x].person3.last_name, 
            vehicle_info[x].person.age,
            vehicle_info[x].person2.age,
            vehicle_info[x].person3.age, 
            vehicle_info[x].vehicle_type, 
            vehicle_info[x].vehicle_brand, 
            vehicle_info[x].number_plate);
        }
    }
}
//Extrauppgift 2:
void getAllOfOneOwnersVehicles(vehicle vehicle_info[]) {
    int x, has_vehicle = 0;
    char name[ARRAY_50], last_name[ARRAY_50];
    printf("För- och efternamn på ägaren?\n");
    scanf("%s %s", name, last_name);
    printf("Alla fordon som har %s %s som ägare:\n", name, last_name);
    for (x = 0; x < ARRAY_10; x++) {
        if (strcasecmp(name, vehicle_info[x].person.name) == 0 && strcasecmp(last_name, vehicle_info[x].person.last_name) == 0) {
            printf("Fordon %d:\n\tFordonstyp: %s\n\tBilmärke: %s\n\tRegistreringsnummer: %s\n", 
            x + 1,
            vehicle_info[x].vehicle_type, 
            vehicle_info[x].vehicle_brand, 
            vehicle_info[x].number_plate);
            has_vehicle = 1;
        }
    }
    for (x = 0; x < ARRAY_10; x++) {
        if (strcasecmp(name, vehicle_info[x].person2.name) == 0 && strcasecmp(last_name, vehicle_info[x].person2.last_name) == 0) {
            printf("Fordon %d:\n\tFordonstyp: %s\n\tBilmärke: %s\n\tRegistreringsnummer: %s\n", 
            x + 1,
            vehicle_info[x].vehicle_type, 
            vehicle_info[x].vehicle_brand, 
            vehicle_info[x].number_plate);
            has_vehicle = 1;
        }
    }
    for (x = 0; x < ARRAY_10; x++) {
        if (strcasecmp(name, vehicle_info[x].person3.name) == 0 && strcasecmp(last_name, vehicle_info[x].person3.last_name) == 0) {
            printf("Fordon %d:\n\tFordonstyp: %s\n\tBilmärke: %s\n\tRegistreringsnummer: %s\n", 
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
    scanf("%s", reg_number);
    for (x = 0; x < ARRAY_10; x++) {
        if (strcasecmp(reg_number, vehicle_info[x].number_plate) == 0) {
            printf("Ägare:\n\t%s %s    %s %s    %s %s\n", vehicle_info[x].person.name, vehicle_info[x].person.last_name, vehicle_info[x].person2.name, vehicle_info[x].person2.last_name, vehicle_info[x].person3.name, vehicle_info[x].person3.last_name);
            has_owner = 1;
        }
    }
    if (!has_owner) {
        printf("Det finns ingen ägare för det registreringsnumret du angav\n");
    }
}
//Extrauppgift 4:
void getOneVehicleProperty(vehicle vehicle_info[]) {
    int x, vehicle, has_owner = 0;
    char reg_number[ARRAY_50], property;
    printf("Skriv registreringsnumret till fordonet du vill veta en egenskap för: ");
    scanf("%s", reg_number);
    for (x = 0; x < ARRAY_10; x++) {
        if (strcasecmp(reg_number, vehicle_info[x].number_plate) == 0) {
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
        scanf(" %c", &property);
        switch (property) {
            case '1': 
                printf("Fordonstyp: %s\n", vehicle_info[vehicle].vehicle_type);
                break;
            case '2':
                printf("Fordonstyp: %s\n", vehicle_info[vehicle].vehicle_brand);
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
    char reg_number[ARRAY_50], property, answer;
    printf("Skriv registreringsnumret till fordonet du vill veta några egenskaper för: ");
    scanf("%s", reg_number);
    for (x = 0; x < ARRAY_10; x++) {
        if (strcasecmp(reg_number, vehicle_info[x].number_plate) == 0) {
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
        scanf(" %c", &property);
        switch (property) {
            case '1': 
                printf("Fordonstyp: %s\n", vehicle_info[vehicle].vehicle_type);
                printf("Vill du även veta bilmärke?\n\t1. Ja\n\t2. Nej\n");
                scanf(" %c", &answer);
                if (answer == '1') {
                    printf("Bilmärke: %s\n", vehicle_info[vehicle].vehicle_brand);    
                }
                if (answer == '2') {
                    printf("Skriver inte ut bilmärke\n");
                }
                if (answer != '1' && answer != '2') {
                    printf("Felaktigt alternativ\n");
                }
                break;
            case '2':
                printf("Bilmärke: %s\n", vehicle_info[vehicle].vehicle_brand);
                printf("Vill du även veta fordonstyp?\n\t1. Ja\n\t2. Nej\n");
                scanf(" %c", &answer);
                if (answer == '1') {
                    printf("Fordonstyp: %s\n", vehicle_info[vehicle].vehicle_brand);    
                }
                if (answer == '2') {
                    printf("Skriver inte ut bilmärke\n");
                }
                if (answer != '1' && answer != '2') {
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
            if (y != 10) {
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

/* OBS Denna kan vara bra att kika på om man vill invertera char till int
int checkAge(vehicle vehicle_info[], int y, int ctrl3) {
    char *end_ptr;
    char age[ARRAY_50];
    long number;
    int base = 10, age_ctrl;
    if (ctrl3 == 1) {
        strcpy(age, vehicle_info[y].person.age);
    }
    if (ctrl3 == 2) {
        strcpy(age, vehicle_info[y].person2.age);
    }
    if (ctrl3 == 3) {
        strcpy(age, vehicle_info[y].person3.age);
    }
    number = strtol(age, &end_ptr, base);
    printf("number=%li\n", number);
    if (*end_ptr) {
        printf("Error\n");
    }
    else {
        if(number > TOO_YOUNG && number < TOO_OLD) {
            age_ctrl = 1;
        }
        else {
            age_ctrl = 0;
        }
    }
    return age_ctrl;
}*/
