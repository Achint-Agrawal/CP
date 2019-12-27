#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		string s1,s2;
		cin>>s1>>s2;
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		int n1=stoi(s1);
		int n2=stoi(s2);
		int n3=n1+n2;
		string s3=to_string(n3);
		reverse(s3.begin(),s3.end());
		n3=stoi(s3);
		cout<<n3<<endl;
	}
	return 0;
}