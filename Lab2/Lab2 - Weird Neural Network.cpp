#include<iostream>
using namespace std; 
class Node{
	public:
    	long long int data;
    	Node *left=NULL; 
		Node *right=NULL;
		void postorder(Node* tree);
};

void Node::postorder(Node* tree){
	if(tree->left==NULL){
		tree->data=tree->data%1000000007;
	}
	else{
		postorder(tree->left);
		postorder(tree->right);
		tree->data=((tree->left->data%1000000007+tree->right->data%1000000007)*(tree->data))%1000000007;
	}	
}


int main(){
	long long int n;
	cin>>n;
	long long int a[n-1];
	Node arr[n];
	for(long long int i=0;i<n;i++){
		cin>>arr[i].data;
	}
	for(long long int i=0;i<n-1;i++){
		cin>>a[i];
		a[i]=a[i]-1;
	}
	for(long long int i=0;i<n-1;i++){
		if(arr[a[i]].left==NULL){
			arr[a[i]].left=&arr[i+1];
		}
		else{
			arr[a[i]].right=&arr[i+1];
		}
	}
	arr[n].postorder(&arr[0]);
	cout<<arr[0].data%1000000007;
	return 0;
}
