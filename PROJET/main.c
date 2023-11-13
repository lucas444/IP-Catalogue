#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct reseaux {
	int ipv4[4];
    int mask[4];
};

void fichier_ecriture(FILE *f,int ipv4[4]){

    //ecriture dans le fichier ip.txt
    fprintf(f, "%d.%d.%d.%d\n", ipv4[0], ipv4[1], ipv4[2], ipv4[3]);
    printf("Je suis arrivé jusqu'ici");
    printf(" avec cette ip : %d.%d.%d.%d\n", ipv4[0], ipv4[1], ipv4[2], ipv4[3] );
}

void ajout_ip(){
	
	struct reseaux ip;
	bool verif = false;


    //sasie de la nouvelle ip
	printf("Saisir une ip : \n");
	scanf("%d.%d.%d.%d", &ip.ipv4[0], &ip.ipv4[1], &ip.ipv4[2], &ip.ipv4[3]);		
	// printf("Saisir son masque : \n");
	// scanf("%d.%d.%d.%d", &ip.mask[0], &ip.mask[1], &ip.mask[2], &ip.mask[3]);
       
	printf("test ip : %d.%d.%d.%d\n", ip.ipv4[0], ip.ipv4[1], ip.ipv4[2], ip.ipv4[3] );


    //ouverture du fichier ip.txt
    FILE *fp = fopen("ip.txt", "w");
    if (fp == NULL)
    {
        printf("Le fichier texte.txt n'a pas pu être ouvert\n");
        exit(1);
    }

    printf("Le fichier ip.txt existe\n");

    if (fclose(fp) == EOF)
    {
        printf("Erreur lors de la fermeture du flux\n");
        exit(1);      
    }

    //ecriture dans le fichier ip.txt
    fichier_ecriture(fp, ip.ipv4);

    //fermeture du fichier ip.txt   
    fclose(fp);
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
    
    switch (menuPrincipal()) {
        case 1 : 
        ajout_ip();
}



    return 0;
}
