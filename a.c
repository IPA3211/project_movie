#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include <windows.h>

typedef struct movie {
    
    int serial_num;
    char *title;
    char *genre;
    char *director;
    char *year;
    char *time;
    char *actors;
    director *direc
    movie *next;
    
} movie;

typedef struct director {
    
    int serial_num;
    char *name;
    char *sex;
    char *birth;
    char *best_movie;
    
    director *next;
    
} director;

typedef struct actor {
    
    int serial_num;
    char *name;
    char *sex;
    char *birth;
    char *best_movie;
    actor *next;
    
} actor;

//cheolsoon

//jeawoo

//junwon

//seung mo



int print(char *test){
	printf("test = %s\n", test);
	return 0;
}

void put_command(char *a){
    printf("(movie) ");
	scanf("%[^\n]", a);
   
    char **tok;
	char num_tok;

	for(int i = 0;; i++){
		if(a[i] == ' ')
			num_tok++;
		else if(a[i] == '\0')
			break;
	}
	printf("%d\n", num_tok);
	
	tok = (char **)malloc(sizeof(char *) * (num_tok + 1));
	*tok = strtok(a, " ");
		
	for (int i = 0; i < num_tok; i++){
		*(tok + 1 + i) = strtok(NULL, " ");
	}

	for (int i = 0; i < num_tok + 1; i++)
		printf("%s \n", *(tok + i));

    if (!strcmp(*tok, "search"))
    {
		if (num_tok == 1){
			printf("string = %s\n", *(tok + 1));
		}
		else if (num_tok == 2){
			printf("option = %s\n", *(tok + 1));
			printf("string = %s\n", *(tok + 2));	
		}
    }

	else if (!strcmp(*tok,"print"))
	{
		printf("m|d|a = %s\n", *(tok + 1));
		printf("num = %s\n", *(tok + 2));	
	}
	else if (!strcmp(*tok, "add"))
	{
		printf("m|d|a = %s\n", *(tok + 1));
	}
	else if (!strcmp(*tok, "update"))
	{
		printf("m|d|a = %s\n", *(tok + 1));
		printf("option = %s\n", *(tok + 2));
		printf("num = %s\n", *(tok + 3));

		if (num_tok == 2){
			printf("m|d|a = %s\n", *(tok + 1));
			printf("num = %s\n", *(tok + 2));	
		}
	}
	else if (!strcmp(*tok, "delete"))
	{
		printf("m|d|a = %s\n", *(tok + 1));
		printf("num = %s\n", *(tok + 2));	
	}
	else if (!strcmp(*tok, "sort"))
	{
		char *file;
		for (int a = 0; a < num_tok + 1; a++){
			if(*(*(tok + a) + 1) == 'f'){
				file = (char *)malloc(sizeof(char) * strlen(*(tok + a + 1)));
				file = *(tok + a + 1);
				*(tok + a) = NULL;
				break;
			}
			else
				file = NULL;
		}
		printf("m|d|a = %s\n", *(tok + 1));
		printf("option = %s\n", *(tok + 2));
		printf("file = %s\n", file);
	}
	else if (!strcmp(*tok, "save"))
	{
		char *file;
		for (int a = 0; a < num_tok + 1; a++){
			if(*(*(tok + a) + 1) == 'f'){
				file = (char *)malloc(sizeof(char) * strlen(*(tok + a + 1)));
				file = *(tok + a + 1);
				*(tok + a) = NULL;
				break;
			}
			else
				file = NULL;
		}
		printf("m|d|a = %s\n", *(tok + 1));
		printf("option = %s\n", *(tok + 2));
		printf("file = %s\n", file);
	}
	else if (!strcmp(*tok, "end"))
	{
        
	}
	else
	{
	}
    print(*tok);

}

int main(void){
	char *a = (char *)malloc(sizeof(char));
    while(1){
        put_command(a);
    }
//    print(a);

	printf("\n");
	return 0;
}
