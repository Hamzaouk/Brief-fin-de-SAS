#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TACHES 100

struct Tache {
    char titre[50];
    char desc[100];
    char date[11];
    char prio[5];
    char statut[10];
};

struct Tache taches[MAX_TACHES];
int n_tch = 0;


void ajout_tch();
void affiche_tch();
void modif_tch();
void suppr_tch();
