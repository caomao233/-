#include<iostream>
#include<stack>
#include<queue>

using namespace std;
class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;//左孩子节点
    BinaryTreeNode *right;//右孩子节点
    BinaryTreeNode(const int& ele=0,BinaryTreeNode *l=NULL,BinaryTreeNode*r=NULL)
    {
        data=ele;
        left=l;
        right=r;
    }
};
class BinaryTree
{

public:
    void levelOrder(BinaryTreeNode* root)//广度遍历
    {
        queue<BinaryTreeNode*>que;
        BinaryTreeNode *p=root;
        if(p)
            que.push(p);
        while(!que.empty())
        {
            p=que.front();
            cout<<p->data<<"  ";
            que.pop();
            if(p->left)
                que.push(p->left);
            if(p->right)
                que.push(p->right);
        }
    }
    void preOrder0(BinaryTreeNode* p)
    {
        if(p)
        {
            cout<<p->data<<"  ";
            preOrder0(p->left);
            preOrder0(p->right);
        }
    }
    void inOrder0(BinaryTreeNode* p)
    {
        if(p)
        {
            inOrder0(p->left);
            cout<<p->data<<"  ";
            inOrder0(p->right);
        }

    }
    void postOrder0(BinaryTreeNode* p)
    {
        if(p)
        {
            postOrder0(p->left);
            postOrder0(p->right);
            cout<<p->data<<"  ";
        }
    }
    void preOrder1(BinaryTreeNode* root)
    {
        stack<BinaryTreeNode*>s;
        BinaryTreeNode* p=root;
        while(!s.empty()||p)
        {
            if(p)
            {
                cout<<p->data<<"  ";
                if(p->right)
                    s.push(p->right);
                p=p->left;
            }
            else
            {
                p=s.top();
                s.pop();
            }
        }
    }
    void inOrder1(BinaryTreeNode* root)
    {
        stack<BinaryTreeNode*>s;
        BinaryTreeNode *p=root;
        while(!s.empty()||p)
        {
            if(p)
            {
                s.push(p);
                p=p->left;
            }
            else
            {
                p=s.top();
                cout<<p->data<<"  ";
                p=p->right;
                s.pop();
            }
        }
    }
    void postOrder1(BinaryTreeNode* root)
    {
        stack<BinaryTreeNode*>s;
        BinaryTreeNode*p=root;
        BinaryTreeNode*pre=root;
        while(p)
        {
            for(;p->left;p=p->left)
                s.push(p);
            while(p&&p->right==NULL||p->right==pre)
            {
                cout<<p->data<<"  ";
                pre=p;
                if(s.empty())
                    return;
                p=s.top();
                s.pop();
            }
            s.push(p);
            p=p->right;
        }
    }
    BinaryTreeNode* build(int *pre,int* in,int prestart,int preend,int instart,int inend)//前序和中序
    {
        BinaryTreeNode *root =new BinaryTreeNode(pre[prestart]);
        if(prestart==preend&&instart==inend)
            return root;
        int i;
        for(i=instart;in[i]==pre[prestart];i++);
        int leftlength=i-instart;
        int rightlength=inend-i;
        if(leftlength>0)
            root->left=build(pre,in,prestart+1,prestart+leftlength,instart,i-1);
        if(rightlength>0)
            root->right=build(pre,in,prestart+leftlength+1,preend,i+1,inend);
        return root;
    }
};
int main()
{
    BinaryTree* t;
    BinaryTreeNode* a=new BinaryTreeNode(1);
    BinaryTreeNode* b=new BinaryTreeNode(2);
    BinaryTreeNode* c=new BinaryTreeNode(3);
    BinaryTreeNode* d=new BinaryTreeNode(4);
    BinaryTreeNode* e=new BinaryTreeNode(5);
    BinaryTreeNode* f=new BinaryTreeNode(6);
    BinaryTreeNode* g=new BinaryTreeNode(7);
    BinaryTreeNode* h=new BinaryTreeNode(8);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    d->right=f;
    c->left=g;
    c->right=h;
    cout<<"     1       "<<endl;
    cout<<"   2     3   "<<endl;
    cout<<" 4   5  7  8 "<<endl;
    cout<<"   6         "<<endl;
    t->levelOrder(a);
    cout<<endl;
    t->preOrder0(a);
    cout<<endl;
    t->preOrder1(a);
    cout<<endl;
    t->inOrder0(a);
    cout<<endl;
    t->inOrder1(a);
    cout<<endl;
    t->postOrder0(a);
    cout<<endl;
    t->postOrder1(a);
    cout<<endl;
    int pre[10]={1,2,4,6,7,3,5,8};
    int in[10]={2,6,4,7,1,3,5,8};
    t->preOrder0(t->build(pre,in,0,7,0,7));
}
