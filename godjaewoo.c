#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void add_movie(char *t, char *g, char *d, char *y, char *r, char *a){
	printf("start add_movie\n");
	printf("%s\n", t);
	printf("%s\n", g);
	printf("%s\n", d);
	printf("%s\n", y);
	printf("%s\n", r);
	printf("%s\n", a);
}

int main(void)
{
	FILE *m_log, *m_list;
	char *line, *tok, *tag, *title, *genre, *director, *year, *running, *actor;
	int check, serial;

	line = (char *)malloc(sizeof(char) * 200);
	tok = (char *)malloc(sizeof(char) * 100);
	m_log = fopen("movie_log", "r");
	m_list = fopen("movie_list", "w");

	while(fgets(line, 200, m_log) != NULL)
	{
		tok = strtok(line, ":");
		tag = (char *)malloc(sizeof(char) * (strlen(tok) + 1));
		strcpy(tag, tok);

		tok = strtok(NULL, ":");
		serial = atoi(tok);
		
		tok = strtok(NULL, ":");
		title = (char *)malloc(sizeof(char) * (strlen(tok) + 1));
		strcpy(title, tok);
		
		tok = strtok(NULL, ":");
		genre = (char *)malloc(sizeof(char) * (strlen(tok) + 1));
		strcpy(genre, tok);
		
		tok = strtok(NULL, ":");
		director = (char *)malloc(sizeof(char) * (strlen(tok) + 1));
		strcpy(director, tok);
		
		tok = strtok(NULL, ":");
		year = (char *)malloc(sizeof(char) * (strlen(tok) + 1));
		strcpy(year, tok);
		
		tok = strtok(NULL, ":");
		running = (char *)malloc(sizeof(char) * (strlen(tok) + 1));
		strcpy(running, tok);
		
		tok = strtok(NULL, ":");
		actor = (char *)malloc(sizeof(char) * (strlen(tok) + 1));
		strcpy(actor, tok);
		add_movie(title, genre, director, year, running, actor);

		/*switch(tag)
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
		}*/
	}
	return 0;
}
