#include<iostream>
using namespace std;
class power{
    public:
    int powers(int x, int y){
        int temp;
        if(y==0)
            return 1;
        temp = powers(x,y/2);
        if(y%2 == 0)
            return temp * temp;
        else
            return x * temp * temp;
    }
};
int main(){
    power p;
    int x = 2;
    int y = 3;
    cout<< p.powers(x,y);
    return 0;
}