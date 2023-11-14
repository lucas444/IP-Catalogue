#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


struct reseaux {
	int ipv4[4];
    int mask[4];
};

int verification(char ipv4[], char mask[]){
    int verif = 0;

    for (int i = 0; i < (strlen(ipv4)); i++) {   
        
        //vérrifie qu'il s'agit bien de nombre
        if ((!isdigit(ipv4[i])!=0)) {
            if(!(ipv4[i] == (46))){
                printf("Invalid IP address ICI !!\n");
                printf("erreur ici %c\n", ipv4[i]);
                verif = 1;
            }
        }
    }
    
    // vérifie que le valeur son entre 0 et 255
    if((ipv4[0] < 0) && (ipv4[0] > 255) &&
    (ipv4[1] < 0) && (ipv4[1] > 255) &&
    (ipv4[2] < 0) && (ipv4[2] > 255) &&
    (ipv4[3] < 0) && (ipv4[3] > 255)){
        printf("Invalid IP address\n");
        verif = 1;
    }
    
    //vérrifie qu'il s'agit bien de nombre
    for (int i = 0; i < (strlen(mask)); i++) {
    if ((!isdigit(mask[i])!=0)) {
        if(!(mask[i] == (46))){
            printf("Invalid mask LA !!\n");
            printf("erreur LA %c\n", mask[i]);
            verif = 1;
        }
    }
    }
    // vérifie que le valeur son entre 0 et 255
    if((mask[0] < 0) && (mask[0] > 255) &&
    (mask[1] < 0) && (mask[1] > 255) &&
    (mask[2] < 0) && (mask[2] > 255) &&
    (mask[3] < 0) && (mask[3] > 255)){
        printf("Invalid mask !\n");
        verif = 1;
    }
    return verif; 
}

void ajout_ip(){

    struct reseaux ip;

    char c_ip[50];
    char c_mask[50];

    printf("Saisir une ip  \n");
    scanf("%s", c_ip);
    printf("Saisir un mask  \n");
    scanf("%s", c_mask);

    //lance la vérification et redemande une ip si echec
    if(!verification(c_ip, c_mask)!=1){
        printf("\n\n Erreur, ip non comforme \n\n");
        ajout_ip();
    }

    //ouverture du fichier ip.txt
    FILE * fp = NULL;
    fp = fopen("ip.txt", "a");
    
    if(fp != NULL){

        //ecriture dans le fichier ip.txt
        if(fprintf(fp,"%s/%s \n", c_ip, c_mask)){
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

    //ouvre le fichier ip.txt
    FILE * fp = NULL;
    fp = fopen("ip.txt", "r");


    if(fp != NULL ){
        
        //boucle qui ecrit ligne par ligne 
        printf("\nVoici la liste des ip : \n\n");
        while(fscanf(fp, "%d.%d.%d.%d/%d.%d.%d.%d", &ip.ipv4[0],&ip.ipv4[1], &ip.ipv4[2], &ip.ipv4[3],&ip.mask[0], &ip.mask[1], &ip.mask[2], &ip.mask[3] )!= EOF){
            printf("ID %d : %d.%d.%d.%d/%d.%d.%d.%d \n", i, ip.ipv4[0], ip.ipv4[1], ip.ipv4[2], ip.ipv4[3], ip.mask[0], ip.mask[1], ip.mask[2], ip.mask[3]);
            i++;
        }
    }


    //message d'erreur si le fichier ne s'ouvre pas et ferme le programe
    else{
        printf("Impossible d'ouvrir le fichier\n");
        exit(1);
    }  

    fclose(fp); 

    return 0;

}

void supp_ip(){

    int i = 0; //compteur 
	struct reseaux ip;
    int ip_choisi;

    //ouvre le fichier ip.txt
    FILE * fp = NULL;
    FILE * temp = NULL;
    fp = fopen("ip.txt", "r");
    temp = fopen("temp.txt","wt");  

    
    if(fp == NULL){
        printf("Impossible d'ouvrir le fichier\n");
        exit(1);
    }
    if(temp == NULL){
        printf("Impossible d'ouvrir le fichier\n");
        exit(1);
    }  

    printf("\nSaisir l'ID de l'IP que vous souhaitait supprimer :\n");
    scanf("%d", &ip_choisi);

    //boucle qui lit le fichier ip.txt
    while(fscanf(fp, "%d.%d.%d.%d/%d.%d.%d.%d", &ip.ipv4[0],&ip.ipv4[1], &ip.ipv4[2], &ip.ipv4[3],&ip.mask[0], &ip.mask[1], &ip.mask[2], &ip.mask[3])== 8){  

        i++;

        //rééctit tout les ligne dans un fichier temp SI il son différent de l'id choisi
        if(i != ip_choisi){
            fprintf(temp,"%d.%d.%d.%d/%d.%d.%d.%d \n", ip.ipv4[0], ip.ipv4[1], ip.ipv4[2], ip.ipv4[3], ip.mask[0], ip.mask[1], ip.mask[2], ip.mask[3]);
        }
        else
        printf("l'ip a bien été supprimer\n");

    }
    fclose(fp); 
    fclose(temp); 
    remove("ip.txt");
    rename("temp.txt","ip.txt");
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

    int boul = 0;
    while (boul == 0)
    {
        switch (menuPrincipal()) {
            case 1 : 
                ajout_ip();
                break;
            case 2 :
                liste_ip();
                break;
            case 3 :
                liste_ip();
                break;
            case 4 :
                liste_ip();
                break;
            case 5 :
                printf("Au revoir !");
                boul = 1;
                break;
        }
    }
    return 0;
}
