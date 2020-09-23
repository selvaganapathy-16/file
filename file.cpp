#include<stdio.h>
#include<stdlib.h>
int main()
{
	char sname[]="x.txt";
	char tname[]="y.txt";
	char c;
	
	FILE *sf,*tf;
	sf =fopen(sname,"w");
	if(sf==NULL)
	{
		printf("press any key to exit");
		exit(EXIT_FAILURE);
	}
	fprintf(sf,"MY Captain");
	int length=ftell(sf);
	printf("%d",length);
	fclose(sf);
	sf =fopen(sname,"r");
	if(sf==NULL)
	{
		printf("press any key to exit");
		exit(EXIT_FAILURE);
	}
     tf =fopen(tname,"w");
	if(tf==NULL)
	{
		printf("press any key to exit");
		exit(EXIT_FAILURE);
	}

	for(int position=length;position>=0;position--)
	{
		fseek(sf,position,SEEK_SET);
		fputc(fgetc(sf),tf);
	}
	
	printf("file copied succesfully");
	fclose(sf);
	fclose(tf);
}

