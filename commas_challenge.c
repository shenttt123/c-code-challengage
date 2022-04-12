#include <stdio.h>

void comma(int num){
    int length,i;
    char str[10];
    length = log10(num)+1;//integer length
    for(i=0;i<length;i++){//store integer character into char array backwards
        str[i]=num%10+'0';
        num=num/10;
    }

    for(i=length;i>0;i--){//printout array and comma
        printf("%c",str[i-1]);
        if((i-1)%3==0 && i!=1){//add comma every three char expect the last one
            printf(",");
        }
    }
printf("\n");

}

int main()
{
    int i;
	int values[10] = {
		123, 1899, 48266, 123456, 9876543,
		10100100, 5, 500000, 99000111, 83
	};
	for (i=0;i<10;i++){


       comma(values[i]);

	}


	return(0);
}

