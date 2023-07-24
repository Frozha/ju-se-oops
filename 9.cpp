#include<iostream>
using namespace std;
#define size_a 20
#define size_b 20

void str_swap_addrs(char (*a),char (*b)){
	char temp[size_a];
	cout<<"\nswap by address.\n";
	for(int i=0;(i<size_a);i++){
		temp[i] = *(a+i);
		*(a+i) = *(b+i);
		*(b+i) = temp[i];
	}

}
//this needs fixing for some reason
void str_swap_ref(char &a, char &b){
	char temp[size_a];
	cout<<"\nswap by refrence.\n";
        for(int i=0;(i<size_a);i++){
                temp[i] = (a[i]);
                (a[i]) = (b[i]);
                (b[i]) = temp[i];
        }
	
}

int main(){
	char a[size_a]="hello world";
	char b[size_b]="goodbye world";
	cout<<"a = "<<a<<" b = "<<b;
 	str_swap_addrs(&a,&b);
        cout<<"a = "<<a<<" b = "<<b;
	str_swap_ref(a[0],b[0]);
	cout<<"a = "<<a<<" b = "<<b;
	return 0;
}

