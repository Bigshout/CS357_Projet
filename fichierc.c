#include "fichier.h"


int choice=0;

void Affichage_du_menu()
{
	int choix,quit=1;
  	ListeDoss* mylist_Dossier=InitialisationListeDossier();
	Liste* mylisteCollab=InitialisationListeAssist();

	
	do
	{
		

		printf("\t \t Gestion du cabinet \t \t \n");
		printf("1:charger les Fichiers de données\n");	
		printf("2:Afficher les informations d'un dossier\n");
		printf("3:créer un dossier\n");
		printf("4:créer un collaborateur\n");
		printf("5:supprimer un collaborateur\n");
		printf("6:Annuler Un dossier\n");	
		printf("7:Cloturer un dossier\n");
		printf("8:Modifier un Dossier\n");
		printf("9:Modifier un collaborateur\n");
		printf("10:Afficher la liste des dossiers suivis par un colllaborateur\n");
		printf("11:Les Statistiques de l'entreprise\n");
		printf("12:changer le nom des fichiers de sauvegarde\n");
		printf("13:Quitter le programme\n");
		

		scanf("%d",&choix);
		fflush(stdin);

		
		switch(choix)
		{

			case 1:
				fonc1(mylist_Dossier,mylisteCollab);
					
			break;

			case 2:
				fonc2(mylist_Dossier);
			break;

			case 3:
				ajouterDossier(mylist_Dossier,mylisteCollab);
				
			break;

			case 4:
				createCollab(mylisteCollab);

			break;

			case 5:
				fonc5(mylisteCollab);
				
			break;

			case 6:
				fonc6(mylist_Dossier);
				
			break;
			
			case 7:
				fonc7(mylist_Dossier);	
			
			break;

			case 8:
				fonc8(mylist_Dossier,mylisteCollab);
			break;
			
			case 9:
				fonc9(mylisteCollab);
				
			break;

			case 10:
				fonc10(mylisteCollab);
				
			break;
			
			case 11:
				printf("l'entreprise a %d de collaborateurs\n \
					le nombre maximum de dossier est de %d \n \
					Une moyenne de %d dossier/Collaborateur\n",nbreCollaborateur(),nbreMAxdoss(mylisteCollab),nbreMoyendossparCollab());
				
				
			break;

			case 12:
				nomSauvegarder();

			break;
			case 13:
				
				quit=0;

			break;
			
			break;
			default:
			break;
		}

	} while (quit);
	

}
void fonc1(ListeDoss *mylistedoss,Liste *listcoll)
{
	
    nomSauvegarder();
    listcoll=chargerListe();
    mylistedoss=chargerListeDossier(listcoll);



}
void fonc2(ListeDoss* mylist)
{
	char chaine[128];
	printf("Entrer le nom du dossier recherché\n");
	scanf("%s",chaine);
	fflush(stdin);

	Dossier* tmp=rechercheDossierNom(mylist,chaine);
	AfficherDossier(tmp);
}
void fonc5(Liste *mylist)
{
	char chaine[128];
	printf("Entrer le nom du collaborateur à supprimer\n");
	scanf("%s",chaine);
	fflush(stdin);ListeDoss* chargerListeDossier();
}
void fonc6(ListeDoss* mylist)
{
	char chaine[128];
	printf("Entrer le nom du Dossier à annuler\n");
	scanf("%s",chaine);
	fflush(stdin);
	Dossier* tmp=rechercheDossierNom(mylist,chaine);
	tmp->etat_dossier=ANNULE;


}
void fonc7(ListeDoss *mylist)
{
	char chaine[128];
	printf("Entrer le nom du Dossier à cloturer\n");
	scanf("%s",chaine);
	fflush(stdin);
	Dossier* tmp= rechercheDossierNom(mylist,chaine);
	cloturerDossier(tmp);
}
void fonc8(ListeDoss* mylist,Liste*mine)
{
	char chaine[128];
	printf("Entrer le nom du Dossier à modifier\n");
	scanf("%s",chaine);
	fflush(stdin);
	Dossier* tmp=rechercheDossierNom(mylist,chaine);
	modifierDossier(tmp,mine);
	enregistrerListeDossier(mylist);
	
}
void fonc9(Liste* mylist)
{
	char chaine[128];
	printf("Entrer le nom du collaborateur à modifier\n");
	scanf("%s",chaine);
	fflush(stdin);
	Collaborateur* tmp=rechercheCollaborateurNom(mylist,chaine);
	modifierCollab(tmp);


}
void fonc10(Liste* mylist)
{	
	char chaine[128];
	printf("Entrer le nom du collaborateur\n");
	scanf("%s",chaine);
	fflush(stdin);
	Collaborateur *tmp=rechercheCollaborateurNom(mylist,chaine);
	AfficherListeDossSuivi(tmp);
}