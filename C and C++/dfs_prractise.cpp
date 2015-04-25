#include<iostream>
#include<list>
using namespace std;
int v;
class graph
{
	int n;
	list<int> *adj;
	public:
		graph(){
		}
		graph(int a)
		{
			n=a;
			adj=new list<int>[a];
		}
		void add_edge(int src,int dest)
		{
			adj[src].push_back(dest);
		}
		void DFS(int src)
		{
			bool visited[n];
			for(int i=0;i<n;i++)visited[i]=false;
			for(int i=0;i<n;i++)
			{
				if(visited[i]==false)
				{
					dfs_util(i,visited);
				}
			}
			
		}
		
		void dfs_util(int src,bool visited[])
		{
			visited[src]=true;
			cout<<src<<"  ";
			list<int>::iterator it;
			for(it=adj[src].begin();it!=adj[src].end();it++)
			{
				if(visited[*it]==false)
				{
				dfs_util(*it,visited);
				}
			}
		}
};


int main()
{
	v=5;
	graph g(v);
	
	g.add_edge(0,1);
	g.add_edge(4,3);
	graph g2(v+1);
	g2.add_edge(6,1);
	g2.DFS(0);
	return 0;
}
