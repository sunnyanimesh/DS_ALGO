#include<bits/stdc++.h>

using namespace std;


class Edge 
{
    public:
    int src;
    int dest;

};


class Graph{
    public:
    int V,E;

    Edge *edges;
};


Graph *createGraph(int v,int e){
    Graph *graph = new Graph();
    graph->V = v;
    graph->E = e;
    graph->edges = new Edge[e * sizeof(Edge)];
    return graph;
}

int find(int parent[],int x){
    if(parent[x]== -1){
        return x;
    }
    else
    return find(parent,parent[x]);
}

void union_set(int parent[],int x,int y){
int xset = find(parent,x);
int yset = find(parent,y);
if(xset !=yset){
    parent[xset] = yset;
}

}

int isCycle(Graph *graph){
    int parent[graph->V] ;
    memset(parent,-1,sizeof(parent));

    for(int i=0;i<graph->E;i++){
      int srcp = find(parent,graph->edges[i].src);
      int destp = find(parent,graph->edges[i].dest);
        if(srcp == destp){
            return 1;
        }
        union_set(parent,srcp,destp);
    }
return 0;
}

int main(){

	int V = 3, E = 3; 
	Graph* graph = createGraph(V, E); 

	graph->edges[0].src = 0; 
	graph->edges[0].dest = 1; 

	graph->edges[1].src = 1; 
	graph->edges[1].dest = 2; 

	graph->edges[2].src = 0; 
	graph->edges[2].dest = 2; 

    if (isCycle(graph)) 
		cout<<"graph contains cycle"; 
	else
		cout<<"graph doesn't contain cycle"; 

return 0;
}