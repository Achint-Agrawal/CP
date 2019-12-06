#include <iostream>
using namespace std;

int main() {
	long a[1000001]={};
	a[1]=1;
	for(long i=2;i<=1000000;i++){
		if(a[i]==0){
			for(long j=i;j<=1000000;j+=i){
				if(a[j]==0){
					a[j]=(j*(i-1))/i;
				}
				else{
					a[j]=(a[j]*(i-1))/i;
				}
			}
		}
	}
	int t;
	cin>>t;
	while(t--){
		int x;
		cin>>x;
		cout<<a[x]<<endl;
	}
	return 0;
}