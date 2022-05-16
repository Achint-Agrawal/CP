#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int price[n];
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    sort(price,price+n);
    int q;
    cin>>q;
    while(q--){
        int coins;
        cin>>coins;
        int l=0;
        int u=n-1;
        int mid=(l+u)/2;
        int result=-1;
        while(l<u){
            if(coins==price[mid]){
                result=mid;
                l=mid+1;
            }
            if(coins<price[mid]){
                u=mid-1;
            }
            else{
                l=mid+1;
            }
            mid=(l+u)/2;
        }
        if(result>=0){
            mid=result;
        }
        while(mid<=n-1&& price[mid]<=coins){
            mid++;
        }
        // if(price[mid]<=coins && mid<=n-1){
        //     cout<<(mid+1)<<"\n";
        // }
        // else{
        //     cout<<mid<<"\n";
        // }
        cout<<mid<<"\n";
    }
}