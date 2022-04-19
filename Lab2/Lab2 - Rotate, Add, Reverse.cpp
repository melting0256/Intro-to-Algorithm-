#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

void calculate(vector<int> ivector,int w,int N){
	vector<int> a;
	vector<int> b;
	vector<int> ans;
	if(N==0){
		cout<<"1";
	}
	else{
		int num=pow(2,w-1);
		vector<int> tmp;
		tmp=ivector;
		reverse(ivector.begin(),ivector.end());
		a=ivector;
		for(int i=0;i<tmp.size();i++){
			tmp[i]=tmp[i]+num;
		}
		b=tmp;
		a.insert(a.end(),b.begin(),b.end());
		int rotR=num;
		std::rotate(a.begin(),a.begin()+a.size()-rotR,a.end());	//¥ª±Û 
		ans=a;
		w=w+1;
		if(w>N){
				for(int i=0;i<a.size();i++){
					cout<<a[i]<<" ";
				}
		}
		else{
			calculate(ans,w,N);
		}
	}
}

int main(){
	int N;
	vector<int> ivector;
	ivector.push_back(1);
	while(cin>>N){
		calculate(ivector,1,N);
	}
	return 0;
}
