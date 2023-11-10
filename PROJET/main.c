#include <stdio.h>
#include <stdlib.h>


int fichier_open(void){
    FILE *fp = fopen("texte.txt", "r");

    if (fp == NULL)
    {
        printf("Le fichier texte.txt n'a pas pu être ouvert\n");
        return EXIT_FAILURE;
    }

    printf("Le fichier texte.txt existe\n");
    return 0;
}



struct res {
	int ip[4];
};

struct res t(void){

	struct res init = {{192, 168, 1, 1 }};

	return init;
}



int menuPrincipal(void) {
    printf("\nVeuillez selectionner une option :\n");
    printf("\n1 - Enregistrer une nouvelle adresse\n");
    printf("2 - Lister les adresses IP\n");
    printf("3 - Filtrer par masque\n");
    printf("4 - Supprimer une adresse\n");
    printf("5 - Quitter\n\n");
    int choixMenu1 = 0;
    scanf("%d", &choixMenu1);
    return choixMenu1;
}

int main(){
    menuPrincipal();
    
    switch (menuPrincipal()) {
        case 1 : 
    }



    return 0;
}
