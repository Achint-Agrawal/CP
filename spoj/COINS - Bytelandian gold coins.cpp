#include <iostream>
#include<algorithm>
using namespace std;

long long maxval(long long n, int arr[]){
	if(n<=11){
		return n;
	}
	if(n<=10000000){
		if(arr[n]==0){
			arr[n]=max(n, maxval(n/2, arr) + maxval(n/3, arr) + maxval(n/4, arr));
		}
		return arr[n];
	}
	return max(n, maxval(n/2, arr) + maxval(n/3, arr) + maxval(n/4, arr));
}
int main() {
	long long n;
	while(cin>>n){
		int arr[10000000]={};
		cout<<maxval(n,arr)<<endl;
	}
	return 0;
}