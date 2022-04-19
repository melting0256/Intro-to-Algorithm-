#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
	cin.tie(0);
    cin.sync_with_stdio(0);
	int t;
	cin>>t;
	for(int w=0;w<t;w++){
		long long int n,m,s;
		cin>>n>>m>>s;
		long long int u,v;
		vector<vector<long long int> > f;
		f.resize(n+1);
		for(long long int i=0;i<m;i++){
			cin>>u>>v;
			f[u].push_back(v);
			f[v].push_back(u);
		}
		long long int x;
		cin>>x;
		long long int a;
		vector<int> who(n+1,0);
		who[s]=1;
		queue<long long int> q1;
		vector<int> pnum(n+1,-1);
		for(long long int i=0;i<x;i++){
			cin>>a;
			who[a]=2;	//警察出發點
			q1.push(a);
			pnum[a]=0;
		}
		long long int y;
		cin>>y;
		vector<long long int> b(y);
		for(long long int i=0;i<y;i++){
			cin>>b[i];	//藏的地方 
			who[b[i]]=3;
		} 
		while(!q1.empty()){
			long long int current=q1.front();
			q1.pop();
			for(long long int i=0;i<f[current].size();i++){
				if(pnum[f[current][i]]==-1){
					pnum[f[current][i]]=pnum[current]+1;
					q1.push(f[current][i]);
				}
			}
		}
		queue<long long int> q2;
		q2.push(s);
		vector<int> sv(n+1,0);	//visit
		sv[s]=1;
		vector<long long int> snum(n+1);
		snum[s]=0;
		int flag=0;
		while(!q2.empty()&&flag==0){
			long long int curr=q2.front();
			long long int count=snum[curr];
			q2.pop();
			for(long long int i=0;i<f[curr].size();i++){
				if(sv[f[curr][i]]==0){
					q2.push(f[curr][i]);
					sv[f[curr][i]]=1;
					snum[f[curr][i]]=count+1;
					if(who[f[curr][i]]==3){
						if(pnum[f[curr][i]]>snum[f[curr][i]]){
							cout<<"Yes"<<'\n';
							flag=1;
							break;
						}
						else{
							continue;
						}
					}
				}
			}
		}
		if(flag==0){
			cout<<"No"<<'\n';
		}
	}
}
