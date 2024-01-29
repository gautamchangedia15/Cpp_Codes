#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};


node* buildTree(node *root){
    int data;
    cout<<"Enter data to insert: ";
    cin>>data;

    if(data==-1)
        return NULL;

    root=new node(data);
   
    cout<<"Enter data to insert to left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data to insert to right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}


void buildTreeFromLevel(node* &root){
    queue<node*> q;
    int data,leftData,rightData;

    cout<<"Enter data of root: ";
    cin>>data;
    root=new node(data);

    q.push(root);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        cout<<"enter data for left node of "<<temp->data<<" :";
        cin>>leftData;

        if(leftData!=-1){
            temp->left=new node(leftData);
            q.push(temp->left);
        }

        cout<<"enter data for right node of "<<temp->data<<" :";
        cin>>rightData;

        if(rightData!=-1){
            temp->right=new node(rightData);
            q.push(temp->right);
        }
    }
    return;
}



void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);   //to show that level 0 is completed. It is just a delimiter

    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        if(temp==NULL)
        {
            //purana level pura transfer ho chuka hai
            cout<<endl;
            if(!q.empty()){
                //parent node hogaye but aabhi bhe uske child node baki hai
                q.push(NULL);
            }
        }

        else{
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }

}



void reverseLevelOrderTraversal(node* root){
    stack<node*>s;
    queue<node*> q;
    q.push(root);
    q.push(NULL);   //to show that level 0 is completed

    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        s.push(temp);

        if(temp==NULL)
        {
            //purana level pura transfer ho chuka hai
            if(!q.empty()){
                //parent node hogaye but aabhi bhe child node hai
                q.push(NULL);
            }
        }

        else{
            
            if(temp->right)
                q.push(temp->right);
            if(temp->left)
                q.push(temp->left);
        }
    }


        while(!s.empty()){
            node* temp=s.top();
            if(temp!=NULL)
                cout<<temp->data<<" ";
            else
                cout<<endl;
            s.pop();
        }
}



void inorder(node* root){
    if(root==NULL)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){
    if(root==NULL)
        return;
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root==NULL)
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}


void morrisTraversal(node* curr){
    while(curr!=NULL){

        if(curr->left==NULL){
            cout<<curr->data<<" ";
            curr=curr->right;
        }

        else{
            node* prec=curr->left;
            while(prec->right!=NULL && prec->right!=curr)
                prec=prec->right;
            
            if(prec->right==NULL){
                prec->right=curr;
                //cout<<curr->data<<" ";    //for preorder
                curr=curr->left;
            }

            else{
                prec->right=NULL;
                cout<<curr->data<<" "; //for inorder
                curr=curr->right;
            }
        }
    }

    cout<<endl;
    return;
}


int main()
{
    node* root=NULL;
    //root=buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    buildTreeFromLevel(root);
    cout<<"\nLevel Order Traversal"<<endl;
    levelOrderTraversal(root);
    cout<<"\nReverse Level Order Traversal";
    reverseLevelOrderTraversal(root);

    cout<<"\nInorder: ";
    inorder(root);

    cout<<"\nPostorder:  ";
    postorder(root);

    cout<<"\nPreorder ";
    preorder(root);


    cout<<"\nMories Inorder Traversal: ";
    morrisTraversal(root);

    return 0;
}