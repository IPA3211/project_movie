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
    struct director *direc;
    struct movie *next;
    
} movie;

typedef struct director {
    
    int serial_num;
    char *name;
    char *sex;
    char *birth;
    char *best_movie;
    
    struct director *next;
    
} director;

typedef struct actor {
    
    int serial_num;
    char *name;
    char *sex;
    char *birth;
    char *best_movie;
    struct actor *next;
    
} actor;

void init_data (movie *, char *, char *, char *, char *, char *, char *);


movie *m;
director *d;
actor *a;

int size_of_data = 0;
//cheolsoon

//jeawoo

//junwon
void add(char *mda){
    char *t;
    t = (char *)malloc(sizeof(char) * 100);
    char *g = (char *)malloc(sizeof(char) * 100);
    char *d = (char *)malloc(sizeof(char) * 100);
    char *y = (char *)malloc(sizeof(char) * 100);
    char *r = (char *)malloc(sizeof(char) * 100);
    char *a = (char *)malloc(sizeof(char) * 100);
    
    printf(" title > ");
    scanf("%s[^\n]", t);
    
    printf(" genre > ");
    scanf("%s", g);
    
    getchar();
    
    printf(" director > ");
    scanf("%s[^\n]", d);
    
    printf(" year > ");
    scanf("%s", y);

    getchar();
    
    printf(" run time > ");
    scanf("%s", r);
    
    getchar();
    
    printf(" actors >  ");
    scanf("%[^\n]", a);
    
    if(size_of_data == 0)
        init_data(m, t, g, d, y, r, a);
    
    printf(" title > %s\n", m -> title);
    printf(" genre > %s\n", m -> genre);
    printf(" director > %s\n", m -> director);
    printf(" year > %s\n", m -> year);
    printf(" run time > %s\n", m -> time);
    printf(" actors > %s\n", m -> actors);
    
    
    
    return;
}

//seung mo

void init_data (movie *movie_init, char *t, char *g, char *d, char *y, char *r, char *a){
//    movie_init = (movie *)malloc(sizeof(movie));
    movie_init -> title = (char *)malloc(sizeof(char) * (strlen(t) + 1));
    movie_init -> genre = (char *)malloc(sizeof(char) * (strlen(g) + 1));
    movie_init -> director = (char *)malloc(sizeof(char) * (strlen(d) + 1));
    movie_init -> year = (char *)malloc(sizeof(char) * (strlen(y)+ 1));
    movie_init -> time = (char *)malloc(sizeof(char) * (strlen(r) + 1));
    movie_init -> actors = (char *)malloc(sizeof(char) * (strlen(a) + 1));
    
    strcpy(movie_init -> title, t);
    strcpy(movie_init -> genre, g);
    strcpy(movie_init -> director, d);
    strcpy(movie_init -> year, y);
    strcpy(movie_init -> time, r);
    strcpy(movie_init -> actors, a);
    
    movie_init -> next = NULL;
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
        add(*(tok + 1));
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
//    print(*tok);

}

int main(void){
	char *input = (char *)malloc(sizeof(char));
    
    m = (movie *)malloc(sizeof(movie));
    d = (director *)malloc(sizeof(director));
    a = (actor *)malloc(sizeof(actor));
    
    put_command(input);
//    print(a);

	printf("\n");
	return 0;
}
