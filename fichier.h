#ifndef FICHIER_H
#define FICHIER_H
#include <stdlib.h> 
#include <stdio.h>
typedef struct ListeAssistant ListeAssistant;
struct ListeAssistant;
typedef enum Status Status;
enum Status{

    EN_COURS_D_INSTRUCTION, CLOTURE, ANNULE
};

typedef struct Collaborateur Collaborateur;
struct Collaborateur{

     char nom[128];
    char prenom[128];
    char fonction[128];
    ListeAssistant *assistant;
    Collaborateur *suivant;
};

typedef struct Dossier Dossier;
struct Dossier{

    char nom_dossier[128];
    int open_date[3];
    int closed_date[3];
    Status etat_dossier;
    Collaborateur *collabo; //tableau dynamique de collaborateur
};
struct ListeAssistant{
    Collaborateur *collabFirst; 
};

////////////////////////begin_of_Assitant_GESTION///////////////////

ListeAssistant* InitialisationListeAssist();
void insert(ListeAssistant* liste,Collaborateur *collabo);
void deleteElement(ListeAssistant *liste,Collaborateur *cible);
void deleteListeAssistant(ListeAssistant *listsuppr);
///////////////////END OF ASSISTANT_GESTION//////////////////

void vidBuff();



///////////////////begin of Creation_de dossier //////////////////
Dossier* creation_dossier();
void suppression_Dossier(Dossier *mydossier);


#endif