#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	long long int n,m;
	cin>>n>>m;
	vector<vector<long long int> > f(n,vector<long long int>(n));
	for(long long int i=0;i<n;i++){
		for(long long int j=0;j<n;j++){
			if(i==j){
				f[i][j]=0;
			}
			else{
				f[i][j]=500000000001;
			}
		}
	}
	long long int a,b,w;
	for(long long int i=0;i<m;i++){
		cin>>a>>b>>w;
		f[a][b]=min(w,f[a][b]);
	}
	for(long long int i=0;i<n;i++){
		for(long long int j=0;j<n;j++){
			for(long long int k=0;k<n;k++){
				if(f[j][i]+f[i][k]<f[j][k]){
					f[j][k]=f[j][i]+f[i][k];
				}
			}
		}
	}
	
	long long int K;
	cin>>K;
	long long int first,target;
	for(long long int i=0;i<K;i++){
		cin>>first>>target;
		if(f[first][target]==500000000001){
			cout<<"-1"<<'\n';
		}
		else{
			cout<<f[first][target]<<'\n';
		}
	}
	return 0;
} 
