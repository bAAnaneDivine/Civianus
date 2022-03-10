// Mise en oeuvre contigue d'une liste d'entiers 
#define TAILLE_MAX 100
#include<stdio.h>

// Declaration du tableau contenant les elements de liste
int liste[TAILLE_MAX];
// Declaration des indices de queue et d'element courant
int queue, ec;

void init_liste(void){
// Initialise la liste a vide

	queue = -1;
	ec = -1;
}

int liste_vide(void){
// Rend vrai si la liste est vide, faux sinon

	return (queue== -1);
}

int hors_liste(void){
// Rend vrai si l'elt courant est hors de la liste, faux sinon

	return(ec < 0 || ec > queue);
}

void en_tete(void){
// Positionne en tete de la liste

	if(!liste_vide())
		ec = 0;
}

void en_queue(void){
// Positionne en queue de la liste

	if(!liste_vide())
		ec = queue;
}

void precedent(void){
// Positionne sur l'elt precedent

	if(!hors_liste())
		ec--;
}

void suivant(void){
// Positionne sur l'elt suivant

	if(!hors_liste())
		ec++;
}

void valeur_elt(int* v){
// Renvoie dans v la valeur de l'elt courant

	if(!hors_liste())
		*v= liste[ec];
}

void modif_elt(int v){
// Affecte v a l'elt courant

	if(!hors_liste())
		liste[ec]=v;
}

void oter_elt(void){
// Supprime l'elt courant et positionne sur le precedent

	int i;
	if(!hors_liste()){
		for(i=ec;i<queue;i++)
			liste[i]=liste[i+1];
		ec--; queue--;
	}
}

void ajout_droit(int v){
// Ajoute v a droite de l'elt courant

	int i;

	if(liste_vide()||!hors_liste()){
		for(i=queue;i>ec;i--)
			liste[i+1]=liste[i];
		liste[ec+1]=v;
		ec++; queue++;
	}
}

void ajout_gauche(int v){
// Ajoute v a gauche de l'elt courant

	int i;

	if(liste_vide())
		ec++;

	if(liste_vide()||!hors_liste()){
		for(i=queue;i>=ec;i--)
			liste[i+1]=liste[i];
		liste[ec]=v;
		queue++;
	}
}
