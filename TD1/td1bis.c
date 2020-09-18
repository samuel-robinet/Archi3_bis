#include <stdio.h>
int main(int argc,){
	int ch=getchar();
	while(ch!=EOF){ // EOF = fin 
		if(ch=='z'){
			ch='a';
		}else{
			if(ch=='Z'){
				ch=='A';
			}else{ ch++;}
		}
		putchar(ch);
		ch=getchar();
	}
	printf("\n");
}