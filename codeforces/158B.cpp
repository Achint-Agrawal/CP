#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;
	int ones=0, twos=0, threes=0, ans=0;
	while(n--){
		int x;
		cin>>x;
		if(x==1)	ones++;
		else if(x==2)	twos++;
		else if(x==3)	threes++;
		else			ans++;
	}
	ans+=min(ones, threes) + twos/2;
	int k=abs(ones-threes);
	twos=twos%2;
	if(ones>threes){
		if(twos){
			ans+=1;
			twos=0;
			k-=2;
		}
		ans+=k/4;
		if(k>0 && k%4) ans++;
	}
	else{
		if(twos){
			ans++;
		}
		ans+=k;
	}
	cout<<ans;
	return 0;
}
