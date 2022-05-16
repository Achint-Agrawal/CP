#include <iostream>
using namespace std;

int main() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int d1=abs(a-b);
    int d2=abs(b-c);
    int d3=abs(c-a);
    if(d1>d2){
        int t=d1;
        d1=d2;
        d2=t;
    }
    if(d2>d3){
        d2=d3;
    }
    int result=0;
    if(d-d1>0)
        result+=d-d1;
    if(d-d2>0)
        result+=d-d2;
    cout<<result;
    return 0;
}
