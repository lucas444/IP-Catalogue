#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct reseaux {
	int ipv4[4];
    int mask[4];
};

void ajout_ip(){
	
	struct reseaux ip;


    //sasie de la nouvelle ip + mask
	printf("Saisir une ip : \n");
	scanf("%d.%d.%d.%d", &ip.ipv4[0], &ip.ipv4[1], &ip.ipv4[2], &ip.ipv4[3]);		
	printf("Saisir son masque : \n");
	scanf("%d.%d.%d.%d", &ip.mask[0], &ip.mask[1], &ip.mask[2], &ip.mask[3]);

    //ouverture du fichier ip.txt
    FILE * fp = NULL;
    fp = fopen("ip.txt", "a");

    char txt_ip[10] ="ip : ";
    char txt_mask[10] ="mask : ";
    
    if(fp != NULL){

        //ecriture dans le fichier ip.txt
        if(fprintf(fp,"%d.%d.%d.%d %d.%d.%d.%d \n", ip.ipv4[0], ip.ipv4[1], ip.ipv4[2], ip.ipv4[3], ip.mask[0], ip.mask[1], ip.mask[2], ip.mask[3])){
            printf("IP Ajouté au fichier ip.txt\n");

        }

    }
    
    //message d'erreur si le fichier ne s'ouvre pas et ferme le programe
    else{
        printf("Impossible d'ouvrir le fichier\n");
        exit(1);
    }  
    fclose(fp);
}

int liste_ip(){

    int i = 1;
	struct reseaux ip;
    char valeur = 0;
    int test; 


    //ouvre le fichier ip.txt
    FILE * fp = NULL;
    fp = fopen("ip.txt", "r");


    if(fp != NULL ){
        
        //boucle qui ecrit ligne par ligne 
        printf("\nVoici la liste des ip : \n\n");
        while(fscanf(fp, "%d.%d.%d.%d %d.%d.%d.%d", &ip.ipv4[0],&ip.ipv4[1], &ip.ipv4[2], &ip.ipv4[3],&ip.mask[0], &ip.mask[1], &ip.mask[2], &ip.mask[3] )!= EOF)
        
        {
            printf("IP numéro %d : %d.%d.%d.%d %d.%d.%d.%d \n", i, ip.ipv4[0], ip.ipv4[1], ip.ipv4[2], ip.ipv4[3], ip.mask[0], ip.mask[1], ip.mask[2], ip.mask[3]);
            i++;
        }
    }


    //message d'erreur si le fichier ne s'ouvre pas et ferme le programe
    else{
        printf("Impossible d'ouvrir le fichier\n");
        exit(1);
    }  

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
        break;
        case 2 :
        liste_ip();
        break;
}



    return 0;
}
