#include<iostream>
#include<string.h>
using namespace std;
class person
{
public:
    char*name;
    person *next;
    int num;
    person(const char *p=NULL)
    {
        strcpy(name,p);
        next= NULL;
    }
};
class airline
{
public:
    person *head=NULL;
    int total;
    airline(const int t=0)
    {
        total=t;
    }
    void show()
    {
        person *p=head;
        for(int i=1;i<=total;i++)
        {
            cout<<p->name<<"    ";
            if(i%4==0)
                cout<<endl;
        }
    }
    void book()
    {
        char *n;
        cout<<"请输入你的姓名:";
        cin>>n;
        int flag;
        if(head==NULL)
        {
            person*p=new person(n);
            head=p;
        }
        else
        {
            person *p=new person(n);
            person *s=head;
            while(s->name>=n)
            {
                s->next->next=p->next;
                s->next=p;
            }
        int want;
        cout<<"请输入你要预定的座位号：";
        cin>>want;
        while(p->num!=want)
            p=p->next;
        if(p->name=="none")
        {
            cout<<"已经有人"<<endl;
            return;
        }
        else
        {
            p->name=n;
            cout<<"预定成功"<<endl;
        }
    }
    void cancel()
    {
        int want;
        int flag=1;
        person *p=head;
        char* n=NULL;
        do
        {
            do
            {
                cout<<"请输入你预定的座位号；";
                if(want<0||want>a->total)
                {
                    flag=0;
                    cout<<"错误的座位号"<<endl;
                }
            }while(flag==1);
            while(p->num!=want)
                p=p->next;
            p->name;
            cout<<"确认你的姓名："<<n<<endl;
            cout<<"确认请按1,错误请按0"<<endl;
            cin>>flag;
        }while(flag!=1);
        char *fix="none";
        p->name=fix;
        delete n;
        cout<<"退订成功"<<endl;
    }
    bool find()
    {
        int flag=1;
        int want;
        do
        {
            cout<<"请输入想要查询的座位号";
            cin>>want;
            if(want<0||want>a->total)
            {
                flag=0;
                cout<<"错误的座位号"<<endl;
            }
        }while(flag==1);
        person *p=a->head;
        while(p->num!=want)
            p=p->next;
        if(p->name!="none")
        {
            cout<<"已经有人"<<endl;
            return true;
        }
        else
            return false;
    }
    void show()
    {
        int flag;
        cout<<"预定机票请按1"<<endl;
        cout<<"取消预定请按2"<<endl;
        cout<<"查询机票请按3"<<endl;
        cout<<"显示乘客请按4"<<endl;
        cout<<"退出请按5"<<endl;
        cin>>flag;
        if(flag==1)
            book();
        else if(flag==2)
            cancel();
        else if(flag==3)
            find();
        else if(flag==4)
            a->show();
        else
            return;
        show();
    }
};
int main()
{
    UI *i=new UI();
    i->show();
    return 0;
}

