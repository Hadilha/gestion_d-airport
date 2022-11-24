int N =0;

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include  "myconio.h"
#include <assert.h>

/*****creation*****/
liste * creer_liste()
{   liste* L;
    L=(liste* )malloc(sizeof(liste));
	L->premier=NULL;
	L->dernier=NULL;
	return L;
}
/*****liste vide *****/
int liste_vide(liste*ll)
{
    return((ll->dernier==NULL)&&(ll->premier==NULL));
}
/****Taille_Liste****/
int taille_liste_av(liste*ll)
{   assert(!liste_vide(ll));
    struct cellule *n=ll->premier;
    int cp=0;
    while(n)

    {
        n=n->suivant;
        cp++;
    }
    return cp;
}
/****teste par identifiant****/
struct cellule *TEST2(liste *L,char *ident)
{
    struct cellule *aux=L->premier;
	while(aux && ((strcmp((aux->info.identifiant), ident)!=0)))

    aux=aux->suivant;
	return aux;

}
/*****teste par identifinat return void*****/
void TESTT(liste*L)

  {


        char * iden=(char*)malloc(sizeof(char));
        printf("\n\t\t\t\t***Recherche par l'identifiant de l'avion***  \n\n");
        printf("\n donner l'identifiant de l'avion \n ");
        scanf("%s",iden);
        int s=0;
        struct cellule *p1=L->premier;

        while ((p1)&&(s==0))
    {
        if (strcmp(p1->info.identifiant,iden)==0)
            s=1;

        else
           p1=p1->suivant;
    }

        if (s==1)
            printf("oui l'avion existe");
        else if(s==0)
            printf("non l'avion n'existe pas ");
    }

/*****teste par  compagnie return void*****/
void TESTcomp( liste *L)
  {if(liste_vide(L))
  {
      printf("l'avion est vide ");
      return;
  }
  else
  {


    char * comp=(char*)malloc(sizeof(char));
    printf("\n\t\t\t\t***Recherche par compagnie de l'avion***  \n\n");
    printf("\n donner la compagnie de l'avion \n ");
    scanf("%s",comp);
    int s=0;
    struct cellule *p1=L->premier;
    while ((p1)&&(s==0))
    {
        if (strcmp(p1->info.comp->nom,comp)==0)
            s=1;
        else
            p1=p1->suivant;

    }

    if (s==1)
        printf("oui l'avion de cette compagnie existe");
        else
    if(s==0)
        printf("non l'avion de cette compagnie n'existe pas ");
  }

  }
/*****teste par heure return void*****/
 void TESThdec(liste *L)
 {

    char * hdec=(char*)malloc(sizeof(char));
    printf("\n\t\t\t\t***Recherche par heure de decollage***  \n\n");
    do{
    printf("\n donner l'heure de  decollage  de l'avion voulez chercher\n");
    fflush(stdin);
    gets( hdec);}while(!((strlen(hdec))==5));
    int s=0;
    struct cellule*p1=L->premier;
    while ((p1)&&(s==0))
    {
        if (strcmp(p1->info.heure_decollage,hdec)==0)
            s=1;
        else
            p1=p1->suivant;

    }

    if (s==1)
        printf("oui l'avion de cette heure decollage existe");
    else if(s==0)
       printf("non l'avion de cette heure decollage n'existe pas ");

 }

/*****************saisie***************/
avion SAISIE_AVION()
{
    struct avion av;
    char carburant[10];
    char consomation[10];
    struct compagnie* pc;
    do{
        printf("saisir l'identifiant:(6 caracteres)(char) : ");
        fflush(stdin);
        gets(av.identifiant);
    }while(!(strlen(av.identifiant)==6));

    do{printf("saisir le carburant(int) :");
    fflush(stdin);
    scanf("%d",&av.carburant);
    itoa(av.carburant,carburant,10);}while(!verifNumerique(carburant));

    do{printf("saisir la consommation (int):");
    fflush(stdin);
    scanf("%d",&av.consommation);
    itoa(av.consommation,consomation,10);}while(!verifNumerique(consomation));


    do{
    printf("saisir l'heure_decollage (char) (4chiffres) de la fomrmat HH:MM : ");
    fflush(stdin);
    gets(av.heure_decollage);
    ;}while((!strlen(av.heure_decollage)==5)||(!valide(av.heure_decollage)));


    av.comp=(struct compagnie*)malloc(sizeof(struct compagnie));
    pc=av.comp;
    pc->nom=(char*)malloc(sizeof(char));

   do{printf("saisir nom de la compagnie :(char) : ");
    fflush(stdin);
    gets(pc->nom);}while(!(verifAlpha(pc->nom)));
    do{
        printf("saisir l'acronyme de la compagnie (3caracteres ) :");
        fflush(stdin);
        gets(pc->acronyme);
    }while(!(strlen(pc->acronyme)==3)||(!verifAlpha(pc->acronyme)));

    return (av) ;
}
/*****insere_queue_av*****/
void insere_queue_av(struct avion av ,liste* ll)
{
    if(!TEST2(ll,av.identifiant))
   {
    struct cellule  *new=(struct cellule *)malloc(sizeof(struct cellule ));
    new->info=av;
	new->suivant=NULL;
	if(!ll->premier && !ll->dernier)
        {
            ll->premier=new;
            ll->dernier=new;
        }
	else
        {
            ll->dernier->suivant=new;
            ll->dernier=new;
        }
            textbackground (11);textcolor(15);
            system("color 0F");
            affiche_liste(ll);
        }
	else
            printf("cette avion deja existe\n");

}
/*****insere_tete_av*****/
void insere_tete_av(struct avion av,liste*ll)
{
    if(!TEST2(ll,av.identifiant))
    {
        struct cellule *new=(  struct cellule *)malloc(sizeof(  struct cellule ));
        new->info=av;
        new->suivant=ll->premier;
	if(!ll->premier && !ll->dernier)
	{
		ll->premier=new;
		ll->dernier=new;
	}
	else
	{
		ll->premier=new;
	}
    textbackground (11);textcolor(15);
    system("color 0F");
	affiche_liste(ll);}
	else
    printf("cette avion deja existe\n");
}
/****CREATION****/
liste * CREATION()
{
    struct avion p;
    int pos;
    int ch;
	liste *L=(liste *)malloc(sizeof(liste));
	L=creer_liste();
    textbackground (11);textcolor(15);

    printf("\n                            * BIENVENUE A NOTRE PLATEFORM ***\n ");

    textbackground (11);textcolor(15);
    printf("\n                  * NOUS ESPERONS QUE VOUS SEREZ SATISFAIT DE NOS SERVICE * \n");
    textbackground (11);textcolor(0);
	do{printf("\nVoulez vous ajouter un avion a notre repertoire   ? \nTAPER 1 POUR EFFECTUER L'AJOUT ! \nTAPER 0 POUR QUITTER !   \nVOTRE CHOIX  : ");
    scanf("%d",&ch);}while(!((ch==1)||(ch==0)));
	if(ch)
	{
		textbackground (11);textcolor(0);
         N =1;

		p=SAISIE_AVION(L);

		 struct cellule *new=(struct cellule *)malloc(sizeof(struct cellule));
				new->info=p;
				new->suivant=NULL;
				if(!L->premier)
				{
					L->premier=new;
					L->dernier=new;
				}
				else
				{
					L->dernier->suivant=new;
					L->dernier=new;
				}
	}
	do
	{
	    system("color B0");
		printf("VOUS VOULEZ ENCORE AJOUTER DES AVIONS   ? \n TAPER  1 - si oui \n TAPER  0 -si non \n VOTRE CHOIX : ");
		scanf("%d",&ch);
		if(ch)
		{
        p=SAISIE_AVION(L);
		if(!TEST2(L,p.identifiant))
        {
            int taille=taille_liste_av(L);
            printf ("DONNER LA POSITION DE L'INSERTION !");
            scanf("%d",&pos);

				if(pos==1)
				{
				    insere_tete_av(p ,L);

				}
				else
				 if(pos==taille+1)
				{
				    insere_queue_av(p ,L);

				}
				else if(pos<taille+1)
                {
                    int cp=1;
                    struct cellule * noeuddeposition=( struct cellule *)malloc(sizeof( struct cellule));
                    noeuddeposition=L->premier;
                while(cp!=pos-1)
                {   noeuddeposition=noeuddeposition->suivant;
                    cp++;

                }
                insere_pos_av (p,L,noeuddeposition);
                }
}
			else
			{   textbackground (11);textcolor(15);

				printf("l'identifiant existe deja , veuillez verifier!!\n");
			}
		}

	}while(ch);

	return L;
}
/****Affichage les info de la liste****/
void affiche_liste(liste *L)
{


	struct cellule *aux=L->premier;
    textbackground (0);textcolor(10);
    printf ("AVION:     identifiant : ||     Carburant:  ||     Consommation:   ||     Heure_decollage:  ||    Nom_Compagnie:   ||    Acronyme_Compagnie :     \n");


	while(aux)

{textbackground (0);textcolor(12);
    printf(" \n */   :    %s                  %d              %d                    %s                    %s                           %s             \n",aux->info.identifiant,aux->info.carburant,aux->info.consommation,aux->info.heure_decollage,aux->info.comp->nom,aux->info.comp->acronyme);
		aux=aux->suivant;
	}
	printf("\n\n");
}

/****Recherche avion ****/
int recherche_av(struct avion *av,liste*ll)/*(0==>existe)(1==>n'existe pas)*/

{
        struct cellule *aux =ll->premier;
        int i=0;
    while(aux)
	{
		if(&(aux->info)==av)
            i++;
            aux=aux->suivant;
	}
	if(i==1)
		return 0; //existe une seule fois
	else
		return 1; //n'existe pas ou il existe plusieur fois
}

/****Recherche avion par identifiant****/
void recherche_id (char*q ,  liste *p)
{
    int s=0;
    struct cellule *p1=p->premier;
    while ((p1)&&(s=0))
    {
        if (strcmp(p1->info.identifiant,q)==0)
            s=1;
           else
            p1=p1->suivant;

    }

    if (s==1)
        printf("oui l'avion existe");
    else if(s==0)
        printf("non l'avion n'existe pas ");


}
/****Recherche par compagnie****/
struct cellule *recherche_compagnie(liste *L,char *nom)
{
	struct cellule *aux=L->premier;
	while(aux && aux->info.comp->nom!=nom)
    aux=aux->suivant;
	return aux;
}
/****Recherche par heure****/
struct cellule *recherche_heure(liste *L,char *heure)
{
	struct cellule *aux=L->premier;
	while(aux && aux->info.heure_decollage!=heure)
    aux=aux->suivant;
	return aux;
}

/****Affichage les info d'un avion donnee****/
void affiche_cellule(struct cellule *aux)
{
   textbackground (0);textcolor(10);
    printf ("AVION:     identifiant : ||     Carburant:  ||     Consommation:   ||     Heure_decollage:  ||    Nom_Compagnie:   ||    Acronyme_Compagnie :     \n");
    textbackground (0);textcolor(12);
    printf("*/   :     %s||     %d ||     %d ||     %s ||     %s ||     %s \n",aux->info.identifiant,aux->info.carburant,aux->info.consommation,aux->info.heure_decollage,aux->info.comp->nom,aux->info.comp->acronyme);
}
/****supprimer en queue****/
void supprimer_dernier(liste *L)
{
	struct cellule *aux=L->premier;
	while(aux->suivant->suivant)
		aux=aux->suivant;
	free(L->dernier);
	L->dernier=aux;
	aux->suivant=NULL;
}
/****supprimer apres un ref donnee****/
void supprime_apres(liste *L,struct cellule *p)
{	assert(p->suivant);
	if(p->suivant==L->dernier)
		supprimer_dernier(L);
	else
	{
		struct cellule *aux=p->suivant;
		p->suivant=aux->suivant;
		free(aux);
	}
}
/****supprimer en tete****/
void supprimer_premier(liste *L)
{
	struct cellule *aux=L->premier;
	L->premier=aux->suivant;
	if(!L->premier)
		L->dernier=NULL;
	free(aux);
}
/****suppression d'un avion donnee****/
void suppression_av_donne(liste *L)

	{int taille=taille_liste_av(L);
	    char *ident=(char*)malloc(sizeof(char));
	    struct cellule *ll1=L->premier->suivant;/*ali fayta*/
        struct cellule *ll2=L->premier;
        textbackground (11);textcolor(15);
	    printf("donner l'identifiant de l'avion voulez supprimer \n");
	    fflush(stdin);
        gets(ident);


        int pos=1;
        if ((taille==1)&&((strcmp(ll2->info.identifiant,ident)==0)))
         supprimer_premier (L);
        else {


     while(ll1)
     {
        if(strcmp(ll2->info.identifiant,ident)==0)

            supprimer_premier (L);

        else if(strcmp(ll2->info.identifiant,ident)==0)
         {
            suppression_pos_av(L);
         }
         ll1=ll1->suivant;
         ll2=ll2->suivant;
         pos++;


     }}
     if(ll2==NULL)
        supprimer_dernier(L);

     if(liste_vide(L))
        printf("l'avion est vide ");
     else
        affiche_liste(L);
    }
/****suppression des avions d'une compagnie donnee****/

void suppression_comp_donne(liste *L)

	{int taille=taille_liste_av(L);
	    char *comp=(char*)malloc(sizeof(char));
	    struct cellule *ll1=L->premier->suivant;/*ali fayta*/
        struct cellule *ll2=L->premier;
        textbackground (11);textcolor(15);
	    printf("donner la companie  de l'avion voulez supprimer \n");
	    fflush(stdin);
        gets(comp);


        int pos=1;
        if ((taille==1)&&((strcmp(ll2->info.comp->nom,comp)==0)))
         supprimer_premier (L);
        else {


     while(ll1)
     {
        if(strcmp(ll2->info.comp->nom,comp)==0)

            supprimer_premier (L);

        else if(strcmp(ll2->info.comp->nom,comp)==0)
         {
            suppression_pos_av(L);
         }
         ll1=ll1->suivant;
         ll2=ll2->suivant;
         pos++;


     }}
     if(ll2==NULL)
        supprimer_dernier(L);

     if(liste_vide(L))
        printf("l'avion est vide ");
     else
        affiche_liste(L);
    }


/****Tri par ordre decroissant du consommation du carburant****/
void TRI1(liste *L)
{
        struct cellule *aux=L->premier;
        struct cellule *var,*aux1;
        int a;
        char ch[20];
	if(!aux->suivant)
		return;
	while(aux->suivant)
	{
		var=aux;
		aux1=aux->suivant;
    while(aux1)
		{
			if(aux1->info.consommation>var->info.consommation)
				var=aux1;
			aux1=aux1->suivant;
            }
            if(var!=aux)
            {
			a=var->info.carburant;
			var->info.carburant=aux->info.carburant;
			aux->info.carburant=a;
			a=var->info.consommation;
			var->info.consommation=aux->info.consommation;
			aux->info.consommation=a;
			strcpy(ch,aux->info.identifiant);
			strcpy(aux->info.identifiant,var->info.identifiant);
			strcpy(var->info.identifiant,ch);
			strcpy(ch,aux->info.heure_decollage);
			strcpy(aux->info.heure_decollage,var->info.heure_decollage);
			strcpy(var->info.heure_decollage,ch);
			strcpy(ch,aux->info.comp->nom);////icii
			strcpy(aux->info.comp->nom,var->info.comp->nom);
			strcpy(var->info.comp->nom,ch);
			strcpy(ch,aux->info.comp->acronyme);
			strcpy(aux->info.comp->acronyme,var->info.comp->acronyme);
			strcpy(var->info.comp->acronyme,ch);
		}
		aux=aux->suivant;
	}
    system("color 0F");
	affiche_liste(L);
}
/****Inserer_Pos****/
struct  cellule*pos(liste *L)
{
	struct cellule*aux=L->premier;
	struct  cellule *re=aux;
	int taille=taille_liste_av(L);
	int p,nb=1;
	do{

        printf("\nDonner la position\n");
        scanf("%d",&p);
    }while((((p==1)||(p==taille+1))));
	while((aux)&&(nb-1!=p))
	{
	    nb++;
		aux=aux->suivant;
	}
	return re;
}
/****Inserer_Pos****/
void inserer_pos(liste *L,struct avion av)
{
    if(!TEST2(L,av.identifiant))

    {

    int poss,taille=taille_liste_av(L);
    do{

        printf("donner la position");
        scanf("%d",&poss);}while((poss==1)&&(poss==taille+1));
        int cp=1;
        struct cellule * noeuddeposition=( struct cellule *)malloc(sizeof( struct cellule));
        noeuddeposition=L->premier;
        while(cp!=poss-1)
    {   noeuddeposition=noeuddeposition->suivant;
        cp++;

    }
        insere_pos_av (av,L,noeuddeposition);
        system("color 0F");
        affiche_liste(L);
        }


}
/****suppression pos avion****/
void suppression_pos_av(liste *L)
{
struct cellule*aux=pos(L);

struct cellule  *aux1=L->premier;
struct cellule  *aux2;
aux2=aux1;
    while(aux1!=aux)
		{
			aux2=aux1;
			aux1=aux1->suivant;
		}
    supprime_apres(L,aux2);

}

/****modification de l'identifiant***/
void modifie_identifiant(liste L)
{
    char * identifiant;
    int nombre;
    int taille=taille_liste_av(&L);
    identifiant=(char*)malloc(sizeof(char));

    do{
    textbackground (11);textcolor(15);
    printf("donner le noveau identifiant ");
    gets(identifiant);}while (!(strlen(identifiant)==6));
    do{
    textbackground (11);textcolor(15);
    printf("donner le nombre de l'avion qui va etre modifier  ");
    scanf("%d",&nombre );}while(!(nombre>=1)||!(nombre<=taille));
    struct cellule* n;
    n=L.premier;
    int i=1;
    while(i<nombre)
    {
        i++;
        n=n->suivant;
    }
    strcpy(n->info.identifiant,identifiant);
    system("color 0F");
    affiche_liste(&L);
    }


/***modification du Compagnie***/
void modifie_Compagnie(liste L )
{
    char * Compagnie;
    int nombre;
    int taille=taille_liste_av(&L);
    Compagnie=(char*)malloc(sizeof(char));
    fflush(stdin);
    textbackground (11);textcolor(15);
    printf("donner la nouvelle companie  ");
    gets(Compagnie);
    fflush(stdin);
    do{
    textbackground (11);textcolor(15);
    printf("donner le nombre de l'avion qui va etre modifier  ");
    scanf("%d",&nombre );}while(!(nombre>=1)||!(nombre<=taille));
    fflush(stdin);
    struct cellule * n=(struct cellule *)malloc(sizeof(struct cellule));
    n=L.premier;
    int i=1;
    while(i<nombre)
    {
        i++;
        n=n->suivant;
    }

     strcpy(n->info.comp->nom,Compagnie);
     system("color 0F");
     affiche_liste(&L);}


/***insere_pos_av***/
void insere_pos_av (struct avion av,liste* ll,struct cellule *n)
{   struct cellule *q;
    q = (struct cellule  *)malloc(sizeof(struct cellule ));
    q->info = av;
    q->suivant = n->suivant;
    n->suivant = q;
}
unsigned verifAlpha(char *ch){
    int i;
    for(i = 0;i<strlen(ch);i++){
        if(!isalpha(ch[i])){
            return 0;
        }
    }
    return 1;
}
unsigned verifNumerique(char ch[3]){

int i, ret;
ret=1;

for(i=0;i<strlen(ch)-1;i++)
{
      if(ch[i] <'a' || ch[i] >'z')
          ret=0;
          break;
}
return ret;
}

   int valide( char heure[] )
{
    int i,k,h,m;
    char hh[3]="", mm[3]="";
    strncpy(hh,heure,2);
    for(i=3,k=0;i<5;i++)
        mm[k++]=heure[i];
    mm[k]='\0';
    h=atoi(hh);
    m=atoi(mm);
    return ((((0<=h)&&(h<=23)&&(0<=m)&&(m<=59))));
}
void enregistrement(liste *l)
{
    if(!liste_vide(l))
    {
        struct cellule *aux=l->premier;
    FILE *fic=fopen("repertoire_avion.txt","w"); //lecture+ecriture fin fichier
    if(fic==NULL)
        printf("ce fichier n'existe pas\n");
    else
    {
        while(aux)
        {
        fprintf(fic,"\n%s|%d|%d|%s|%s|%s|\n",aux->info.identifiant,aux->info.carburant,aux->info.consommation,aux->info.heure_decollage,aux->info.comp->nom,aux->info.comp->acronyme);
        aux=aux->suivant;
        }
    fclose(fic);
    }
    }
    else
        printf("La liste est vide veuillez le remplir !\n");
}
/******CHARGEMENT*****/
//Fonction qui remplir une cellule a partir d'une chaine sous la  forme : id|consomation|...|acronyme|
void remplirNoeudAvion(liste *ll,char *ch){
    char *aux;
    int n;
    avion *cle;



    aux = (char *)malloc(50);
    cle = (avion *)malloc(sizeof(avion));
    cle->comp = (compagnie *)malloc(sizeof(compagnie));



    cle->comp->nom = (char *)malloc(50);



    n = strchr(ch,'|') - ch+1;
    strncpy(aux,ch,n-1);
    strcpy(cle->identifiant,aux);
    ch+=n;



    n = strchr(ch,'|') - ch+1;
    strncpy(aux,ch,n-1);
    cle->carburant = atoi(aux);
    ch+=n;



    n = strchr(ch,'|') - ch+1;
    strncpy(aux,ch,n-1);
    cle->consommation = atoi(aux);
    ch+=n;



    n = strchr(ch,'|') - ch+1;
    strncpy(aux,ch,n-1);
    strcpy(cle->heure_decollage,aux);
    ch+=n;



    n = strchr(ch,'|') - ch+1;
    strncpy(aux,ch,n-1);
    strcpy(cle->comp->nom,aux);
    ch+=n;



    n = strchr(ch,'|') - ch+1;
    strncpy(aux,ch,n-1);
    strcpy(cle->comp->acronyme,aux);
    struct cellule *q=(struct cellule *)malloc(sizeof(struct cellule));
    q->info=*cle;
    q->suivant=ll->premier;
    ll->premier=q;
    if(ll->premier->suivant==NULL)
        ll->dernier=q;



}
//contenu d'un fichier vers une liste
void chargement(liste *ll){
    FILE *f;
    char *ch;
    ch = (char *)malloc(1000);
    f = fopen("repertoire_avion.txt","a");
        while(fgets(ch,1000,f)!=NULL)
        {
            remplirNoeudAvion(ll,ch);
        }
    fclose(f);
}
