#include<bits/stdc++.h> 
using namespace std; 

class Graph 
{ 
    int V;    
  
    list< pair<int, int> > *adj; 
  
public: 
    Graph(int V); 
  
  
    void addEdge(int u, int v, int w); 
  
 
    void shortestPath(int start , int end , int V); 
}; 
  

Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list< pair<int, int> >[V]; 
} 
  
void Graph::addEdge(int u, int v, int w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
}

void Graph::shortestPath(int start , int end , int V) 
{ 

    set< pair<int, int> > setds; 

  
    vector<int> dist(V + 1, 100000); 
  

    setds.insert(make_pair(0, start)); 
    dist[start] = 0; 
  
    int cnt = 0;
    while (!setds.empty()) 
    { 
        // tr("yo");
        cnt++;
        if(cnt > 100) break;
        pair<int, int> tmp = *(setds.begin()); 
        setds.erase(setds.begin()); 

        int u = tmp.second; 
        
        cout << "siz:" << adj[u].size() << endl;
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            
            int v = (*i).first; 
            int weight = (*i).second; 
            cout << "v:" << v << " " << u << endl;

            if (dist[v] > dist[u] + weight) 
            { 

                if (dist[v] != 100000){
                        setds.erase(setds.find(make_pair(dist[v], v))); 
                } 
  
                dist[v] = dist[u] + weight; 
                setds.insert(make_pair(dist[v], v)); 
            } 
        } 
    } 

    printf("Vertex   Distance from Source\n"); 
    for (int i = 0; i < V; ++i) 
        printf("%d \t\t %d\n", i, dist[i]); 

   int shortest_Path = dist[end] - dist[start] ; 

   cout << shortest_Path ; 
} 

int main()
{
	int n , m ; 
	cin >> n >> m ; 

	int k[m] ; 
	int t[m] ; 

	vector<int> subway[m] ; 
	vector<int> time[m] ; 

	for(int i=0 ; i<m ; i++)
	{
		cin >> k[i] >> t[i] ; 

		for(int j=0 ; j<k[i] ; j++)
		{
			int data1 ; 
			cin >> data1 ; 
			subway[i].push_back(data1) ; 
		}

		for(int j=0 ; j < k[i]-1 ; j++)
		{
			int data2 ; 
			cin >> data2 ; 
			time[i].push_back(data2) ;
		}

	}
    //printf("Y"); 

	int start , end ; 

	cin >> start >> end ;

    printf("y") ; 

	Graph g(n); 

	for(int i = 0 ; i < m ; i++)
	{
		for(int j = 0 ; j < subway[i].size() - 1 ; j++)
		{
			g.addEdge(subway[i][j] , subway[i][j+1] , t[i] + time[i][j]) ; 
		}
	}

    g.shortestPath(start , end, n);
    printf("y") ; 

}