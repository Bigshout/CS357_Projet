#include"fichier.h"

static int dossiernum=0;

////////////////////////begin_of_Assitant_GESTION///////////////////


Liste* InitialisationListeAssist()
{
    Liste* myliste=malloc(sizeof(Liste));

    if(!myliste)

    {
           fprintf(stderr,"erreur lors de la création de la liste");

            exit(EXIT_FAILURE);
    }

    myliste->collabFirst=NULL;
   return myliste;

}

void insert(Liste* liste,Collaborateur *collabo)
{
    if(liste==NULL)

        printf("la liste est vide");

    else if(liste->collabFirst==NULL)
       { 
            liste->collabFirst=collabo;

            liste->collabFirst->suivant=NULL;
       }

    else 
    {
        Collaborateur *temp=liste->collabFirst;

        liste->collabFirst=collabo;

        collabo->suivant=temp;
    }
    
}
void deleteElement(Liste *liste,Collaborateur *cible)
 {
    if(liste==NULL)
    {   
        printf("Gros y'a rien dedans\n");

        return;
    }

    else if(liste->collabFirst==cible)

        {

            liste->collabFirst=cible->suivant;

        }
    else 
    { 
        Collaborateur* temp=liste->collabFirst;

        while(temp->suivant!=cible && temp->suivant!=NULL)
        {
            printf("suppr\n");

            temp=temp->suivant;
        }

        temp->suivant=cible->suivant;

        free(cible);

    }

 }
 void deleteListe(Liste *listsuppr)
 {
    
     Collaborateur* temp=listsuppr->collabFirst;
   
     while (temp!=NULL)
     {
        deleteElement(listsuppr,temp);

        temp=temp->suivant;
       
     }
     
     
 }


 void afficherListe(Liste *myliste)
{
	
    if (!myliste->collabFirst)
	{
		printf("La liste est vide poto\n");
		return;
	}

	else
	{
		Collaborateur *temp = myliste->collabFirst;
		
		while (temp != NULL)
		{
			afficherCollab(temp);
			temp = temp->suivant;
		}
		
	}	

}
void afficherCollab(Collaborateur* collab)
{
     if (!collab)
	{
		printf("le collaborateur n'existe pas \n");
		return;
	}

	else
	{
		
		
	
		
			printf("-nom du collaborateur : %s\n", collab->nom);
			printf("prenom : %s\n",collab->prenom);
			printf("fonction : %s\n",collab->fonction);
            printf("matricule : %x\n",collab->matricule);

			
		
		
	}	
}
Collaborateur* rechercheCollaborateur(Liste* liste,unsigned int matricule)
{
    if(liste==NULL)
    {   
        printf("Gros y'a rien dedans\n");

        return 0;
    }

    else 
    { 
        Collaborateur* temp=liste->collabFirst;

        while(temp->matricule!=matricule && temp!=NULL)
        {
           
            temp=temp->suivant;
        }
        return temp;
        
    }
    return 0;

}

Collaborateur* rechercheCollaborateurNom(Liste* liste,char *nom)
{
     if(liste==NULL)
    {   
        printf("Gros y'a rien dedans\n");

        return 0;
    }

    else 
    { 
        Collaborateur* temp=liste->collabFirst;

        while(strncmp(temp->prenom,nom,strlen(nom)) && temp!=NULL)
        {
           
            temp=temp->suivant;
        }

          return temp;
        
    }
  



}




void modifierCollab(Collaborateur* tomdify)
{
    if (!tomdify)
    {
        fprintf(stderr,"Erreur lors de la modification du collaborateur ");
        return;
    }

    fflush(stdin);
    int choix;
    
    do{
    
        printf("1 : pour modifier le prenom\n");
        printf("2 : pour modifier le nom\n");
        printf("3 : pour modifier le matricule\n");
        printf("4 : pour modifier sa fonction\n");
        printf("0 : pour quitter!");

        scanf("%d",&choix);
        fflush(stdin);

        switch (choix)
            {
                case 1:
                        printf("Entrer le prenom :\n");
                        scanf("%s",tomdify->prenom);
                        fflush(stdin);

                    break;

                case 2:
                        printf("Entrer le nom :\n");
                        scanf("%s",tomdify->nom);
                        fflush(stdin);

                    break;

                case 3:
                        printf("Entrer le matricule :\n");
                        scanf("%d",&tomdify->matricule);
                        fflush(stdin);

                    break;

                case 4:
                        printf("Entrer la fonction :\n");
                        scanf("%s",tomdify->fonction);
                        fflush(stdin);

                    break;
    
                default:

                    break;
            }

        }while(choix);

}



void AfficherListeDossSuivi(Collaborateur *collab)
{
    if(!collab)
        {
            printf("Erreur lors de l'affichage de la liste des collaborateurs \n");
            return;
        }
    
    printf("la liste des dossiers suivis : \n");
    for(int i=0 ; i < collab->nbreDoss ;++i)
    {       
            
            printf("%s \n",collab->suivi[i]);
    }
    
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



///////////////////begin of Gestion dossier //////////////////
Dossier* creation_dossier()
{
    Dossier *mydossier=malloc(sizeof(Dossier));
    mydossier->etat_dossier=EN_COURS_D_INSTRUCTION;
    mydossier->collabo=malloc(sizeof(Collaborateur));
    dossiernum++;
    mydossier->num_dossier=dossiernum;
    
   
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

    
    mydossier->assistant=InitialisationListeAssist();

    
        Collaborateur *assist=malloc(sizeof(Collaborateur));
       

        printf("Quel est le nom de l'assistant\n");
        scanf("%s",assist->nom);
        vidBuff();

        printf("Quel est le prenom de l'assistant \n");
        scanf("%s",assist->prenom);
        vidBuff();
        printf("Quel est la fonction de l'assistant \n");
        scanf("%s",assist->fonction);
        vidBuff();
        insert(mydossier->assistant,assist);


    

    afficherListe(mydossier->assistant);


    
    return mydossier;

}

void suppression_Dossier(Dossier *mydossier)//validé
{
    printf("Suppression du dossier: %s\n",mydossier->nom_dossier);

    deleteListe(mydossier->assistant);
    free(mydossier->assistant);
    free(mydossier->collabo);
   
}

void afficherListeDossier(ListeDoss *myliste)//validé
{
    
     if (myliste->Dossier_first==NULL)
	{
		printf("La liste est vide poto\n");
		
	}

	else
	{
		Dossier *temp = myliste->Dossier_first;
		
		while (temp != NULL)
		{
			AfficherDossier(temp);
			temp = temp->suivant;
		}
		
	}	


}


void AfficherDossier(Dossier *mydossier)//validé
{
    
        if(!mydossier)
        {
            printf("le dossier n'existe pas \n");
            return;
        }
        else
        {
            printf("Dossier : %d\n",mydossier->num_dossier);
            printf("Nom du Dossier : %s\n \
                    Statut : %d \n \
                    Date d'ouverture :%d / %d / %d\n \
                    Date de fermeture :%d / %d / %d\n\
                     Binome Avocat/clerc: %s %s / %s %s\n\n"\
                                                    ,mydossier->nom_dossier,mydossier->etat_dossier,
                                                    mydossier->open_date[0],mydossier->open_date[1],mydossier->open_date[2],
                                                    mydossier->closed_date[0],mydossier->closed_date[1],mydossier->closed_date[2],
                                                    mydossier->collabo->nom,mydossier->collabo->prenom,
                                                    mydossier->assistant->collabFirst->nom,mydossier->assistant->collabFirst->prenom);

        }
        
        

}
void AfficherDossierNom(ListeDoss* mydossier,char *nom)
{
   
    Dossier* toAffiche=rechercheDossierNom(mydossier,nom);
    if(!toAffiche)
    {
        printf("le dossier n'existe pas \n");
        return;
    }

    AfficherDossier(toAffiche);
    


}

ListeDoss* InitialisationListeDossier()//validé
{
    ListeDoss* myliste=malloc(sizeof(ListeDoss));

    if(!myliste)

    {
           fprintf(stderr,"erreur lors de la création de la liste de dossier");

            exit(EXIT_FAILURE);
    }

    myliste->Dossier_first=NULL;
   return myliste;

}


void insertDossier(ListeDoss* liste,Dossier *newDossier)//validé
{
    if(liste==NULL)

        printf("la liste est vide");

    else if(liste->Dossier_first==NULL)
       { 
            liste->Dossier_first=newDossier;

            liste->Dossier_first->suivant=NULL;
       }

    else 
    {
        Dossier* temp=liste->Dossier_first;

        liste->Dossier_first=newDossier;

        newDossier->suivant=temp;
    }
}


void deleteElementDossier(ListeDoss *liste,Dossier *cible)//validé
 {
    if(liste==NULL)
    {   
        printf("Gros y'a rien dedans\n");

        return;
    }

    else if(liste->Dossier_first==cible)

        {
           
            liste->Dossier_first=cible->suivant;
            suppression_Dossier(cible);
            free(cible);

        }
    else 
    { 
        Dossier* temp=liste->Dossier_first;

        while(temp->suivant!=cible && temp->suivant!=NULL)
        {
            printf("suppr\n");

            temp=temp->suivant;
        }

        temp->suivant=cible->suivant;

        suppression_Dossier(cible);

        free(cible);

    }

Collaborateur* rechercheCollaborateurNom(Liste* liste,char *nom);//validé!
 }
 void deleteListeDossier(ListeDoss *listsuppr)
 {
    
     Dossier* temp=listsuppr->Dossier_first;
   
     while (temp!=NULL)
     {
        deleteElementDossier(listsuppr,temp);

        temp=temp->suivant;
       
     }
     
     
 }

 Dossier* rechercheDossier(ListeDoss* liste,unsigned int cible)
 {
    if(liste==NULL)
    {   
        printf("Gros y'a rien dedans\n");

        return 0;
    }

    else 
    { 
        Dossier* temp=liste->Dossier_first;

        while(temp->num_dossier!=cible && temp!=NULL)
        {
           
            temp=temp->suivant;
        }
        return temp;
        
    }
    return 0;

 }
 Dossier* rechercheDossierNom(ListeDoss* liste,char *cible)
 {
    if(liste==NULL)
    {   
        printf("la liste est vide 0\n");

        return 0;
    }

    else 
    { 
        Dossier* temp=liste->Dossier_first;

        while(strcmp(temp->nom_dossier,cible) && temp!=NULL)
        {
           
            temp=temp->suivant;
        }
        if(temp!=NULL)
            return temp;
        
    }
    return NULL;

 }


 void modifierDossier(Dossier* tomodify,Liste* liscollab)
 {

    if(!tomodify)
    {
        fprintf(stderr,"erreur lors de la modification du dossier");
    }


    fflush(stdin);
    int choix;
    
    do{
    
        printf("1 : pour modifier le nom\n");
        printf("2 : pour modifier le statut\n");
        printf("3 : pour modifier le numero_du_dossier\n");
        printf("4 : pour modifier la date d'ouverture\n");
        printf("5 : pour modifier la date de fermeture\n");
        printf("0 : pour quitter!");

        scanf("%d",&choix);
        fflush(stdin);

        switch (choix)
            {
                case 1:
                        printf("Entrer le nom :\n");
                        scanf("%s",tomodify->nom_dossier);
                        fflush(stdin);
 
                    break;

                case 2:
                        printf("\t Entrer le Statut :\n");
                        printf("0 : pour dossier en cour :\n");
                        printf("1 :pour dossier cloture :\n");
                        printf("2 : pour dossier annule :\n");
                        int choice;
                        scanf("%d",&choice);
                        fflush(stdin);
                        switch(choice)
                        {
                            case 0:
                                    
                                    tomodify->etat_dossier=EN_COURS_D_INSTRUCTION;
                                break;

                            case 1:

                                    tomodify->etat_dossier=CLOTURE;

                                break;

                            case 2:

                                    tomodify->etat_dossier=ANNULE;
                                break;
                            default:
                                break;
                        }
                       

                    break;

                case 3:
                        printf("Entrer le numero du dossier :\n");
                        scanf("%d",&(tomodify->num_dossier));

                    break;

                case 4:
                        printf("changement de la date d'ouverture :\n");
                        printf("jour: :\n");
                        scanf("%d",&(tomodify->open_date[0]));
                        fflush(stdin);
                        printf("mois :\n");
                        scanf("%d",&(tomodify->open_date[1]));
                        fflush(stdin);
                        printf("Annee:\n");
                        scanf("%d",&(tomodify->open_date[2]));
                        fflush(stdin);

                    break;
                case 5:
                        cloturerDossier(tomodify);
                    break;
    
                default:
                        choix=0;
                    break;
            }

        }while(choix);
         

}

void cloturerDossier(Dossier *tomodify)
{
                        
                        printf("changement de la date de fermeture :\n");
                        printf("jour: :\n");
                        scanf("%d",&(tomodify->closed_date[0]));
                        fflush(stdin);
                        printf("mois :\n");
                        scanf("%d",&(tomodify->closed_date[1]));
                        fflush(stdin);
                        printf("Annee:\n");
                        scanf("%d",&(tomodify->closed_date[2]));
                        fflush(stdin);

                        tomodify->etat_dossier=CLOTURE;
                
               
}
void dossierSuivi(Collaborateur* collab,char *name)
{
    if(!collab)
    {
        printf("Erreur le collaborateur n'existe pas");

       
    }
    else
    {
        collab->suivi=realloc(collab->suivi,collab->nbreDoss);
        collab->suivi[collab->nbreDoss-1]=malloc(strlen(name)*sizeof(char));
        strcpy(collab->suivi[collab->nbreDoss-1],name);
    }

    return;
}