#include <iostream>
using namespace std;

class LinkNode {
public:
    int data; //������
    LinkNode* link; //ָ����ָ��Ľ��
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
    //��ն���
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
            cout << "����Ϊ��" << endl;
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
    cout<<"������Ҫ������"<<endl;
    cin>>j;
    for(int i=1;i<=j;i++)
    {
        s->EnQueue(s->GetFront());//ÿһ�еĵ�һ��
        while(s->GetFront())//��⵽0����
        {
            cout<<s->GetFront()<<" ";
            s->EnQueue(s->DeQueue()+s->GetFront());
        }
        s->DeQueue();//��0�˳�����
        s->EnQueue(0);//����һ��ĩβ��0
        cout<<endl;
    }
    return 0;
}
