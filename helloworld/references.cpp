#include<iostream>

using namespace std;
int main(){
    int v[] = {0,1,2,3};

    for(auto& x: v){
        ++x;
    }

    for(auto& x:v){
        cout << x;
    }

}