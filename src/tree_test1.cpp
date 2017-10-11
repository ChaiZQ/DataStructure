#include <iostream>
#include <algorithm>
using namespace std;
//#define max(a,b) ((a)>(b)? (a):(b))

struct treeNode{
    treeNode* left=NULL;
    treeNode* right=NULL;
    int val;
    treeNode(int n,treeNode*l=NULL,treeNode*r=NULL){val=n;left=l;right=r;};
};


treeNode* treefind(treeNode*node,int val)
    {
    if(node==NULL)return NULL;
    
    if(node->val>val)
        return treefind(node->left,val);
    else if(node->val<val)
        return treefind(node->right,val);
    else
        return node;
}

void insert(treeNode*node,treeNode*newNode)
    {
    if(node==NULL)return;
    if(node->val> newNode->val){
        if(node->left==NULL){
            node->left=newNode;
            return;
        }
        else
            return insert(node->left,newNode); 
    }
    else if(node->val<newNode->val){
        if(node->right==NULL){
            node->right=newNode;
            return;
        }
        else
            return insert(node->right,newNode); 
    }
    else
        return;
        
}

int calc_height(treeNode* pNode)
    {
    if(pNode==NULL)
        return 0;
   	return (max(calc_height(pNode->left),calc_height(pNode->right)) + 1);
}

int main(int argc,char**argv){
	int cnt = 0,n;
    cin>>n;
	treeNode* rootNode=NULL;
    while(1){
        
        int num1,num2;
        cin>>num1>>num2;
        if(rootNode==NULL)
            {
            rootNode=new treeNode(num1);
			cnt++;
        }
        treeNode* parentNode = treefind(rootNode,num1);
        treeNode* pNode=new treeNode(num2);
        insert(parentNode,pNode);
		if (++cnt >= n)
			break;
    }
    
    cout<<calc_height(rootNode)<<endl;
    
	system("pause");
    return 0;
    
}