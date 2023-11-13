#include <stdio.h>
#include <stdlib.h>

int palindrome(int n) {
  int reversed = 0;
  int temp = n;

  while (n > 0) {
    int last = n % 10;

    reversed += last;

    reversed *= 10;

    n /= 10;
  }

  reversed /= 10;

  return temp == reversed;
}

int main() {
  //  int e;
  //  printf("entrez un nombre\n");
  //  scanf("%d", &e);
  //  printf("le nombre est %d\n", e);

  // printf("%d", binaire);
}