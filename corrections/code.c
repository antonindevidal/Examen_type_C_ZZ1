#include "code.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void compter_chiffres(char *s,int * rep){
	int i = 0, number;

	//On initialise le tableau de résultat avec des 0
	//On ne sait pas ce qu'il y a dans le tableau donc si on oublie cette partie, 
	//il y aurait des valeurs totalement randoms dedans
	for (int j = 0;j<10;j++){
		rep[j] = 0;
	}

	while (s[i] != '\0'){ //On parcours la chaine de caractères en entier 
		number = s[i] - '0'; //Pour convertir un char en int on enlève le caractère '0' qui équivaut à 49 dans la table ASCII
		rep[number]++; //Les chiffres correspondent directement à leurs indices dans le tableau donc il ne reste plus qu'à incrémenter la valeur
		i++;
	}
}

void exo2(char *s, char* r){
	//Pour chaque caractères, on va compter son nombre d'occurence d'affilé

	int i = 0,cpt =0;
	char en_cours;

	while(s[i] != '\0'){ //On parcours toute la chaine de carac
		cpt = 1;
		en_cours = s[i];
		i++;
		while(s[i]!='\0' && s[i] == en_cours){ // Tant que le carac suivant et le même et que on est pas à la fin
			i++; //On passe au carac suivant
			cpt++; //On incrément notre compteur d'occurences
		}

		if(cpt >1){//Quand on a plus d'une occurence on écrit le_carac*nb_occurences
			
			//Le sprintf c'est comme printf mais au lieu de mettre le résultat dans la console, on l'écrit dans une variable
			sprintf(r,"%s%c*%d ",r,en_cours,cpt);
		}else{ // On ajoute juste le carac en cours et un espace
			sprintf(r,"%s%c ",r,en_cours);
		}
	}

	//Vu qu'on ajoute un espace à chaque fois, il faut supprimer le dernier
	r[strlen(r)-1] = '\0'; //strlen -> taille de la chaine de caractères
}

int** creation_grille(int n){
	// int ** grille -> un tableau à 2 dimensions est un tableau de tableau de int (on met autant d'étoiles que de dimensions souhaités)
	// (int**) -> type de la variable (ici grille est bien de type int**)
	// n*sizeof(int) -> grille est un tableau de tableau d'entier, du coup le type des éléments de grille est un tableau d'entier (int*)
	int **grille = (int**) malloc(n*sizeof(int*)); // On alloue le premier tableau de taille n

	if(grille == NULL) return NULL;// Toujours vérifier que l'allocation s'est bien passée

	//Pour chaque cases de ce tableau on alloue un tableau de taille n
	for(int i =0;i<n;i++){ 
		grille[i] = (int*) malloc(n*sizeof(int));//On alloue
		if(grille[i] == NULL) return NULL;//Vérification

		for(int j =0;j<n;j++){
			grille[i][j] = 0; //Dans chaque cases on met 0
		}
	}
	return grille;//On retourne la grille
}

void liberation_grille(int ** grille,int n){
	if(grille != NULL){ // On vérifie que la variable passée à bien été allouée

		//Il faut bien libérer en premier chaque éléments de la grille avant la grille en elle même
		//On free toujours dans le sens inverse ou on malloc
		for(int i =0 ; i<n ; i++){
			free(grille[i]); //On libère chaque éléments de la grille
		}
		free(grille);//On libère la grille
	}
}

int** lecture_coordonees(int ** grille, int n, char * fichier){
	int x,y;
	FILE *fe = fopen(fichier,"r");// Ouverture du fichier

	if(fe != NULL){//Vérifier que l'ouverture s'est bien passée

		while(!feof(fe)){ //Tant qu'on est pas à la fin du fichier
			fscanf(fe,"%d%d",&x,&y); //Lecture d'une paire de coordonées
			if( x >0 && x < n && y >0 && y < n){ //Bien vérifier que les coordonnées sont biens compris dans la taille de la matrice
				grille[x][y] =1; //On met 1 dans la case de coordonées x y
			}
		}
		fclose(fe); //Bien fermer le fichier
	}
	return grille;
}

int** touche(int **grille, int n, int x, int y){
	if( x >0 && x < n && y >0 && y < n){ //Bien vérifier que les coordonnées sont biens compris dans la taille de la matrice
		
		if(grille[x][y] == 1){
			grille[x][y] = 2;
		}else{
			grille[x][y] = 3;
		}
	}
	return grille;
}

int fini(int **grille, int n){
	//Parcours de toute la grille 
	for(int i =0;i <n;i++){
		for(int j = 0;j<n;j++){
			if(grille[i][j] ==1){// Si on tombe sur un bateau, on sait que la partie n'est pas finie donc on retourne 0
				return 0;
			}
		}
	}
	return 1;//La partie est finie
}


void exo4(char *s){
	int i = 0;
	while(s[i] != '\0'){
		if ( s[i] <= 'z' && s[i] >= 'a' && i%2 ==0){ //Le modulo 2 permet de traiter que un caractère sur 2
			s[i] = s[i] +'A' - 'a';
		}
		i++;
	}
}