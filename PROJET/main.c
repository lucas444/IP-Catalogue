#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct reseaux {
	int ipv4[4];
    int mask[4];
};

int verification(int a,int b, int c, int d){
    printf("on est la %d.%d.%d.%d\n", a,b,c,d);
    int verif = 0;

if(a < 256 && b < 256 && c < 256 && d < 256 && a >= 0 && b >= 0 && c >= 0 && d >= 0){
verif = 1;
}
printf("\nyes %d\n",verif);

return verif;
}

void ajout_ip(){
	
	struct reseaux ip;


    //sasie de la nouvelle ip + mask
	printf("Saisir une ip : \n");
	scanf("%d.%d.%d.%d", &ip.ipv4[0], &ip.ipv4[1], &ip.ipv4[2], &ip.ipv4[3]);		
	// printf("Saisir son masque : \n");
	// scanf("%d.%d.%d.%d", &ip.mask[0], &ip.mask[1], &ip.mask[2], &ip.mask[3]);

    while((verification(ip.ipv4[0], ip.ipv4[1], ip.ipv4[2], ip.ipv4[3]))!=1){
        printf("\nIp saisie non valide. \n\nExemple: \nafs.213.sf.23ew // Invalide\n300.192.1.2     // Invalide\n-12.23.12.23    // Invalide\n172.45.223..1    // Invalide\n192.168.1.1     //valide\n\nSaisir une ip : \n");
        ip.ipv4[0]=400;
        ip.ipv4[1]=300;
        ip.ipv4[2]=300;
        ip.ipv4[3]=0300;
        printf("%d.%d.%d.%d %d.%d.%d.%d \n", ip.ipv4[0], ip.ipv4[1], ip.ipv4[2], ip.ipv4[3], ip.mask[0], ip.mask[1], ip.mask[2], ip.mask[3]);
        scanf("%d.%d.%d.%d", &ip.ipv4[0], &ip.ipv4[1], &ip.ipv4[2], &ip.ipv4[3]);
    }

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

    //ouvre le fichier ip.txt
    FILE * fp = NULL;
    fp = fopen("ip.txt", "r");


    if(fp != NULL ){
        
        //boucle qui ecrit ligne par ligne 
        printf("\nVoici la liste des ip : \n\n");
        while(fscanf(fp, "%d.%d.%d.%d %d.%d.%d.%d", &ip.ipv4[0],&ip.ipv4[1], &ip.ipv4[2], &ip.ipv4[3],&ip.mask[0], &ip.mask[1], &ip.mask[2], &ip.mask[3] )!= EOF)
        
        {
            printf("ID %d : %d.%d.%d.%d %d.%d.%d.%d \n", i, ip.ipv4[0], ip.ipv4[1], ip.ipv4[2], ip.ipv4[3], ip.mask[0], ip.mask[1], ip.mask[2], ip.mask[3]);
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
    while(fscanf(fp, "%d.%d.%d.%d %d.%d.%d.%d", &ip.ipv4[0],&ip.ipv4[1], &ip.ipv4[2], &ip.ipv4[3],&ip.mask[0], &ip.mask[1], &ip.mask[2], &ip.mask[3])== 8){  

        i++;

        //rééctit tout les ligne dans un fichier temp SI il son différent de l'id choisi
        if(i != ip_choisi){
            fprintf(temp,"%d.%d.%d.%d %d.%d.%d.%d \n", ip.ipv4[0], ip.ipv4[1], ip.ipv4[2], ip.ipv4[3], ip.mask[0], ip.mask[1], ip.mask[2], ip.mask[3]);
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
    switch (menuPrincipal()) {

        case 1 : 
        ajout_ip();
        break;

        case 2 :
        liste_ip();
        break;

        case 4 :
        supp_ip();
        break;
    }



    return 0;
}
