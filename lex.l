%{
#include <stdio.h>
%}

%%

(?i:"CREATE") 			printf("keyword CREATE\n");
(?i:"TABLE")			printf("keyword TABLE\n");
(?i:"SELECT")			printf("keyword SELECT\n");
(?i:"INSERT")			printf("keyword INSERT\n");
(?i:"INTO")				printf("keyword INTO\n");
(?i:"VALUES")			printf("keyword VALUES\n");
(?i:"UPDATE")			printf("keyword UPDATE\n");
(?i:"SET")				printf("keyword SET\n");
(?i:"FROM")				printf("keyword FROM\n");
(?i:"DELETE")			printf("keyword DELETE\n");
(?i:"WHERE")			printf("keyword WHERE\n");
(?i:"DROP")				printf("keyword DROP\n");
(?i:"ALTER")			printf("keyword ALTER\n");
(?i:"COLUMN")			printf("keyword COLUMN\n");
(?i:"ADD")				printf("keyword ADD\n");

(?i:"FOREIGN")			printf("keyword FOREIGN\n");
(?i:"PRIMARY")		    printf("keyword PRIMARY\n");
(?i:"KEY")				printf("keyword KEY\n");
(?i:"UNIQUE")			printf("keyword UNIQUE\n");
(?i:"DEFAULT")		    printf("keyword DEFAULT\n");
(?i:"CHECK")			printf("keyword CHECK\n");
(?i:"GROUP")			printf("keyword GROUP\n");
(?i:"BY")				printf("keyword BY\n");
(?i:"ORDER")			printf("keyword ORDER\n");
(?i:"HAVING")			printf("keyword HAVING\n");
(?i:"NULL")				printf("keyword NULL\n");
(?i:"NOT")				printf("keyword NOT\n");
(?i:"CHAR")				printf("keyword CHAR\n");
(?i:"VARCHAR")			printf("keyword VARCHAR\n");
(?i:"INT")		    	printf("keyword INT\n");
(?i:"AND")				printf("keyword AND\n");
(?i:"LIKE")				printf("keyword LIKE\n");
(?i:"COUNT")			printf("keyword COUNT\n");
(?i:"MIN")				printf("keyword MIN\n");
(?i:"MAX")				printf("keyword MAX\n");
(?i:"SUM")				printf("keyword SUM\n");
(?i:"AVG")				printf("keyword AVG\n");
(?i:"ANY")		    	printf("keyword ANY\n");
(?i:"ALL")		    	printf("keyword ALL\n");
(?i:"AS")		    	printf("keyword AS\n");


[_a-zA-Z][_a-zA-Z0-9]*	printf("identifier\n");

[-][1-9][0-9]*	|
[-][1-9][0-9]*[.][0-9]* |
[-][.][0-9][0-9]*	|
[0] 	|	
[-][0][.][0-9]*  |

[1-9][0-9]*	|
[1-9][0-9]*[.][0-9]* |
[.][0-9][0-9]*	|
[0][.][0-9]*   printf("value\n");

"("				printf("left paranthesis\n");
")"				printf("right paranthesis\n");
"{"				printf("left brace\n");
"}"				printf("right brace\n");
"["				printf("left bracket\n");
"]"				printf("right bracket\n");

"<>"		|
"!="	        printf("not equal\n");
"<="			printf("lesser than or equal to\n");
">="			printf("greater than or equal to\n");
"<"				printf("lesser than\n");
">" 			printf("greater than\n");
"="				printf("equal\n");

"+"             printf("addition operator\n");
"-"             printf("subtraction operator\n");
"*"             printf("multiplication operator\n");
"/"             printf("division operator\n");

","             printf("comma operator\n");
"."             printf("dot operator\n");
"&"             printf("ampersand operator\n");
"%"             printf("percent operator\n");
"?"			    printf("question\n");
"|"			    printf("vertical bar\n");
"^"			    printf("circumflex\n");


":"			    printf("colon\n");
";"			    printf("semicolon\n");
"'"             printf("single quote\n");
[\""]           printf("double quote\n");


[ \t\n]			;

.				printf("unexpected character\n");

%%

int yywrap(void)
{
	return 1;
}