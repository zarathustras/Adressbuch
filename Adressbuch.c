//
//  Adressbuch.c
//  Adressbuch
//
//  Created by Rudolf Nitsche on 14/12/14.
//  Copyright (c) 2014 red. All rights reserved.
//

#include "Adressbuch.h"
#include <stdlib.h>
#include <string.h>

void ReadStr(char* str)
{
    for(;;)
    {
        char c = getchar();
        if( c == '\n' ) break;
        *str = c;
        str++;
    }
    
}

void Name_Create(Name* this)
{
    for (int i = 0; i < NUM_SURNAMES; i++) {
        
        printf("%d. Vorname: ", i + 1);
        this->surNames[i][0] = '\0';
        ReadStr(this->surNames[i]);
        
        if( !strlen(this->surNames[i]) ) break;
        //fgets(this->surNames[i], NUM_SURNAMES, stdin);
    }

    printf("Nachname: ");
    scanf("\n%s", this->lastName);
    getchar();
}
void Datum_Create(Datum* this)
{
    printf("Tag: ");
    scanf("%d", &this->day);
    
    printf("Monat: ");
    scanf("%d", &this->month);
    
    printf("Jahr: ");
    scanf("%d", &this->year);
}

void Address_Create(Address* this)
{
    printf("Straße: ");
    scanf("\n%s", this->street);
    getchar();
    //fgets(this->street, MAX_STREET_LEN, stdin);
    
    printf("Nr: ");
    scanf("%d", &this->number);
    
    printf("PLZ: ");
    scanf("%d", &this->postcode);
    
    printf("Ort: ");
    scanf("\n%s", this->city);
    getchar();
    //fgets(this->city, MAX_COUNTRY_LEN, stdin);
    
    printf("Land: ");
    scanf("\n%s", this->country);
    getchar();
    //fgets(this->country, MAX_COUNTRY_LEN, stdin);
}

void Contact_Create(Contact* this)
{
    for (int i = 0; i < NUM_TELNUMBERS; i++) {
        
        printf("Telefonnr %d: ", i + 1);
        this->tel[i][0] = '\0';
        ReadStr(this->tel[i]);
        //fgets(this->tel[i], MAX_TEL_LEN, stdin);
        if( !strlen(this->tel[i] )) break;
    }
    
    printf("Email Adresse: ");
    scanf("\n%s", this->email);
    getchar();
    //fgets(this->email, MAX_EMAIL_LEN, stdin);
}



void PersonListEntry_CreateListEntry(PersonListEntry* this)
{
    Name_Create(&this->person.name);
    Datum_Create(&this->person.datum);
    Address_Create(&this->person.address);
    Contact_Create(&this->person.contact);
    
    this->next = this->prev = NULL;
}



void PersonListEntry_AddListEntry(PersonListEntry* this, PersonListEntry *new)
{
    //Finde das letzte Element der Liste
    PersonListEntry* end = this;
    while( end->next )
    {
        end = end->next;
    }
    
    
    end->next = new;
    new->prev = end;
}

void PersonListEntry_SearchListEntrys(PersonListEntry* this, char* name)
{
    PersonListEntry* current = this;
    int count = 1;
    
    while(current)
    {
        int ret = strncmp(current->person.name.lastName, name, strlen(name));
        
        if (!ret)
        {
            PersonListEntry_OutputListEntry(this, count - 1);
        }
        
        if (current->next)
        {
            current = current->next;
            count++;
        }
        else
        {
            return;
        }
    }
    
    printf("Kein Eintrag gefunden?\n");
}


void PersonListEntry_DeleteListEntry(PersonListEntry* this, int position)
{
    PersonListEntry* current = this;
    
    
    for (int i = 0; i < position; i++)
    {
        if (current)
        {
            current = current->next;
        }
        else
        {
            printf("Kein Eintrag gefunden?\n");
            break;
        }
    }
    
    if (current)
    {
        if(current->prev) current->prev->next = current->next;
        if(current->next) current->next->prev = current->prev;
        free(current);
    }
}

void PersonListEntry_OutputListEntry(PersonListEntry* this, int position)
{
    PersonListEntry* ret = this;
    for (int i = 0; i < position; i++)
    {
        // Verhindet zu großen position
        if(!ret)
        {
            break;
        }
        // Hangelt sich von Liste zu Liste
        ret = ret->next;
    }
    
    if(ret)
    {
        // printf entry
        for (int i = 0; i < NUM_SURNAMES; i++) {
            
            if(!strlen(ret->person.name.surNames[i]))
            {
                break;
            }
            
            printf("%d. Vorname: %s\n", i + 1, ret->person.name.surNames[i]);
        }
        printf("Nachname: %s\n", ret->person.name.lastName);
        
        printf("Tag: %d\n", ret->person.datum.day);
        printf("Monat: %d\n", ret->person.datum.month);
        printf("Jahr: %d\n", ret->person.datum.year);
        
        printf("Straße: %s\n", ret->person.address.street);
        printf("Nr: %d\n", ret->person.address.number);
        printf("PLZ: %d\n", ret->person.address.postcode);
        printf("Ort: %s\n", ret->person.address.city);
        printf("Land: %s\n", ret->person.address.country);
        
        for (int i = 0; i < NUM_TELNUMBERS; i++) {
                   
            if(!strlen(ret->person.contact.tel[i]))
            {
                break;
            }
            
            printf("Telefonnr %d: %s\n", i + 1, ret->person.contact.tel[i]);
        }
        printf("Email: %s\n", ret->person.contact.email);
        
        
    }
    else
    {
        printf("Zu Hoher Index!");
    }
}

void PersonListEntry_OutputAll(PersonListEntry* this){
    
    PersonListEntry* current = this;
    do
    {
        // printf entry
        for (int i = 0; i < NUM_SURNAMES; i++) {
            
            if(!strlen(current->person.name.surNames[i]))
            {
                break;
            }
            
            printf("%d. Vorname: %s\n", i + 1, current->person.name.surNames[i]);
        }
        printf("Nachname: %s\n", current->person.name.lastName);
        
        printf("Tag: %d\n", current->person.datum.day);
        printf("Monat: %d\n", current->person.datum.month);
        printf("Jahr: %d\n", current->person.datum.year);
        
        printf("Straße: %s\n", current->person.address.street);
        printf("Nr: %d\n", current->person.address.number);
        printf("PLZ: %d\n", current->person.address.postcode);
        printf("Ort: %s\n", current->person.address.city);
        printf("Land: %s\n", current->person.address.country);
        
        for (int i = 0; i < NUM_TELNUMBERS; i++) {
            
            if(!strlen(current->person.contact.tel[i]))
            {
                break;
            }
            
            printf("Telefonnr %d: %s\n", i + 1, current->person.contact.tel[i]);
        }
        printf("Email: %s\n\n\n", current->person.contact.email);
        
        current = current->next;
        
    }while(current);
    
}

void PersonListEntry_DeleteAll(PersonListEntry* this)
{
    PersonListEntry* current = this;
    do
    {
        PersonListEntry* tmp = current->next;
        free(current);
        current = tmp;
        
    } while(current);
}

void PersonListEntry_SaveAllToDisk(PersonListEntry* this)
{
    FILE *pFile;
    
    if(!this) {
        printf("Fehler! - Liste ist leer.");
    }
    
    pFile = fopen("PersonList.txt", "w");
    
    if(!pFile) {
        printf("Fehler! - Datei kann nicht geschrieben werden.");
        return;
    }
    
    PersonListEntry* current = this;
    
    while(current) {
        fprintf(pFile, "Name: %s\n", current->person.name.lastName);
        
        for (int i = 0; i < NUM_SURNAMES; i++)
        {
            if( !strlen(current->person.name.surNames[i]) ) break;
            fprintf(pFile, "Vorname %d: %s\n", i, current->person.name.surNames[i]);
        }
        
        fprintf(pFile, "Tag: %d\n", current->person.datum.day);
        fprintf(pFile, "Monat: %d\n", current->person.datum.month);
        fprintf(pFile, "Jahr: %d\n", current->person.datum.year);
        fprintf(pFile, "Strasse: %s\n", current->person.address.street);
        fprintf(pFile, "Nr.: %d\n", current->person.address.number);
        fprintf(pFile, "PLZ: %d\n", current->person.address.postcode);
        fprintf(pFile, "Stadt: %s\n", current->person.address.city);
        fprintf(pFile, "Land: %s\n", current->person.address.country);
        fprintf(pFile, "Email: %s\n", current->person.contact.email);
        
        for (int i = 0; i < NUM_TELNUMBERS; i++)
        {
            if( !strlen(current->person.contact.tel[i]) ) break;
            fprintf(pFile, "Telefon: %s\n", current->person.contact.tel[i]);
        }
        
        fprintf(pFile, "---\n");
        current = current->next;
    }
    fclose(pFile);
    pFile = NULL;
}

void PersonListEntry_LoadAllFromDisk(PersonListEntry** this)
{
    FILE *pFile;
    
    pFile = fopen("PersonList.txt", "r");
    
    if (!pFile) {
        printf("Fehler! - Datei kann nicht gelesen werden.");
        return;
    }
  
    
    char linebuffer[MAX_BUFFER_LEN * 2];
    PersonListEntry *last = NULL;
    
    while( !feof(pFile) ) {
        PersonListEntry* current = (PersonListEntry*)malloc(sizeof(PersonListEntry));
        current->prev = *this;
        current->next = NULL;
        
        if(*this)
        {
            if(last)
            {
                last->next = current;
                current->prev = last;
            }
            else
            {
                (*this)->next = current;
                current->prev = *this;
            }
        }
        else
        {
            *this = current;
        }
        
        
        
        fscanf(pFile, "Name: %s\n", current->person.name.lastName);
        
        for (int i = 0; i < NUM_SURNAMES; i++)
        {
            int inty;
            fpos_t posOld = ftell(pFile);
            fgets(linebuffer, MAX_BUFFER_LEN * 2, pFile);
            if( sscanf(linebuffer, "Vorname %d: %s\n", &inty, current->person.name.surNames[i]) == 0 )
            {
                fsetpos(pFile, &posOld);
                break;
            }
            //fscanf(pFile, "Vorname %d: %s\n", &inty, current->person.name.surNames[i]);
        }
        
        fscanf(pFile, "Tag: %d\n", &current->person.datum.day);
        fscanf(pFile, "Monat: %d\n", &current->person.datum.month);
        fscanf(pFile, "Jahr: %d\n", &current->person.datum.year);
        fscanf(pFile, "Strasse: %s\n", current->person.address.street);
        fscanf(pFile, "Nr.: %d\n", &current->person.address.number);
        fscanf(pFile, "PLZ: %d\n", &current->person.address.postcode);
        fscanf(pFile, "Stadt: %s\n", current->person.address.city);
        fscanf(pFile, "Land: %s\n", current->person.address.country);
        fscanf(pFile, "Email: %s\n", current->person.contact.email);
        
        for (int i = 0; i < NUM_TELNUMBERS; i++)
        {
            fpos_t posOld = ftell(pFile);
            fgets(linebuffer, MAX_BUFFER_LEN * 2, pFile);
            if( sscanf(linebuffer, "Telefon: %s\n", current->person.contact.tel[i]) == 0 )
            {
                fsetpos(pFile, &posOld);
                break;
            }
            //fscanf(pFile, "Telefon: %s\n", current->person.contact.tel[i]);
        }
        
        fscanf(pFile, "---\n");
        
        last = current;
    }
    
    fclose(pFile);
    return;
}


void PersonListEntry_SortAll(PersonListEntry** this)
{
    PersonListEntry *list = *this;
    
    //Finde den Namen mit dem kleinstem char als Anfangsbuchstaben.
    PersonListEntry *cur = list;
    PersonListEntry *smallest = list;
    for(; cur; cur = cur->next)
    {
        if( smallest->person.name.lastName[0] == '\0' ) smallest = cur;
        else smallest = cur->person.name.lastName[0] < smallest->person.name.lastName[0] ? cur : smallest;
    }
    
    
    //Entferne smallest aus der alten Liste.
    // smallest bildet nun den Anfang der neuen, sortierten Liste.
    if( smallest == list ) list = smallest->next;
    if( smallest->prev ) smallest->prev->next = smallest->next;
    if( smallest->next ) smallest->next->prev = smallest->prev;
    smallest->prev = smallest->next = NULL;
    
    
    
    for(cur = list; cur;)
    {
        //Finde den kleinsten Anfangsbuchstaben aller Nachnamen der alten Liste.
        PersonListEntry *_smallest_ = cur;
        for(; cur; cur = cur->next)
        {
            if( _smallest_->person.name.lastName[0] == '\0' ) _smallest_ = cur;
            else _smallest_ = cur->person.name.lastName[0] < _smallest_->person.name.lastName[0] ? cur : _smallest_;
        }
        
        
        //_smallest_ enthält nun den "kleinsten" Nachnamen.
        // Entferne _smallest_ aus der alten Liste.
        // Füge diesen nun zur neuen hinzu.
        int endloop = 0;
        if( _smallest_ == list )
        {
            //Wenn _smallest_ gleich list ist ==> der Listenanfang ist dann
            // wenn es kein nächstes Element gibt, dann kann die Schleife beendet werden, weil es nichts mehr zu sortieren gibt oO :D
            // ansonsten existiert noch min. ein Element ==> der alte Listenanfang muss neu gesetzt werden.
            if( _smallest_->next == NULL ) endloop = 1;
            else list = _smallest_->next;
        }
        if( _smallest_->prev ) _smallest_->prev->next = _smallest_->next;
        if( _smallest_->next ) _smallest_->next->prev = _smallest_->prev;
        _smallest_->next = _smallest_->prev = NULL;
        PersonListEntry_AddListEntry(smallest, _smallest_);        
        
        if( endloop ) break;
    }
    
    *this = smallest;
}



