// seung mo
#include <stdio.h>
#include <string.h>
int print(char *test){
	printf("test = %s\n", test);
	return 0;
}

void put_commend(char *a){
    printf("(movie) ");
	scanf("%[^\n]s", a);
    
    char *tok = strtok(a," ");
    char *commned_name = tok;
    
    if (strcmp(*tok, "search"))
    print(commned_name);
}
