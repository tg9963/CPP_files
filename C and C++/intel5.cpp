#include<iostream>
#include<list>
using namespace std;

class graph
{
	int v;
	list<int> *adj;
	
	public:
		int count;
		graph(int v)
		{
			this->v=v;
			count=0;
			adj=new list<int>[v];
		}
		void add_edge(int start,int end)
		{
			adj[end].push_back(start);
		}
	void	DFSUtil(int v, bool visited[])
{
     
    visited[v] = true;
 
     
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
           {
           	count++;
           	DFSUtil(*i, visited);
           } 
}
 void DFS(int src)
{
   
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++)
       {
       	visited[i] = false;
       } 
 
     
    DFSUtil(src, visited);
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
		g.DFS(0);
		cout<<g.count<<endl;
	}
	return 0;
}
