#include <stdio.h>


struct res {
	int ip[4];
};

struct res t(void){

	struct res init = {{192, 168, 1, 1 }};

	return init;
}

int main (void){

	
	struct res s = t();


	//printf("test %d", &ip);
	printf("test ip : %d.%d.%d.%d\n", s.ip[0], s.ip[1], s.ip[2], s.ip[3] );

	return 0;
}
