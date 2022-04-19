#include<iostream>
#include<set>
#include<iterator>
using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	long long int n,t,w;
	cin>>n>>t;
	long long int ans=0;
	multiset<long long int> mset;
	for(long long int i=0;i<n;i++){
		cin>>w;
		mset.insert(w);
	}
	multiset<long long int>::iterator it1;
	multiset<long long int>::iterator it2;
	multiset<long long int>::iterator it3;
	for(it1=mset.begin();it1!=prev(mset.end(),2);it1++){
		it3=--mset.end();
		it2=++it1;
		--it1;
		while(it3!=next(it1,1)&&it2!=it3&&it1!=it2&&it1!=it3){
//			cout<<"it1:"<<*it1<<endl;
//			cout<<"it2:"<<*it2<<endl;
//			cout<<"it3:"<<*it3<<endl;
//			cout<<"sum:"<<*it1+*it2+*it3<<endl;
			if(*it1+*it2+*it3==t){
				if(*it2==*prev(it2)&&*it3==*next(it3)){
					++it2;
					--it3;
				}
				else if(*it2==*prev(it2)&&it2!=next(it1)){
					++it2;
				}
				else if(*it3==*next(it3)){
					--it3;
				}
				else if(*it1==*prev(it1)){
					break;
				}
				else{
					ans+=1;
					++it2;
				}	
			}
			else if(*it1+*it2+*it3>t){
				--it3;
			}
			else if(*it1+*it2+*it3<t){
				++it2;
			}
//			cout<<"ans:"<<ans<<endl;
//			cout<<"------"<<endl;
		}
	}
	if(ans!=0){
		cout<<ans;
	}
	else{
		cout<<"FeiDooDoo_Zuo_Wei_Men";
	}
	return 0;
}
