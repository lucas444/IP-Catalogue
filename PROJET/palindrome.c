#include <stdio.h>

int main() {
  int input;
  printf("Entrer un nombre\n");

  scanf("%d", &input);

  int reversed = 0;
  int cache = input;
  while (cache > 0) {
    reversed += cache % 10;
    reversed *= 10;
    cache /= 10;
  }

  reversed /= 10;

  printf("Original = %d\n", input);
  printf("Reversed = %d\n", reversed);
  if (reversed == input) {
    printf("%d is a palindrome\n", input);
  } else {
    printf("%d is not a palindrome\n", input);
  }
  return 0;
}