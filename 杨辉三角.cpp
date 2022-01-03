#include <iostream>
using namespace std;

class LinkNode {
public:
    int data; //数据域
    LinkNode* link; //指向后继指针的结点
    LinkNode(const int & el)
    {
        data = el;
        link = NULL;
    }
};
class LinkQueue {
private:
    int size;
    LinkNode* front;
    LinkNode* rear;

public:
    LinkQueue()
    {
        size = 0;
        front = rear = NULL;
    }

    ~LinkQueue()
    {
        //Clear();
    }
    //清空队列
    void Clear()
    {
        while (front != NULL) {
            rear = front;
            front = front->link;
            delete rear;
        }
        rear = NULL;
        size = 0;
    }

    bool IsEmpty()
    {
        if (size == 0) {
            cout << "队列为空" << endl;
            return true;
        }
        return false;
    }

    bool EnQueue(const int item)
    {
        if(rear==NULL)
            front=rear=new LinkNode(item);
        else
        {
            LinkNode *p=new LinkNode(item);
            rear->link=p;
            rear=p;
        }
        size++;
        return true;
    }

    int DeQueue()
    {
            int item;

            LinkNode* p=front;
            item=p->data;
            front=p->link;
            delete p;
            if(front==NULL)
                rear=NULL;
            size--;
            return item;
        }


    int GetFront()
    {

            return front->data;
    }
};
int main()
{
    LinkQueue *s=new LinkQueue;
    int j;
    s->EnQueue(1);
    s->EnQueue(0);
    cout<<"输入想要的行数"<<endl;
    cin>>j;
    for(int i=1;i<=j;i++)
    {
        s->EnQueue(s->GetFront());//每一行的第一列
        while(s->GetFront())//检测到0分行
        {
            cout<<s->GetFront()<<" ";
            s->EnQueue(s->DeQueue()+s->GetFront());
        }
        s->DeQueue();//将0退出队列
        s->EnQueue(0);//在下一行末尾加0
        cout<<endl;
    }
    return 0;
}
