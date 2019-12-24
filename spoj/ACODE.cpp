#include <iostream>
#include <string>
#include <string.h>
using namespace std;

string n;

int ways(int i,int l,int arr[]){
	if(i>l){
		return 0;
	}
	else if(i==l){
		return 1;
	}
	else if(n[i]=='0'){
		return 0;
	}
	else{
		if(arr[i]!=-1){
			return arr[i];
		}
		string s2=n.substr(i,2);
		int n2=stoi(s2);
		if(n2>=10 && n2<=26){
			arr[i]=ways(i+1,l,arr)+ways(i+2,l,arr);
			return arr[i];
		}
		else{
			arr[i]=ways(i+1,l,arr);
			return arr[i];
		}
	}
}
int main() {
	while(1){
		cin>>n;
		if(n[0]=='0'){
			break;
		}
		int l=n.length();
		int arr[l]={};
		for(int i=0;i<l;i++){
			arr[i]=-1;
		}
		cout<<ways(0,l,arr)<<endl;
	}
	return 0;
}