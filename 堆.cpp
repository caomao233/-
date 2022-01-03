#include<iostream>
using namespace std;
template <class T>
class MaxHeap
{
private:
    T* heap;
    int Size;
    int MaxSize;
public:
    MaxHeap(T* a,int num,int max)
    {
        heap=a;
        Size=num;
        MaxSize=max;
        toheap();
    }
    bool upswap(int i)
    {
        T t;
        if(2*i+2>Size-1)
        {
            if(heap[i]<heap[2*i+1])
            {
                t=heap[i];
                heap[i]=heap[2*i+1];
                heap[2*i+1]=t;
                return true;
            }
            else
                return false;
        }
        else
        {
            int p;
            if(heap[2*i+1]>heap[2*i+2])
                p=2*i+1;
            else
                p=2*i+2;
            if(heap[p]>heap[i])
            {
                t=heap[i];
                heap[i]=heap[p];
                heap[p]=t;
                upswap(p);
                return true;
            }
            else
                return false;
        }
    }
    void toheap()//É¸Ñ¡·¨
    {
        for(int i=Size/2-1;i>=0;i--)
        {
            upswap(i);
        }
    }
    void add(T a)//²åÈë
    {
        if(Size-1>=MaxSize)
        {
            cout<<"full"<<endl;
        }
        else
        {
            Size++;
            heap[Size-1]=a;
            for(int dad=Size/2-1;upswap(dad)&&dad>0;dad=(dad-1)/2);
        }
    }
    void del(int i)
    {
        if(i==Size-1)
            Size--;
        else
        {
            T t;
            int p;
            t=heap[i];
            heap[i]=heap[Size-1];
            heap[Size-1]=t;
            Size--;
            while(i<=Size/2-1)
            {
                if(2*i+2>Size-1)
                {
                    if(heap[i]<heap[2*i+1])
                    {
                        t=heap[i];
                        heap[i]=heap[2*i+1];
                        heap[2*i+1]=t;
                        i=2*i+1;
                    }
                    else
                        return;
                }
                else
                {
                    if(heap[2*i+1]<heap[2*i+2])
                        p=2*i+2;
                    else
                        p=2*i+1;
                    if(heap[i]<heap[p])
                    {
                        t=heap[i];
                        heap[i]=heap[p];
                        heap[p]=t;
                        i=p;
                    }
                    else
                        return;
                }
            }
        }
    }
    void print()
    {
        for(int i=0;i<=Size-1;i++)
            cout<<heap[i]<<"    ";
        cout<<endl;
    }
    void rush()
    {
        int s=Size;
        while(Size>0)
        {
            del(0);
        }
        Size=s;
    }
};
int main()
{
    int a[10]={5,4,6,7,3,8,9};
    MaxHeap<int>* h=new MaxHeap<int>(a,7,10);
    h->print();
    h->add(10);
    h->print();
    h->del(2);
    h->print();
    h->rush();
    h->print();
}
