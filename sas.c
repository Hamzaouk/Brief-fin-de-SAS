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
void filtre_p();


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
            case 5:
                printf("Quitte.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 5);


    return 0;
}

//fonction d'ajouter les taches
void ajout_tch() {
    if (n_tch >= MAX_TACHES) {
        printf("La liste des taches est pleine.\n");
        return;
    }

    struct Tache t;
    printf("Titre de la tache : ");
    scanf(" %[^\n]s", t.titre);

    printf("Description : ");
    scanf(" %[^\n]s", t.desc);

    printf("Date d'echeance (JJ-MM-AAAA) : ");
    scanf(" %[^\n]s", t.date);

    printf("Priorite (High/Low) : ");
    scanf(" %[^\n]s", t.prio);

    printf("Statut (Complete/Incomplete) : ");
    scanf(" %[^\n]s", t.statut);

    taches[n_tch++] = t;
    printf("Tache ajoutee avec succes.\n");
}
void affiche_tch() {
    if (n_tch == 0) {
        printf("Pas de taches.\n");
        return;
    }

    for (int i = 0; i < n_tch; i++) {
        printf("Tache %d :\n", i + 1);
        printf("Titre : %s\n", taches[i].titre);
        printf("Description : %s\n", taches[i].desc);
        printf("Date d'echeance : %s\n", taches[i].date);
        printf("Priorite : %s\n", taches[i].prio);
        printf("Statut : %s\n", taches[i].statut);
    }
}


