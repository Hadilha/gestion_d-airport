#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include  "myconio.h"
#include <assert.h>
#include <ctype.h>
typedef struct compagnie{
 char* nom;
 char acronyme[4];
 }compagnie;
typedef struct avion{
    char identifiant[7];
    int carburant;
    int consommation;
    char heure_decollage[5];
    compagnie* comp;
}avion;
struct cellule{
    avion info;
    struct cellule *suivant ;
 };
typedef struct liste{
   struct cellule *premier;
   struct  cellule *dernier;
}liste;
liste *creer_liste();
int liste_vide(liste*);
int taille_liste_av(liste*);
unsigned TEST(liste *,char *,char *);
void TESTT(liste*);
void TESTcomp(liste *);
void TESThdec(liste *);
struct cellule *TEST2(liste *,char *);
 avion SAISIE_AVION();
void insere_queue_av(struct avion  ,liste* );
void insere_tete_av(struct avion ,liste*);
void insere_pos_av (struct avion ,liste*,struct cellule *);
liste * CREATION();
void affiche_liste(liste *);
int recherche_av(struct avion* ,liste*);
void recherche_id (char* ,  liste *);
struct cellule *recherche_compagnie(liste *,char *);
struct cellule *recherche_heure(liste *,char *);
void affiche_cellule(struct cellule *);
void supprimer_dernier(liste *);
void supprime_apres(liste *,struct cellule *);
void supprimer_premier(liste *L);
void suppression_av_donne(liste *);
void suppression_comp_donne(liste *);
void TRI1(liste *);
struct  cellule*pos(liste *);
void inserer_pos(liste *,struct avion );
void suppression_pos_av(liste *);
void modifie_identifiant(liste );
void modifie_Compagnie(liste  );
void chargement(liste *);
void enregistrement(liste *);
unsigned verifNumerique(char []);
unsigned verifAlpha(char *);
void remplirNoeudAvion(liste *,char *);
int valide(char[]);
unsigned TEST(liste *,char *,char *);


#endif // LISTE_H_INCLUDED
