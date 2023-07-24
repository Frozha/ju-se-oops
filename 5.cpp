#include<iostream>
using namespace std;


int main(){
	float celcius,farenh;
	for(celcius =0;celcius<=100;celcius++){
		farenh = (9*celcius/5)+32;
		cout<<celcius<<"C = "<<farenh<<"F\n";
	}		
	return 0;
}
