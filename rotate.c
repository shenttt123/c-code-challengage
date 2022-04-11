//https://www.linkedin.com/learning/c-code-challenges/rotating-a-matrix
#include <stdio.h>

struct matrix{
char a[10][10];
};
int main(){

srand( (unsigned)time(NULL) );

populatematrix(3,8,1);
populatematrix(5,5,2);
populatematrix(6,4,3);

return(0);
}

void populatematrix(int row, int col, int count){

int x,y;
struct matrix mar;
struct matrix temp;
    
printf("Original Matrix: %d\n", count);
for (x=0;x<row;x++){//generate matrix
    for (y=0;y<col;y++){
            mar.a[x][y]=rand()%26+ 'a';
            temp.a[x][y]=mar.a[x][y];//copy into temp
            printf("%c ",mar.a[x][y]);
        } printf("\n");
}
    
printf("Rotated Matrix: %d\n", count);
for (x=0;x<col;x++){//rotate
    for (y=0;y<row;y++){
        mar.a[x][y]=temp.a[row-y-1][x];
        printf("%c ",mar.a[x][y]);
    }printf("\n");
}
}
