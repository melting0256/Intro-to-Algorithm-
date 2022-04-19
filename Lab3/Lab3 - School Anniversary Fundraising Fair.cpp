#include<iostream>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
	long long int N,p;
	long long int targetL,targetR;
	map<long long int,long long int> bo;
	map<long long int,long long int>:: iterator it;
	map<long long int,long long int>:: iterator iter;
	cin>>N>>p>>targetL>>targetR;
	long long int fmax=targetL;
	long long int num=0;
	int flag=0;
	for(int i=0;i<N;i++){
		long long int l,r;
		cin>>l>>r;
		bo[r]=l;
	}
	iter=it=bo.begin();
	for(it=bo.begin();it!=bo.end();it++){
		if(it->first>fmax&&it->second<=fmax){	//找可以符合中最長的部分 
			flag=1;
			iter=it;
			//cout<<"iter_first:"<<iter->first<<endl;
		}
		else if(flag==1&&it->second<=iter->first){	//找接續前一個的下一個 
			num+=1;	//加上面的 
			flag=0;
			fmax=iter->first;
			it--;
			//cout<<"fmax:"<<fmax<<endl;
		}
	}
	//cout<<"num1:"<<num<<endl;
	if(iter->first<targetR){
		num=0;
	}
	else{
		if(fmax!=targetL){
			num+=1;
		}
		else{
			num=0;
		}
	}
	//cout<<"num2:"<<num<<endl;
	cout<<num*p;
	return 0;
}
