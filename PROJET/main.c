#include <stdio.h>
#include <stdlib.h>

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
