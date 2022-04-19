#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long int> order;

struct edge{
	long long int x,y;
};

long long int find(long long int a){
	if(order[a]==a){
		return a;
	}
	else{
		order[a]=find(order[a]);
		return order[a];
	}
}

int main(){
	cin.tie(0);
    cin.sync_with_stdio(0);
	int t;
	cin>>t;
	for(int j=0;j<t;j++){
		long long int n,m,k,f,s;
		cin>>n>>m>>k>>f>>s;
		order.clear();
		order.resize(n);
		vector<edge> v1;
		vector<edge> v2;
		vector<edge> v3;
		v1.clear();
		v2.clear();
		v3.clear();
		for(long long int i=0;i<n;i++){
			order[i]=i;
		}
		long long int x,y;
		char c;
		for(long long int i=0;i<m;i++){
			cin>>x>>y>>c;
			if(c=='F'){
				v1.push_back({x,y});
			}
			else if(c=='S'){
				v2.push_back({x,y});
			}
			v3.push_back({x,y});
		} 
		long long int todo=0;
		for(long long int i=0;i<v3.size();i++){
			x=find(v3[i].x);
			y=find(v3[i].y);
			if(x==y){
				continue;
			}
			else{
				order[y]=x;
				todo+=1;
			}
		}
		for(long long int i=0;i<n;i++){
			order[i]=i;
		}
		long long int ftodo=0;
		for(long long int i=0;i<v1.size();i++){
			x=find(v1[i].x);
			y=find(v1[i].y);
			if(x==y){
				continue;
			}
			else{
				order[y]=x;
				ftodo+=1;
			}
		}
		for(long long int i=0;i<n;i++){
			order[i]=i;
		}
		long long int stodo=0;
		for(long long int i=0;i<v2.size();i++){
			x=find(v2[i].x);
			y=find(v2[i].y);
			if(x==y){
				continue;
			}
			else{
				order[y]=x;
				stodo+=1;
			}
		}
		int flag=0;
		for(long long int i=ftodo;i>=n-1-stodo;i--){
			long long int tmp=f*i+(n-1-i)*s;
			if((n-1-ftodo)<=(n-1-i)&&(n-1-i)<=stodo){
				if(tmp==k&&todo==n-1){
					cout<<"Yes"<<'\n';
					flag=1;
					break;
				}
			}
		}
		if(flag==0){
			cout<<"No"<<'\n';
		}
	} 
}
