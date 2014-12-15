//
//  main.c
//  Adressbuch
//
//  Created by Rudolf Nitsche on 14/12/14.
//  Copyright (c) 2014 red. All rights reserved.
//

#include <stdio.h>
#include "Adressbuch.h"
#include <stdlib.h>


int main(int argc, const char * argv[])
{
    // Liste und Variablen deklarieren
    PersonListEntry* List = NULL;
    PersonListEntry* newEntry = NULL;
    char input;
    int position;

    
    printf("--- Adressbuch --- Rudolf Nitsche, 4AHEL");
    
    int running = 1;
    while (running) {
        printf("\n\n\nMenü: \n");
        printf("n... Neuer Eintrag\n");
        printf("p... Person anzeigen\n");
        printf("l... Eintrag löschen\n");
        printf("m... Nachnamen suchen\n\n");
        
        printf("a... Liste anzeigen\n");
        printf("o... Liste lesen\n");
        printf("v... Liste speichern\n");
        //printf("t... Liste Sortieren\n");
        printf("d... Liste löschen\n");
        printf("x... Exit\n\n");

        printf("-> ");
        scanf("\n%c", &input);
        getchar();
        
        switch (input) {
            case 'n':
                if( !List ) continue;
                
                // Neuen Personen-Eintrag erstellen.
                newEntry = (PersonListEntry*) malloc(sizeof(PersonListEntry));
                PersonListEntry_CreateListEntry(newEntry);
                
                //To do:
                // Fehlerbehandlung: ob kein Vorname oder keine Tel.nr angegegeben wurde.
                if(List)
                {
                    PersonListEntry_AddListEntry(List, newEntry);
                }
                else
                {
                    // Es existiert noch keine Liste -> der neue Eintrag ist die neue Liste
                    List = newEntry;
                }
                break;
            
            case 'p':
                if( !List ) continue;
                
                printf("Welche Person anzeigen?: ");
                scanf("%d", &position);
                
                PersonListEntry_OutputListEntry(List, position);
                break;
                
            case 'l':
                if( !List ) continue;
                
                printf("Welchen Eintrag löschen?: ");
                scanf("%d", &position);
                
                PersonListEntry_DeleteListEntry(List, position);
                break;
                
            case 'a':
                if( !List ) continue;
                
                printf("Alle Personen: \n");
                
                PersonListEntry_OutputAll(List);
                break;
                
            case 'm':
                {
                    if( !List ) continue;
                
                    char name[MAX_NAME_LEN];
                    printf("Welchen Nachnamen suchen?: ");
                    scanf("\n%s", name);
                    getchar();
                
                    PersonListEntry_SearchListEntrys(List, name);
                }
                break;
            
            case 'v':
                if( !List ) continue;
                
                printf("Datei schreiben ...");
                
                PersonListEntry_SaveAllToDisk(List);
                break;
                
            case 'o':
                printf("Datei laden ...");
                
                if (List) PersonListEntry_DeleteAll(List);
                List = NULL;
                
                PersonListEntry_LoadAllFromDisk(&List);
                break;
                
            case 'd':
                if (List) {
                    PersonListEntry_DeleteAll(List);
                    List = NULL;
                }
                break;
            
            case 't':
                if( List )
                {
                    PersonListEntry_SortAll(&List);
                }
                break;             
                
            case 'x':
                running = 0;
                break;
                
            default:
                continue;
        }
    }
    
    
    return 0;
}
