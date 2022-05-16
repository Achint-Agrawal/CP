#include <iostream>
using namespace std;

int bslast(int a[], int lo, int hi, int x){
	while(lo<=hi){
		int m=(lo+hi)/2;
		if(a[m]<x){
			hi=m-1;
		}
		else{
			lo=m+1;
		}
		// cout<<"lo="<<lo<<" hi="<<hi<<" m="<<m<<" a[m]="<<a[m]<<" x="<<x<<endl;
	}
	return lo-1;
}
int main() {
	int n,k;
	cin>>n>>k;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans;
	if(a[k]>0){
		ans=bslast(a,k,n,a[k]);
	}
	else{
		ans=bslast(a,1,k-1,1);
	}
	cout<<ans<<endl;
	return 0;
}