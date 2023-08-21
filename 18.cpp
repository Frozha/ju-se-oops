#include<iostream>
#include<cmath>
using namespace std;
class point{
    private:
        double x ;
        double y ;
        double z ; 
    public:
        point(double a = 0,double b = 0, double c =0):x(a),y(b),z(c){}
        double distance(point origin = point()){
            double dist = sqrt(pow(x-origin.x,2)+pow(y-origin.y,2)+pow(z-origin.z,2));
            return dist;
        }
};

int main(){
    double x,y,z;

    cout<<"Enter coordinates of first point : \nx = ";
    cin>>x;
    cout<<"y = ";
    cin>>y;
    cout<<"z = ";
    cin>>z;
    point point1(x,y,z);
    
    cout<<"Enter coordinates of second point : \nx = ";
    cin>>x;
    cout<<"y = ";
    cin>>y;
    cout<<"z = ";
    cin>>z;
    point point2(x,y,z);

    cout<<"distance between :-\n";
    cout<<"point 1 and origin : "<<point1.distance();
    cout<<"\npoint 1 and point 2 : "<<point1.distance(point2);

}
