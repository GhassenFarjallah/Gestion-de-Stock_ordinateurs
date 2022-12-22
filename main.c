#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include<stdlib.h>
#include <string.h>
typedef struct {
    char modele[10];
    int nb_coeurs;
    int frequence;
    int memoire_cache;
}CPU;

typedef struct {
    char type_disque_dur[5];
    int  capacite_stockage;
}Stockage;

typedef struct{
    int ref;
    char marque[18];
    Stockage S;
    int RAM;
    char systeme_exploitation[10];
    int  taille_ecran;
    char carte_graphique[15];
    char type_clavier[5];
    int prix;
    int poids;
    CPU p;
    int autonomie;
}Ordinateur;



typedef struct Noeud {
    Ordinateur ordinateur;
    int quantite;
    struct Noeud *suivant;
} Noeud;

Noeud * creerNoeud(Ordinateur ordinateur, int quantite) {
    Noeud *nouveau = (Noeud *) malloc(sizeof(Noeud));
    nouveau->ordinateur = ordinateur;
    nouveau->quantite = quantite;
    nouveau->suivant = NULL;
    return nouveau;
}

static int i=0;

int sontEgaux(Ordinateur ordinateur1,Ordinateur ordinateur2){
    if (strcmp(ordinateur1.marque, ordinateur2.marque) == 0 &&
        strcmp(ordinateur1.S.type_disque_dur, ordinateur2.S.type_disque_dur) == 0 &&
        ordinateur1.S.capacite_stockage == ordinateur2.S.capacite_stockage &&
        ordinateur1.RAM == ordinateur2.RAM &&
        strcmp(ordinateur1.systeme_exploitation, ordinateur2.systeme_exploitation) == 0 &&
        ordinateur1.taille_ecran == ordinateur2.taille_ecran &&
        strcmp(ordinateur1.p.modele, ordinateur2.p.modele) == 0 &&
        ordinateur1.p.memoire_cache == ordinateur2.p.memoire_cache &&
        ordinateur1.p.nb_coeurs == ordinateur2.p.nb_coeurs &&
        ordinateur1.p.frequence == ordinateur2.p.frequence &&
        strcmp(ordinateur1.type_clavier, ordinateur2.type_clavier) == 0 &&
        strcmp(ordinateur1.carte_graphique, ordinateur2.carte_graphique) == 0 &&
        ordinateur1.autonomie == ordinateur2.autonomie &&
        ordinateur1.poids == ordinateur2.poids &&
        ordinateur1.prix == ordinateur2.prix)
        return 1;
    else
        return 0;
}

void ajouterAuStock(Noeud **tete, Ordinateur ordinateur, int quantite) {
    Noeud *courant = *tete;

    while (courant != NULL) {
        if (sontEgaux(courant->ordinateur ,ordinateur) ==1) {
            courant->quantite += quantite;
            break;
        }
        courant = courant->suivant;
    }
    Noeud *nouveau = creerNoeud(ordinateur, quantite);
    nouveau->suivant = *tete;
    *tete = nouveau;
}



void ajout(Noeud **head, Ordinateur ordinateur, int quantite){
    i++;
    printf("Donner les caracteristiques de l'ordinateur N %d ", i );
    printf("\n Donner la reference : ");
    scanf("%d", &ordinateur.ref); // (*T[i]).ref
    printf("la marque : ");
    scanf("%s", &ordinateur.marque);
    printf("Donner le type disque dur (HDD/SSD) : ");
    scanf("%s", &(ordinateur.S.type_disque_dur));
    printf("Donner la capacite de stockage (To) : ");
    scanf("%d", &(ordinateur.S.capacite_stockage));
    printf("Donner la  RAM : ");
    scanf("%d", &ordinateur.RAM);
    printf("Donner le systeme_exploitation : ");
    scanf("%s", &ordinateur.systeme_exploitation);
    printf("Donner la taille_ecran (pouces): ");
    scanf("%d", &ordinateur.taille_ecran);
    printf("Donner la carte_graphique : ");
    scanf("%s", &ordinateur.carte_graphique);
    printf("Donner le type_clavier retroeclaire (oui/non) : ");
    scanf("%s", &ordinateur.type_clavier);
    printf("Donner le prix (DT): ");
    scanf("%d", &ordinateur.prix);
    printf("Donner le poids (kg) : ");
    scanf("%d", &ordinateur.poids);
    printf("Donner l'autonomie (heures) : ");
    scanf("%d", &ordinateur.autonomie);
    printf("Donner modele du CPU : ");
    scanf("%s", &(ordinateur.p.modele));
    printf("Donner le nb_coeurs du CPU : ");
    scanf("%d", &(ordinateur.p.nb_coeurs));
    printf("Donner la frequence d'horloge du CPU (Hz) : ");
    scanf("%d", &(ordinateur.p.frequence));
    printf("Donner memoire cache du CPU : ");
    scanf("%d", &(ordinateur.p.memoire_cache));
    ajouterAuStock( &(*head), ordinateur,quantite);

}

void delete_computer(Noeud** head, int ref) {
    Noeud* current = *head;
    Noeud* previous = NULL;

    // Recherche de l'ordinateur à supprimer
    while (current != NULL && current->ordinateur.ref != ref) {
        previous = current;
        current = current->suivant;
    }

    // Si l'ordinateur n'a pas été trouvé, on quitte la fonction
    if (current == NULL) {
        printf("l'ordinateur n'existe pas dans le stock");
        return;
    }

    // Si l'ordinateur à supprimer est le premier de la liste
    if (current->ordinateur.ref == ref) {
        *head = current->suivant;
        free(current);
        return;
    }
        // Sinon, on relie l'ordinateur précédent à l'ordinateur suivant
    else {
        previous->suivant = current->suivant;
        free(current);
        return;
    }

}

Noeud *rechercherOrdinateur(Noeud *liste, int ref) {
    Noeud *noeudActuel = liste;

    while (noeudActuel != NULL) {
        if (noeudActuel->ordinateur.ref == ref) {
            return noeudActuel;
        }
        noeudActuel = noeudActuel->suivant;
    }

    return NULL;
}

void recherche(Noeud *liste, int ref){
    Noeud *resultat = rechercherOrdinateur(liste, ref);
    if (resultat != NULL)
        printf("Ordinateur trouve! Marque: %s, RAM: %d\n", resultat->ordinateur.marque, resultat->ordinateur.RAM);
    else
        printf("Ordinateur non trouve\n");
}





void modifierOrdinateur(Noeud *noeud, Ordinateur nouvellesValeurs) {
    noeud->ordinateur.ref = nouvellesValeurs.ref;
    strcpy(noeud->ordinateur.marque , nouvellesValeurs.marque);
    strcpy(noeud->ordinateur.p.modele, nouvellesValeurs.p.modele);
    noeud->ordinateur.p.nb_coeurs = nouvellesValeurs.p.nb_coeurs;
    noeud->ordinateur.p.frequence = nouvellesValeurs.p.frequence;
    noeud->ordinateur.p.memoire_cache = nouvellesValeurs.p.memoire_cache;
    strcpy(noeud->ordinateur.S.type_disque_dur, nouvellesValeurs.S.type_disque_dur);
    noeud->ordinateur.S.capacite_stockage = nouvellesValeurs.S.capacite_stockage;
    noeud->ordinateur.RAM = nouvellesValeurs.RAM;
    strcpy(noeud->ordinateur.systeme_exploitation, nouvellesValeurs.systeme_exploitation);
    noeud->ordinateur.taille_ecran = nouvellesValeurs.taille_ecran;
    strcpy(noeud->ordinateur.carte_graphique, nouvellesValeurs.carte_graphique);
    strcpy(noeud->ordinateur.type_clavier, nouvellesValeurs.type_clavier);
    noeud->ordinateur.prix = nouvellesValeurs.prix;
    noeud->ordinateur.poids = nouvellesValeurs.poids;
    noeud->ordinateur.autonomie = nouvellesValeurs.autonomie;
}

void modification(Noeud *liste,Ordinateur nouvellesValeurs,int ref) {

    Noeud *noeud = rechercherOrdinateur(liste, ref);

    if (noeud != NULL) {
        modifierOrdinateur(noeud, nouvellesValeurs);
    }
}

void afficherOrdinateur(Noeud *liste,int ref) {/*void afficherOrdinateur(Noeud *liste,Ordinateur ordinateur,int ref)*/
    Noeud *noeud = rechercherOrdinateur(liste, ref);
    if (noeud != NULL) {
        printf("Référence: %d\n", noeud->ordinateur.ref);
        printf("Marque: %s\n", noeud->ordinateur.marque);
        printf("Type de disque dur: %s\n", noeud->ordinateur.S.type_disque_dur);
        printf("Capacité de stockage: %d GB\n", noeud->ordinateur.S.capacite_stockage);
        printf("RAM: %d GB\n", noeud->ordinateur.RAM);
        printf("Système d'exploitation: %s\n", noeud->ordinateur.systeme_exploitation);
        printf("Taille de l'écran: %d pouces\n", noeud->ordinateur.taille_ecran);
        printf("Carte graphique: %s\n", noeud->ordinateur.carte_graphique);
        printf("Type de clavier: %s\n", noeud->ordinateur.type_clavier);
        printf("Prix: %d €\n", noeud->ordinateur.prix);
        printf("Poids: %d kg\n", noeud->ordinateur.poids);
        printf("Modèle CPU: %s\n", noeud->ordinateur.p.modele);
        printf("Nombre de coeurs: %d\n", noeud->ordinateur.p.nb_coeurs);
        printf("Fréquence: %d GHz\n", noeud->ordinateur.p.frequence);
        printf("Mémoire cache: %d MB\n", noeud->ordinateur.p.memoire_cache);
        printf("Autonomie: %d heures\n", noeud->ordinateur.autonomie);
    }
}



int main()
{
    // Déclaration et initialisation de la liste chainée
    Noeud *tete = NULL;

    // Boucle infinie du menu principal
    int test = 1;
    while (test)
    {
        // Affichage du menu
        printf("\nMenu principal :\n");
        printf("1. Ajout d'un ordinateur\n");
        printf("2. Affichage des  ordinateurs\n");
        printf("3. Recherche d'un ordinateur\n");
        printf("4. Modification d'un ordinateur\n");
        printf("5. Suppression d'un ordinateur\n");
        printf("6. Quitter\n");
        printf("Veuillez choisir une option : ");

        // Saisie de l'option choisie par l'utilisateur
        int option;
        scanf("%d", &option);

        // Selon l'option choisie, appel de la fonction correspondante
        switch (option)
        {
        case 1:
        {
            Ordinateur ordinateur;
            int quantite;
            printf("Veuillez entrer les informations de l'ordinateur à ajouter et la quantité :\n");
            // Saisie et ajout de l'ordinateur au stock
            ajout(&tete, ordinateur, quantite);
            break;
        }
        case 2:
        {
            int ref;
            printf("donner la reference de cet ordinateur : ");
            scanf("%d",&ref);
            afficherOrdinateur(tete,ref);

        }
        case 3:
        {
            Ordinateur ordinateur;
            printf("Veuillez entrer les informations de l'ordinateur à rechercher :\n");
            // Saisie et recherche de l'ordinateur dans le stock
            int ref;
            printf("donner la reference de cet ordinateur : ");
            scanf("%d",&ref);
            recherche(tete, ref);
            break;
        }
        case 4:
        {
            Ordinateur nouvellesValeurs;
            printf("Veuillez entrer les informations de l'ordinateur à modifier :\n");
            printf("entrer les nouvelles caracteristiques de l'ordinateur  ");
            printf("\n Donner la  nouvelle reference : ");
            scanf("%d", &nouvellesValeurs.ref); // (*T[i]).ref
            printf("la marque : ");
            scanf("%s", &nouvellesValeurs.marque);
            printf("Donner le type disque dur (HDD/SSD) : ");
            scanf("%s", &(nouvellesValeurs.S.type_disque_dur));
            printf("Donner la capacite de stockage (To) : ");
            scanf("%d", &(nouvellesValeurs.S.capacite_stockage));
            printf("Donner la  RAM : ");
            scanf("%d", &nouvellesValeurs.RAM);
            printf("Donner le systeme_exploitation : ");
            scanf("%s", &nouvellesValeurs.systeme_exploitation);
            printf("Donner la taille_ecran (pouces): ");
            scanf("%d", &nouvellesValeurs.taille_ecran);
            printf("Donner la carte_graphique : ");
            scanf("%s", &nouvellesValeurs.carte_graphique);
            printf("Donner le type_clavier retroeclaire (oui/non) : ");
            scanf("%s", &nouvellesValeurs.type_clavier);
            printf("Donner le prix (DT): ");
            scanf("%d", &nouvellesValeurs.prix);
            printf("Donner le poids (kg) : ");
            scanf("%d", &nouvellesValeurs.poids);
            printf("Donner l'autonomie (heures) : ");
            scanf("%d", &nouvellesValeurs.autonomie);
            printf("Donner modele du CPU : ");
            scanf("%s", &(nouvellesValeurs.p.modele));
            printf("Donner le nb_coeurs du CPU : ");
            scanf("%d", &(nouvellesValeurs.p.nb_coeurs));
            printf("Donner la frequence d'horloge du CPU (Hz) : ");
            scanf("%d", &(nouvellesValeurs.p.frequence));
            printf("Donner memoire cache du CPU : ");
            scanf("%d", &(nouvellesValeurs.p.memoire_cache));
            /* Noeud *parcour = &(*stock) ;*/
            int ref;
            printf("donner la reference de l'ancien ordinateur : ");
            scanf("%d",&ref);
            // Saisie et modification de l'ordinateur dans le stock
            modification(tete, nouvellesValeurs,ref);
            break;
        }
        case 5:
        {
            Ordinateur ordinateur;
            printf("Veuillez entrer les informations de l'ordinateur à supprimer :\n");
            int ref;
            printf("donner la reference de cet ordinateur : ");
            scanf("%d",&ref);
            delete_computer(&tete,ref);
        }
        case 6:
        {   test =0;
            break;
        }
        }

    }
    return(0);
}

