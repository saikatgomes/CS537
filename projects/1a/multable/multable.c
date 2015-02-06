#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int D =10;
    int * table;
    if (argc >= 2) {
        D=atoi(argv[1]);
    }
    printf("D = %d \n",D);
    
    table = (int*) malloc(D*D);
    if(table == NULL){
        printf("Memory could not be allocated!");
        exit(1);
    }

    int r,c;
    for(r=0; r< D; r++){
        for (c=0; c<D; c++){
            table[r*D+c] = (r+1)*(c+1);
        }
    }

    for (r=0;r<D;r++){
        for (c=0; c<D; c++){
            printf("%d\t",table[r*D+c]);
        }
        printf("\n");
    }
    //free (table); 
    return(0);
}

