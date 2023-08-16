#include<iostream>
#include<vector>
using namespace std;
#define cols 3
#define rows 2
void prints(vector<char> v_str){
    int sizes = v_str.size();
    for(int i=0;i<sizes;i++){
        cout<<v_str[i];
    }
}

void prints(char (*sentence)[cols]){
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
    vector<char> v;
    v.push_back('g');
    v.push_back('h');
    v.push_back('i');

    prints(s);
    prints(v);

}
