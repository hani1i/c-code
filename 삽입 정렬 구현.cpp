#include <stdio.h>
int main(){
	char a[20];
	int i, j, temp;
	
	scanf("%s", &a);
	
	for(i = 0; i < 20; i++) {
		j = i - 1;
		while((j>=0 && j+1<20 && a[j] > a[j + 1])){
			temp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = temp;
			j--;
		}
	}
	for(i = 0; i < 20; i++){
		printf("%c", a[i]);
	}
}
