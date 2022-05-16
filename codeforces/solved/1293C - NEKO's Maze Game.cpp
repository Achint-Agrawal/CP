#include <iostream>
using namespace std;
 
int main() {
	int n,q;
	cin>>n>>q;
	int pos[3][n+2];
	int block[3][n+2];
	for(int i=0;i<3;i++){
	    for(int j=0;j<n+2;j++){
	        pos[i][j]=0;
	        block[i][j]=0;
	    }
	}
	int nblock=0;
	while(q--){
	    int x,y;
	    cin>>x>>y;
	    if(pos[x][y]==0){
	       pos[x][y]=1;
	       int z=2;
	       if(x==2)    z=1;
	       if(!(pos[z][y-1]==0 && pos[z][y]==0 && pos[z][y+1]==0)){
	           block[x][y]=1;
	           if(pos[z][y-1]!=0){
	               block[z][y-1]=1;
	               nblock++;
	           }
	           if(pos[z][y]!=0){
	               block[z][y]=1;
	               nblock++;
	           }
	           if(pos[z][y+1]!=0){
	               block[z][y+1]=1;
	               nblock++;
	           }
	       }
	    }
	    else{
	        pos[x][y]=0;
	        if(block[x][y]==1){
	            block[x][y]=0;
	            int z=2;
	            if(x==2)    z=1;
	            if(block[z][y]==1){
	                nblock--;
	                if(pos[x][y-1]==0 && pos[x][y+1]==0){
	                    block[z][y]=0;
	                }
	            }
	            if(block[z][y-1]==1){
	                nblock--;
	                int k=1;
	                if(y-2>=0){
	                    if(pos[x][y-2]!=0) k=0;
	                }
	                if(k && pos[x][y-1]==0){
	                    block[z][y-1]=0;
	                }
	            }
	            if(block[z][y+1]==1){
	                nblock--;
	                int k=1;
	                if(y+2<=n){
	                    if(pos[x][y+2]!=0) k=0;
	                }
	                if(k && pos[x][y+1]==0){
	                    block[z][y+1]=0;
	                }
	            }
	        }
	    }
	    if(nblock==0){
	        cout<<"YES"<<endl;
	    }
	    else{
	        cout<<"NO"<<endl;
	    }
	}
	return 0;
}