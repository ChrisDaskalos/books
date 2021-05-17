#include <stdio.h>
#include <string.h>
#define MAXTITLE 40				//maximum capacity of chars within the title
#define MAXAUTHOR 40				//maximum capacity of chars within the author
#define MAXBOOKS 100				//capacity for 100 books 
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

	while(count<MAXBOOKS && s_gets(library[count].title,MAXTITLE)!=NULL	//s_gets checks if input attemps to read past EOF 
		&& library[count].title[0]!='\0')	//s_gets checks whether the 1st char is null and terminates if true.
	{
		printf("\nEnter the author.\n");
		s_gets(library[count].author,MAXAUTHOR);
		printf("\nEnter the value.\n");
		scanf("%f",&library[count++].value);

		while(getchar()!='\n')	//clear input line for scanf() 
			continue;	//this code compensates for the scanf() function ignoring spaces and newlines

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
		find=strchr(st,'\n');	//look for newline , if address not NULL place '\0'
		if(find)
			*find='\0';
		else
			while(getchar()!='\n')	//dispose bad input
				continue;
	}
	return ret_val;
}
