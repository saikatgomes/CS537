#include <stdio.h>
#include <stdlib.h>

void buildTable(int * t, int d);
void printTable(int * t, int d);

int main(int argc, char *argv[]) {
    //default size of the table is 10
    int D =10;
    int * table;
    
    if (argc >= 2) {
        // user speified table size
        D=atoi(argv[1]);
        if (D>10 || D<1) {
            //bound the table size
            D=10;
        }
    }
    
    table = (int*) malloc(D*D);
    if(table == NULL){
        printf("Memory could not be allocated!");
        exit(1);
    }

    buildTable(table,D);
    printTable(table,D);

    //free (table); 
    return(0);
}

void buildTable(int * t, int d){
    int r,c;
    for(r=0;r<d;r++){
        for(c=0;c<d;c++){
            //t[r*d+c] = (r+1)*(c+1);
            *(t + r*d + c) = (r+1)*(c+1);
        }
    }
}

void printTable(int * t, int d){
    int r,c;
    for(r=0;r<d;r++){
        for(c=0;c<d;c++){
            //printf("%d\t",t[r*d+c]);
            printf("%d\t",*(t+r*d+c));
        }
        printf("\n");
    }
}




