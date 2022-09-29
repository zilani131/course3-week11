#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    char val;
    Node* right;
    Node* left;

    Node(char val)
    {
        this->val=val;

        right=NULL;
        left=NULL;
    }
};
void buildTree(Node* &root,string z)
{
    int a;
    cin>>a;
    root=new Node(z[a]);
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
            l=new Node(z[x]);

        }
        if(y!=-1)
        {
            r=new Node(z[y]);

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
/*void printTreeOrdering(Node* root,int l)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        cout<<root->val;
    }
    else
    {
        cout<<endl;
        spacePrint(l);

        cout<<"Root : "<<root->val;

    }
    if(root->left)
    {
        cout<<endl;
        spacePrint(l);
        cout<<"Left : ";
        printTreeOrdering(root->left,l+1);
    }

    if(root->right)
    {
        cout<<endl;
        spacePrint(l);
        cout<<"Right : ";

        printTreeOrdering(root->right,l+1);
    }
}*/
string  a ;


//vector<string>q;
void inOrder(Node*root,vector <string >&q,string current)
{
    if(root==NULL)
    {

        return;
    }

    current+=root->val;
    if(root->left==NULL&&root->right==NULL)
    {
        q.push_back(current);

        return;
    }

    inOrder(root->left,q,current);


//cout<<root->val<<" ";

    inOrder(root->right,q,current);


    return;
}
vector<string>path(Node *root)
{
    string current;
    vector<string > q;
    inOrder(root,q,current);
   /* for(int i=0; i<q.size(); i++)
    {
        cout<<q[i]<<" ";
    }*/
    return q;

}
bool palindrome(string a){
string b=a;
reverse(b.begin(),b.end());
if(b==a){
    return true;
}
return false;

}
int main()
{
    string s;
    cin>>s;
    Node*root=NULL;
    buildTree(root,s);
    //inOrder(root);

    vector<string > ans=path(root);
    int ctn=0;
    for(int i=0;i<ans.size();i++){
        if(palindrome(ans[i])){
            ctn++;
        }

    }
    cout<<ctn;
}
