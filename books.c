#include <stdio.h>
#include <string.h>
#define MAXTITLE 40
#define MAXAUTHOR 40
#define MAXBOOKS 100
char *s_gets(char *st,int n);

struct book{
	char title[MAXTITLE];
	char author[MAXAUTHOR];
	float value;
}library[MAXBOOKS];

int main(void)
{
	
	int count=0;
	int index;

	printf("Please enter the book title.\n");
	printf("Press [ENTER] at the start of the line to stop.\n");

	while(count<MAXBOOKS && s_gets(library[count].title,MAXTITLE)!=NULL
		&& library[count].title[0]!='\0')
	{
		printf("\nEnter the author.\n");
		s_gets(library[count].author,MAXAUTHOR);
		printf("\nEnter the value.\n");
		scanf("%f",&library[count++].value);

		while(getchar()!='\n')
			continue;

		if(count<MAXBOOKS)
			printf("\nEnter the next title.\n");
	}
	if(count>0)
	{
		printf("List of books:\n");
		for(index=0;index<count;index++)
		{
			printf("%s by %s: $%.2f\n",library[index].title,
				library[index].author,library[index].value);
		}
	}
	else
		printf("No books were found!\n");


	return 0;
}
char *s_gets(char *st,int n)
{
	char *ret_val;
	char *find;
	ret_val=fgets(st,n,stdin);

	if(ret_val)
	{
		find=strchr(st,'\n');
		if(find)
			*find='\0';
		else
			while(getchar()!='\n')
				continue;
	}
	return ret_val;
}