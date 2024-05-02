#include <stdio.h>
#include <stdbool.h>

#define NUM_ETAGES 5
#define APP_PAR_ETAGE 3
#define NB_SEMAINES 52

// Structure pour repr�senter un appartement
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
                L[numApp].R[semaine] = false; // Initialiser toutes les semaines � non r�serv�es
            }
            numApp++;
        }
    }
}

// Fonction pour afficher les appartements disponibles pour une semaine donn�e
void DispSem(Appartement L[], int semaine) {
    printf("Appartements disponibles pour la semaine %d :\n", semaine);
    for (int i = 0; i < NUM_ETAGES * APP_PAR_ETAGE; i++) {
        if (L[i].R[semaine - 1] == false) { // V�rifier si l'appartement est disponible pour la semaine donn�e
            printf("Appartement %d\n", L[i].numApp);
        }
    }
}

// Fonction pour trouver le premier appartement disponible sur un �tage donn� pour une semaine donn�e
int AppDisp(Appartement L[], int etage, int semaine) {
    for (int i = 0; i < NUM_ETAGES * APP_PAR_ETAGE; i++) {
        if (L[i].numApp / 10 == etage && L[i].R[semaine - 1] == false) {
            return L[i].numApp;
        }
    }
    return -1; // Aucun appartement disponible trouv�
}

// Fonction pour r�server un appartement pour une semaine donn�e
void Reserver(Appartement L[], int numApp, int semaine) {
    for (int i = 0; i < NUM_ETAGES * APP_PAR_ETAGE; i++) {
        if (L[i].numApp == numApp) {
            if (L[i].R[semaine - 1] == true) {
                printf("L'appartement %d est d�j� r�serv� pour la semaine %d.\n", numApp, semaine);
            } else {
                L[i].R[semaine - 1] = true;
                printf("L'appartement %d a �t� r�serv� pour la semaine %d.\n", numApp, semaine);
            }
            return;
        }
    }
    printf("L'appartement %d n'a pas �t� trouv�.\n", numApp);
}
