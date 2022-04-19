#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n,l,k,w;
	long long time=0;
	cin>>n>>l>>k;
	vector<int>v;
	for(int i=0;i<n;i++){
		cin>>w;
		v.push_back(w);
	}
	sort(v.begin(),v.end());
	int* start=&v[0];
	int* end=&v[v.size()-1];
	while(start<=end){
		time+=k*2;
		if(start==end){
			break;
		}
		else if(*start+*end<=l){
			start++;
			end--;
		}
		else{
			end--;
		}
	}
	cout<<time<<'\n';
	return 0;
}
