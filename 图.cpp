#include <iostream>
#include <queue>
#include <stack>
using namespace std;
template<class EdgeType>
class Edge
{
public:
	int start, end;//起点、终点
	Edge()
	{
		start = -1;
		end = -1;
	}
	Edge(int st, int en)
	{
		start = st;
		end = en;
	}
};
template<class EdgeType>
class Graph
{
public:
	int vertexNum;//顶点数目
	int edgeNum;//边数目
	int* Mark;
	Edge<EdgeType>* e;
	Graph(int verticesNum)
	{
		e = new Edge<EdgeType>[100];
		vertexNum = verticesNum;
		edgeNum = 0;
		Mark = new int[vertexNum];
		for (int i = 0;i < vertexNum;i++)
		{
			Mark[i] = 0;//没访问过
		}
	}
	~Graph()
	{
		delete[]Mark;
	}
	void setEdge(int i,int st,int ed)
	{
		Edge<EdgeType> tmpEdge(-1,-1);
		tmpEdge.start = st;
		tmpEdge.end = ed;
		e[i] = tmpEdge;
		edgeNum++;
	}
	Edge<EdgeType> FirstEdge(int oneVertex)//返回与顶点相关联的第一条边
	{
		for (int i = 0;i < edgeNum;i++)
		{
			Edge<EdgeType> tmpEdge = e[i];
			if ((tmpEdge.start == oneVertex&&Mark[tmpEdge.end]==0) || (tmpEdge.end == oneVertex && Mark[tmpEdge.start] == 0))
				return tmpEdge;
		}
	}
	Edge<EdgeType> NextEdge(Edge<EdgeType> oneEdge)//返回下一条边
	{
		int st = oneEdge.start;
		int ed = oneEdge.end;
		for (int i = 0;i < edgeNum;i++)
		{
			Edge<EdgeType> tmpEdge=e[i];
			if (tmpEdge.start == st||tmpEdge.end==st||tmpEdge.start==ed||tmpEdge.end==ed)
			{
				return tmpEdge;
			}
		}
	}
	bool isEdge(Edge<EdgeType> oneEdge)
	{
		for (int i = 0;i < edgeNum;i++)
		{
			Edge<EdgeType> tmpEdge=e[i];
			if (Mark[tmpEdge.start] == 1 && Mark[tmpEdge.end] == 0)
				return false;
			if (tmpEdge.start == oneEdge.start && tmpEdge.end == oneEdge.end)
			{
				return true;
			}
		}
		return false;
	}


	int DFS(int v)
	{
		Mark[v] = 1;
		cout << v;
		for (Edge<EdgeType> e = FirstEdge(v);isEdge(e);e = NextEdge(e))
		{
			if (Mark[e.end] == 0)
			{
				DFS(e.end);
			}
		}
		return 0;
	}
	void DFSTraverse()
	{
		cout << "深度:" << endl;
		for (int i = 0;i < vertexNum;i++)
			Mark[i] = 0;
		for (int i = 0;i < vertexNum;i++)
			if (Mark[i] == 0)
				DFS(i);
	}
	void DFSNOReverse()
	{
		int i,v,u;
		stack<int>s;
		for(i=0;i<vertexNum;i++)
			Mark[i]=0;
		for(i=0;i<vertexNum;i++)
		{
			if(Mark[i]==0)
			{
				s.push(i);
				cout<<i<<endl;
				Mark[i]=1;
				while(!s.empty())
				{
					v=s.pop();
					for(Edge<EdgeType> e=FirstEdge(v);isEdge(e);e=NextEdge(e))
					{
						u=EndVertex(e);
						if(Mark[u]==0)
						{
							s.push(u);
							cout<<i<<endl;
							Mark[i]=1;
						}
					}
				}
			}
		}
	}
	void BFS(int v)
	{
		queue<int> q;
		Mark[v] = 1;
		cout << v ;
		q.push(v);
		stop:
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			Edge<EdgeType>m = FirstEdge(x);
			while(true)
			{
				if (m.end == x)
				{
					int u = Mark[m.start];
					if (u == 0)
					{
						cout << m.start;
						Mark[m.start] = 1;
						q.push(m.start);
					}
				}
				if (m.start == x)
				{
					int u = Mark[m.end];
					if (u == 0)
					{
						cout << m.end;
						Mark[m.end] = 1;
						q.push(m.end);
					}
				}
				int flag = 0;
			    for (int i = 0;i < edgeNum;i++)
				{

					Edge<EdgeType> tmpEdge = e[i];
					if ((tmpEdge.start == x || tmpEdge.end == x) && !(m.start==tmpEdge.start&&m.end==tmpEdge.end)&&(Mark[tmpEdge.end]==0||Mark[tmpEdge.start]==0))
					{
						m = tmpEdge;
						flag = 1;
					}
				}
				if (flag == 0)
					break;

			}

		}
	}
	void BFSTraverse()
	{
		cout << "广度:" << endl;
		int i;
		for (i = 0;i < vertexNum;i++)
		{
			Mark[i] = 0;
		}
		for (i = 0;i < vertexNum;i++)
		{
			if (Mark[i] == 0)
				BFS(i);
		}
	}
	void print()
	{
		for (int i = 0;i < edgeNum;i++)
		{
			Edge<EdgeType> tmpEdge = e[i];
			cout << tmpEdge.start << tmpEdge.end << endl;
		}
	}
};
template<class EdgeType>
class AdjGraph//邻接矩阵
{
public:
	int vertexNum=0;
	int** matrix;
	int edgeNum=0;
	AdjGraph(int verticesNum)
	{
		vertexNum = verticesNum;
		int i=0, j=0;
		matrix = (int**)new int* [verticesNum];
		for (i = 0;i < verticesNum;i++)
		{
			matrix[i] = new int[verticesNum];
		}
		for (i = 0;i < verticesNum;i++)
		{
			for (j = 0;j < verticesNum;j++)
			{
				matrix[i][j] = 0;
			}
		}
	}
	~AdjGraph()
	{
		for (int i = 0;i < vertexNum;i++)
		{
			delete [] matrix[i];
		}
		delete [] matrix;
	}
	Edge<EdgeType> FirstEdge(int oneVertex)
	{
		Edge<EdgeType> tmpEdge;
		tmpEdge.start = oneVertex;
		for (int i = 0;i < vertexNum;i++)
		{
			if (matrix[oneVertex][i] != 0)
			{
				tmpEdge.end = i;
				break;
			}
		}
		return tmpEdge;
	}
	Edge<EdgeType> NextEdge(Edge<EdgeType> oneEdge)
	{
		Edge<EdgeType> tmpEdge;
		tmpEdge.start = oneEdge.start;
		for (int i = oneEdge.end + 1;i < vertexNum;i++)
		{
			tmpEdge.end = i;
			break;
		}
		return tmpEdge;
	}
	void setEdge(int start, int end)
	{
		if (matrix[start][end] == 0)
		{
			edgeNum++;
		}
		matrix[start][end] = 1;
	}
	void delEdge(int start, int end)
	{
		if (matrix[start][end] != 0)
		{
			edgeNum--;
		}
		matrix[start][end] = 0;
	}
	void print()
	{
		int i, j;
		for (i = 0;i < vertexNum;i++)
		{
			for (j = 0;j < vertexNum;j++)
			{
				cout << matrix[i][j];
			}
			cout << endl;
		}
	}
};
template<class EdgeType>
class listData
{
public:
	int vertex;//边的终点
	EdgeType weight;
};
template<class Elem>
class ListNode
{
public:
	Elem element;//边节点的数据
	ListNode<Elem>* next;//边节点指针
	ListNode(const Elem& elemval, ListNode<Elem>* nextval = NULL)
	{
		element = elemval;
		next = nextval;
	}
	ListNode(ListNode<Elem>* nextval = NULL)
	{
		next = nextval;
	}
};
template<class Elem>
class EdgeList //每个顶点所关联的边表
{
public:
	ListNode<Elem>* head;
	EdgeList()
	{
		head = new ListNode<Elem>();
	}
	~EdgeList()
	{
		ListNode<Elem>* tmp;
		while (head != NULL)
		{
			tmp = head;
			head = head->next;
			delete tmp;
		}
	}
};
template<class EdgeType>
class ListGraph
{
public:
	EdgeList<listData<EdgeType> >* graList;//保存所有边表的数组
	ListGraph(int verticesNum)
	{
		graList = new EdgeList<listData<EdgeType> >[verticesNum];
	}
	~ListGraph()
	{
		delete[]graList;
	}

	Edge<EdgeType> FirstEdge(int oneVertex)//返回顶点的第一条边
	{
		Edge<EdgeType> tmpEdge;
		tmpEdge.start = oneVertex;
		EdgeList<EdgeType> pointer = graList[oneVertex];
		ListNode<listData<EdgeType> >* temp = pointer.head;
		if (temp->next != NULL)
		{
			tmpEdge.end = temp->next->element.vertex;
			tmpEdge.weight=temp->next->element.weight;
		}
		return tmpEdge;
	}
	Edge<EdgeType> NextEdge(Edge<EdgeType> oneEdge)//返回与边oneEdge有相同关联顶点的下一条边
	{
		Edge<EdgeType> tmpEdge;
		tmpEdge.start = oneEdge.start;
		EdgeList<EdgeType> pointer = graList[oneEdge.start];
		ListNode<listData<EdgeType> >* temp = pointer.head;
		while (temp->next != NULL && temp->next->element.vertex <= oneEdge.end)
			temp = temp->next;
		if (temp->next != NULL)
		{
			tmpEdge.end = temp->next->element.vertex;
            tmpEdge.weight=temp->next->element.weight;
		}
		return tmpEdge;
	}
	void setEdge(int start, int end,EdgeType weight)
	{
		EdgeList<listData<EdgeType> > pointer = graList[start];
		ListNode<listData<EdgeType> >* temp = pointer.head;
		while (temp->next != NULL && temp->next->element.vertex < end)
			temp = temp->next;
		if (temp->next == NULL)//边不存在且其后无其他边
		{
			temp->next = new ListNode<listData<EdgeType> >;
			temp->next->element.vertex = end;
			temp->next->element.weight = weight;
			return;
		}
		if (temp->next->element.vertex == end)//边已存在
		{
		    temp->next->element.weight = weight;
			return;
		}
		if (temp->next->element.vertex > end)//边不存在，但其后存在其他边
		{
			ListNode<listData<EdgeType> >* other = temp->next;
			temp->next = new ListNode<listData<EdgeType> >;
			temp->next->element.vertex = end;
			temp->next->element.weight = weight;
			temp->next->next = other;
		}
	}
	void print()
	{
		int i=0, j;
		while (i<5)
		{
			ListNode<listData<EdgeType> >* p = graList[i].head;
			cout <<i<<" ";
			while(p->next)
            {
                cout<<"->"<<p->next->element.vertex<<"  "<<p->next->element.weight;
                p=p->next;
            }
            cout<<endl;
			i++;
		}
	}
};
int main()
{
    ListGraph<int> c(5);
	c.setEdge(0, 1,0);
	c.setEdge(1, 2,1);
	c.setEdge(2, 3,2);
	c.setEdge(3, 4,3);
	c.setEdge(4, 2,4);
	c.setEdge(4, 1,5);
    c.print();
	AdjGraph<int> a(5);
	a.setEdge(0, 1);
	a.setEdge(1, 2);
	a.setEdge(2, 3);
	a.setEdge(3, 4);
	a.setEdge(4, 2);
	a.setEdge(4, 1);
	a.print();
	Graph<int> b(5);
	b.setEdge(0, 0, 1);
	b.setEdge(1, 1, 2);
	b.setEdge(2, 2, 3);
	b.setEdge(3, 3, 4);
	b.setEdge(4, 4, 2);
	b.setEdge(5, 4, 1);
	b.BFSTraverse();
	cout << endl;
	b.DFSTraverse();
	cout << endl;
	return 0;
}

