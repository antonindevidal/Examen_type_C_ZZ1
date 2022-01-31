/*
 * REMPLACER LES NOMS DES FONCTIONS PAR LES VOTRES
 * DANS LES FICHIERS VOTRECODE.H et VOTRECODE.C
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#include "code.h"
#include "teZZt.h"


// DEBUT DES FONCTIONS DE TESTS
BEGIN_TEST_GROUP(exos)

/*
TEST(EXO1, "") {

    int tab_rep[10],tab_rep2[10];
    int tab[10] = {0,1,1,1,2,3,0,0,1,1};
    int tab2[10] = { 0,0,0,0,0,0,0,0,0,0};

    compter_chiffres("5534528491",tab_rep);
    CHECK(tab[0] == tab_rep[0]
        &&tab[1] == tab_rep[1]
        &&tab[2] == tab_rep[2]
        &&tab[3] == tab_rep[3]
        &&tab[4] == tab_rep[4]
        &&tab[5] == tab_rep[5]
        &&tab[6] == tab_rep[6]
        &&tab[7] == tab_rep[7]
        &&tab[8] == tab_rep[8]
        &&tab[9] == tab_rep[9]);

    compter_chiffres("",tab_rep2);
    CHECK(tab2[0] == tab_rep2[0]
        &&tab2[1] == tab_rep2[1]
        &&tab2[2] == tab_rep2[2]
        &&tab2[3] == tab_rep2[3]
        &&tab2[4] == tab_rep2[4]
        &&tab2[5] == tab_rep2[5]
        &&tab2[6] == tab_rep2[6]
        &&tab2[7] == tab_rep2[7]
        &&tab2[8] == tab_rep2[8]
        &&tab2[9] == tab_rep2[9]);
}
*/

/*
TEST(EXO2, "") {

    char * s1 = "553444";
    char r1[50] ="";
    exo2(s1,r1);
    CHECK(0 == strcmp(r1,"5*2 3 4*3"));
}
*/

/*
TEST(CREATION_GRILLE, "") {

    int verif=0;
    int **grille =creation_grille(10);
    if(grille == NULL){
        CHECK(0);
        printf("Erreur lors de l'allocation de la grille");
        exit(-1);
    }
    for(int i =0; i< 10;i++){
        for (int j =0;j <10;j++){
            if(grille[i][j] !=0){
                verif =1;
            }
        }
    }
    CHECK(0 == verif);
}
*/

/*
TEST(LIBERATION_GRILLE, "") {

    int **grille2 =NULL;
    int **grille =creation_grille(10);
    if(grille == NULL){
        printf("Erreur lors de l'allocation de la grille");
        exit(-1);
    }
    liberation_grille(grille,10);
    liberation_grille(grille2,10);   
}
*/

/*
TEST(LECTURE_COORDONEES1, "") {

    int **grille =creation_grille(10);
    if(grille == NULL){
        printf("Erreur lors de l'allocation de la grille");
        exit(-1);
    }

    grille =lecture_coordonees(grille,10,"coords.txt");
    CHECK(
        grille[2][2] == 1 &&
        grille[1][3] == 1 &&
        grille[5][8] == 1 &&
        grille[8][5] == 0);

    liberation_grille(grille,10);
}
*/

/*
TEST(LECTURE_COORDONEES2, "") {

    int **grille =creation_grille(10);
    if(grille == NULL){
        printf("Erreur lors de l'allocation de la grille");
        exit(-1);
    }

    grille =lecture_coordonees(grille,10,"coords2.txt");
    CHECK(
        grille[3][3] == 1 &&
        grille[1][1] == 1 &&
        grille[6][3] == 1 &&
        grille[3][6] == 0);

    liberation_grille(grille,10);
}
*/

/*
TEST(LECTURE_COORDONEES3, "") {

    int **grille =creation_grille(10);
    if(grille == NULL){
        printf("Erreur lors de l'allocation de la grille");
        exit(-1);
    }

    grille =lecture_coordonees(grille,10,"ce_fichier_nesxiste_pas.txt");
    CHECK(1);

    liberation_grille(grille,10);
}
*/

/*
TEST(TOUCHE, "") {

    int **grille =creation_grille(10);
    if(grille == NULL){
        printf("Erreur lors de l'allocation de la grille");
        exit(-1);
    }

    grille =lecture_coordonees(grille,10,"coords.txt");

    grille = touche(grille,10,2,2);
    grille = touche(grille,10,8,5);

    CHECK(grille[2][2] == 2);
    CHECK(grille[8][5] == 3);
    CHECK(grille[1][3] == 1);
    CHECK(grille[1][1] == 0);
    liberation_grille(grille,10);
}
*/

/*
TEST(FINI, "") {

    int **grille =creation_grille(10);
    if(grille == NULL){
        printf("Erreur lors de l'allocation de la grille");
        exit(-1);
    }

    grille =lecture_coordonees(grille,10,"coords.txt");

    grille = touche(grille,10,2,2);
    grille = touche(grille,10,1,3);
    CHECK(fini(grille,10) == 0);


    grille = touche(grille,10,5,8);
    CHECK(fini(grille,10) == 1);

    liberation_grille(grille,10);
}
*/

/*
TEST(EXO4, "") {
    char s[50];
    strcpy(s,"hello world");
    exo4(s);
    CHECK(strcmp(s,"HeLlO WoRlD") == 0);
}
*/

END_TEST_GROUP(exos)


int main() {
    RUN_TEST_GROUP(exos); 
 
   return 0;
}

