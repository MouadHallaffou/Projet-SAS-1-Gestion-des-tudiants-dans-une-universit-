#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ETUDIANTS 500

/** Structs **/

typedef struct
{
    int jour;
    int mois;
    int annee;
} dateNaissance;

typedef struct
{
    int numeroUnique;
    char nom[20];
    char prenom[20];
    dateNaissance date;
    char departement[100];
    float noteGenerale;
} Etudiant;

/** Fonctions **/

void Ajouter(Etudiant etudiants[], int *nombresEtudiants)
{
    int n;
    do
    {
        printf("\nCombien d'etudiants souhaitez-vous ajouter ? (max %d) : ", MAX_ETUDIANTS - *nombresEtudiants);
        scanf("%d", &n);
    }
    while (n < 0 || n > (MAX_ETUDIANTS - *nombresEtudiants));

    for (int i = 0; i < n; i++)
    {
        Etudiant etudiant;
        int existeDeja;

        printf("Entrez les informations pour l'etudiant %d:\n", *nombresEtudiants + 1);

        do
        {
            printf("Numero unique: ");
            scanf("%d", &etudiant.numeroUnique);


            ///**** Vérifier si le numéro unique existe déjà ****///

            existeDeja = 0;
            for (int j = 0; j < *nombresEtudiants; j++)
            {
                if (etudiants[j].numeroUnique == etudiant.numeroUnique)
                {
                    existeDeja = 1;
                    break;
                }
            }

            if (existeDeja)
            {
                printf("Ce numero unique (%d) est deja utilise. Veuillez en entrer un autre.\n",etudiants[i].numeroUnique);
            }
        }
        while (existeDeja);

        printf("Nom: ");
        scanf("%s", etudiant.nom);

        printf("Prenom: ");
        scanf("%s", etudiant.prenom);

        do
        {
            printf("Date de naissance (jj mm aaaa): ");
            scanf("%d %d %d", &etudiant.date.jour, &etudiant.date.mois, &etudiant.date.annee);
        }
        while (etudiant.date.jour < 1 || etudiant.date.jour > 31 || etudiant.date.mois < 1 || etudiant.date.mois > 12 || etudiant.date.annee < 1950 || etudiant.date.annee > 2008);

        int choixDepartement;
        printf("Departement (1: Informatique, 2: Math, 3: Biologie) : ");
        scanf("%d", &choixDepartement);
        switch (choixDepartement)
        {
        case 1:
            strcpy(etudiant.departement, "Informatique");
            break;
        case 2:
            strcpy(etudiant.departement, "Math");
            break;
        case 3:
            strcpy(etudiant.departement, "Biologie");
            break;
        default:
            strcpy(etudiant.departement, "Inconnu");
            break;
        }

        do
        {
            printf("Note generale (0-20): ");
            scanf("%f", &etudiant.noteGenerale);
        }
        while (etudiant.noteGenerale < 0 || etudiant.noteGenerale > 20);

        etudiants[*nombresEtudiants] = etudiant;
        (*nombresEtudiants)++;
    }

    printf("Etudiant(s) ajoute(s) avec succes !\n");
}

void modifier(Etudiant etudiants[], int nombresEtudiants)
{
    int id;
    printf("Entrez le numero unique de l'etudiant a modifier: ");
    scanf("%d", &id);

    for (int i = 0; i < nombresEtudiants; i++)
    {
        if (etudiants[i].numeroUnique == id)
        {
            printf("Etudiant trouve : %s %s\n", etudiants[i].nom, etudiants[i].prenom);

            printf("Nouveau nom: ");
            scanf("%s", etudiants[i].nom);

            printf("Nouveau prenom: ");
            scanf("%s", etudiants[i].prenom);

            do
            {
                printf("Nouvelle date de naissance (jj mm aaaa): ");
                scanf("%d %d %d", &etudiants[i].date.jour, &etudiants[i].date.mois, &etudiants[i].date.annee);
            }
            while (etudiants[i].date.jour < 1 || etudiants[i].date.jour > 31 || etudiants[i].date.mois < 1 || etudiants[i].date.mois > 12 || etudiants[i].date.annee < 1950 || etudiants[i].date.annee > 2008);

            int choixDepartement;
            printf("Nouveau departement (1: Informatique, 2: Math, 3: Biologie) : ");
            scanf("%d", &choixDepartement);
            switch (choixDepartement)
            {
            case 1:
                strcpy(etudiants[i].departement, "Informatique");
                break;
            case 2:
                strcpy(etudiants[i].departement, "Math");
                break;
            case 3:
                strcpy(etudiants[i].departement, "Biologie");
                break;
            default:
                strcpy(etudiants[i].departement, "Inconnu");
                break;
            }

            do
            {
                printf("Nouvelle note generale (0-20): ");
                scanf("%f", &etudiants[i].noteGenerale);
            }
            while (etudiants[i].noteGenerale < 0 || etudiants[i].noteGenerale > 20);

            printf("Modification effectuee avec succes !\n");
            return;
        }
    }
    printf("Etudiant non trouve.\n");
}

void supprimer(Etudiant etudiants[], int *nombresEtudiants)
{
    int id;
    printf("Entrez le numero unique de l'etudiant a supprimer: ");
    scanf("%d", &id);

    for (int i = 0; i < *nombresEtudiants; i++)
    {
        if (etudiants[i].numeroUnique == id)
        {
            for (int j = i; j < *nombresEtudiants - 1; j++)
            {
                etudiants[j] = etudiants[j + 1];
            }
            (*nombresEtudiants)--;
            printf("Etudiant supprime avec succes.\n");
            return;
        }
    }
    printf("Etudiant non trouve.\n");
}

void afficherDetails(Etudiant etudiants[], int nombresEtudiants)
{
    int id;
    printf("Entrez le numero unique de l'etudiant pour afficher les details : ");
    scanf("%d", &id);

    for (int i = 0; i < nombresEtudiants; i++)
    {
        if (etudiants[i].numeroUnique == id)
        {
            printf("Details de l'etudiant %d :\n", id);
            printf("Nom : %s\n", etudiants[i].nom);
            printf("Prenom : %s\n", etudiants[i].prenom);
            printf("Date de naissance : %02d/%02d/%04d\n", etudiants[i].date.jour, etudiants[i].date.mois, etudiants[i].date.annee);
            printf("Departement : %s\n", etudiants[i].departement);
            printf("Note generale : %.2f\n", etudiants[i].noteGenerale);
            return;
        }
    }
    printf("Etudiant non trouve.\n");
}

float calculerMoyenneGenerale(Etudiant etudiants[], int nombresEtudiants)
{
    float somme = 0;
    for (int i = 0; i < nombresEtudiants; i++)
    {
        somme += etudiants[i].noteGenerale;
    }
    return (nombresEtudiants > 0) ? somme / nombresEtudiants : 0;
}

void statistiques(Etudiant etudiants[], int nombresEtudiants)
{
    int totalEtudiants = nombresEtudiants;
    int etudiantsInformatique = 0, etudiantsMath = 0, etudiantsBiologie = 0;
    int etudiantsReussis = 0;

    for (int i = 0; i < nombresEtudiants; i++)
    {
        if (etudiants[i].noteGenerale >= 10)
        {
            etudiantsReussis++;
        }

        if (strcmp(etudiants[i].departement, "Informatique") == 0)
            etudiantsInformatique++;
        else if (strcmp(etudiants[i].departement, "Math") == 0)
            etudiantsMath++;
        else if (strcmp(etudiants[i].departement, "Biologie") == 0)
            etudiantsBiologie++;
    }

    printf("Statistiques :\n");
    printf("Total d'etudiants : %d\n", totalEtudiants);
    printf("Etudiants en Informatique : %d\n", etudiantsInformatique);
    printf("Etudiants en Math : %d\n", etudiantsMath);
    printf("Etudiants en Biologie : %d\n", etudiantsBiologie);
    printf("Etudiants ayant une moyenne >= 10 (reussite) : %d\n", etudiantsReussis);
}
void rechercherParNom(Etudiant etudiants[], int nombresEtudiants)
{
    char nom[20];
    printf("Entrez le nom de l'etudiant a rechercher : ");
    scanf("%s", nom);

    int trouve = 0;
    for (int i = 0; i < nombresEtudiants; i++)
    {
        if (strcmp(etudiants[i].nom, nom) == 0)
        {
            afficherDetails(etudiants, nombresEtudiants);
            trouve = 1;
        }
    }
    if (!trouve)
    {
        printf("Aucun etudiant trouve avec le nom %s.\n", nom);
    }
}

void afficherDepartement(Etudiant etudiants[], int nombresEtudiants)
{
    char departement[100];
    printf("Entrez le nom du departement : ");
    scanf("%s", departement);

    int trouve = 0;
    for (int i = 0; i < nombresEtudiants; i++)
    {
        if (strcmp(etudiants[i].departement, departement) == 0)
        {
            afficherDetails(etudiants, nombresEtudiants);
            trouve = 1;
        }
    }
    if (!trouve)
    {
        printf("Aucun etudiant trouve dans le departement %s.\n", departement);
    }
}

void trierParNom(Etudiant etudiants[], int nombresEtudiants, int ordre)
{
    for (int i = 0; i < nombresEtudiants - 1; i++)
    {
        for (int j = i + 1; j < nombresEtudiants; j++)
        {
            int cmp = strcmp(etudiants[i].nom, etudiants[j].nom);
            if ((ordre == 1 && cmp > 0) || (ordre == -1 && cmp < 0))
            {
                Etudiant temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
    printf("Liste des etudiants triee par nom.\n");
}

void trierParNote(Etudiant etudiants[], int nombresEtudiants, int ordre)
{
    for (int i = 0; i < nombresEtudiants - 1; i++)
    {
        for (int j = i + 1; j < nombresEtudiants; j++)
        {
            if ((ordre == 1 && etudiants[i].noteGenerale < etudiants[j].noteGenerale) || (ordre == -1 && etudiants[i].noteGenerale > etudiants[j].noteGenerale))
            {
                Etudiant temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
    printf("Liste des etudiants triee par note generale.\n");
}

void trierParStatut(Etudiant etudiants[], int nombresEtudiants, int statut)
{
    for (int i = 0; i < nombresEtudiants - 1; i++)
    {
        for (int j = i + 1; j < nombresEtudiants; j++)
        {
            int condition = (statut == 1) ? (etudiants[i].noteGenerale >= 10) : (etudiants[j].noteGenerale < 10);
            if (condition)
            {
                Etudiant temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
    printf("Liste des etudiants triee par statut de reussite.\n");
}

void afficherTop3(Etudiant etudiants[], int nombresEtudiants)
{
    trierParNote(etudiants, nombresEtudiants, 1);

    printf("Top 3 des etudiants ayant les meilleures notes :\n");
    for (int i = 0; i < 3 && i < nombresEtudiants; i++)
    {
        afficherDetails(&etudiants[i], nombresEtudiants);
    }
}

int main()
{
    Etudiant etudiants[MAX_ETUDIANTS];
    int nombresEtudiants = 0;
    int choix;

    printf("\n =======================================\n");
    printf("\n =======================================\n");
    printf("\n ============ Menu Principale ==========\n");
    printf("\n =======================================\n");
    printf("\n =======================================\n");
    do
    {
        printf("\n");
        printf("1  - Ajouter un etudiant\n");
        printf("2  - Modifier un etudiant\n");
        printf("3  - Supprimer un etudiant\n");
        printf("4  - Afficher les details d'un etudiant\n");
        printf("5  - Calculer la moyenne generale\n");
        printf("6  - Statistiques\n");
        printf("7  - Rechercher par nom\n");
        printf("8  - Afficher les etudiants d'un departement\n");
        printf("9  - Trier par nom\n");
        printf("10 - Trier par note generale\n");
        printf("11 - Trier par statut de reussite\n");
        printf("12 - Afficher les 3 meilleurs etudiants\n");
        printf("13 - Sortir...\n");
        printf("\n");
        printf(" entre votre choix! \n");
        printf("\n");
        printf(" Choix: ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            Ajouter(etudiants, &nombresEtudiants);
            break;
        case 2:
            modifier(etudiants, nombresEtudiants);
            break;
        case 3:
            supprimer(etudiants, &nombresEtudiants);
            break;
        case 4:
            afficherDetails(etudiants, nombresEtudiants);
            break;
        case 5:
            printf("Moyenne generale : %.2f\n", calculerMoyenneGenerale(etudiants, nombresEtudiants));
            break;
        case 6:
            statistiques(etudiants, nombresEtudiants);
            break;
        case 7:
            rechercherParNom(etudiants, nombresEtudiants);
            break;
        case 8:
            afficherDepartement(etudiants, nombresEtudiants);
            break;
        case 9:
        {
            int ordre;
            printf(" 1 - Tri alphabetique croissant\n");
            printf(" 2 - Tri alphabetique decroissant\n");
            printf(" Choix: ");
            scanf("%d", &ordre);
            trierParNom(etudiants, nombresEtudiants, (ordre == 1) ? 1 : -1);
            break;
        }
        case 10:
        {
            int ordre;
            printf(" 1 - Tri par note croissant\n");
            printf(" 2 - Tri par note decroissant\n");
            printf(" Choix: ");
            scanf("%d", &ordre);
            trierParNote(etudiants, nombresEtudiants, (ordre == 1) ? 1 : -1);
            break;
        }
        case 11:
        {
            int statut;
            printf(" 1 - Etudiants reussis\n");
            printf(" 2 - Etudiants echoues\n");
            printf(" Choix: ");
            scanf("%d", &statut);
            trierParStatut(etudiants, nombresEtudiants, statut);
            break;
        }
        case 12:
            afficherTop3(etudiants, nombresEtudiants);
            break;
        case 13:
            printf(" Sortiiiiiiiiiiir.\n");
            break;
        default:
            printf(" Choix invalide. Veuillez reessayer.\n");
            break;
        }
    }
    while (choix != 13);

    return 0;
}



