#ifndef LABB4FILE_H
#define LABB4FILE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Globaler
#define ARRAY_10 10
#define ARRAY_50 50
#define LAST_ELEMENT 9
#define FIRST_ELEMENT 0
#define OWNER_TWO 1
#define OWNER_THREE 2
#define TWO 2
#define OWNER_LIMIT 3
#define TOO_YOUNG 17
#define TOO_OLD 100

//Poster (Structures)
struct person{
    char name[ARRAY_50];
    char age[ARRAY_50];
};

struct person2{
    int exist;
    char name[ARRAY_50];
    char age[ARRAY_50];
};

struct person3{
    int exist;
    char name[ARRAY_50];
    char age[ARRAY_50];
};

typedef struct vehicle{
    char vehicle_type[ARRAY_50];
    char vehicle_brand[ARRAY_50];
    char number_plate[ARRAY_50];
    struct person person;
    struct person2 person2;
    struct person3 person3;
}vehicle;

void printMenu();

//Lägg till fordon
void addVehicle(vehicle vehicle_info[], int n);

//Ta bort fordon
int rmVehicle(vehicle vehicle_info[], int n);

//Sortering efter bilmärke
void sortVehicleBrand(vehicle vehicle_info[], int n);

//Skriv ut information om ett fordon
void checkVehicle(vehicle vehicle_info[], int n);

//Skriv ut hela fordonsregistret
void printVehicleRegister(vehicle vehicle_info[], int n);

//Avsluta
void exitProgram(vehicle vehicle_info[], int n);

//Sök efter en persons registrerade fordon
void getAllOfOneOwnersVehicles(vehicle vehicle_info[]);

//Sök efter ett specifikt fordons ägare
void getOwnerOfCertainVehicle(vehicle vehicle_info[]);

//Sök efter någon av ett fordons egenskaper
void getOneVehicleProperty(vehicle vehicle_info[]);

//Sök efter kombinationer om ett fordons egenskaper
void getComboVehicleProperty(vehicle vehicle_info[]);

//Ta fram nästa lediga element
int getFirstFreeIndex(vehicle vehicle_info[]);

#endif