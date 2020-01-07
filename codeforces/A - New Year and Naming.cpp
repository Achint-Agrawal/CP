#include <iostream>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	string s[n+1];
	string t[m+1];
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=m;i++){
		cin>>t[i];
	}
	int q;
	cin>>q;
	while(q--){
		int y;
		cin>>y;
		if(y%n==0){
			cout<<s[n];
		}
		else{
			cout<<s[y%n];
		}
		if(y%m==0){
			cout<<t[m]<<endl;
		}
		else{
			cout<<t[y%m]<<endl;
		}
	}
	return 0;
}