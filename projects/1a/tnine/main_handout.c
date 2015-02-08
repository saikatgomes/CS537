#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "p1a2.h"

/* This is an array of 10 POINTERS to KeyboardElements
*/

KEPtr keypad[10];
char * letters[10] = { "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ", "" };


void PrintFunction(char c);

int main(int argc, char * argv[])
{
	if (argc <= 1)
	{
		printf("Usage: tnine string1 [stringN]\n");
		exit(1);
	}
    
    int n;
    int isError = 0;
    int offSet;
    for (n=1;n<argc;n++){
        //printf("%d) --- %s\n",n,argv[n]);
        char * c = argv[n];
        offSet=0;
        while(*(c+offSet)!='\0'){
            if(*(c+offSet+1)=='\0'){
                //expecting a second digit here!
                printf("-x1");
                break;
            }
            
            char a1 = *(c+offSet);
            if(isdigit(a1)==0){
                //first entry should be a digit
                printf("-x2");
                break;
            }

            char a2 = *(c+offSet+1);
            if(isdigit(a2)==0){
                //second entry should be a digit
                printf("-x3");
                break;
            }

            //printf(" * %c - %c \n",a1,a2);
            int k1 = a1-'0';
            int k2 = a2-'0';
           
            if(k1<=1||k2<=0||k2>4||(k1!=7 && k1!=9 && k2>3)){
                //illegal KeyboardElements
                printf("-x3");
                break;
            }
            char alpha = *(*(letters+k1-1)+k2-1);

            //printf("%d%d(%s-%c)",k1,k2,*(letters+k1-1),*(*(letters+k1-1)+k2-1));
            //printf("%d%d(%c)",k1,k2,*(*(letters+k1-1)+k2-1));
            //printf("%c",*(*(letters+k1-1)+k2-1));
            //PrintFunction(*(*(letters+k1-1)+k2-1));
            PrintWrapper(PrintFunction,*(*(letters+k1-1)+k2-1));
            //printf("   1->%c 2->%c\n",*(c+offSet),*(c+offSet+1));
            //printf("   1->%d 2->%d\n",k1,k2);
            offSet=offSet+2;
        }
        //printf("\n");
        PrintWrapper(PrintFunction,'\n');
    }
	// YOUR CODE HERE

	return 0;
}

void PrintFunction(char c)
{
	printf("%c", c);
}
