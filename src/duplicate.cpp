#include<iostream>

#define MLEN 16

int main() {
	const int MAXLEN = MLEN;

	int numbers[MAXLEN];
	
	for (int i=0; i<MAXLEN; ++i) {
		numbers[i] = 0;
	}
	
	std::cout<<"[ ";
	
	for (int i=0; i<MAXLEN; ++i) {
		std::cout<<numbers[i]<<" ,";
	}
	
	std::cout<<" ]";
	
	std::cout<<'\n';
	
	return 0;
}
