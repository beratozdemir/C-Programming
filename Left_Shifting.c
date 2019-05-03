#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int x,y,a1;
char r;
int left_shift(){		
do{
	printf("\n\n [1] LEFT SHIFTING OPERATIONS \n\n");
	printf("Enter a number to Left Shifting \n(It's mean divide by 2's powers for each shift): ");
	scanf("%d",&x);
		while(x<0){ 
			printf("Error! Please, Enter a number to Left Shifting again \n(It's mean divide by 2's powers for each shift): ");
    		scanf("%d",&x);
			}	
	printf("\n\n Enter the Shifting Amount:");
	scanf("%d", &a1);
				while(a1<0){ 
				printf("Error! Please, Enter the shifting amount again: ");
    			scanf("%d",&a1);
				}	
	printf("\n\n    RESULT:  %d \n\n", y = x << a1);
}while(x>0);
return 0;    		
				}
int main(){
	left_shift();	
return 0;
}
