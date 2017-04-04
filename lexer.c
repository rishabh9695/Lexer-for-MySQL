#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int selector(char *a){
	char* keywords[]={"CREATE","TABLE","SELECT","INSERT","INTO","VALUES","UPDATE","SET","FROM","DELETE","WHERE","DROP","ALTER","COLUMN","ADD","FOREIGN","PRIMARY","KEY","UNIQUE","DEFAULT","CHECK","GROUP","BY","ORDER","HAVING","NOT","NULL","CHAR","VARCHAR","INT","AND","LIKE","COUNT","MIN","MAX","SUM","AVG","ANY","ALL","AS"};
	char *o[]={"=","<>","<=",">=","<",">","*","-","+","!=","/"};
	char *s[]={",","%","&",".","(",")"};
	int i,c=0;
	for(i=0;i<40;i++)
	{	
		if(strcasecmp(a,keywords[i])==0)
		{	
			return 1;
		}
	}
	for(i=0;i<11;i++)
	{	
		if(strcasecmp(a,o[i])==0)
		{	
			return 2;
		}
	}
	for(i=0;i<6;i++)
	{	
		if(strcasecmp(a,s[i])==0)
		{	
			return 3;
		}
	
	}
//num
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]!=46 && (a[i]<48 || a[i]>57))
		break;
		else if(a[i]==46)
		c++;
	}
	if(c>1);
	else if(i==strlen(a))
		return 4;
//alpha
	if(a[0]<65 || (a[0]>90 && a[0]<97) || a[0]>122)
		return 0;
	for(i=1;i<strlen(a);i++){
		if((a[i]>=65 && a[i]<=90) || (a[i]>=97 && a[i]<=122) || (a[i]>=48 && a[i]<=57) || a[i]==95)
			;
		else
			return 0;
	}
	return 5;
}


void main()
{
char S[200],Str[200],T[20],*token,dlm[2]=" ";
char M[50][15];
int i,j,k;
char temp,buffer;

S[0] = '\0';
Str[0] = '\0';

top:
//old code start
while(1)
{
	scanf("%s",T);
	//getchar();
	strcat(S," ");
	strcat(S,T);
	
	if(T[strlen(T)-1]==';')
	{
		break;	
	}

	if(strcmp(T,";")==0)
	{
		break;
	}
	if(strcmp(T,"exit")==0)
	{
		exit(0);
	}
}

//added padding
for(i=0,j=0;S[i]!='\0';i++,j++)
{
	if(
	(S[i]=='<')&&(S[i+1]=='=')||
	(S[i]=='>')&&(S[i+1]=='=')||
	(S[i]=='<')&&(S[i+1]=='>')||
	(S[i]=='!')&&(S[i+1]=='=')
	)
	{	
		Str[j]=' ';
		Str[j+1]=S[i];
		Str[j+2]=S[i+1];
		Str[j+3]=' ';
		j+=3;
		i++;
	}
	else if(
		(S[i]=='=')||
		(S[i]=='>')||
		(S[i]=='<')||
		(S[i]=='!')||
		(S[i]==';')||
		(S[i]=='(')||
		(S[i]==')')||
		(S[i]==',')		
		)
	{
		Str[j]=' ';
		Str[j+1]=S[i];
		Str[j+2]=' ';
		j+=2;
			
	}
	else
	{
		Str[j]=S[i];	
	}
}
Str[j]='\0';


//finished padding
//printf("\nWe entered:%s\n",Str);

token = strtok(Str,dlm);
strcpy(M[0],token);
//printf("%s\n",M[0]);

i=1;
while( token != NULL ) 
{
	//printf( "%d : %s\n",i, token );
    
	token = strtok(NULL,dlm);
	//if(strcmp(token,NULL)==0)
	if(token==NULL)
	break;
	strcpy(M[i],token);
	i++;
	//printf(" %d ",i);
}

//printf("Stored in Matrix\n");
strcpy(M[i],"\0");

//debug tokeniser
/*
for(i=0;strcmp(M[i],"\0")!=0;i++)
{
	printf("At position %d : %s\n",i,M[i]);
}
*/

printf("........................................\n");
printf("|| TOKEN ....................... TYPE ||\n");
printf("........................................\n");

for(i=0;strcmp(M[i],"\0")!=0;i++)
{
	k = selector(M[i]);
	//printf("At position %d we have %d type token : %s\n",i,k,M[i]);
	if(k==1)
	printf(" %s ......................... KEYWORD\n",M[i]);
	else if(k==2)
	printf(" %s ......................... OPERATOR\n",M[i]);
	else if(k==3)
	printf(" %s ......................... SPECIAL SYMBOL\n",M[i]);
	else if(k==4)
	printf(" %s ......................... VALUE\n",M[i]);
	else if(k==5)
	printf(" %s ......................... IDENTIFIER\n",M[i]);
	else
	printf(" %s ......................... OTHER\n",M[i]);
}

goto top;
//old code ends
}