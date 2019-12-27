#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans=0;
		for(int k=5;n>=k;k*=5){
			ans+=n/k;
		}
		cout<<ans<<endl;
	}
	return 0;
}