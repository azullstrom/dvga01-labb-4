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

//Lägg till fordon
void addVehicle();

//Ta bort fordon
void rmVehicle();

//Sortering efter bilmärke
void sortVehicleBrand();

//Skriv ut information om ett fordon
void checkVehicle();

//Skriv ut hela fordonsregistret
void printVehicleRegister();

//Avsluta
void exitProgram();

//Sök efter en persons registrerade fordon
void getAllOfOneOwnersVehicles();

//Sök efter ett specifikt fordons ägare
void getOwnerOfCertainVehicle();

//Sök efter någon av ett fordons egenskaper
void getOneVehicleProperty();

//Sök efter kombinationer om ett fordons egenskaper
void getComboVehicleProperty();

//Ta fram nästa lediga element
int getFirstFreeIndex();

//Ta fram första tagna element
int getFirstTakenIndex();

//Ta fram nästa tagna element
int getSecondTakenIndex();

int checkAge();

//Poster (Structures)
struct person{
    char name[ARRAY_50];
    char last_name[ARRAY_50];
    char age[ARRAY_50];
};

struct person2{
    char name[ARRAY_50];
    char last_name[ARRAY_50];
    char age[ARRAY_50];
};

struct person3{
    char name[ARRAY_50];
    char last_name[ARRAY_50];
    char age[ARRAY_50];
};

typedef struct vehicle{
    int car_found;
    char vehicle_type[ARRAY_50];
    char vehicle_brand[ARRAY_50];
    char number_plate[ARRAY_50];
    struct person person;
    struct person2 person2;
    struct person3 person3;
}vehicle;

#endif