#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<random>
using namespace std;


class point{
    private:
    public:
        double x ;
        double y ;
        double z ; 
        point(double a = 0,double b = 0, double c =0):x(a),y(b),z(c){}
        double distance(point origin = point()){
            double dist = sqrt(pow(x-origin.x,2)+pow(y-origin.y,2)+pow(z-origin.z,2));
            return dist;
        }
		double distance(point *origin){
			double dist = sqrt(pow(x-origin->x,2)+pow(y-origin->y,2)+pow(z-origin->z,2));
			return dist;
		}
};

class wlan{
    private:
        double range;
    public:
        point *coordinate;
        string uuid;
		wlan(point* a, string id, double r){coordinate=a;uuid=id;range=r;}
        
        bool inrange(wlan *neighbor){
            double distance = coordinate->distance(neighbor->coordinate);
            if(distance<=range&&distance<=neighbor->range){
                return true;
            }
            return false;
        }

        void info(){
            cout<<endl<<uuid<<" at ("<<coordinate->x<<","<<coordinate->y<<","<<coordinate->z<<")"<<" with range : "<<range;
        }
	void neighbor_info(wlan *n){
	    cout<<endl<<uuid<<" neighbor with "<<n->uuid;
	}
	void change_location(point *a){
		coordinate=a;
	}


};

vector<wlan*> devices;

struct inrange{
	int home_index;
	int neighbor_index;
};
vector<inrange> inrange_v1,inrange_v2;

int main(){
    string id = "tp-1000";
    double r;
    double x,y,z;
    default_random_engine gen;
    uniform_real_distribution<double> range_distrib(0,25);
    uniform_real_distribution<double> xy_coordinate_distrib(-50,50);
    uniform_real_distribution<double> z_coordinate_distrib(-2,2);


    for(int i=0;i<10;i++){
        id[6]='0'+i;
        r = range_distrib(gen);
        x = xy_coordinate_distrib(gen);
        y = xy_coordinate_distrib(gen);
        z = z_coordinate_distrib(gen);
		point *loc = new point(x,y,z);
		wlan *dev = new wlan(loc,id,r);
        devices.push_back(dev);
    }

    cout<<"initialised devices";
    for(int i=0;i<10;i++){
        devices[i]->info();
    }
    
    
    for(int i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
            if(devices[i]->inrange(devices[j])){
                inrange_v1.push_back({i,j});
            }
        }
    }

    cout<<"\n\nin range devices";

    for(int i=0;i<inrange_v1.size();i++){
        devices.at(inrange_v1[i].home_index)->neighbor_info(devices.at(inrange_v1[i].neighbor_index));
    }
    
    cout<<"\n\nnew location of devices";
    for(int i=0;i<devices.size();i++){
		x = xy_coordinate_distrib(gen);
        y = xy_coordinate_distrib(gen);
        z = z_coordinate_distrib(gen);
        point *loc1 = new point(x,y,z);
		point *temp = devices[i]->coordinate;
		delete temp;
		devices[i]->change_location(loc1);
    }
    
	for(int i=0;i<devices.size();i++){
        devices[i]->info();
    }


    for(int i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
            if(devices[i]->inrange(devices[j])){
                inrange_v2.push_back({i,j});
            }
        }
    }

    cout<<"\n\nnew range devices";

    for(int i=0;i<inrange_v2.size();i++){
        devices.at(inrange_v2[i].home_index)->neighbor_info(devices.at(inrange_v2[i].neighbor_index));
    }
    
cout<<endl;	
    for(int i=0;i<devices.size();i++){
    	delete devices[i]->coordinate;
		delete devices[i];
    }

}

