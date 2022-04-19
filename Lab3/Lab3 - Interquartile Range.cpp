#include<iostream>
#include<set>
#include<iomanip>
using namespace std;

int main(){
	cin.tie(0);
  	cin.sync_with_stdio(0);
  	multiset<long double> mset;
  	long long int k;
  	long double median1,median2;
  	multiset<long double>::iterator it1;
  	multiset<long double>::iterator it2;
  	while(cin>>k&&k!=0){
  		mset.insert(k);
  		if(mset.size()==1){
  			it1=mset.begin();
  			it2=mset.begin();
			cout<<"0"<<'\n';
			continue;	
		}
		else if(mset.size()%4==2){
			if(k>=*it2){
				++it2;
			}
			else if(k<*it1){
				--it1;
			}
			median1=*it1;
			median2=*it2;
//			cout<<"it1:"<<*it1<<endl;
//			cout<<"it2:"<<*it2<<endl;
		}
		else if(mset.size()%4==3){
			if(k>=*it2){
				++it2;
			}
			else if(k<*it1){
				--it1;
			}
			median1=*it1;
			median2=*it2;
//			cout<<"it1:"<<*it1<<endl;
//			cout<<"it2:"<<*it2<<endl;
		}
		else if(mset.size()%4==0){
			if(k>=*it2){
				++it2;
			}
			else if(k<*it1){
				--it1;
			}
			median1=(*it1+*(++it1))/2.0;
			--it1;
			median2=(*it2+*(--it2))/2.0;
			++it2;
//			cout<<"it1:"<<*it1<<endl;
//			cout<<"it2:"<<*it2<<endl;
		}
		else if(mset.size()%4==1){
			if(k>=*it2){
				++it2;
			}
			else if(k<*it1){
				--it1;
			}
			median1=(*it1+*(++it1))/2.0;
			--it1;
			median2=(*it2+*(--it2))/2.0;
			++it2;
			++it1;
			--it2;
//			cout<<"it1:"<<*it1<<endl;
//			cout<<"it2:"<<*it2<<endl;
		}
  		if((int)(median2-median1)==median2-median1){
			cout<< int(median2-median1) <<'\n';
		}
		else{
			cout<<fixed<<setprecision(1)<<median2-median1<<'\n';
		}
//		cout<<"--------"<<endl;
	}
	return 0;
}
