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
        cout<<"�������������:";
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
        cout<<"��������ҪԤ������λ�ţ�";
        cin>>want;
        while(p->num!=want)
            p=p->next;
        if(p->name=="none")
        {
            cout<<"�Ѿ�����"<<endl;
            return;
        }
        else
        {
            p->name=n;
            cout<<"Ԥ���ɹ�"<<endl;
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
                cout<<"��������Ԥ������λ�ţ�";
                if(want<0||want>a->total)
                {
                    flag=0;
                    cout<<"�������λ��"<<endl;
                }
            }while(flag==1);
            while(p->num!=want)
                p=p->next;
            p->name;
            cout<<"ȷ�����������"<<n<<endl;
            cout<<"ȷ���밴1,�����밴0"<<endl;
            cin>>flag;
        }while(flag!=1);
        char *fix="none";
        p->name=fix;
        delete n;
        cout<<"�˶��ɹ�"<<endl;
    }
    bool find()
    {
        int flag=1;
        int want;
        do
        {
            cout<<"��������Ҫ��ѯ����λ��";
            cin>>want;
            if(want<0||want>a->total)
            {
                flag=0;
                cout<<"�������λ��"<<endl;
            }
        }while(flag==1);
        person *p=a->head;
        while(p->num!=want)
            p=p->next;
        if(p->name!="none")
        {
            cout<<"�Ѿ�����"<<endl;
            return true;
        }
        else
            return false;
    }
    void show()
    {
        int flag;
        cout<<"Ԥ����Ʊ�밴1"<<endl;
        cout<<"ȡ��Ԥ���밴2"<<endl;
        cout<<"��ѯ��Ʊ�밴3"<<endl;
        cout<<"��ʾ�˿��밴4"<<endl;
        cout<<"�˳��밴5"<<endl;
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

