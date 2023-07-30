#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<random>
using namespace std;


class point{
    private:
    public:
        double x = 0;
        double y = 0;
        double z = 0; 
        point(double a = 0,double b = 0, double c =0):x{a},y{b},z{c}{}
        double distance(point origin = point()){
            double dist = sqrt(pow(x-origin.x,2)+pow(y-origin.y,2)+pow(z-origin.z,2));
            return dist;
        }
};

class wlan{
    private:
        string uuid;
        double range;
    public:
        point coordinate;
        wlan(point a, string id, double r):coordinate{a},uuid{id},range{r}{}
        
        bool inrange(wlan neighbor){
            double distance = coordinate.distance(neighbor.coordinate);
            if(distance<=range&&distance<=neighbor.range){
                return true;
            }
            return false;
        }

        void info(){
            cout<<endl<<uuid<<" at ("<<coordinate.x<<","<<coordinate.y<<","<<coordinate.z<<")"<<" with range : "<<range;
        }


};

vector<wlan> devices;

struct inrange{
    int home_index;
    int neighbor_index;
};

vector<inrange> inrange_v;

int main(){
    string id = "tp-1000";
    double r;
    int x,y,z=0;
    uniform_real_distribution<double> range_distrib(0,100);
    uniform_real_distribution<double> xy_coordinate_distrib(-50,50);
    uniform_real_distribution<double> z_coordinate_distrib(-2,2);
    random_device rd;
    mt19937 gen(rd());

    for(int i=0;i<10;i++){
        id[-1]=(char)(i+48);
        r = range_distrib(gen);
        x = xy_coordinate_distrib(gen);
        y = xy_coordinate_distrib(gen);
        z = z_coordinate_distrib(gen);
        point loc(x,y,z);
        wlan dev(loc,id,r);
        devices.push_back(dev);
        delete &loc;
        delete &dev;

    }
    for(wlan dev:devices){
        dev.info();
    }

/*
    for(int i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
            if(devices[i].inrange(devices[j])){
                inrange_v.push_back({i,j});
            }
        }
    }

    for(inrange k:inrange_v){
        cout<<endl;
        devices.at(k.home_index).info();
        devices.at(k.neighbor_index).info();
    }
*/
}

