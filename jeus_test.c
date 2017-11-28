#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	FILE *m_log, *m_list;
	char *read, *tok, tag;
	int check;

	m_log = fopen("movie_log", "r");
	m_list = fopen("movie_list", "w");

	while(check != EOF)
	{
		check = fscanf(m_log, "%[^\n]", read);
		printf("%s\n",read);

		tok = strtok(read, ":");
		printf("%s\n",tok);

		tag = *tok;
		switch(tag)
		{
			case 'a':
				while(tok = strtok(NULL,":"))
				{
					printf("%s\n",tok);
					fprintf(m_list,"%s:",tok);
				}
				break;
			case 'u':
				while(tok = strtok(NULL,":"))
				{

				}
				break;
			case 'd':
				break;
			default:
				break;
		}
		break;
	}
	return 0;
}
