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
    int prio; // 0 for Low, 1 for High
    int statut; // 0 for Incomplete, 1 for Complete
};

struct Tache taches[MAX_TACHES];
int n_tch = 0;

void ajout_tch();
void affiche_tch();
void modif_tch();
void suppr_tch();
void filtre_p();
void Vdate(struct Tache *t);
void Vprio(struct Tache *t);
void Vstatut(struct Tache *t);

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

void Vdate(struct Tache *t) {
    do {
        printf("Entrer la date :\n");
        printf("Jour (entre 1 et 31): ");
        scanf("%d", &t->date.jour);
    } while (t->date.jour < 1 || t->date.jour > 31);

    do {
        printf("Mois (entre 1 et 12): ");
        scanf("%d", &t->date.mois);
    } while (t->date.mois < 1 || t->date.mois > 12);

    do {
        printf("Annee (2024 ou grande annee): ");
        scanf("%d", &t->date.annee);
    } while (t->date.annee < 2024);
}

void Vprio(struct Tache *t) {
    do {
        printf("Priorite (High = 1 / Low = 0) : ");
        scanf("%d", &t->prio);
    } while (t->prio != 0 && t->prio != 1);
}

void Vstatut(struct Tache *t) {
    do {
        printf("Staut (Incomplete = 1 / Complete = 0) : ");
        scanf("%d", &t->statut);
    } while (t->statut != 0 && t->statut != 1);
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

    // Fonction pour verifier la date
    Vdate(&t);

    // Fonction pour priorite
    Vprio(&t);

     // Fonction de statut
    Vstatut(&t);

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
        printf("Date : %02d-%02d-%04d\n", taches[i].date.jour, taches[i].date.mois, taches[i].date.annee);
        printf("Priorite : %s\n", (taches[i].prio == 1) ? "High" : "Low");
        printf("Statut : %s\n", (taches[i].statut == 1) ? "Incomplete" : "Complete");
    }
}

void modif_tch() {
    int index;
    printf("Tache a modifier (index) : ");
    scanf("%d", &index);

    if (index < 1 || index > n_tch) {
        printf("Index invalide.\n");
        return;
    }

    index=index-1; // la base 0
    printf("Modification de la Tache %d :\n", index + 1);
    //Modifier le titre
    printf("Nouveau titre (actuel: %s) : ", taches[index].titre);
    scanf(" %[^\n]s", taches[index].titre);

    //Modifier description
    printf("Nouvelle description (actuelle: %s) : ", taches[index].desc);
    scanf(" %[^\n]s", taches[index].desc);

    //Modifier date
    printf("Nouveau jour (actuel est: %d) : ", taches[index].date.jour);
    scanf("%d", &taches[index].date.jour);

    printf("Nouveau mois (actuel est: %d) : ", taches[index].date.mois);
    scanf("%d", &taches[index].date.mois);

    printf("Nouvelle annee (actuelle est: %d) : ", taches[index].date.annee);
    scanf("%d", &taches[index].date.annee);

    //Modifier priorite et statut
    printf("Nouvelle priorite (actuelle est: %d) : ", taches[index].prio);
    scanf("%d", &taches[index].prio);

    printf("Nouvelle statut (actuelle est: %d) : ", taches[index].statut);
    scanf("%d", &taches[index].statut);


    printf("Tache ete modifiee .\n");
}



void suppr_tch() {
    int index;
    printf("Tache a supprimer (index) : ");
    scanf("%d", &index);

    if (index < 1 || index > n_tch) {
        printf("Index invalide.\n");
        return;
    }

    index=index-1; // la base 0
    for (int i = index; i < n_tch - 1; i++) {
        taches[i] = taches[i + 1];
    }
    n_tch=n_tch-1; // Réduire la tâches
    printf("Tache est supprimee.\n");
}
