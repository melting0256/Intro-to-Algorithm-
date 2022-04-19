#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

void binary_search(vector<pair<int,int> > &v,int key,int l,int r){
	if(l>r){
		cout<<"-1"<<'\n';
		return;
	}
	if(l==r&&v[l].second!=key){
		cout<<"-1"<<'\n';
		return;
	}
	int middle=(l+r)/2;
	if(v[middle].second==key){
		cout<<v[middle].first<<'\n';
		return;
	}
	else if(v[middle].second>key){
		binary_search(v,key,l,middle);
	}
	else{
		binary_search(v,key,middle+1,r);
	}
}

int main(){
	cin.tie(0); cin.sync_with_stdio(0);
    int N,M;
	int a,key = 0;
	cin>>N>>M;
	vector<pair<int,int> >s,l;
	for(int i=0;i<N;i++){
		cin>>a;
		if(i==0){
			l.push_back(pair<int,int>(i,a));
		}
		else{
			if(l[i-1].second>=a){
				key=i;
				s.push_back(pair<int,int>(i,a));
				break;
			}
			else{
				l.push_back(pair<int,int>(i,a));
			}
		}
	}
	for(int i=key+1;i<N;i++){
		cin>>a;
		s.push_back(pair<int,int>(i,a));
	}
	reverse(s.begin(),s.end());
	s.insert(s.end(),l.begin(),l.end());
	for(int i=0;i<M;i++){
		cin>>a;
		binary_search(s,a,0,N-1);
	}
	return 0;	
}
