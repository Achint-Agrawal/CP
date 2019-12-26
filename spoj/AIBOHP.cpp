#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
int a[6100][6100];
int find(string &s, int start, int end){
	if(start>=end){
		return 0;
	}
	else{
		if(s[start]==s[end]){
			if(a[start][end]==-1){
				a[start][end]=find(s,start+1,end-1);
			}
			return a[start][end];
		}
		else{
			if(a[start][end]==-1){
				a[start][end]=min(1+find(s,start+1,end), 1+find(s,start,end-1));
			}
			return a[start][end];
		}
	}
}
int main() {
	int t;
	cin>>t;
		
	while(t--){
		for(int i=0;i<6100;i++){
			for(int j=0;j<6100;j++){
				a[i][j]=-1;
			}
		}
		string s;
		cin>>s;
		/*string s2=s;
		int l=s.length();
		reverse(s2.begin(),s2.end());
		int arr[l+1][l+1]={};
		for(int i=1;i<=l;i++){
			arr[0][i]=i-1;
			arr[i][0]=i-1;
		}
		for(int i=1;i<=l;i++){
			for(int j=1;j<=l;j++){
				if(s2[i-1]==s[j-1]){
					arr[i][j]=arr[i-1][j-1];
				}
				else{
					arr[i][j]=1+min(arr[i-1][j],arr[i][j-1]);
				}
				cout<<arr[i][j]<<"  ";
			}
			cout<<endl;
		}
		
		cout<<arr[l][l]<<endl;*/
		
		int l=s.length();
		cout<<find(s,0,l-1)<<endl;
	}
	return 0;
}