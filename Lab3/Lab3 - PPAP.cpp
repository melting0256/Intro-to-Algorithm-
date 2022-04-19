#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include<vector>
#include<math.h>
#include<iomanip>
using namespace std;

// A Tree node
struct Node{
	string str;
	int freq;
	Node *left, *right;
};

// Function to allocate a new tree node
Node* getNode(string str, int freq, Node* left, Node* right){
	Node* node = new Node();

	node->str = str;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}

struct comp{
	bool operator()(Node* l, Node* r){
		if(l->freq==r->freq){
			return l->str > r->str;
		}
		else{
			return l->freq > r->freq;
		}
	}
};

void encode(Node* root, string str1,unordered_map<string, string> &huffmanCode){
	if (root == nullptr)
		return;
	if (!root->left && !root->right) {
		huffmanCode[root->str] = str1;
	}
	encode(root->left, str1 + "0", huffmanCode);
	encode(root->right, str1 + "1", huffmanCode);
}


unordered_map<string,string> buildHuffmanTree(unordered_map<string,long long int> name){
	priority_queue<Node*, vector<Node*>, comp> pq;
	for (auto pair: name) {
		pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
	}
	while (pq.size() != 1){
		Node *left = pq.top(); pq.pop();
		Node *right = pq.top();	pq.pop();
		long long int sum = left->freq + right->freq;
		string choose;
		if(left->str>right->str){
			choose=right->str;
		}
		else{
			choose=left->str;
		}
		pq.push(getNode(choose, sum, left, right));
	}
	Node* root = pq.top();
	unordered_map<string, string> huffmanCode;
	unordered_map<string, string> ::iterator it;	//後面放各個單詞對應到的編碼 
	encode(root, "", huffmanCode);

/*	cout << "Huffman Codes are :\n" << '\n';
	for (it=huffmanCode.begin();it!=huffmanCode.end();it++) {
		cout << it->first << " " << it->second << '\n';
	}*/
	return huffmanCode; 
	// print encoded string
//	string str2 = "";
//	unordered_map<string, string>::iterator it;
//	for () {
//		str2 += huffmanCode[str];
//	}

//	cout << "\nEncoded string is :\n" << str2 << '\n';

}

int main(){
	long long int n;
	cin>>n;
	string input;
	string use;
	unordered_map<string,long long int> name;
	vector<string> order(n);
	getline(cin,input);
	for(long long int i=0;i<n;i++){
		getline(cin,input);
		input+=' ';
		order[i]=input;
		for(long long int t=0;t<input.length();t++){
			if(input[t]!=' '){
				use+=input[t];
			}
			else if(input[t]==' '){
				name[use]+=1;
				use.clear();
			}
		}
	}
	unordered_map<string,string> ans=buildHuffmanTree(name);
	string nuse;
	for(long long int i=0;i<n;i++){
		long double upper=0.0;
		long double word=0.0;
		for(long long int t=0;t<order[i].length();t++){
			if(order[i][t]!=' '){
				nuse+=order[i][t];
			}
			else if(order[i][t]==' '){
//				cout <<"nuse " << nuse <<endl; 
//				cout << "codelength " << ans[nuse].length() << endl; 
				upper+=ans[nuse].length();
				nuse.clear();
				word+=1.0;
			}
		}
//		cout << "up " <<upper <<endl; 
//		cout<<"word:"<<word<<endl;
		long double lower;
//		cout << "n sizze " << name.size() << endl; 
		lower=log(name.size())/log(2.0);
//		cout << "lower " << lower << endl;
		long double nlower;
		if(lower-(int)lower==0){
			nlower=lower*word;
		}
		else{
			nlower=(ceil(lower))*word;
		}
//		cout<<"origin:"<<setprecision(10)<<nlower<<endl;
		cout<<fixed<<setprecision(10)<<upper/nlower<<'\n';
	}

	return 0;
}
