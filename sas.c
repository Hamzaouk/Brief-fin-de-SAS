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


//fonction main
int main(){
 int choix;

    do {
        printf("\n--- Menu des taches ---\n");
        printf("1. Ajouter une tache\n");
        printf("2. Afficher toutes les taches\n");
        printf("3. Modifier une tache\n");
        printf("4. Supprimer une tache\n");
        printf("5. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajout_tch();
                break;
            case 2:
                affiche_tch();
                break;
            case 3:
                modif_tch();
                break;
            case 4:
                suppr_tch();
                break;
            case 5:
                printf("Quitte.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 5);


    return 0;
}
