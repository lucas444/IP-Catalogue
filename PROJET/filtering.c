#include <stdio.h>
struct ipv4 
{
    int octet[4];
};
struct mask 
{
    int octet[4];
};
struct ipv4 ipv4_init(void)
{
    struct ipv4 init = { { 192, 168, 1, 1 } };
    printf("Saisir une ip : \n");
    scanf("%d.%d.%d.%d", &init.octet[0], &init.octet[1], &init.octet[2], &init.octet[3]);    
    return init;
};
struct mask mask_init(void)
{
    struct mask init = { { 255, 255, 255, 0 } };
    printf("Saisir un mask : \n");
    scanf("%d.%d.%d.%d", &init.octet[0], &init.octet[1], &init.octet[2], &init.octet[3]);      
    return init;
};
int main (void)
{        
    struct ipv4 address = ipv4_init();
    struct mask masque = mask_init();
    printf("IP address : %d.%d.%d.%d\n", address.octet[0], address.octet[1], address.octet[2], address.octet[3]);
    printf("Mask : %d.%d.%d.%d\n", masque.octet[0], masque.octet[1], masque.octet[2], masque.octet[3]);
    return 0;
}