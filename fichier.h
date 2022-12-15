#ifndef FICHIER_H
#define FICHIER_H
#endif
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include<stdbool.h>

typedef struct Liste Liste;
typedef struct ListeDoss ListeDoss;


typedef enum Status Status;
enum Status
{

    EN_COURS_D_INSTRUCTION, CLOTURE, ANNULE
};

typedef struct Collaborateur Collaborateur;
struct Collaborateur
{

     char nom[128];
    char prenom[128];
    char fonction[128];
    unsigned int matricule;
    char **suivi;
    unsigned int nbreDoss;
    Collaborateur *suivant;
    
};

typedef struct Dossier Dossier;
struct Dossier
{

    char nom_dossier[128];
    int open_date[3];
    int closed_date[3];
    Status etat_dossier;
    Collaborateur *collabo;
    Liste *assistant;
    unsigned int num_dossier;
    Dossier *suivant;
};

struct Liste{
    Collaborateur *collabFirst; 
};
struct ListeDoss{

    Dossier *Dossier_first;
};

////////////////////////begin_of_Collab_GESTION///////////////////

Liste* InitialisationListeAssist();//validé
void insert(Liste* liste,Collaborateur *collabo);//validé
void deleteElement(Liste *liste,Collaborateur *cible);//validé
void deleteListe(Liste *listsuppr);//validé
void afficherListe(Liste *myliste); ///validé
void afficherCollab(Collaborateur* collab);//validé
void dossierSuivi(Collaborateur* collab,char *name);//validé


Collaborateur* rechercheCollaborateur(Liste* liste,unsigned int matricule);//validé
Collaborateur* rechercheCollaborateurNom(Liste* liste,char *nom);//validé!
void modifierCollab(Collaborateur* tomdify);//validé
void AfficherListeDossSuivi(Collaborateur *collab);//validé
/////////////////// END OF ASSISTANT_GESTION //////////////////

void vidBuff();//validé



/////////////////// begin of Gestion dossier //////////////////

Dossier* creation_dossier();//validé
void suppression_Dossier(Dossier *mydossier);//validé
Dossier* rechercheDossier(ListeDoss* liste,unsigned int cible);//validé
Dossier* rechercheDossierNom(ListeDoss* liste,char *cible);//validé
void AfficherDossier(Dossier* mydossier);//validé
void AfficherDossierNom(ListeDoss* mydossier,char *nom);//validé!
void modifierDossier(Dossier* tomodify,Liste* liscollab);//validé
void cloturerDossier(Dossier *tocloturer);//validé




ListeDoss* InitialisationListeDossier();//validé
void insertDossier(ListeDoss* liste,Dossier *newDossier);//validé
void deleteElementDossier(ListeDoss *liste,Dossier *cible);//validé
void deleteListeDossier(ListeDoss *listsuppr);//validé
void afficherListeDossier(ListeDoss *myliste); //validé




///////////// gestion du menu de commande  ///////////////

void Affichage_du_menu();
void fonc1(ListeDoss *mydoss,Liste *coll);
void fonc2(ListeDoss* mylist);
void fonc5(Liste *mylist);
void fonc6(ListeDoss* mylist);
void fonc7(ListeDoss *mylist);
void fonc8(ListeDoss* mylist,Liste* mine);
void fonc9(Liste* mylist);
void fonc10(Liste* mylist);



///////////// gestion d'enregistrement et de chargement ///////////////

void enregistrerListe(Liste *myliste);//validé
Liste* chargerListe();//validé
void createCollab(Liste *myliste);//validé
void deleteCollab(Liste *myliste,unsigned int matricule);//validé

void enregistrerListeDossier(ListeDoss *myliste);//no implé
ListeDoss* chargerListeDossier(Liste *listecollab);//no implé
void ajouterDossier(ListeDoss *myliste,Liste *listecollab);
void nomSauvegarder();//validé



/////////////////gestion ds statistiques/////////////////

unsigned int nbreCollaborateur();
unsigned int nbreMoyendossparCollab();
unsigned int nbreMAxdoss(Liste * myliste);
char *nomdesVieuxdocs(ListeDoss *mydoss);

