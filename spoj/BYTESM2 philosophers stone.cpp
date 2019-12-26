#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int h,w;
		cin>>h>>w;
		int arr[h][w];
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cin>>arr[i][j];
			}
		}
		for(int i=h-2;i>=0;i--){
			arr[i][0]=arr[i][0] + max(arr[i+1][0], arr[i+1][1]);
			for(int j=1;j<=w-2;j++){
				arr[i][j]=arr[i][j] + *(max_element(arr[i+1]+j-1,arr[i+1]+j+2));
			}
			arr[i][w-1]=arr[i][w-1] + max(arr[i+1][w-2], arr[i+1][w-1]);
		}
		cout<<*(max_element(arr[0],arr[0]+w))<<endl;
	}
	return 0;
}