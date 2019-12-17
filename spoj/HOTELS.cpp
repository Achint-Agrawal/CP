#include <iostream>
using namespace std;

int main() {
	int n;
	long m;
	cin>>n;
	cin>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long max=0,current=a[0];
	int start=0,end=0;
	while(end<n){
		if(current<=m){
			if(current>max){
				max=current;
			}
			end++;
			current+=a[end];
		}
		else{
			current-=a[start];
			start++;
		}
	}
	cout<<max<<endl;
	return 0;
}