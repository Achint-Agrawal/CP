#include <iostream>
using namespace std;

int main() {
	int n,k,q;
	scanf("%d %d %d",&n,&k,&q);
	int arr[200002]={};
	while(n--){
		int l,r;
		cin>>l>>r;
		arr[l]++;
		arr[r+1]--;
	}
	for(int i=1;i<=200000;i++){
		arr[i]=arr[i]+arr[i-1];
	}
	for(int i=0;i<=200000;i++){
		if(arr[i]>=k){
			arr[i]=1;
		}
		else{
			arr[i]=0;
		}
	}
	for(int i=1;i<=200000;i++){
		arr[i]=arr[i]+arr[i-1];
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		printf("%d\n",(arr[b]-arr[a-1]));
	}
	return 0;
}