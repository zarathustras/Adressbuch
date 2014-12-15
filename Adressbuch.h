//
//  Adressbuch.h
//  Adressbuch
//
//  Created by Rudolf Nitsche on 14/12/14.
//  Copyright (c) 2014 red. All rights reserved.
//

#ifndef __Adressbuch__Adressbuch__
#define __Adressbuch__Adressbuch__

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 30
#define MAX_STREET_LEN 50
#define MAX_COUNTRY_LEN 50
#define MAX_TEL_LEN 20
#define MAX_EMAIL_LEN 20
#define MAX_BUFFER_LEN MAX_COUNTRY_LEN

#define NUM_TELNUMBERS 5
#define NUM_SURNAMES 3

typedef struct Name{
    char surNames[NUM_SURNAMES][MAX_NAME_LEN];
    char lastName[MAX_NAME_LEN];
} Name;

typedef struct Datum{
    int day;
    int month;
    int year;
} Datum;

typedef struct Address{
    char street[MAX_STREET_LEN];
    int number;
    int postcode;
    char city[MAX_COUNTRY_LEN];
    char country[MAX_COUNTRY_LEN];
} Address;

typedef struct Contact{
    char tel[NUM_TELNUMBERS][MAX_TEL_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

typedef struct Person{
    Name name;
    Datum datum;
    Address address;
    Contact contact;
} Person;


typedef struct PersonListEntry{
    Person person;
    struct PersonListEntry* prev;
    struct PersonListEntry* next;
} PersonListEntry;



void Name_Create(Name* this);
void Datum_Create(Datum* this);
void Address_Create(Address* this);
void Contact_Create(Contact* this);

void ReadStr(char* str);

void PersonListEntry_CreateListEntry(PersonListEntry* this);
void PersonListEntry_AddListEntry(PersonListEntry* this, PersonListEntry* new);
void PersonListEntry_SearchListEntrys(PersonListEntry* this, char* name);
void PersonListEntry_DeleteListEntry(PersonListEntry* this, int position);
void PersonListEntry_DeleteAll(PersonListEntry* this);
void PersonListEntry_OutputListEntry(PersonListEntry* this, int position);
void PersonListEntry_OutputAll(PersonListEntry* this);

void PersonListEntry_SaveAllToDisk(PersonListEntry* this);
void PersonListEntry_LoadAllFromDisk(PersonListEntry** this);
void PersonListEntry_SortAll(PersonListEntry** this);


#endif /* defined(__Adressbuch__Adressbuch__) */
