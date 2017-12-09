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
void init_movie (movie *, char *, char *, char *, char *, char *, char *, int);
void add_movie (movie *, char *, char *, char *, char *, char *, char *, int);

void init_actor (actor *, char *, char *, char *, char *, int);
void add_actor (actor *, char *, char *, char *, char *, int);

void init_director (director *, char *, char *, char *, char *, int);
void add_director (director *, char *, char *, char *, char *, int);

void movie_log(int, int, char *, char *, char *, char *, char *, char *);
void director_log(int, int, char *, char *, char *, char *);
void actor_log(int, int, char *, char *, char *, char *);

void link_director(movie *);
void link_director_r(director *);

void print(char *, char *);

void write_movie(char *, char *);
void write_director(char *, char *);
void write_actor(char *, char *);

void save(char *, char *, char *);

int M_TitleSorting(const void *, const void *);
int M_GenreSorting(const void *, const void *);
int M_DirectorSorting(const void *, const void *);
int M_YearSorting(const void *, const void *);
int M_RunTimeSorting(const void *, const void *);
int M_ActorSorting(const void *, const void *);
int M_SerialSorting(const void *, const void *);

int A_NameSorting(const void *, const void *);
int A_SexSorting(const void *, const void *);
int A_BirthSorting(const void *, const void *);
int A_BestSorting(const void *, const void *);
int A_SerialSorting(const void *, const void *);

int D_NameSorting(const void *, const void *);
int D_SexSorting(const void *, const void *);
int D_BirthSorting(const void *, const void *);
int D_BestSorting(const void *, const void *);
int D_SerialSorting(const void *, const void *);

void sort_movie(char *, char *);
void sort_director(char *, char *);
void sort_actor(char *, char *);

void end();

movie *m_point;
director *d_point;
actor *a_point;

int size_of_movie = 0;
int size_of_actor = 0;
int size_of_director = 0;

movie *POINT_MOVIE;
director *POINT_DIRECTOR;
actor *POINT_ACTOR;
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
    print_movie = POINT_MOVIE;
    while(print_movie -> next != NULL){
      if(p_serial_num == print_movie -> serial_num){
        break;
      }
        print_movie = print_movie -> next;
    }
    printf("%d, %s, %s\n", print_movie -> serial_num, print_movie -> title, print_movie -> genre);
    if(print_movie -> direc == NULL){
      printf("  D : %s(-)\n", print_movie -> director);
    }
    else
      printf("  D : %s(%s)\n", print_movie -> director, print_movie -> direc -> birth);

    if(print_movie -> act == NULL){
      printf("  A1 : %s(-)\n", print_movie->actors);
    }
    else
      printf("  A1 : %s(%s)\n", print_movie->actors, print_movie->act->birth);

  }
  else if(strcmp(p_opt, "d") == 0)
  {
    print_director = POINT_DIRECTOR;
    while(print_director -> next != NULL){
      if(p_serial_num == print_director -> serial_num){
        break;
      }
        print_director = print_director -> next;
    }
    printf("%d, %s, %s, %s\n", print_director -> serial_num, print_director->name,
    print_director->sex, print_director->birth);
    //best_movie 1 , 2 , 3
  }
  else if(strcmp(p_opt, "a") == 0)
  {
    print_actor = POINT_ACTOR;
    while(print_actor -> next != NULL){
      if(p_serial_num == print_actor -> serial_num){
        break;
      }
        print_actor = print_actor -> next;
    }
    printf("%d, %s, %s, %s\n", print_actor -> serial_num, print_actor->name,
    print_actor->sex, print_actor->birth);
    //best_movie 1 , 2 , 3
  }
  else
    printf("print :  option Error\n");
}

void delete(char * del_opt, char * del_num)
{
  int del_serial;
  movie * del_movie;
  director * del_director;
  actor * del_actor;
  del_director
  if(del_num == NULL){
    printf(" delete m|a|d serial_num \n");
  }
  else{
    del_serial = atoi(del_num);
    if(strcmp(del_opt, "m") == 0){
      while(del_movie -> next != NULL){
        if(del_serial == del_movie -> serial_num){
          break;
        }
      }
    }
    else if(strcmp(del_opt, "d") == 0){

    }
    else if(strcmp(del_opt, "a") == 0){

    }
  }
}

//jeawoo

int read_movie_log(void)
{
    printf("read START");
    FILE *m_log, *d_log, *a_log;
    char *line, *token;
    char *tag;
    char *title, *genre, *director, *year, *running, *actor;
    char *name, *sex, *birth, *best_mov;
    char *serial_a, *serial_d, *serial_m;
    int check;

    line = (char *)malloc(sizeof(char));
    token = (char *)malloc(sizeof(char));

    m_log = fopen("movie_log.txt", "r");
    a_log = fopen("actor_log.txt", "r");
    d_log = fopen("director_log.txt", "r");

    while(fscanf(m_log, "%s", line) != EOF){
        tag = (char *)malloc(sizeof(char));
        serial_m = (char *)malloc(sizeof(char));
        title = (char *)malloc(sizeof(char));
        genre = (char *)malloc(sizeof(char));
        director = (char *)malloc(sizeof(char));
        year = (char *)malloc(sizeof(char));
        running = (char *)malloc(sizeof(char));
        actor = (char *)malloc(sizeof(char));

        token = strtok(line, ":");
        tag = token;

        token = strtok(NULL, ":");
        serial_m = token;

        token = strtok(NULL, ":");
        title = token;

        token = strtok(NULL, ":");
        genre = token;

        token = strtok(NULL, ":");
        director = token;

        token = strtok(NULL, ":");
        year = token;

        token = strtok(NULL, ":");
        running = token;

        token = strtok(NULL, ":");
        actor = token;

        token = strtok(NULL, ":");

        printf("%s %s %s %s %s %s %s %s \n", tag, serial_m, title, genre, director, year, running, actor);

        if (!strcmp(tag, "add")){
            if(size_of_movie == 0){
                printf("init_movie\n");
                init_movie(m_point, title, genre, director, year, running, actor, 1);
                size_of_movie++;
            }
            else{
                printf("add_movie");
                add_movie(m_point, title, genre, director, year, running, actor, 1);
                size_of_movie++;
            }
        }
    }

    while(fscanf(a_log, "%s", line) != EOF){
        tag = (char *)malloc(sizeof(char));
        serial_a = (char *)malloc(sizeof(char));
        name = (char *)malloc(sizeof(char));
        sex = (char *)malloc(sizeof(char));
        birth = (char *)malloc(sizeof(char));
        best_mov = (char *)malloc(sizeof(char));

        token = strtok(line, ":");
        tag = token;

        token = strtok(NULL, ":");
        serial_a = token;

        token = strtok(NULL, ":");
        name= token;

        token = strtok(NULL, ":");
        sex = token;

        token = strtok(NULL, ":");
        birth = token;

        token = strtok(NULL, ":");
        best_mov = token;

        token = strtok(NULL, ":");

        printf("%s %s %s %s %s %s\n", tag, serial_a, name, sex, birth, best_mov);

        if (!strcmp(tag, "add")){
            if(size_of_actor == 0){
                printf("init_movie\n");
                init_actor(a_point, name, sex, birth, best_mov, 1);
                size_of_actor++;
            }
            else{
                printf("add_movie");
                add_actor(a_point, name, sex, birth, best_mov, 1);
                size_of_actor++;
            }
        }
    }

    while(fscanf(d_log, "%s", line) != EOF){
        tag = (char *)malloc(sizeof(char));
        serial_d = (char *)malloc(sizeof(char));
        name = (char *)malloc(sizeof(char));
        sex = (char *)malloc(sizeof(char));
        birth = (char *)malloc(sizeof(char));
        best_mov = (char *)malloc(sizeof(char));

        token = strtok(line, ":");
        tag = token;

        token = strtok(NULL, ":");
        serial_d = token;

        token = strtok(NULL, ":");
        name = token;

        token = strtok(NULL, ":");
        sex = token;

        token = strtok(NULL, ":");
        birth = token;

        token = strtok(NULL, ":");
        best_mov = token;

        token = strtok(NULL, ":");

        printf("%s %s %s %s %s %s \n", tag, serial_d, name, sex, birth, best_mov);

        if (!strcmp(tag, "add")){
            if(size_of_director == 0){
                printf("init_movie\n");
                init_director(d_point, name, sex, birth, best_mov, 1);
                size_of_director++;
            }
            else{
                printf("add_movie");
                add_director(d_point, name, sex, birth, best_mov, 1);
                size_of_director++;
            }
        }
    }

    printf("finish\n");
    /*
    while(fscanf(m_log, "%[^\n]", line) != EOF)
    {
        *tok = strtok(line, ":");
        tag = (char *)malloc(sizeof(char) * (strlen(*tok) + 1));
        strcpy(tag, *tok);
        printf("%s", tag);

        *tok = strtok(NULL, ":");
        serial = atoi(*tok);
        printf("%d", serial);

        *tok = strtok(NULL, ":");
        title = (char *)malloc(sizeof(char) * (strlen(*tok) + 1));
        strcpy(title, *tok);
        printf("%s", title);

        *tok = strtok(NULL, ":");
        genre = (char *)malloc(sizeof(char) * (strlen(*tok) + 1));
        strcpy(genre, *tok);
        printf("%s", genre);

        *tok = strtok(NULL, ":");
        director = (char *)malloc(sizeof(char) * (strlen(*tok) + 1));
        strcpy(director, *tok);

        *tok = strtok(NULL, ":");
        year = (char *)malloc(sizeof(char) * (strlen(*tok) + 1));
        strcpy(year, *tok);

        *tok = strtok(NULL, ":");
        running = (char *)malloc(sizeof(char) * (strlen(*tok) + 1));
        strcpy(running, *tok);

        *tok = strtok(NULL, ":");
        actor = (char *)malloc(sizeof(char) * (strlen(*tok) + 1));
        strcpy(actor, *tok);

        if (!strcmp(tag, "add")){
            if(size_of_movie == 0){
                printf("init_movie");
                init_movie(m_point, title, genre, director, year, running, actor, 1);
                size_of_movie++;
            }
            else{
                printf("add_movie");
                init_movie(m_point, title, genre, director, year, running, actor, 1);
                size_of_movie++;
            }
        }

        switch(tag)
         {
         case 'a':
         while(tok = strtok(NULL,":"))
         {

         }
         add_movie();
         break;
         case 'u':
         while(tok = strtok(NULL,":"))
         {
         printf("%s\n",tok);
         }
         break;
         case 'd':
         while(tok = strtok(NULL,":"))
         {
         printf("%s\n",tok);
         }
         break;
         default:
         break;
         }
    }
    */
    /*
    free(token);
    free(tag);
    free(genre);
    free(director);
    free(year);
    free(running);
    free(actor);
     */
    fclose(m_log);

    printf("end\n");
    return 0;
}


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
            init_movie(m_point, t, g, d, y, r, a, 0);
            size_of_movie++;
        }
        else{
            printf("add_movie");
            add_movie(m_point, t, g, d, y, r, a, 0);
            size_of_movie++;
        }

    }
    else if (!strcmp(mda, "d")){
        char *n = (char *)malloc(sizeof(char) * 100);
        char *s = (char *)malloc(sizeof(char) * 100);
        char *b = (char *)malloc(sizeof(char) * 100);
        char *m = (char *)malloc(sizeof(char) * 100);

        printf(" name > ");
        scanf("%[^\n]", n);
        getchar();

        printf(" sex > ");
        scanf("%[^\n]", s);
        getchar();

        printf(" birth > ");
        scanf("%[^\n]", b);
        getchar();

        printf(" best movie > ");
        scanf("%[^\n]", m);
        getchar();

        if(size_of_director == 0){
            init_director(d_point, n, s, b, m, 0);
            size_of_director++;
        }
        else{
            add_director(d_point, n, s, b, m, 0);
            size_of_director++;
        }

    }
    else if (!strcmp(mda, "a")){
        char *n = (char *)malloc(sizeof(char) * 100);
        char *s = (char *)malloc(sizeof(char) * 100);
        char *b = (char *)malloc(sizeof(char) * 100);
        char *m = (char *)malloc(sizeof(char) * 100);

        printf(" name > ");
        scanf("%[^\n]", n);
        getchar();

        printf(" sex > ");
        scanf("%[^\n]", s);
        getchar();

        printf(" birth > ");
        scanf("%[^\n]", b);
        getchar();

        printf(" best movie > ");
        scanf("%[^\n]", m);
        getchar();

        if(size_of_actor == 0){
            init_actor(a_point, n, s, b, m, 0);
            size_of_actor++;
        }
        else{
            add_actor(a_point, n, s, b, m, 0);
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
//
//void save(char *mda, char *option, char *file_name){
//
//}

void update(char *mda, char *option, char *num){
    if(!strcmp(mda, "a")){
        if(atoi(num) > size_of_actor)
            return;

        actor *update_a = POINT_ACTOR;

        while(update_a -> next != NULL){
            if(update_a -> serial_num == atoi(num))
                break;
            else
                update_a = update_a -> next;
        }

        for(int i = 0; ; i++){
            if(*(option + i) == '\0')
                break;

            switch (*(option + i)) {
                case 'n':
                {
                    char *n = (char *)malloc(sizeof(char));
                    printf("name >");
                    scanf("%[^\n]", n);

                    strcpy(update_a -> name, n);
                    break;
                }
                case 's':
                {
                    char *s = (char *)malloc(sizeof(char));
                    printf("sex >");
                    scanf("%[^\n]", s);

                    strcpy(update_a -> sex, s);
                    break;
                }
                case 'b':
                {
                    char *b = (char *)malloc(sizeof(char));
                    printf("birth >");
                    scanf("%[^\n]", b);

                    strcpy(update_a -> birth, b);
                    break;
                }
                case 'm':
                {
                    char *m = (char *)malloc(sizeof(char));
                    printf("best movie >");
                    scanf("%[^\n]", m);

                    strcpy(update_a -> best_movie, m);
                    break;
                }

                default:
                    break;
            }

        }
	}
    if(!strcmp(mda, "d")){
        if(atoi(num) > size_of_director)
            return;

        director *update_d = POINT_DIRECTOR;

        while(update_d -> next != NULL){
            if(update_d -> serial_num == atoi(num))
                break;
            else
                update_d = update_d -> next;
        }

        for(int i = 0; ; i++){
            if(*(option + i) == '\0')
                break;

            switch (*(option + i)) {
                case 'n':
                {
                    char *n = (char *)malloc(sizeof(char));
                    printf("name >");
                    scanf("%[^\n]", n);

                    strcpy(update_d -> name, n);
                    link_director_r(update_d);
                    break;
                }
                case 's':
                {
                    char *s = (char *)malloc(sizeof(char));
                    printf("sex >");
                    scanf("%[^\n]", s);

                    strcpy(update_d -> sex, s);
                    break;
                }
                case 'b':
                {
                    char *b = (char *)malloc(sizeof(char));
                    printf("birth >");
                    scanf("%[^\n]", b);

                    strcpy(update_d -> birth, b);
                    break;
                }
                case 'm':
                {
                    char *m = (char *)malloc(sizeof(char));
                    printf("best movie >");
                    scanf("%[^\n]", m);

                    strcpy(update_d -> best_movie, m);
                    break;
                }

                default:
                    break;
            }

        }
    }
    if(!strcmp(mda, "m")){
        if(atoi(num) > size_of_movie)
            return;

        movie *update_m = POINT_MOVIE;

        while(update_m -> next != NULL){
            if(update_m -> serial_num == atoi(num))
                break;
            else
                update_m = update_m -> next;
        }

        for(int i = 0; ; i++){
            if(*(option + i) == '\0')
                break;

            switch (*(option + i)) {
                case 't':
                {
                    char *t = (char *)malloc(sizeof(char));
                    printf("title >");
                    scanf("%s", t);

                    strcpy(update_m -> title, t);
                    break;
                }
                case 'g':
                {
                    char *g = (char *)malloc(sizeof(char));
                    printf("genre >");
                    scanf("%s", g);

                    strcpy(update_m -> genre, g);
                    break;
                }
                case 'd':
                {
                    char *d = (char *)malloc(sizeof(char));
                    printf("director >");
                    scanf("%s", d);

                    strcpy(update_m -> director, d);
                    link_director(update_m);
                    break;
                }
                case 'y':
                {
                    char *y = (char *)malloc(sizeof(char));
                    printf("year >");
                    scanf("%s", y);

                    strcpy(update_m -> year, y);
                    break;
                }
                case 'r':
                {
                    char *r = (char *)malloc(sizeof(char));
                    printf("run time >");
                    scanf("%s", r);

                    strcpy(update_m -> time, r);
                    break;
                }
                case 'a':
                {
                    char *a = (char *)malloc(sizeof(char));
                    printf("actor >");
                    scanf("%s", a);

                    strcpy(update_m -> actors, a);
                    break;
                }

                default:
                    break;
            }

        }
    }
}

//seung mo

/*******************************************/
//                                         //
// movie, actor, director init or add      //
//                                         //
/*******************************************/

void init_movie (movie *movie_init, char *t, char *g, char *d, char *y, char *r, char *a, int log){
    //    movie_init = (movie *)malloc(sizeof(movie));

    movie_init = POINT_MOVIE;

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

    printf("%d %s %s %s %s %s %s \n", movie_init -> serial_num, movie_init -> title, movie_init -> genre, movie_init -> director, movie_init -> year, movie_init -> time, movie_init -> actors);

    if(log == 0)
        movie_log(1, movie_init -> serial_num, movie_init -> title, movie_init -> genre, movie_init -> director, movie_init -> year, movie_init -> time, movie_init -> actors);

	link_director(movie_init);

}

void add_movie(movie *movie_add, char *t, char *g, char *d, char *y, char *r, char *a, int log){

    int num =1;
    movie_add = POINT_MOVIE;

    while(movie_add -> next != NULL){
        movie_add = movie_add -> next;
        num = movie_add -> serial_num;
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

    printf("%d %s %s %s %s %s %s \n", movie_add -> serial_num, movie_add -> title, movie_add -> genre, movie_add -> director, movie_add -> year, movie_add -> time, movie_add -> actors);

    if(log == 0)
        movie_log(1, movie_add -> serial_num, movie_add -> title, movie_add -> genre, movie_add -> director, movie_add -> year, movie_add -> time, movie_add -> actors);

	link_director(movie_add);


}

void init_actor(actor *actor_init, char *n, char *s, char *b, char *m, int log){
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

    if(log == 0)
        actor_log(1 ,actor_init -> serial_num ,actor_init -> name, actor_init -> sex, actor_init -> birth, actor_init -> best_movie);
}

void add_actor(actor *actor_add, char *n, char *s, char *b, char *m, int log){

    int num = 1;

    while(actor_add -> next != NULL){
        actor_add = actor_add -> next;
        num = actor_add -> serial_num;
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

    if(log == 0)
        actor_log(1, actor_add -> serial_num, actor_add -> name, actor_add -> sex, actor_add -> birth, actor_add -> best_movie);

}

void init_director(director *director_init, char *n, char *s, char *b, char *m, int log){
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
    link_director_r(director_init);

    if(log == 0)
        director_log(1, director_init -> serial_num, director_init -> name, director_init -> sex, director_init -> birth, director_init -> best_movie);
}

void add_director(director *director_add, char *n, char *s, char *b, char *m, int log){

    int num = 1;

    while(director_add -> next != NULL){
        director_add = director_add -> next;
        num = director_add -> serial_num;
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
	link_director_r(director_add);

    if(log == 0)
        director_log(1, director_add -> serial_num, director_add -> name, director_add -> sex, director_add -> birth, director_add -> best_movie);
}
/*******************************************/
//                                         //
//              end                        //
//                                         //
/*******************************************/

/*******************************************/
//                                         //
// movie, actor, director make log         //
//                                         //
/*******************************************/

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

void director_log(int command, int serial, char *n, char *s, char *b, char *bm){
    FILE *movie_f;

    movie_f = fopen("director_log.txt", "a");

    if(command == 1)
        fprintf(movie_f, "add:%d:%s:%s:%s:%s\n", serial, n, s, b, bm);
    else if(command == 2)
        fprintf(movie_f, "update:%d:%s:%s:%s:%s\n", serial, n, s, b, bm);
    else
        fprintf(movie_f, "delete:%d:%s:%s:%s:%s\n", serial, n, s, b, bm);

    fclose(movie_f);

    return;

}

void actor_log(int command, int serial, char *n, char *s, char *b, char *bm){
    FILE *movie_f;

    movie_f = fopen("actor_log.txt", "a");

    if(command == 1)
        fprintf(movie_f, "add:%d:%s:%s:%s:%s\n", serial, n, s, b, bm);
    else if(command == 2)
        fprintf(movie_f, "update:%d:%s:%s:%s:%s\n", serial, n, s, b, bm);
    else
        fprintf(movie_f, "delete:%d:%s:%s:%s:%s\n", serial, n, s, b, bm);

    fclose(movie_f);

    return;

}

/*******************************************/
//                                         //
//                  end                    //
//                                         //
/*******************************************/
/*******************************************/
//                                         //
// movie, actor, director link             //
//                                         //
/*******************************************/

void link_director(movie *movie_link){// when movie changed
    director *director_link = POINT_DIRECTOR;

    printf("link. \n");
    if (size_of_director == 0)
        return;

    do{
        printf("link2. \n");
        if(!strcmp(director_link -> name, movie_link -> director)){
            printf("link3. \n");
            movie_link -> direc = director_link;
            return;
        }
        else{
            if(director_link -> next != NULL)
                director_link = director_link -> next;
            else
                return;
        }
    }
    while(1);
}

void link_director_r(director *director_link){// when director changed
    movie *movie_link = POINT_MOVIE;

    printf("link \n");
    if(size_of_movie == 0)
        return;

    do{
        printf("link2 \n");
        if(!strcmp(movie_link -> director, director_link -> name)){
            printf("link3 \n");
            movie_link -> direc = director_link;
            if(movie_link -> next != NULL)
                movie_link = movie_link -> next;
            else
                break;
        }
        else{
            if(movie_link -> next != NULL)
                movie_link = movie_link -> next;
            else
                break;
        }
    }
    while(1);
}
/*******************************************/
//                                         //
//                  end                    //
//                                         //
/*******************************************/
/*******************************************/
//                                         //
// movie, actor, director write            //
//                                         //
/*******************************************/

void save(char *mda, char *option, char *file){

    if(!strcmp(mda, "m")){
        printf("write_movie go\n");
        write_movie(option, file);
    }
    else if(!strcmp(mda, "d")){
        write_director(option, file);
    }
    else if(!strcmp(mda, "a")){
        write_actor(option, file);
    }
}

void write_movie(char *option, char *file_name){
    printf("write_movie in\n");
    FILE *m_write;
    movie *movie_w = POINT_MOVIE;

    if(file_name == NULL)
        m_write = fopen("movie_list.txt", "w");
    else
        m_write = fopen(file_name, "w");

    if(size_of_movie == 0)
        return;

    if(option == NULL){
        printf("open_NULL \n");
        do{
            fprintf(m_write, "%d:%s:%s:%s:%s:%s:%s\n", movie_w -> serial_num, movie_w -> title, movie_w -> genre, movie_w -> director, movie_w -> year, movie_w -> time, movie_w -> actors);
            if(movie_w -> next != NULL)
                movie_w = movie_w -> next;
            else
                break;
        }
        while(1);
    }

    else{
        do{
            fprintf(m_write, "%d", movie_w -> serial_num);
            for (int a = 0; a < strlen(option); a++)
                switch (*(option + a)) {
                    case 't':
                        fprintf(m_write, ":%s", movie_w -> title);
                        break;

                    case 'g':
                        fprintf(m_write, ":%s", movie_w -> genre);
                        break;

                    case 'd':
                        fprintf(m_write, ":%s", movie_w -> director);
                        break;

                    case 'y':
                        fprintf(m_write, ":%s", movie_w -> year);
                        break;

                    case 'r':
                        fprintf(m_write, ":%s", movie_w -> time);
                        break;

                    case 'a':
                        fprintf(m_write, ":%s", movie_w -> actors);
                        break;

                    default:
                        break;
                }

            fprintf(m_write, "\n");

            if(movie_w -> next != NULL)
                movie_w = movie_w -> next;
            else
                break;
        }
        while(1);
    }

    fclose(m_write);
}

void write_actor(char *option, char *file_name){
    FILE *a_write;
    actor *actor_w = POINT_ACTOR;

    if(file_name == NULL)
        a_write = fopen("actor_list.txt", "w");
    else
        a_write = fopen(file_name, "w");

    if(size_of_actor == 0)
        return;

    if(option == NULL){
        do{
            fprintf(a_write, "%d:%s:%s:%s:%s\n", actor_w -> serial_num, actor_w -> name, actor_w -> sex, actor_w -> birth, actor_w -> best_movie);
            if(actor_w -> next != NULL)
                actor_w = actor_w -> next;
            else
                break;
        }
        while(1);
    }

    else{
        do{
            fprintf(a_write, "%d", actor_w -> serial_num);
            for (int a = 0; a < strlen(option); a++)
                switch (*(option + a)) {
                    case 'n':
                        fprintf(a_write, ":%s", actor_w -> name);
                        break;

                    case 's':
                        fprintf(a_write, ":%s", actor_w -> sex);
                        break;

                    case 'b':
                        fprintf(a_write, ":%s", actor_w -> birth);
                        break;

                    case 'm':
                        fprintf(a_write, ":%s", actor_w -> best_movie);
                        break;

                    default:
                        break;
                }

            fprintf(a_write, "\n");

            if(actor_w -> next != NULL)
                actor_w = actor_w -> next;
            else
                break;
        }
        while(1);
    }
    fclose(a_write);
}

void write_director(char *option, char *file_name){
    FILE *d_write;
    director *director_w = POINT_DIRECTOR;

    if(file_name == NULL)
        d_write = fopen("director_list.txt", "w");
    else
        d_write = fopen(file_name, "w");

    if(size_of_director == 0)
        return;

    if(option == NULL){
        do{
            fprintf(d_write, "%d:%s:%s:%s:%s\n", director_w -> serial_num, director_w -> name, director_w -> sex, director_w -> birth, director_w -> best_movie);
            if(director_w -> next != NULL)
                director_w = director_w -> next;
            else
                break;
        }
        while(1);
    }

    else{
        do{
            fprintf(d_write, "%d", director_w -> serial_num);
            for (int a = 0; a < strlen(option); a++)
                switch (*(option + a)) {
                    case 'n':
                        fprintf(d_write, ":%s", director_w -> name);
                        break;

                    case 's':
                        fprintf(d_write, ":%s", director_w -> sex);
                        break;

                    case 'b':
                        fprintf(d_write, ":%s", director_w -> birth);
                        break;

                    case 'm':
                        fprintf(d_write, ":%s", director_w -> best_movie);
                        break;

                    default:
                        break;
                }

            fprintf(d_write, "\n");

            if(director_w -> next != NULL)
                director_w = director_w -> next;
            else
                break;
        }
        while(1);
    }

    fclose(d_write);
}
/*******************************************/
//                                         //
//                  end                    //
//                                         //
/*******************************************/
/*******************************************/
//                                         //
// movie, actor, director sort             //
//                                         //
/*******************************************/
int M_TitleSorting(const void *a, const void *b){
    return(strcmp((((movie*)a) -> title) , (((movie*)b) -> title)));
}
int M_GenreSorting(const void *a, const void *b){
    return(strcmp((((movie*)a) -> genre) , (((movie*)b) -> genre)));
}
int M_DirectorSorting(const void *a, const void *b){
    return(strcmp((((movie*)a) -> director) , (((movie*)b) -> director)));
}
int M_YearSorting(const void *a, const void *b){
    return(strcmp((((movie*)a) -> year) , (((movie*)b) -> year)));
}
int M_RunTimeSorting(const void *a, const void *b){
    return(strcmp((((movie*)a) -> time) , (((movie*)b) -> time)));
}
int M_ActorSorting(const void *a, const void *b){
    return(strcmp((((movie*)a) -> actors) , (((movie*)b) -> actors)));
}
int M_SerialSorting(const void *a, const void *b){
    return((((movie*)a) -> serial_num) - (((movie*)b) -> serial_num));
}

int A_NameSorting(const void *a, const void *b){
    return(strcmp((((actor*)a) -> name) , (((actor*)b) -> name)));
}
int A_SexSorting(const void *a, const void *b){
    return(strcmp((((actor*)a) -> sex) , (((actor*)b) -> sex)));
}
int A_BirthSorting(const void *a, const void *b){
    return(strcmp((((actor*)a) -> birth) , (((actor*)b) -> birth)));
}
int A_BestSorting(const void *a, const void *b){
    return(strcmp((((actor*)a) -> best_movie) , (((actor*)b) -> best_movie)));
}
int A_SerialSorting(const void *a, const void *b){
    return((((actor*)a) -> serial_num) - (((actor*)b) -> serial_num));
}

int D_NameSorting(const void *a, const void *b){
    return(strcmp((((director*)a) -> name) , (((director*)b) -> name)));
}
int D_SexSorting(const void *a, const void *b){
    return(strcmp((((director*)a) -> sex) , (((director*)b) -> sex)));
}
int D_BirthSorting(const void *a, const void *b){
    return(strcmp((((director*)a) -> birth) , (((director*)b) -> birth)));
}
int D_BestSorting(const void *a, const void *b){
    return(strcmp((((director*)a) -> best_movie) , (((director*)b) -> best_movie)));
}
int D_SerialSorting(const void *a, const void *b){
    return((((director*)a) -> serial_num) - (((director*)b) -> serial_num));
}

void sort(char *mda, char *option, char *file){

    if(!strcmp(mda, "m")){
        printf("sort_movie go\n");
        sort_movie(option, file);
    }
    else if(!strcmp(mda, "d")){
        sort_director(option, file);
    }
    else if(!strcmp(mda, "a")){
        sort_actor(option, file);
    }
}

void sort_movie(char *option, char *file_name){
    printf("sort_movie in\n");
    FILE *m_write;
    movie *movie_w = POINT_MOVIE;

    if(file_name == NULL)
        m_write = fopen("movie_list.txt", "w");
    else
        m_write = fopen(file_name, "w");

    if(size_of_movie == 0)
        return;

    printf("%d\n", size_of_movie);

    if(option == NULL){
        qsort((void *)POINT_MOVIE, size_of_movie - 4, sizeof(movie*), M_TitleSorting);
    }
    else{
        switch (*option) {
            case 't':
//                char **str = (char **)malloc(sizeof(char *) * size_of_movie);
                qsort((void *)POINT_MOVIE, size_of_movie + 1, sizeof(movie*), M_TitleSorting);
                break;

            case 'g':
                qsort((void *)POINT_MOVIE, sizeof(POINT_MOVIE)/ sizeof(movie*), sizeof(movie*), M_GenreSorting);
                break;

            case 'd':
                qsort((void *)POINT_MOVIE, sizeof(POINT_MOVIE)/ sizeof(movie*), sizeof(movie*), M_DirectorSorting);
                break;

            case 'y':
                qsort((void *)POINT_MOVIE, sizeof(POINT_MOVIE)/ sizeof(movie*), sizeof(movie*), M_YearSorting);
                break;

            case 'r':
                qsort((void *)POINT_MOVIE, sizeof(POINT_MOVIE)/ sizeof(movie*), sizeof(movie*), M_RunTimeSorting);
                break;

            case 'a':
                qsort((void *)POINT_MOVIE, sizeof(POINT_MOVIE)/ sizeof(movie*), sizeof(movie*), M_ActorSorting);
                break;

            default:
                break;
        }
    }

    do{
        fprintf(m_write, "%d:%s:%s:%s:%s:%s:%s\n", movie_w -> serial_num, movie_w -> title, movie_w -> genre, movie_w -> director, movie_w -> year, movie_w -> time, movie_w -> actors);
        if(movie_w -> next != NULL)
            movie_w = movie_w -> next;
        else
            break;
    }
    while(1);

    qsort((void *)POINT_MOVIE, sizeof(POINT_MOVIE)/ sizeof(movie*), sizeof(movie*), M_SerialSorting);

    fclose(m_write);
}

void sort_actor(char *option, char *file_name){
    FILE *a_write;
    actor *actor_w = POINT_ACTOR;

    if(file_name == NULL)
        a_write = fopen("actor_list.txt", "w");
    else
        a_write = fopen(file_name, "w");

    if(size_of_actor == 0)
        return;

    if(option == NULL){
        do{
            fprintf(a_write, "%d:%s:%s:%s:%s\n", actor_w -> serial_num, actor_w -> name, actor_w -> sex, actor_w -> birth, actor_w -> best_movie);
            if(actor_w -> next != NULL)
                actor_w = actor_w -> next;
            else
                break;
        }
        while(1);
    }

    else{
        do{
            fprintf(a_write, "%d", actor_w -> serial_num);
            for (int a = 0; a < strlen(option); a++)
                switch (*(option + a)) {
                    case 'n':
                        fprintf(a_write, ":%s", actor_w -> name);
                        break;

                    case 's':
                        fprintf(a_write, ":%s", actor_w -> sex);
                        break;

                    case 'b':
                        fprintf(a_write, ":%s", actor_w -> birth);
                        break;

                    case 'm':
                        fprintf(a_write, ":%s", actor_w -> best_movie);
                        break;

                    default:
                        break;
                }

            fprintf(a_write, "\n");

            if(actor_w -> next != NULL)
                actor_w = actor_w -> next;
            else
                break;
        }
        while(1);
    }
    fclose(a_write);
}

void sort_director(char *option, char *file_name){
    FILE *d_write;
    director *director_w = POINT_DIRECTOR;

    if(file_name == NULL)
        d_write = fopen("director_list.txt", "w");
    else
        d_write = fopen(file_name, "w");

    if(size_of_director == 0)
        return;

    if(option == NULL){
        do{
            fprintf(d_write, "%d:%s:%s:%s:%s\n", director_w -> serial_num, director_w -> name, director_w -> sex, director_w -> birth, director_w -> best_movie);
            if(director_w -> next != NULL)
                director_w = director_w -> next;
            else
                break;
        }
        while(1);
    }

    else{
        do{
            fprintf(d_write, "%d", director_w -> serial_num);
            for (int a = 0; a < strlen(option); a++)
                switch (*(option + a)) {
                    case 'n':
                        fprintf(d_write, ":%s", director_w -> name);
                        break;

                    case 's':
                        fprintf(d_write, ":%s", director_w -> sex);
                        break;

                    case 'b':
                        fprintf(d_write, ":%s", director_w -> birth);
                        break;

                    case 'm':
                        fprintf(d_write, ":%s", director_w -> best_movie);
                        break;

                    default:
                        break;
                }

            fprintf(d_write, "\n");

            if(director_w -> next != NULL)
                director_w = director_w -> next;
            else
                break;
        }
        while(1);
    }

    fclose(d_write);
}
/*******************************************/
//                                         //
//                  end                    //
//                                         //
/*******************************************/
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
        print(*(tok + 1), *(tok + 2));
    }
    else if (!strcmp(*tok, "add"))
    {
        add(*(tok + 1));
    }
    else if (!strcmp(*tok, "update"))
    {
        update(*(tok + 1), *(tok + 2), *(tok + 3));

        if (num_tok == 2){
            update(*(tok + 1), NULL, *(tok + 2));
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
                file = (char *)malloc(sizeof(char) * strlen(*(tok + a) - 1));
                file = *(tok + a + 1);
                *(tok + a) = NULL;
                break;
            }
            else
                file = NULL;
        }
        sort(*(tok + 1), *(tok + 2), file);
        printf("m|d|a = %s\n", *(tok + 1));
        printf("option = %s\n", *(tok + 2));
        printf("file = %s\n", file);
    }
    else if (!strcmp(*tok, "save"))
    {
        char *file;
        for (int a = 0; a < num_tok + 1; a++){
            if(*(*(tok + a) + 1) == 'f'){
                file = (char *)malloc(sizeof(char) * strlen(*(tok + a) - 1));
                file = *(tok + a + 1);
                *(tok + a) = NULL;
                break;
            }
            else
                file = NULL;
        }
        save(*(tok + 1), *(tok + 2), file);
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

    POINT_MOVIE = m_point;
    POINT_DIRECTOR = d_point;
    POINT_ACTOR = a_point;


    printf("loading in\n");
    read_movie_log();
    printf("loading out\n");

    while(1)
        put_command();

	printf("\n");
	return 0;
}
