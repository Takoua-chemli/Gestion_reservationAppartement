#include <stdio.h>
#include <stdbool.h>

#define NUM_ETAGES 5
#define APP_PAR_ETAGE 3
#define NB_SEMAINES 52

// Structure pour représenter un appartement
typedef struct {
    int numApp;
    bool R[NB_SEMAINES];
} Appartement;

// Fonction pour remplir la liste des appartements
void Remplir(Appartement L[]) {
    int numApp = 0;
    for (int etage = 1; etage <= NUM_ETAGES; etage++) {
        for (int app = 1; app <= APP_PAR_ETAGE; app++) {
            L[numApp].numApp = etage * 10 + app;
            for (int semaine = 0; semaine < NB_SEMAINES; semaine++) {
                L[numApp].R[semaine] = false; // Initialiser toutes les semaines à non réservées
            }
            numApp++;
        }
    }
}

// Fonction pour afficher les appartements disponibles pour une semaine donnée
void DispSem(Appartement L[], int semaine) {
    printf("Appartements disponibles pour la semaine %d :\n", semaine);
    for (int i = 0; i < NUM_ETAGES * APP_PAR_ETAGE; i++) {
        if (L[i].R[semaine - 1] == false) { // Vérifier si l'appartement est disponible pour la semaine donnée
            printf("Appartement %d\n", L[i].numApp);
        }
    }
}

// Fonction pour trouver le premier appartement disponible sur un étage donné pour une semaine donnée
int AppDisp(Appartement L[], int etage, int semaine) {
    for (int i = 0; i < NUM_ETAGES * APP_PAR_ETAGE; i++) {
        if (L[i].numApp / 10 == etage && L[i].R[semaine - 1] == false) {
            return L[i].numApp;
        }
    }
    return -1; // Aucun appartement disponible trouvé
}

// Fonction pour réserver un appartement pour une semaine donnée
void Reserver(Appartement L[], int numApp, int semaine) {
    for (int i = 0; i < NUM_ETAGES * APP_PAR_ETAGE; i++) {
        if (L[i].numApp == numApp) {
            if (L[i].R[semaine - 1] == true) {
                printf("L'appartement %d est deja reserve pour la semaine %d.\n", numApp, semaine);
            } else {
                L[i].R[semaine - 1] = true;
                printf("L'appartement %d a ete reserve pour la semaine %d.\n", numApp, semaine);
            }
            return;
        }
    }
    printf("L'appartement %d n'a pas ete trouve.\n", numApp);
}

int main() {
    Appartement T[NUM_ETAGES * APP_PAR_ETAGE];
    int choix;

    Remplir(T);

    do {
        printf("\nMenu :\n");
        printf("1. Afficher les appartements disponibles pour une semaine\n");
        printf("2. Trouver le premier appartement disponible sur un etage donne pour une semaine donnee\n");
        printf("3. Reserver un appartement pour une semaine donnee\n");
        printf("4. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: {
                int semaine;
                printf("Entrez le numero de la semaine : ");
                scanf("%d", &semaine);
                DispSem(T, semaine);
                break;
            }
            case 2: {
                int etage, semaine;
                printf("Entrez le numero de l'etage : ");
                scanf("%d", &etage);
                printf("Entrez le numero de la semaine : ");
                scanf("%d", &semaine);
                int numApp = AppDisp(T, etage, semaine);
                if (numApp != -1) {
                    printf("Le premier appartement disponible sur l'etage %d pour la semaine %d est l'appartement %d.\n", etage, semaine, numApp);
                } else {
                    printf("Aucun appartement disponible trouvé sur l'etage %d pour la semaine %d.\n", etage, semaine);
                }
                break;
            }
            case 3: {
                int numApp, semaine;
                printf("Entrez le numero de l'appartement : ");
                scanf("%d", &numApp);
                printf("Entrez le numero de la semaine : ");
                scanf("%d", &semaine);
                Reserver(T, numApp, semaine);
                break;
            }
            case 4:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
                break;
        }
    } while (choix != 4);

    return 0;
}
