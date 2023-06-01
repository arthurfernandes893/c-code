#include <stdio.h>
float conversor (int);

int main(){
	int temp_celsius;
	for (temp_celsius=-10;temp_celsius<=50;temp_celsius+=10){
		conversor(temp_celsius);
		printf("%f\2t",conversor);		
	}

}

float conversor(int celsius){
	return (celsius*(9.0/5))+32;
}	
