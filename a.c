#include <stdio.h>
#include <stdlib.h>
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
    
    if (!strcmp(tok, "search"))
    {
        printf("search ipruk");
    }
    print(commned_name);
}

int main(void){
	char *a = (char *)malloc(sizeof(char));

 	put_commend(a);
    print(a);

	printf("\n");
	return 0;
}
