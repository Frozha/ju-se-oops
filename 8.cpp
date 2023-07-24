#include<iostream>
using namespace std;

//this is call by address not refrence
//redo this with refrence
void swap(int *a,int *b){
	cout<<"\nSwapping by address\n";
	int c = *a;
	*a = *b;
	*b=c;
}

void swap(int &a,int &b){
	cout<<"\nSwapping by reference\n";
	int c = a;
	a = b;
	b =c;
}

int main(){
	int a = 10;
	int b = 21;
	cout<<"a = "<<a<<" b = "<<b;
	swap(a,b);
	cout<<"a = "<<a<<" b = "<<b<<endl;
	return 0;

}


