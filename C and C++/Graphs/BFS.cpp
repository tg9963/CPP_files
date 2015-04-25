#include<iostream>
#include<list>
using namespace std;

class graph
{
	int v;
	list<int> *adj;
	
	public:
		graph(int v)
		{
			this->v=v;
			adj=new list<int>[v];
		}
		void add_edge(int start,int end)
		{
			adj[end].push_back(start);
		} 
		int bfs(int init)
		{
			bool *visited=new bool[v];
			for(int i=0;i<v;i++)
			{
				visited[i]=false;
			}
			list<int> queue;
			int count=0;
			queue.push_back(0);
			visited[init]=true;
			count++;
			int temp=0;
			while(!queue.empty())
			{
				temp=queue.front();
				queue.pop_front();
				list<int>::iterator i;
				for(i=adj[temp].begin();i!=adj[temp].end();++i)
				{
					if(visited[*i]==false)
					{
						visited[*i]=true;
						queue.push_back(*i);
					}
				}
			}
			return (count);
		}
};

int main()
{
	
	int test;
	cin>>test;
	while(test--)
	{
		int n,m;
		cin>>n>>m;
		graph g(n);
		for(int i=0;i<m;i++)
		{
			int src,dest;
			cin>>src>>dest;
			g.add_edge(src-1,dest-1);	
		}
		cout<<g.bfs(0)<<endl;
	}
	return 0;
}
