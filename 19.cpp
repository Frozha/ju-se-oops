#include<iostream>
using namespace std;

class rectangle{
    public:
        rectangle(double l=0, double b=0):length(l),breadth(b){}
        double area(){
            return length*breadth;
        }
    private:
        double length;
        double breadth;
};

int main(){
    rectangle r1(1,2);
    rectangle r2(2,3);
    rectangle r3(3,4);
    rectangle r4(4,5);
    cout<<"area of rectangle 1 : "<<r1.area();
    cout<<"\narea of rectangle 2 : "<<r2.area();     
    cout<<"\narea of rectangle 3 : "<<r3.area();
    cout<<"\narea of rectangle 4 : "<<r4.area();

}
