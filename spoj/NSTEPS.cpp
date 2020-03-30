#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int x,y;
		cin>>x>>y;
		int n=x+y;
		if(x==y){
			if(n%4==2)	n--;
			cout<<n<<endl;
		}
		else if(y==x-2){
			if(n%4==0)	n--;
			cout<<n<<endl;
		}
		else{
			cout<<"No Number"<<endl;
		}
	}
	return 0;
}
