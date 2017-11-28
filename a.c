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
/*
void search_main(char *s_opt1, char *s_opt2)
{
  char *s_opt, *s_keyword;

  if(s_opt2 == NULL) //(movie)search keyword (search all file)
  {
    s_keyword = s_opt1;
    s_opt = (char *)malloc(sizeof(char) * 5);
    s_opt = '-a';
    search_moviefile(s_keyword, s_opt);
    search_actorfile(s_keyword, s_opt);
    search_directorfile(s_keyword, s_opt);
  }
  else //(movie)search -opt keyword (-opt_file)
  {
    s_opt = s_opt1;
    s_keyword = s_opt2;
    if(strcmp('-m', s_opt) == 0)
      search_moviefile(s_keyword, s_opt);
    else if(strcmp('-a', s_opt) == 0)
      search_actorfile(s_keyword, s_opt);
    else if(strcmp('-d', s_opt) == 0)
      search_directorfile(s_keyword, s_opt);
    else if((strcmp('-am', s_opt) == 0) || (strcmp('-ma', s_opt) == 0)){
      search_moviefile(s_keyword, s_opt);
      search_actorfile(s_keyword, s_opt);
    }
    else if((strcmp('-dm', s_opt) == 0) || (strcmp('-md', s_opt) == 0)){
      search_moviefile(s_keyword, s_opt);
      search_directorfile(s_keyword, s_opt);
    }
    else if((strcmp('-ad', s_opt) == 0) || (strcmp('-da', s_opt) == 0)){
      search_actorfile(s_keyword, s_opt);
      search_directorfile(s_keyword, s_opt);
    }
    else{  //search all file
      search_moviefile(s_keyword, s_opt);
      search_actorfile(s_keyword, s_opt);
      search_directorfile(s_keyword, s_opt);
    }
  }
}

void search_moviefile(char *f_keyword, char *f_opt)
{
  FILE *movie_f;

  if((movie_f = fopen("movie_list.txt", "r")) != NULL)//movie_file
  {
    while(ftell(movie_f) == EOF)//until end of file
    {
      if((strcmp(f_keyword, movie_list->title)) == 0){
        printf("ex: movie info print\n");
        movie_list = movie_list->next;
      }
      else{
        movie_list = movie_list->next;
      }
    }
    fclose(movie_f);
  }
}

void search_actorfile(char *f_keyword, char *f_opt)
{
  FILE *act_f;

  if((act_f = fopen("actor_list.txt", "r")) != NULL)//actor_file
  {
    while(ftell(act_f) == EOF)
    {
      if((strcmp(f_keyword, act_list->name)) == 0){
        printf("ex: actor info print\n");
        act_list = act_list->next;
      }
      else{
        act_list = act_list->next;
      }
    }
    fclose(act_f);
  }
}

void search_directorfile(char *f_keyword, char *f_opt)
{
  FILE *dir_f;

  if((dir_f = fopen("director_list.txt", "r")) != NULL)//director_file
  {
    while(ftell(dir_f) == EOF)
    {
      if((strcmp(f_keyword, director_list->name)) == 0){
        printf("ex: director info print\n");
        director_list = director_list->next;
      }
      else{
        director_list = director_list->next;
      }
    }
    fclose(dir_f);
  }
}

void print(char * p_opt1, char * p_opt2)
{
  char * p_serial_num;
  char * p_opt;

  if(p_opt2 == NULL)//(movie)print serial_num
  {
    p_serial_num = p_opt1;
    p_opt=NULL;

  }
  else//(movie)print opt serial_num
  {
    p_opt = p_opt1;
    p_serial_num = p_opt2;
  }
}
*/

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
