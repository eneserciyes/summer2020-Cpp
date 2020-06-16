#include<iostream>

using namespace std;

class Vector{
    private:
        double* elem;
        int sz;

    public:
        Vector(int s){
            elem = new double[s];
            sz = s;
        }
        
        double& operator[](int i){
            return elem[i];
        }

        int size(){
            return sz;
        }


};

int main(){
    Vector v(6);

    for(int i = 0; i< v.size(); ++i){
        cin >> v[i];
    }

    for(int i = 0 ; i<v.size(); ++i){
        cout << v[i];
    }

}