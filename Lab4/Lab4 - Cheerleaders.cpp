#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	long long int n;
	cin>>n;
	vector<long long int> height(n);
	for(long long int i=0;i<n;i++){
		cin>>height[i];
	}
	vector<long long int> num;
	vector<long long int> dp;
	long long int first,second;
	for(long long int i=0;i<n;i++){
		if(i==0){
			num.push_back(height[0]);
			dp.push_back(1);
		}
		else{
			if(height[i]<=num.back()){
				vector<long long int>::iterator it;
				it=lower_bound(num.begin(),num.end(),height[i]);
				*it=height[i];
				dp.push_back(it-num.begin()+1);
			}
			else if(height[i]>num.back()){
				num.push_back(height[i]);
				dp.push_back(num.size());
			}
		}
	}
	vector<long long int> dp1;
	num.clear();
	vector<long long int> v;
	for(long long int i=n-1;i>=0;i--){
		if(i==n-1){
			num.push_back(height[i]);
			dp1.push_back(1);
			v.push_back(1);
		}
		else{
			if(height[i]<=num.back()){
				vector<long long int>::iterator it;
				it=lower_bound(num.begin(),num.end(),height[i]);
				*it=height[i];
				dp1.push_back(it-num.begin()+1);
				if(dp1.back()>v.back()){
					v.push_back(dp1.back());
				} 
				else{
					v.push_back(v.back());
				}
			}
			else if(height[i]>num.back()){
				num.push_back(height[i]);
				dp1.push_back(num.size());
				if(dp1.back()>v.back()){
					v.push_back(dp1.back());
				} 
				else{
					v.push_back(v.back());
				}
			}
		}
	}
	vector<long long int> com(n);
	for(long long int i=0;i<n-1;i++){
		com[i]=dp[i]+v[n-i-2];
	}
	com[n-1]=dp[n-1];
	vector<long long int>::iterator result;
	result=max_element(com.begin(),com.end());
	first=*result;
	dp.clear();
	dp1.clear();
	num.clear();
	v.clear();
	for(long long int i=0;i<n;i++){
		if(i==0){
			num.push_back(height[0]);
			dp.push_back(1);
		}
		else{
			if(height[i]<num.back()){
				num.push_back(height[i]);
				dp.push_back(num.size());
			}
			else if(num.size()!=1&&height[i]>num.back()&&height[i]<num.front()){
				vector<long long int>::iterator it;
				it=lower_bound(num.begin(),num.end(),height[i],greater<long long int>());
				*it=height[i];
				dp.push_back(it-num.begin()+1);
			}
			else if(num.size()==1&&height[i]>=num.back()){
				num[0]=height[i];
				dp.push_back(1);
			}
			else if(num.size()!=1&&height[i]==num.back()){
				dp.push_back(num.size());
			}
			else if(num.size()!=1&&height[i]==num.front()){
				dp.push_back(1);
			}
			else if(num.size()!=1&&height[i]>num.front()){
				num[0]=height[i];
				dp.push_back(1);
			}
		}
	}
	num.clear();
	for(long long int i=n-1;i>=0;i--){
		if(i==n-1){
			num.push_back(height[i]);
			dp1.push_back(1);
			v.push_back(1);
		}
		else{
			if(height[i]<num.back()){
				num.push_back(height[i]);
				dp1.push_back(num.size());
				if(dp1.back()>v.back()){
					v.push_back(dp1.back());
				} 
				else{
					v.push_back(v.back());
				}
			}
			else if(num.size()!=1&&height[i]>num.back()&&height[i]<num.front()){
				vector<long long int>::iterator it;
				it=lower_bound(num.begin(),num.end(),height[i],greater<long long int>());
				*it=height[i];
				dp1.push_back(it-num.begin()+1);
				if(dp1.back()>v.back()){
					v.push_back(dp1.back());
				} 
				else{
					v.push_back(v.back());
				}
			}
			else if(num.size()==1&&height[i]>=num.back()){
				num[0]=height[i];
				dp1.push_back(1);
				if(dp1.back()>v.back()){
					v.push_back(dp1.back());
				} 
				else{
					v.push_back(v.back());
				}
			}
			else if(num.size()!=1&&height[i]==num.back()){
				dp1.push_back(num.size());
				if(dp1.back()>v.back()){
					v.push_back(dp1.back());
				} 
				else{
					v.push_back(v.back());
				}
			}
			else if(num.size()!=1&&height[i]==num.front()){
				dp1.push_back(1);
				if(dp1.back()>v.back()){
					v.push_back(dp1.back());
				} 
				else{
					v.push_back(v.back());
				}
			}
			else if(num.size()!=1&&height[i]>num.front()){
				num[0]=height[i];
				dp1.push_back(1);
				if(dp1.back()>v.back()){
					v.push_back(dp1.back());
				} 
				else{
					v.push_back(v.back());
				}
			}
		}
	}
	vector<long long int> com1(n);
	for(long long int i=0;i<n-1;i++){
		com1[i]=dp[i]+v[n-i-2];
	}
	com1[n-1]=dp[n-1];
	result=max_element(com1.begin(),com1.end());
	second=*result;
	cout<<max(first,second);
	return 0;
}
