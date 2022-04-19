#include<iostream>
#include<map>
#include<vector>
#include<algorithm>>
using namespace std;

typedef pair<int, int> Pair;
bool my_compare(const Pair &p1, const Pair &p2){
	return p1.second < p2.second;
}
struct MyCompare{
public:
	bool operator()(const Pair &p1, const Pair &p2) const{
		return p1.second < p2.second;
	}
};

int main(){
	cin.tie(0);
    cin.sync_with_stdio(0);
    map<int, int> type_map;
    vector<Pair> vec;
    int Q;
    cin>>Q;
    for(int i=Q;i>0;i--){
    	int check,a,x;
    	cin>>check;
    	if(check==1){
    		cin>>a>>x;
    		type_map[a]=x;
    		for(int itr = type_map.begin(); itr != type_map.end(); itr++){
		        vec.push_back(make_pair(itr->first, itr->second));
	        }
	        sort(vec.begin(), vec.end(), MyCompare());
		}
		else if(check==2){
		    cin>>a;
		    if(a!=type_map.end()){
			    cout<<a->second<<'\n';
		    }
		    else if(a==type_map.end()){
			    cout<<"-1"<<'\n';
		    }
	    }
	
	}
	return 0;
}
