#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    FILE *fp = fopen("texte.txt", "w");

    if (fp == NULL)
    {
        fputs("Le fichier texte.txt n'a pas pu être ouvert\n", stderr);
        return EXIT_FAILURE;
    }
    if (fputs("Bonjour\n", fp) == EOF)
    {
        fputs("Erreur lors de l'écriture d'une ligne\n", stderr);
        return EXIT_FAILURE;
    }
    if (fclose(fp) == EOF)
    {
        fputs("Erreur lors de la fermeture du flux\n", stderr);
        return EXIT_FAILURE;        
    }

    return 0;
}
