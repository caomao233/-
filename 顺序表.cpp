#include<iostream>
using namespace std;
template <class T>
class ArrayList
{
public:
    ArrayList(const int size)
    {
        maxSize = size;
        arrayList =new T[maxSize];
        curLen=0;
        position = 0;
    }
    ~ArrayList()
    {
        delete[]arrayList;
    }
    void clear()
    {
        delete[]arrayList;
        curLen=0;
        position=0;
        arrayList=new T[maxSize];
    }
    void print()
    {
        for(int i=0;i<curLen;i++)
            cout<<arrayList[i]<<"   ";
        cout<<endl;
    }
    int length();
    bool append(const T value);
    bool insert(const int p,const T value);
    bool Delete(const int p);
    bool GetValue(const int p, T&value);
    bool SetValue(const int p, const T value);
    bool GetPos(int &P,const T value);
private:
    T *arrayList;
    int maxSize;
    int curLen;
    int position;
};
template <class T>
bool ArrayList<T>::insert(const int p,const T value)//
{
    if(curLen>=maxSize)
    {
        cout<<"the list is overflow"<<endl;
        return false;
    }
    if(p<0||p>curLen)
    {
        cout<<"Insertion point is illegal"<<endl;
        return false;
    }
    for(int i=curLen;i>p;i--)
    {
        arrayList[i]=arrayList[i-1];
    }
    arrayList[p]=value;
    curLen++;
    return true;
}
template <class T>
bool ArrayList<T>::Delete(const int p)
{
    if(curLen<=0)
    {
        cout<<"NO element to delete"<<endl;
        return false;
    }
    if(p<0||p>curLen-1)
    {
        cout<<"Deletion is illegal"<<endl;
        return false;
    }
    for(int i=p;i<curLen-1;i++)
    {
        arrayList[i]=arrayList[i+1];
    }
    curLen--;
    return true;
}
template <class T>
bool ArrayList<T>::append(const T value)
{
    if(curLen>=maxSize)
    {
        cout<<"the list is overflow"<<endl;
        return false;
    }
    arrayList[curLen]=value;
    curLen++;
    return true;
}
template <class T>
bool ArrayList<T>::GetValue(const int p, T&value)
{
    if(p<0||p>=curLen)
    {
        cout<<"Getting point is illegal"<<endl;
        return false;
    }
    value=arrayList[p];
    return true;
}
template <class T>
bool ArrayList<T>::SetValue(const int p, const T value)
{
    if(p<0||p>=curLen)
    {
        cout<<"Setting point is illegal"<<endl;
        return false;
    }
    arrayList[p]=value;
    return true;
}
template <class T>
bool ArrayList<T>::GetPos(int &P,const T value)
{
    int i;
    for(i=0;i<curLen;i++)
    {
        if(arrayList[i]==value)
        {
            P=i;
            return true;
        }
    }
    return false;
}
int main()
{
    ArrayList<int> a(10);
    a.append(1);
    a.print();
    a.append(2);
    a.print();
    a.insert(1,3);
    a.print();
    a.Delete(2);
    a.print();
    return 0;
}
