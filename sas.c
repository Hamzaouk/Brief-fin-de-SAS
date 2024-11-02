#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TACHES 100

struct Date {
    int jour;
    int mois;
    int annee;
};

struct Tache {
    char titre[50];
    char desc[100];
    struct Date date;
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
void Vdate(struct Tache *t);

int main() {
    int choix;

    do {
        printf("\n--- Menu des taches ---\n");
        printf("1. Ajouter une tache\n");
        printf("2. Afficher toutes les taches\n");
        printf("3. Modifier une tache\n");
        printf("4. Supprimer une tache\n");
        printf("5. Quitter\n");
        printf("6. Filtrer les taches par priorite\n");
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


void Vdate(struct Tache *t) {
    do {
        printf("Entrer la date :\n");
        printf("Jour (entre 1 et 31): ");
        scanf("%d", &t->date.jour);
    } while (t->date.jour > 31);

    do {
        printf("Mois (entre 1 et 12): ");
        scanf("%d", &t->date.mois);
    } while (t->date.mois > 12);

    do {
        printf("Annee (2024 ou grande annee): ");
        scanf("%d", &t->date.annee);
    } while (t->date.annee < 2024);
}
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
 // Vdate fonction pour verifier la date
    Vdate(&t);

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
        printf("Date : %02d-%02d-%04d\n", taches[i].date.jour, taches[i].date.mois, taches[i].date.annee); //Date: DD-MM-YYYY
        printf("Priorite : %s\n", taches[i].prio);
        printf("Statut : %s\n", taches[i].statut);
    }
}
