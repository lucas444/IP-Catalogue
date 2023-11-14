#include <stdio.h>

typedef struct{
	int ipv4[4];
    int mask[4];
}reseau;

// void decimalToBinary(int ipv4[i]) {
//     int binaryNumber[32]; // Tableau pour stocker les bits du nombre binaire
//     int i = 0;

//     // Conversion du nombre décimal en binaire
//     while (ipv4[i] > 0) {
//         reverseBinaryNumber[i] = ipv4[i] % 2;
//         ipv4[i] = ipv4[i] / 2;
//         i++;
//     }

//     // Affichage du nombre binaire en ordre inverse
//     printf("Le nombre binaire est : ");
//     for (int j = i - 1; j >= 0; j--) {
//         printf("%d", binaryNumber[j]);
//     }
//     printf("\n");
// }

int main() {

    int ipv4[4];     
    int reverseBinaryNumber[4][8]; // Tableau pour stocker les bits du nombre binaire
    int binaryNumber[4][8]; // Tableau pour stocker les bits du nombre binaire
    int save_ipv4[4]; 
    int bytes = 0;        
    int reste = 0;
    printf("Saisir une ip : \n");
	scanf("%d.%d.%d.%d", &ipv4[0], &ipv4[1], &ipv4[2], &ipv4[3]);
    for (int octet = 0; octet < 4; octet++) {
        bytes=0;        
        save_ipv4[octet]=ipv4[octet];        
        printf("\nValeur de l'octet sur IPv4 %d\n", ipv4[octet]);
        printf("Bytes au restart : %d\n", bytes);
        printf("\nValeur de l'octet %d\n", save_ipv4[octet]);
        // Conversion du nombre décimal en binaire
        while (save_ipv4[octet] > 0) {
            reste=save_ipv4[octet] % 2;            
            printf("Le reste est de : %d\n", reste);
            reverseBinaryNumber[octet][bytes] = reste;            
            printf("Valeur de binary : %d\n", reverseBinaryNumber[octet][bytes]);
            save_ipv4[octet] /= 2;
            printf("save_ipv4 est a : %d\n", save_ipv4[octet]);            
            bytes++;                                    
            printf("bytes est a : %d\n", bytes);            
        }
        while (bytes < 8)
        {
            reverseBinaryNumber[octet][bytes]=0;
            bytes++;
        }        
        bytes=0;        
        printf("\nLe nombre binaire est : \n");
        for (int emplacement = 0; emplacement < 8; emplacement++)
        {
            printf("%d", reverseBinaryNumber[octet][emplacement]);
        }        
        printf("\n");   
        //Affichage du nombre binaire en ordre inverse        
        for (int emplacement = 8; emplacement >= 0; emplacement--) {
            printf("%d",reverseBinaryNumber[octet][emplacement]);
            binaryNumber[octet][emplacement]=reverseBinaryNumber[octet][emplacement];
            bytes++;

        }    
    }        
    
    return 0;
}