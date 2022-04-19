#include<iostream>
#include<queue>
using namespace std;

int main(){
	int count;
	cin>>count;
	int id,p,tmp;
	pair<int,int> p1;
	queue<pair<int,int> > q;
	for(int i=count;i>0;i--){
		cin>>id>>p;
		p1.first=id;
		p1.second=p;
		q.push(p1);
	}
	while(!q.empty()){
		pair<int,int> p2;
		p2=q.front();
		p2.second=p2.second-1;
		cout<<p2.first<<'\n';
		if(p2.second>0){
			q.push(p2);
		}
		q.pop();
	}
	return 0;
}
