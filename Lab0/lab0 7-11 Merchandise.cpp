#include<iostream>
#include<vector>
using namespace std;

int main(){
	cin.tie(0);
    cin.sync_with_stdio(0);
	int N,Q;
	cin>>N>>Q;
	vector <int> ivec[N];
	for(int w=Q;w>0;w--){
		int i,a,x;
		cin>>i>>a>>x;
		if(i==1){
			ivec[a].push_back(x);
		}
		else if(i==2){
			if(x>=ivec[a].size()){
				cout<<"-1"<<'\n';
			}
			else {
				cout<<ivec[a][x]<<'\n';
			}
		}
	}
	return 0;
}
