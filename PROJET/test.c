#include <stdio.h>


struct reseaux {
	int ipv4[4];
};

int main (void){

	struct reseaux ip = {{192, 168, 1, 1 }};
	
	printf("test ip : %d.%d.%d.%d\n", ip.ipv4[0], ip.ipv4[1], ip.ipv4[2], ip.ipv4[3] );



	printf("Saisir une ip : \n");
	scanf("%d.%d.%d.%d", &ip.ipv4[0], &ip.ipv4[1], &ip.ipv4[2], &ip.ipv4[3]);

	printf("test ip : %d.%d.%d.%d\n", ip.ipv4[0], ip.ipv4[1], ip.ipv4[2], ip.ipv4[3] );

	return 0;
}
