#include <stdio.h>

typedef struct{
	int ipv4[4];
    int mask[4];
    int binaire[8];
}reseau;

int conversion_binaire() {
  int ipv4[4] = {192, 168, 95, 5};

  int binaire[4] = {0};
  int save[4] = {0};
  int reste = 0;

    for (int i = 0; i < 4; i++)
    {
        save[i] = ipv4[i];
        while (save[i] >= 2) {
            reste = save[i] % 2;
            printf("|Le reste est egal a = %d|\n", reste);
            if (reste != 0) {
                binaire[i] += reste;
                printf("binaire : %d\n", binaire[i]);
                binaire[i] *= 10;
            }
            else
            {
                reste = 1; 
                binaire[i] *= 10;
                printf("binaire : %d\n", binaire[i]);
            }
            save[i] /= 2;
            printf("%d\n", save[i]);
        }

        binaire[i] /= 10;
        printf("|Original = %d | Binaire = %d|\n", ipv4[i], binaire[i]);
    }
    return 0;
}


void decimalToBinary(int decimalNumber) {
    int binaryNumber[32]; // Tableau pour stocker les bits du nombre binaire
    int i = 0;

    // Conversion du nombre décimal en binaire
    while (decimalNumber > 0) {
        binaryNumber[i] = decimalNumber % 2;
        decimalNumber = decimalNumber / 2;
        i++;
    }

    // Affichage du nombre binaire en ordre inverse
    printf("Le nombre binaire est : ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNumber[j]);
    }
    printf("\n");
}

int main() {
    

    int ipv4[4]; 
    int binaire[8]; 

    printf("Saisir une ip : \n");
	scanf("%d.%d.%d.%d", &ipv4[0], &ipv4[1], &ipv4[2], &ipv4[3]);

    for (int i = 0; i < 4; i++) {
        decimalToBinary(ipv4[i]);
        printf("\n");
    }
    
    return 0;
}