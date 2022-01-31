#ifndef CODE_EXO1
#define CODE_EXO1


void compter_chiffres(char *s,int * rep);
void  exo2(char *s,char * r);
int** creation_grille(int n);
void liberation_grille(int ** grille,int n);
int** lecture_coordonees(int ** grille, int n, char * fichier);
int** touche(int **grille, int n, int x, int y);
int fini(int **grille, int n);
void exo4(char *s);

#endif