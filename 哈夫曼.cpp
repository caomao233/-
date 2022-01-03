#include<iostream>
#include<string>
using namespace std;
struct Htnode{
	int weight,parent,lchild,rchild;
	char c;
};
struct Htcode{
	int bit[25],start;
};
int type(int a[]){
	string s;
	int sum = 0;
	cout<<"输入需要编码的字符串"<<endl;
	cin>>s;
	for(int i = 0; i < s.size(); i++){
		a[s[i]-'A']++;
	}
	cout<<"出现的字母种类以及次数:"<<endl;
	for(int i = 0; i < 26; i++){
		if(a[i] != 0){
			char c = char(i+'A');
			cout<<"i:"<<i<<" c:"<<c<<":"<<a[i]<<endl;
			sum++;
		}
	}
	return sum;//返回总的叶子节点的个数
}
//通过数组的方式构建哈夫曼树
void HufmanTree(Htnode h[],int n, int a[]){
	int i,j,max1,max2,x1,x2;
	for(i=0;i<2*n;i++){
		h[i].weight=0;
		h[i].parent=-1;
		h[i].lchild=-1;
		h[i].rchild=-1;
		h[i].c='0';
	}
	for(i=0;i<26;i++){
		if(a[i] != 0){
			h[i].c = i + 'A';
			h[i].weight = a[i];
		}
	}
	for(i=0;i<n-1;i++){
		max1=1000,max2=1000;
		x1=-1,x2=-1;
		for(j=0;j<n+i;j++){
			if(h[j].weight<max1 && h[j].parent==-1){
				max2=max1;
				x2=x1;
				max1=h[j].weight;
				x1=j;
			}else if(h[j].weight<max2 && h[j].parent==-1){
				max2=h[j].weight;
				x2=j;
			}
		}
		//根据每个节点信息, 将其信息存储到节点数组中
		h[x1].parent=n+i; h[x2].parent=n+i;
		h[n+i].weight=h[x1].weight+h[x2].weight;
		h[n+i].lchild=x1;h[n+i].rchild=x2;
	}
	for (i=0;i<2*n-1;i++){
		cout<<h[i].weight<<" "<<h[i].parent<<" "<<h[i].lchild<<" "<<h[i].rchild<<" "<<h[i].c<<endl;
	}

}
//哈夫曼编码
//根据叶子节点的位置, 将其path路径01数字填充到编码数组中
void  HuffmandeCode(Htnode h[], int n, int a[], Htcode hcode[]){
	HufmanTree(h, n, a);
	int i,j;
	for(i=0;i<n;i++){
		j=0;
		int parent=h[i].parent;//记录当前节点的父亲
		int c=i;
		while(c!=-1){//parent造成根节点不会被访问
			hcode[i].bit[j++]=h[parent].lchild==c?0:1;//从叶子节点到根节点, 应该使用栈结构
			c=parent;
			parent=h[parent].parent;
		}
		hcode[i].start=j-1;
	}
	for(i=0;i<n;i++){
		cout<<h[i].c<<":";
		for(j=hcode[i].start-1;j>=0;j--){
			cout<<hcode[i].bit[j];
		}
		cout<<endl;
	}
}
//哈夫曼译码
void  HuffmanenCode(int s[],int n,Htnode h[]){
	int i=0,j=2*n-2;
	while(i<8){
		if(s[i]==0){
			j=h[j].lchild;

		}
		if(s[i]==1){
			j=h[j].rchild;

		}
		if(h[j].rchild==-1){
			cout<<h[j].c;
			j=2*n-2;

		}
		i++;
	}
}
int main(){
	Htnode h[30];
	Htcode hcode[10];
	int a[26]={0};
	int n = type(a);
	cout<<"n:"<<n<<endl;
	HuffmandeCode(h, n, a, hcode);
	int s[8]={1,0,0,0,1,1,0,1};
	HuffmanenCode(s,n,h);
	return 0;
}
