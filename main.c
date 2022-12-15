#include "fichier.h"

int main(void)
{
    /////////////////////// Unit_Test of collaborateur,Status,Dossier,ListeAssistant,Creation_listassist/////

     /* Liste* mylist=InitialisationListeAssist();
     Collaborateur *col1=malloc(sizeof(Collaborateur));
      Collaborateur* col2=malloc(sizeof(Collaborateur));
      Collaborateur* col3=malloc(sizeof(Collaborateur));
      Collaborateur* col4=malloc(sizeof(Collaborateur));

      strcpy(col1->prenom,"charles");
      strcpy(col2->prenom,"djikako");
      strcpy(col3->prenom,"diatta");
      strcpy(col4->prenom,"ophelie");

      col1->matricule=0;
      col2->matricule=1;
      col3->matricule=2;
      col4->matricule=3;
   

      insert(mylist,col1);
      insert(mylist,col2);
      insert(mylist,col3);
      insert(mylist,col4);


      Collaborateur * test=rechercheCollaborateurNom(mylist,"ophelie");

      test->nbreDoss=3;
      test->suivi=malloc(3*sizeof(char));

      test->suivi[0]=malloc(strlen("bonjour")*sizeof(char));
      strcpy(test->suivi[0],"bonjour");

      test->suivi[1]=malloc(strlen("bonsoir")*sizeof(char));
      strcpy(test->suivi[1],"bonsoir");

      test->suivi[2]=malloc(strlen("djikako")*sizeof(char));
      strcpy(test->suivi[2],"djikako");
      
      test->nbreDoss=1;
      dossierSuivi(test,"bonjour");
      test->nbreDoss=2;
      dossierSuivi(test,"bonsoir");
      test->nbreDoss=3;
      dossierSuivi(test,"djikako");

      AfficherListeDossSuivi(test);

      free(test->suivi);
      deleteListe(mylist);

     



      free(mylist);



    
    ListeDoss *mylist=InitialisationListeDossier();

    Dossier* mydoss1=creation_dossier();

    insertDossier(mylist,mydoss1);


    AfficherDossierNom(mylist,"djikako");
    
    

   AfficherDossierNom(mylist,"djikako");


    deleteListeDossier(mylist);


    afficherListeDossier(mylist);
    









  
   





nomSauvegarder();

createCollab(mylist);
createCollab(mylist);
afficherListe(mylist);
deleteCollab(mylist,1);
afficherListe(mylist);






























 free(mylist);



























 

 
   
    

Collaborateur* collab=malloc(sizeof(Collaborateur));
strcpy(collab->nom,"franky");
collab->matricule=1253;

Dossier* doss1=malloc(sizeof(Dossier));
strcpy(doss1->nom_dossier,"k-fin");
doss1->open_date[0]=10;
doss1->open_date[1]=12;
doss1->open_date[2]=2010;
doss1->etat_dossier=EN_COURS_D_INSTRUCTION;
doss1->num_dossier=25601;
doss1->collabo=collab;
doss1->assistant=InitialisationListeAssist();
doss1->assistant->collabFirst=collab;

Dossier* doss2=malloc(sizeof(Dossier));
strcpy(doss2->nom_dossier,"PreSsens");
doss2->open_date[0]=10;
doss2->open_date[1]=12;
doss2->open_date[2]=2010;
doss2->etat_dossier=EN_COURS_D_INSTRUCTION;
doss2->num_dossier=25602;
doss2->collabo=collab;
doss2->assistant=InitialisationListeAssist();
doss2->assistant->collabFirst=collab;

ListeDoss *mylist=InitialisationListeDossier();
insertDossier(mylist,doss1);
insertDossier(mylist,doss2);
afficherListeDossier(mylist);

enregistrerListeDossier(mylist);

free(doss1->assistant);
free(doss2->assistant);
free(collab);
free(doss1);
free(doss2);
free(mylist);

Liste*lisc=InitialisationListeAssist();
insert(lisc,collab);
ListeDoss* list=chargerListeDossier(lisc);


free(list);*/
Affichage_du_menu();




    return EXIT_SUCCESS;
}