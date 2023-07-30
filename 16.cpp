#include<iostream>
#include<vector>
using namespace std;
#define cols 3
#define rows 2
void print(vector<char> v_str){
    for(char i:v_str){
        cout<<i;
    }
}

void print(char (*sentence)[cols]){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<sentence[i][j];
        }
        cout<<" ";
    }
}
int main(){
    char s[rows][cols] = {
        {'a','b','c'},
        {'d','e','f'}
    };
    vector<char> v = {'g','h','i'};

    print(s);
    print(v);

}