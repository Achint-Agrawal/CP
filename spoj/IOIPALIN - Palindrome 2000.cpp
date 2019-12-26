#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;
	char s[n];
	char rs[n];
	for(int i=0;i<n;i++){
		scanf(" %c",&s[i]);
		rs[n-i-1]=s[i];
	}
	int arr[n+1][n+1]={};
	for(int i=1;i<=n;i++){
		arr[0][i]=i;
		arr[i][0]=i;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; i+j<=n; j++){
			if(rs[i-1]==s[j-1]){
				arr[i][j]=arr[i-1][j-1];
			}
			else{
				arr[i][j]=1+min(arr[i-1][j], arr[i][j-1]);
			}
		}
	}
	int m=5000;
	for(int i=n-1;i>=0;i--){
		m=min(m,arr[i][n-i-1]);
	}
	for(int i=n;i>=0;i--){
		m=min(m,arr[i][n-i]);
	}
	cout<<m<<endl;
	return 0;
}