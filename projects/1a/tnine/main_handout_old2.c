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
   
    int q;
    for(q=0;q<10;q++){
        //int i = (q-1) % 10;
        int i = q-1;
        if(q==0){
            i=9;
        }
        keypad[q]= malloc(sizeof(struct KeyboardElement));
        keypad[q]->counter=0;
        keypad[q]->letters = *(letters+i);
        printf("keypad[%d] = letters[%d]\n",q,i);
    }

    q=0;
    for(q=0;q<10;q++){
        printf("%d - [%d] - %s\n",q,keypad[q]->counter,keypad[q]->letters);
    }

    int n;
    int offSet;
    for (n=1;n<argc;n++){
        char * c = argv[n];
        offSet=0;
        while(*(c+offSet)!='\0'){
            if(*(c+offSet+1)=='\0'){
                //expecting a second digit here!
                printf("-");
                break;
            }
            
            char a1 = *(c+offSet);
            if(isdigit(a1)==0){
                //first entry should be a digit
                printf("-");
                break;
            }

            char a2 = *(c+offSet+1);
            if(isdigit(a2)==0){
                //second entry should be a digit
                printf("-");
                break;
            }

            int k1 = a1-'0';
            int k2 = a2-'0';
            if(k1<=1||k2<=0||k2>4||(k1!=7 && k1!=9 && k2>3)){
                //illegal KeyboardElements
                printf("-");
                break;
            }
            
            char alpha = *(*(letters+k1-1)+k2-1);
            PrintWrapper(PrintFunction,*(*(letters+k1-1)+k2-1));
            offSet=offSet+2;
        }
        PrintWrapper(PrintFunction,'\n');
    }
	// YOUR CODE HERE

	return 0;
}

void PrintFunction(char c)
{
	printf("%c", c);
}
