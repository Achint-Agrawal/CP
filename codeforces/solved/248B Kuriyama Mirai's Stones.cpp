#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;
	long long v[n+1]={};
	long long u[n+1]={};
	for(int i=1;i<=n;i++){
		cin>>v[i];
		u[i]=v[i];
	}
	sort(u,u+n+1);
	for(int i=1;i<=n;i++){
		v[i]=v[i]+v[i-1];
		u[i]=u[i]+u[i-1];
	}
	int m;
	cin>>m;
	while(m--){
		int l,r,type;
		cin>>type>>l>>r;
		if(type==1){
			cout<<(v[r]-v[l-1])<<endl;
		}
		else{
			cout<<(u[r]-u[l-1])<<endl;
		}
	}
	return 0;
}