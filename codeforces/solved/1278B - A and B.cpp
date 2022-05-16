#include <iostream>
#include <cmath>
using namespace std;

long long cumsum(long long x){
	long long s=(((long long)x)*(x+1))/2;
	return s;
}

bool possible(long long x, int d){
	long long s=cumsum(x);
	if(s>=d && s%2==d%2){
		return true;
	}
	return false;
}

int main() {
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		int d=abs(a-b);
		long long x=(-1+(long long)sqrt(1+8ll*d))/2;
		// if(x<0) x=0;
		while(!possible(x,d)){
			x++;
		}
		cout<<x<<endl;
	}
	return 0;
}