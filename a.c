#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>

#define DEBUG 0

//#include <windows.h>

typedef struct movie {

    int serial_num;
    char *title;
    char *genre;
    char *director;
    char *year;
    char *time;
    char *actors;
	struct actor *act;
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

void put_command();
void init_movie (movie *, char *, char *, char *, char *, char *, char *);
void add_movie (movie *, char *, char *, char *, char *, char *, char *);

void init_actor (actor *, char *, char *, char *, char *);
void add_actor (actor *, char *, char *, char *, char *);

void init_director (director *, char *, char *, char *, char *);
void add_director (director *, char *, char *, char *, char *);

void movie_log(int, int, char *, char *, char *, char *, char *, char *);

void link_director(director *, movie *);
void link_director_r(director *, movie *);

void print(char *, char *);

void end();

movie *m_point;
director *d_point;
actor *a_point;

int size_of_movie = 0;
int size_of_actor = 0;
int size_of_director = 0;

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
*/
void print(char * p1, char * p_serial_num_c)
{
  int p_serial_num;
  char * p_opt;
  movie * print_movie;
  director * print_director;
  actor * print_actor;


  if(p_serial_num_c == NULL)//(movie)print serial_num
  {
    printf("print m|d|a : choice one please\n");
    put_command();
  }
  else//(movie)print opt serial_num
  {
    p_opt = p1;
    p_serial_num = atoi(p_serial_num_c);
  }

  if(strcmp(p_opt, "m") == 0)
  {
    print_movie = m_point;
    while(print_movie -> next != NULL){
      print_movie = print_movie -> next;
      if(p_serial_num == print_movie -> serial_num){
        break;
      }
    }
    printf("%d, %s, %s\n", p_serial_num, print_movie -> title, print_movie -> genre);
    if(print_movie -> direc -> birth == NULL){
      printf("  D : %s(-)\n", print_movie -> director);
    }
    else
      printf("  D : %s(%s)\n", print_movie -> director, print_movie -> direc -> birth);

    if(print_movie -> act -> birth == NULL){
      printf("  A1 : %s(-)\n", print_movie->actors);
    }
    else
      printf("  A1 : %s(%s)\n", print_movie->actors, print_movie->act->birth);

  }
  else if(strcmp(p_opt, "d") == 0)
  {
    print_director = d_point;
    while(print_director -> next != NULL){
      print_director = print_director -> next;
      if(p_serial_num == print_director -> serial_num){
        break;
      }
    }
    printf("%d, %s, %s, %s\n", p_serial_num, print_director->name,
    print_director->sex, print_director->birth);
    //best_movie 1 , 2 , 3
  }
  else if(strcmp(p_opt, "a") == 0)
  {
    print_actor = a_point;
    while(print_actor -> next != NULL){
      print_actor = print_actor -> next;
      if(p_serial_num == print_actor -> serial_num){
        break;
      }
    }
    printf("%d, %s, %s, %s\n", p_serial_num, print_actor->name,
    print_actor->sex, print_actor->birth);
    //best_movie 1 , 2 , 3
  }
  else
    printf("print :  option Error\n");
}


//jeawoo

//junwon
void add(char *mda){

    if (!strcmp(mda, "m")){
        char *t = (char *)malloc(sizeof(char) * 100);
        char *g = (char *)malloc(sizeof(char) * 100);
        char *d = (char *)malloc(sizeof(char) * 100);
        char *y = (char *)malloc(sizeof(char) * 100);
        char *r = (char *)malloc(sizeof(char) * 100);
        char *a = (char *)malloc(sizeof(char) * 100);

        printf(" title > ");
        scanf("%[^\n]", t);
        getchar();

        printf(" genre > ");
        scanf("%[^\n]", g);
        getchar();

        printf(" director > ");
        scanf("%[^\n]", d);
        getchar();

        printf(" year > ");
        scanf("%[^\n]", y);
        getchar();

        printf(" run time > ");
        scanf("%[^\n]", r);
        getchar();

        printf(" actors >  ");
        scanf("%[^\n]", a);
        getchar();

        if(size_of_movie == 0){
            printf("init_movie");
            init_movie(m_point, t, g, d, y, r, a);
            size_of_movie++;
        }
        else{
            printf("add_movie");
            add_movie(m_point, t, g, d, y, r, a);
            size_of_movie++;
        }

    }
    else if (!strcmp(mda, "d")){
        char *n = (char *)malloc(sizeof(char) * 100);
        char *s = (char *)malloc(sizeof(char) * 100);
        char *b = (char *)malloc(sizeof(char) * 100);
        char *m = (char *)malloc(sizeof(char) * 100);

        printf(" name > ");
        scanf("%s[^\n]", n);
        getchar();

        printf(" sex > ");
        scanf("%s", s);
        getchar();

        printf(" birth > ");
        scanf("%s[^\n]", b);
        getchar();

        printf(" best movie > ");
        scanf("%s", m);
        getchar();

        if(size_of_director == 0){
            init_director(d_point, n, s, b, m);
            size_of_director++;
        }
        else{
            add_director(d_point, n, s, b, m);
            size_of_director++;
        }

    }
    else if (!strcmp(mda, "a")){
        char *n = (char *)malloc(sizeof(char) * 100);
        char *s = (char *)malloc(sizeof(char) * 100);
        char *b = (char *)malloc(sizeof(char) * 100);
        char *m = (char *)malloc(sizeof(char) * 100);

        printf(" name > ");
        scanf("%s[^\n]", n);
        getchar();

        printf(" sex > ");
        scanf("%s", s);
        getchar();

        printf(" birth > ");
        scanf("%s[^\n]", b);
        getchar();

        printf(" best movie > ");
        scanf("%s", m);
        getchar();

        if(size_of_actor == 0){
            init_actor(a_point, n, s, b, m);
            size_of_actor++;
        }
        else{
            add_actor(a_point, n, s, b, m);
            size_of_actor++;
        }

    }

//    printf(" title > %s\n", m_point -> title);
//    printf(" genre > %s\n", m_point -> genre);
//    printf(" director > %s\n", m_point -> director);
//    printf(" year > %s\n", m_point -> year);
//    printf(" run time > %s\n", m_point -> time);
//    printf(" actors > %s\n", m_point -> actors);
//
//    if(size_of_movie == 2){
//        printf(" title > %s\n", m_point -> next -> title);
//        printf(" genre > %s\n", m_point -> next -> genre);
//        printf(" director > %s\n", m_point -> next -> director);
//        printf(" year > %s\n", m_point -> next -> year);
//        printf(" run time > %s\n", m_point -> next -> time);
//        printf(" actors > %s\n", m_point -> next -> actors);
//    }

    return;
}

void update(char *mda, char *option, char *num){
	if(!strcmp(mda, "a")){

	}
}

//seung mo

/*******************************************/
//                                         //
// movie, actor, director init or add      //
//                                         //
/*******************************************/

void init_movie (movie *movie_init, char *t, char *g, char *d, char *y, char *r, char *a){
//    movie_init = (movie *)malloc(sizeof(movie));
    movie_init -> title = (char *)malloc(sizeof(char) * (strlen(t) + 1));
    movie_init -> genre = (char *)malloc(sizeof(char) * (strlen(g) + 1));
    movie_init -> director = (char *)malloc(sizeof(char) * (strlen(d) + 1));
    movie_init -> year = (char *)malloc(sizeof(char) * (strlen(y)+ 1));
    movie_init -> time = (char *)malloc(sizeof(char) * (strlen(r) + 1));
    movie_init -> actors = (char *)malloc(sizeof(char) * (strlen(a) + 1));

    movie_init -> serial_num = 1;

    strcpy(movie_init -> title, t);
    strcpy(movie_init -> genre, g);
    strcpy(movie_init -> director, d);
    strcpy(movie_init -> year, y);
    strcpy(movie_init -> time, r);
    strcpy(movie_init -> actors, a);

    movie_init -> next = NULL;
    movie_init -> direc = NULL;

    movie_log(1, movie_init -> serial_num, movie_init -> title, movie_init -> genre, movie_init -> director, movie_init -> year, movie_init -> time, movie_init -> actors);
	link_director(d_point, movie_init);
}

void add_movie(movie *movie_add, char *t, char *g, char *d, char *y, char *r, char *a){

    int num =1;

    while(movie_add -> next != NULL){
        movie_add = movie_add -> next;
        num++;
    }

    movie_add -> next = (movie *)malloc(sizeof(movie));
    movie_add = movie_add -> next;

    movie_add -> title = (char *)malloc(sizeof(char) * (strlen(t) + 1));
    movie_add -> genre = (char *)malloc(sizeof(char) * (strlen(g) + 1));
    movie_add -> director = (char *)malloc(sizeof(char) * (strlen(d) + 1));
    movie_add -> year = (char *)malloc(sizeof(char) * (strlen(y)+ 1));
    movie_add -> time = (char *)malloc(sizeof(char) * (strlen(r) + 1));
    movie_add -> actors = (char *)malloc(sizeof(char) * (strlen(a) + 1));

    movie_add -> serial_num = num + 1;

    strcpy(movie_add -> title, t);
    strcpy(movie_add -> genre, g);
    strcpy(movie_add -> director, d);
    strcpy(movie_add -> year, y);
    strcpy(movie_add -> time, r);
    strcpy(movie_add -> actors, a);

    movie_add -> next = NULL;
    movie_add -> direc = NULL;

    movie_log(1, movie_add -> serial_num, movie_add -> title, movie_add -> genre, movie_add -> director, movie_add -> year, movie_add -> time, movie_add -> actors);
	link_director(d_point, movie_add);

}

void init_actor(actor *actor_init, char *n, char *s, char *b, char *m){
    actor_init -> name = (char *)malloc(sizeof(char) * (strlen(n) + 1));
    actor_init -> sex = (char *)malloc(sizeof(char) * (strlen(s) + 1));
    actor_init -> birth = (char *)malloc(sizeof(char) * (strlen(b) + 1));
    actor_init -> best_movie = (char *)malloc(sizeof(char) * (strlen(m)+ 1));

    actor_init -> serial_num = 1;

    strcpy(actor_init -> name, n);
    strcpy(actor_init -> sex, s);
    strcpy(actor_init -> birth, b);
    strcpy(actor_init -> best_movie, m);

    actor_init -> next = NULL;
}

void add_actor(actor *actor_add, char *n, char *s, char *b, char *m){

    int num =0;

    while(actor_add -> next != NULL){
        actor_add = actor_add -> next;
        num++;
    }

    actor_add -> next = (actor *)malloc(sizeof(actor));
    actor_add = actor_add -> next;

    actor_add -> name = (char *)malloc(sizeof(char) * (strlen(n) + 1));
    actor_add -> sex = (char *)malloc(sizeof(char) * (strlen(s) + 1));
    actor_add -> birth = (char *)malloc(sizeof(char) * (strlen(b) + 1));
    actor_add -> best_movie = (char *)malloc(sizeof(char) * (strlen(m)+ 1));

    actor_add -> serial_num = num + 1;

    strcpy(actor_add -> name, n);
    strcpy(actor_add -> sex, s);
    strcpy(actor_add -> birth, b);
    strcpy(actor_add -> best_movie, m);

    actor_add -> next = NULL;
}

void init_director(director *director_init, char *n, char *s, char *b, char *m){
    director_init -> name = (char *)malloc(sizeof(char) * (strlen(n) + 1));
    director_init -> sex = (char *)malloc(sizeof(char) * (strlen(s) + 1));
    director_init -> birth = (char *)malloc(sizeof(char) * (strlen(b) + 1));
    director_init -> best_movie = (char *)malloc(sizeof(char) * (strlen(m)+ 1));

    director_init -> serial_num = 1;

    strcpy(director_init -> name, n);
    strcpy(director_init -> sex, s);
    strcpy(director_init -> birth, b);
    strcpy(director_init -> best_movie, m);

    director_init -> next = NULL;
	  link_director_r(director_init, m_point);
}

void add_director(director *director_add, char *n, char *s, char *b, char *m){

    int num =0;

    while(director_add -> next != NULL){
        director_add = director_add -> next;
        num++;
    }

    director_add -> next = (director *)malloc(sizeof(director));
    director_add = director_add -> next;

    director_add -> name = (char *)malloc(sizeof(char) * (strlen(n) + 1));
    director_add -> sex = (char *)malloc(sizeof(char) * (strlen(s) + 1));
    director_add -> birth = (char *)malloc(sizeof(char) * (strlen(b) + 1));
    director_add -> best_movie = (char *)malloc(sizeof(char) * (strlen(m)+ 1));

    director_add -> serial_num = num + 1;

    strcpy(director_add -> name, n);
    strcpy(director_add -> sex, s);
    strcpy(director_add -> birth, b);
    strcpy(director_add -> best_movie, m);

    director_add -> next = NULL;
	link_director_r(director_add, m_point);
}
/****************************************/
//                                      //
//          end                         //
//                                      //
/****************************************/
void put_command(){

    char *input = (char *)malloc(sizeof(char));

    char **tok;
    char num_tok = 0;

    printf("(movie) ");
    scanf("%[^\n]", input);
    getchar();

//    if(input == NULL)
//        put_command();

	for(int i = 0;; i++){
		if(input[i] == ' ')
			num_tok++;
		else if(input[i] == '\0')
			break;
	}

    if(DEBUG)
        printf("%d\n", num_tok);

	tok = (char **)malloc(sizeof(char *) * (num_tok + 1));
	*tok = strtok(input, " ");

	for (int i = 0; i < num_tok; i++){
		*(tok + 1 + i) = strtok(NULL, " ");
	}


    if(DEBUG)
        for (int i = 0; i < num_tok + 1; i++)
            printf("%s \n", *(tok + i));


    if(*tok == NULL)
        return;

    else if (!strcmp(*tok, "search"))
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
        end();
	}
	else
	{
		printf("��ũ : %p", m_point -> direc);
        return;
	}
//    print(*tok);

}

void movie_log(int command, int serial, char *t, char *g, char *d, char *y, char *r, char *a){
    FILE *movie_f;

    movie_f = fopen("movie_log.txt", "a");

    if(command == 1)
        fprintf(movie_f, "add:%d:%s:%s:%s:%s:%s:%s\n", serial, t, g, d, y, r, a);
    else if(command == 2)
        fprintf(movie_f, "update:%d:%s:%s:%s:%s:%s:%s\n", serial, t, g, d, y, r, a);
    else
        fprintf(movie_f, "delete:%d:%s:%s:%s:%s:%s:%s\n", serial, t, g, d, y, r, a);

    fclose(movie_f);

    return;

}

void link_director(director *director_link, movie *movie_link){
	printf("link. \n");
	if (size_of_director == 0)
		return;

	while(director_link -> next != NULL){
    printf("link2. \n");
		if(!strcmp(director_link -> name, movie_link -> director)){
      printf("link3. \n");
			movie_link -> direc = director_link;
			return;
		}
		else
			director_link = director_link -> next;
	}
}

void link_director_r(director *director_link, movie *movie_link){
	printf("link \n");
	if(size_of_movie == 0)
		return;

	while(movie_link -> next != NULL){
		printf("link2 \n");
		if(!strcmp(movie_link -> director, director_link -> name)){
      printf("link3 \n");
			movie_link -> direc = director_link;
			movie_link = movie_link -> next;
		}
		else
			movie_link = movie_link -> next;
	}
}

void end(){
    exit(1);
}

void sig_handler(){
    char exit;

    printf("\nGet Interrupt Signal.");
    printf("\nDo you want to exit myMOVIE program (Y/N) ");
    scanf("%c", &exit);
    getchar();

    if(exit == 'Y' || exit == 'y'){
        end();
    }
    else{
        put_command();
    }
}

int main(void){
    signal(SIGINT, (void *)sig_handler);

	char *input = (char *)malloc(sizeof(char));

    m_point = (movie *)malloc(sizeof(movie));
    d_point = (director *)malloc(sizeof(director));
    a_point = (actor *)malloc(sizeof(actor));

    while(1)
        put_command();

	printf("\n");
	return 0;
}
