#include"fichier.h"



////////////////////////begin_of_Assitant_GESTION///////////////////


ListeAssistant* InitialisationListeAssist()
{
ListeAssistant* myliste=malloc(sizeof(ListeAssistant));
    if(!myliste)

    {
           fprintf(stderr," erreur lors de la création de la liste",NULL);
            exit(EXIT_FAILURE);
    }
    myliste->collabFirst=NULL;
   return myliste;

}
void insert(ListeAssistant* liste,Collaborateur *collabo)
{
    if(liste==NULL)
        liste=InitialisationListeAssist();

    if(liste->collabFirst==NULL)
       { liste->collabFirst=collabo;
        liste->collabFirst->suivant=NULL;
       }

    else 
    {
        Collaborateur *temp=liste->collabFirst;
        liste->collabFirst=collabo;
        collabo->suivant=temp;
        free (temp);
    }
}
void deleteElement(ListeAssistant *liste,Collaborateur *cible)
 {
     if(liste==NULL)
        printf("Gros y'a rien dedans\n");
        return;

    if(liste->collabFirst==cible)

        liste->collabFirst=cible->suivant;

    else 
    { 
        Collaborateur* temp=liste->collabFirst;
        while(temp->suivant!=cible)
        {
            temp=temp->suivant;
        }
        temp->suivant=cible->suivant;
        free (temp);

    }

 }
 void deleteListeAssistant(ListeAssistant *listsuppr)
 {
     Collaborateur* temp=listsuppr->collabFirst;
     while (temp!=NULL)
     {
         deleteElement(listsuppr,temp);
         temp=listsuppr->collabFirst;
     }
     free(temp);
 }

 void vidBuff()
{
    char c=0;
     while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}


 ///////////////////END OF ASSISTANT_GESTION//////////////////



///////////////////begin of Creation_de dossier //////////////////
Dossier* creation_dossier()
{
    Dossier *mydossier=malloc(sizeof(Dossier));
    mydossier->etat_dossier=EN_COURS_D_INSTRUCTION;
    mydossier->collabo=malloc(sizeof(Collaborateur));
    ListeAssistant* theAssist=NULL;
    int nbAssist=0;
    printf("===========\t\tCréation d'un nouveau dossier============\t\n");


    printf("\tEntrer le nom du dossier\n");
    scanf("%s",mydossier->nom_dossier);

    vidBuff();

    printf("\tEntrer le jour de creation du dossier\n");
    scanf("%d",&(mydossier->open_date[0]));
    
     vidBuff();

    printf("\tEntrer le mois de creation du dossier\n");
    scanf("%d",&(mydossier->open_date[1]));

     vidBuff();

    printf("\tEntrer l'annee de creation du dossier\n");
    scanf("%d",&(mydossier->open_date[2]));

    vidBuff();

    printf("\tEntrer le nom du responsable\n");
    scanf("%s",mydossier->collabo->nom);

     vidBuff();

    printf("\tEntrer le prenom du responsable\n");
    scanf("%s",mydossier->collabo->prenom);

    vidBuff();

    do{
        printf("il y'a combien d'assistant minimum 1");
    scanf("%d",&nbAssist);
    vidBuff();
        }
    while(nbAssist<=0);

    theAssist=InitialisationListeAssist();

    for(int i=0;i<nbAssist;++i)
    {   
        Collaborateur *assist=malloc(sizeof(Collaborateur));
        assist->assistant=NULL;

        printf("Quel est le nom de l'assistant:%d \n",i+1);
        scanf("%s",assist->nom);
        vidBuff();

        printf("Quel est le prenom de l'assistant:%d \n",i+1);
        scanf("%s",assist->prenom);
        vidBuff();
        printf("Quel est la fonction de l'assistant:%d \n",i+1);
        scanf("%s",assist->fonction);
        vidBuff();
        insert(theAssist,assist);


    }


    
    return mydossier;

}

void suppression_Dossier(Dossier *mydossier)
{
    printf("Suppression du dossier: %s",mydossier->nom_dossier);

    deleteListeAssistant(mydossier->collabo->assistant);
    free(mydossier->collabo);
    free(mydossier);
}