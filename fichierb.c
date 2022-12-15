#include"fichier.h"
static unsigned int matricule=0;
static unsigned int nbredoss=0;
static char nomSaveFichierListe[128]="list.txt";
static char nomSaveFichierDoss[128]="doss.txt";

unsigned int nbreCollaborateur()
{
	return matricule;
}

unsigned int nbreMoyendossparCollab()
{
	if(matricule==0)

		return 0;
	else

		return nbredoss/matricule;
}

unsigned int nbreMAxdoss(Liste * myliste)
{
	int max=0;
	 if (!myliste)
	{
		printf("La liste est vide poto\n");
		return 0;
	}

	else
	{
		Collaborateur *temp = myliste->collabFirst;
		
		
		while (temp != NULL)
		{	
			if(temp->nbreDoss > max)
			{
				max=temp->nbreDoss;
			}
			
			temp = temp->suivant;
		}
		
	}

	return max;	
}

char *nomdesVieuxdocs(ListeDoss *myliste)
{
	 if (myliste->Dossier_first==NULL)
	{
		printf("La liste est vide poto\n");
		
	}

	else
	{
		Dossier *temp = myliste->Dossier_first;

		//Dossier* temp1,temp2,temp3;
		
		while (temp != NULL)
		{
			//

			temp = temp->suivant;
		}
		
	}	
return 0;

}





Liste* chargerListe()
{
	Liste* myliste=malloc(sizeof(Liste));

	if(!myliste)
	{
		fprintf(stderr,"Erreur lors de l'allocation dynamique de la liste");
		exit (EXIT_FAILURE);
	}
	else
	{
		FILE* myFichier=fopen(strcat(nomSaveFichierListe,".txt"),"r");
		if(!myFichier)
		{
			fprintf(stderr,"Le fichier spécifié : %s n'existe pas \n",nomSaveFichierListe);
			return 0;
		}
		else
		{	char chaine[128];

			while(!feof(myFichier))
			{	
				strcpy(chaine,"");
				fgets(chaine,128,myFichier);

				if(!strcmp(chaine,"/\n"))
				{
					Collaborateur* newCollab=malloc(sizeof(Collaborateur));
					int i=0;
					do
					{	strcpy(chaine,"");
						fgets(chaine,128,myFichier);
						switch (i)
						{
							case  0:
								strcpy(newCollab->nom,chaine);
							break;

							case 1:
								strcpy(newCollab->prenom,chaine);
							break;

							case 2:
								strcpy(newCollab->fonction,chaine);
							break;
							case 3:
								newCollab->matricule=atoi(chaine);
							break;

							default:

							break;
						}



						i++;
					}
					while(strcmp(chaine,"/\n"));
                insert(myliste,newCollab);

				}
			}
			fclose(myFichier);
		}




	}


	return myliste;
}

void enregistrerListe(Liste *myliste)
{
	FILE* myfichier;

	if(!myliste)
	{
		fprintf(stderr,"La liste est vide\n");
		return;
	}

	myfichier=fopen(nomSaveFichierListe,"w");

	if(!myfichier)
	{
		fprintf(stderr," ENREGISTREMENT.. erreur lors de l'ouverture du fichier organigramme.txt");

		return;
	}
	else
	{
		Collaborateur* tempo=myliste->collabFirst;

		while(tempo)
		{
			fputc(47,myfichier);
			fputc('\n',myfichier);

			fprintf(myfichier,"-%s\n",tempo->nom);
			fprintf(myfichier,"-%s\n,",tempo->prenom);
			fprintf(myfichier,"-%s\n",tempo->fonction);
			fprintf(myfichier,"-%d\n",tempo->matricule);

			fputc(47,myfichier);
			fputc('\n',myfichier);

			tempo=tempo->suivant;
		}

		fclose(myfichier);
	}

}

void createCollab(Liste *myliste)
{
	if(!myliste)
	{
		fprintf(stderr,"erreur lors de lenregistrement du nouveau collaborateur");
		return;
	}
	Collaborateur* nouveau=malloc(sizeof(Collaborateur));

	printf("Entrer le prenom du nouveau collaborateur :\n");
        scanf("%s",nouveau->prenom);
	fflush(stdin);

	printf("Entrer le nom du nouveau collaborateur :\n");
        scanf("%s",nouveau->nom);
        fflush(stdin);

	printf("Entrer sa fonction :\n");
        scanf("%s",nouveau->fonction);
        fflush(stdin);
	matricule+=1;
	nouveau->matricule=matricule;
	


	insert(myliste,nouveau);
	enregistrerListe(myliste);


}


void deleteCollab(Liste *myliste,unsigned int matricule)
{
	if(!myliste)
	{
		fprintf(stderr,"erreur lors de la suppression du collaborateur\n");
		return;
	}
	Collaborateur* cible=rechercheCollaborateur(myliste,matricule);

	deleteElement(myliste,cible);

	enregistrerListe(myliste);

}


void enregistrerListeDossier(ListeDoss *myliste)
{
	FILE* myfichier;

	if(!myliste)
	{
		fprintf(stderr,"La liste est vide\n");
		return;
	}

	myfichier=fopen(nomSaveFichierDoss,"w");

	if(!myfichier)
	{
		fprintf(stderr," ENREGISTREMENT.. erreur lors de l'ouverture du fichier dossier.txt");

		return;
	}
	else
	{
		Dossier* tempo=myliste->Dossier_first;

		while(tempo)
		{
			fputc(47,myfichier);
			fputc('\n',myfichier);




			fprintf(myfichier,"%s\n",tempo->nom_dossier);
			fprintf(myfichier,"%d %d %d\n,",tempo->open_date[0],tempo->open_date[1],tempo->open_date[2]);
			fprintf(myfichier,"%d %d %d\n,",tempo->closed_date[0],tempo->closed_date[1],tempo->closed_date[2]);
			fprintf(myfichier,"%d\n",tempo->num_dossier);
			fprintf(myfichier,"%d\n",tempo->etat_dossier);
			fprintf(myfichier,"%u\n",tempo->collabo->matricule);
			fprintf(myfichier,"%u\n",tempo->assistant->collabFirst->matricule);





			fputc(47,myfichier);
			fputc('\n',myfichier);

			tempo=tempo->suivant;
		}

		fclose(myfichier);
	}



}
ListeDoss* chargerListeDossier(Liste *listecollab)
{
	ListeDoss* myliste=malloc(sizeof(ListeDoss));

	if(!myliste)
	{
		fprintf(stderr,"Erreur lors de l'allocation dynamique de la liste");
		exit (EXIT_FAILURE);
	}
	else
	{
		FILE* myFichier=fopen(nomSaveFichierDoss,"r");
		if(!myFichier)
		{
			fprintf(stderr,"Le fichier : %s spécifié n'existe pas\n",nomSaveFichierDoss);
			return 0;
		}
		else
		{	char chaine[128];

			while(!feof(myFichier))
			{	
				strcpy(chaine,"");
				fgets(chaine,128,myFichier);

				if(!strcmp(chaine,"/\n"))
				{
					Dossier* tmp=malloc(sizeof(Dossier));
					int i=0;
					do
				     	{	strcpy(chaine,"");
						fgets(chaine,128,myFichier);
						switch (i)
						{
							case  0:
								strcpy(tmp->nom_dossier,chaine);
							break;

							case 1:
								
								tmp->open_date[0]=12;
								

								tmp->open_date[0]=12;
								

								tmp->open_date[0]=2022;
							break;

							case 2:

								tmp->closed_date[0]=0;
								

								tmp->closed_date[1]=0;
								

								tmp->closed_date[2]=0;
							
							break;
							case 3:
								tmp->etat_dossier=atoi(chaine);
								
							break;
							case 4:
								/*tmp->collabo=rechercheCollaborateur(listecollab,atoi(chaine));
								tmp->collabo->nbreDoss++;
								dossierSuivi(tmp->collabo,tmp->nom_dossier);*/
								
							break;
							case 5:
								/*tmp->assistant=InitialisationListeAssist();
								tmp->assistant->collabFirst=rechercheCollaborateur(listecollab,atoi(chaine));
								tmp->assistant->collabFirst->nbreDoss++;
								dossierSuivi(tmp->assistant->collabFirst,tmp->nom_dossier);*/
							break;
							case 6:
								tmp->num_dossier=atoi(chaine);
								
							break;


							default:

							break;
						}



						i++;
					}
					while(strcmp(chaine,"/\n"));
                insertDossier(myliste,tmp);

				}
			}
			fclose(myFichier);
		}




	}


	return myliste;


	
}





void ajouterDossier(ListeDoss *myliste,Liste* listecollab)
{	
	if(!myliste)
	{
		fprintf(stderr,"erreur lors de l'ajout du nouveau dossier\n");
		return;
	}

	Dossier* nouveau=creation_dossier();
	Collaborateur* collab=NULL;
	collab=rechercheCollaborateurNom(listecollab,nouveau->collabo->nom);


	if(collab)
	{
		insertDossier(myliste,nouveau);
		collab->nbreDoss++;
		dossierSuivi(collab,nouveau->nom_dossier);
		enregistrerListeDossier(myliste);
	}
	else
	{
		free(nouveau);
		printf("Le responsable n'existe dans la base de donnée\n");
		
	}

	return;
}

void nomSauvegarder()
{
	printf("Entrer le nom du fichier de sauvegarde Liste Colaborateur\n");
	fflush(stdin);
	scanf("%s",nomSaveFichierListe);
	fflush(stdin);

	printf("Entrer le nom du fichier de sauvegarde Liste Dossier\n");
	fflush(stdin);
	scanf("%s",nomSaveFichierDoss);
	fflush(stdin);
}