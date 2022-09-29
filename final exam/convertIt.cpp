#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node* right;
    Node* left;
    Node(int val)
    {
        this->val=val;
        right=NULL;
        left=NULL;
    }
};
void buildTree(Node* &root)
{
    int a;
    cin>>a;
    root=new Node(a);
    queue <Node *>q;
    q.push(root);
    while(!q.empty())
    {
        Node*presentNode=q.front();
        q.pop();
        int x,y;
        cin>>x>>y;
        Node*l=NULL;
        Node*r=NULL;
        if(x!=-1)
        {
            l=new Node(x);
        }
        if(y!=-1)
        {
            r=new Node(y);
        }
        presentNode->left=l;
        presentNode->right=r;
        if(l!=NULL)
        {
            q.push(l);
        }
        if(r!=NULL)
        {
            q.push(r);
        }
    }

}
vector<int> q;
void inOrder(Node*root){
if(root==NULL)return;
//q.push_back(root->val);
inOrder(root->left);
cout<<root->val<<" ";
inOrder(root->right);


}
void preOrder(Node*root){
if(root==NULL)return;
//q.push_back(root->val);
cout<<root->val<<" ";
preOrder(root->left);
//cout<<root->val<<" ";
preOrder(root->right);


}

int main(){

Node* root=NULL;
buildTree(root);

inOrder(root);
cout<<endl;
preOrder(root);
/*priority_queue<int , vector<int> > m;
for(int i=0;i<q.size();i++){
    m.push(q[i]);
}

int t;
cin>>t;
while(t--){
    int option;
    cin>>option;
    if(option==1){
        int val;
        cin>>val;
        m.push(val);
    }
   else if(option==2){
        cout<<m.top()<<endl;
    m.pop();
   }
}*/

}
