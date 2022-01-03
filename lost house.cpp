#include<iostream>
using namespace std;
class node
{
public:
    int i;
    int j;
    node *link;
    node(int a,int b,node*p=NULL)
    {
        i=a;
        j=b;
        link=p;
    }
};
class LinkStack {
public:
    LinkStack()
    {
        top = NULL;
        size = 0;
    }
    ~LinkStack()
    {
        Clear();
    }
    void Clear()
    {
        while (top != NULL) {
            node* tmp = top;
            top = top->link;
            cout<<"("<<tmp->i<<","<<tmp->j<<")"<<endl;
            delete tmp;
        }
        size = 0;
    }


    bool Push(const int a,const int b)
    {
        node *p=new node(a,b,top);
        top=p;
        size++;
        return true;
    }

    bool Pop(int &a,int &b)
    {
        if(size!=0)
        {
            top=top->link;
            a=top->i;
            b=top->j;
            size--;
            return true;
        }
        else
            return false;
    }
    private:
    node* top; //指向链式栈栈顶的指针
    int size; //栈中元素个数
};
int main()
{
    int mg[10][10]={
 {1,1,1,1,1,1,1,1,1,1},
 {1,0,0,1,0,0,1,1,0,1},
 {1,0,0,1,0,0,0,1,0,1},
 {1,0,0,0,0,1,1,0,0,1},
 {1,0,1,1,1,0,0,0,0,1},
 {1,0,0,0,1,0,0,0,0,1},
 {1,0,1,0,0,0,1,0,0,1},
 {1,0,1,1,1,0,1,1,0,1},
 {1,1,0,0,0,0,0,0,0,1},
 {1,1,1,1,1,1,1,1,1,1}
};
    int m=1;
    int n=1;
    LinkStack *s=new LinkStack;
    s->Push(1,1);
    while(m!=8||n!=8)
    {
        if(mg[m+1][n]==0)
        {
            mg[m][n]=1;
            s->Push(++m,n);
        }
        else if(mg[m][n+1]==0)
        {
            mg[m][n]=1;
            s->Push(m,++n);
        }
        else if(mg[m-1][n]==0)
        {
            mg[m][n]=1;
            s->Push(--m,n);
        }
        else if(mg[m][n-1]==0)
        {
            mg[m][n]=1;
            s->Push(m,--n);
        }
        else
        {
            mg[m][n]=1;
            s->Pop(m,n);
        }
    }
    s->Clear();
    return 0;
}
