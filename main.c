#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char AfficheMenu(char menu)
{
    printf("Menu La valse des mots\n");
    printf("1 : Conjugaison\n");
    printf("2 : Miroir\n");
    printf("3 : Palindrome\n");
    printf("4 : Occurrence\n");
    printf("5 : Quitter\n");
    printf("Saisir un nombre de menu souhaite\n");
    scanf("\n%c", &menu);
    return menu;
}

void AfficheConjugaison(char verb[21])
{
    int l;
    char affi[31];
    l = strlen(verb);
    if ((verb[l-2] != 'e') || (verb[l-1] != 'r')) {
        printf("\nCe n'est pas un verb du premier groupe\n");
    } else {
        verb[l-2] = '\0';
        affi[0] = '\0';
        strcat(affi, "Je ");
        strcat(affi, verb);
        strcat(affi, "e");
        printf("%s\n", affi);
        affi[0] = '\0';
        strcat(affi, "Tu ");
        strcat(affi, verb);
        strcat(affi, "es");
        printf("%s\n", affi);
        affi[0] = '\0';
        strcat(affi, "Il/Elle ");
        strcat(affi, verb);
        strcat(affi, "e");
        printf("%s\n", affi);
        affi[0] = '\0';
        strcat(affi, "Nous ");
        strcat(affi, verb);
        strcat(affi, "ons");
        printf("%s\n", affi);
        affi[0] = '\0';
        strcat(affi, "Vous ");
        strcat(affi, verb);
        strcat(affi, "ez");
        printf("%s\n", affi);
        affi[0] = '\0';
        strcat(affi, "Ils/Elles ");
        strcat(affi, verb);
        strcat(affi, "ent");
        printf("%s\n", affi);
        affi[0] = '\0';
        strcat(affi, "Je ");
        strcat(affi, verb);
        strcat(affi, "ais");
        printf("%s\n", affi);
        affi[0] = '\0';
        strcat(affi, "Tu ");
        strcat(affi, verb);
        strcat(affi, "ais");
        printf("%s\n", affi);
        affi[0] = '\0';
        strcat(affi, "Il/Elle ");
        strcat(affi, verb);
        strcat(affi, "ait");
        printf("%s\n", affi);
        affi[0] = '\0';
        strcat(affi, "Nous ");
        strcat(affi, verb);
        strcat(affi, "ions");
        printf("%s\n", affi);
        affi[0] = '\0';
        strcat(affi, "Vous ");
        strcat(affi, verb);
        strcat(affi, "iez");
        printf("%s\n", affi);
        affi[0] = '\0';
        strcat(affi, "Ils/Elles ");
        strcat(affi, verb);
        strcat(affi, "aient");
        printf("%s\n", affi);
        affi[0] = '\0';
        strcat(affi, "Je ");
        strcat(affi, verb);
        strcat(affi, "erai");
        printf("%s\n", affi);
        affi[0] = '\0';
        strcat(affi, "Tu ");
        strcat(affi, verb);
        strcat(affi, "eras");
        printf("%s\n", affi);
        affi[0] = '\0';
        strcat(affi, "Il/Elle ");
        strcat(affi, verb);
        strcat(affi, "era");
        printf("%s\n", affi);
        affi[0] = '\0';
        strcat(affi, "Nous ");
        strcat(affi, verb);
        strcat(affi, "erons");
        printf("%s\n", affi);
        affi[0] = '\0';
        strcat(affi, "Vous ");
        strcat(affi, verb);
        strcat(affi, "erez");
        printf("%s\n", affi);
        affi[0] = '\0';
        strcat(affi, "Ils/Elles ");
        strcat(affi, verb);
        strcat(affi, "eront");
        printf("%s\n", affi);
    }
}

char* AfficheMiroir(char motM[21])
{
    int i,l;
    int j = 0;
    char carac;
    l = strlen(motM);
    char* motMinverse = malloc(l * sizeof(char));
    for (i=(l-1); i>=0; i--)
    {
        carac = motM[i];
        motMinverse[j] = carac;
        j++;
    }
    return motMinverse;

}

void AffichePalindrome(char motP[21])
{
    if (strcmp(AfficheMiroir(motP), motP) !=0)
        {
            printf("Ce mot n'est pas un palindrome\n");
        }
    else
        {
            printf("Ce mot est un palindrome\n");
        }
}

int AfficheOccurence(char motO[16], char lettre)
{
    int i, cpt;
    i = 0;
    cpt = 0;
    for(i=0; i<16; i++)
    {
        if (lettre == motO[i])
            cpt++;
    }
    return cpt;
}

int main()
{
    char menu;
    char verb[21], motM[21], motO[16], motP[21], rep, lettre;
    printf("Ce programme permet de jouer avec les mots\n");
    menu = AfficheMenu(menu);
    while (menu != '5')
    {
        switch (menu) {
            case '1':
                do
                {
                    printf("Saisir un verbe du 1er groupe pour conjuguer au present, a impartfait et au futur\n");
                    scanf("\n%s", &verb);
                    AfficheConjugaison(verb);
                    printf("Voulez-vous continuer ? (o : pour continuer, n : pour retourner au Menu La valse des mots)\n");
                    scanf("\n%c", &rep);
                } while (rep != 'n');
                break;
            case '2':
                do
                {
                    printf("Saisir un mot pour avoir son miroir\n");
                    scanf("\n%s", &motM);
                    printf("Le miroir du mot %s est %s\n", motM, AfficheMiroir(motM));
                    printf("Voulez-vous continuer ? (o : pour continuer, n : pour retourner au Menu La valse des mots)\n");
                    scanf("\n%c", &rep);
                }
                while (rep != 'n');
                break;
            case '3':
                do
                {
                    printf("Saisir un mot pour savoir s'il est un palindrome ou non\n");
                    scanf("\n%s", &motP);
                    AffichePalindrome(motP);
                    printf("Voulez-vous continuer ? (o : pour continuer, n : pour retourner au Menu La valse des mots)\n");
                    scanf("\n%c", &rep);
                }
                while (rep != 'n');
                break;
            case '4':
                do
                {
                    printf("Saisir un mot de 15 lettres maximum et une lettre pour trouver son occurrence\n");
                    scanf("\n%s %c", &motO, &lettre);
                    if (strlen(motO) > 15)
                        {
                            printf("Erreur ! Saisir un mot de 15 lettres maximum\n");
                        }
                    else
                        {
                            printf("On trouve %d lettre(s) %c dans le mot %s\n", AfficheOccurence(motO,lettre), lettre, motO);
                        }
                    printf("Voulez-vous continuer ? (o : pour continuer, n : pour retourner au Menu La valse des mots)\n");
                    scanf("\n%c", &rep);
                }
                while (rep != 'n');
                break;
            default:
                printf("Erreur de saisie !\n");
        }
        menu = AfficheMenu(menu);
    }
    printf("Le programme est termine !\n");
    return 0;
}
