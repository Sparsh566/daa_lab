#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int find(int parent[], int i) {
// Write your code here...
	if(parent[i]!=i)
		parent[i]=find(parent, parent[i]);
	return parent[i];
}


void union1(int parent[], int rank[], int i, int j) {
	int rooti= find(parent, i);
	int rootj= find(parent, j);

	if(rank[rooti]<rank[rootj]){
		parent[rooti]=rootj;
	}else if(rank[rooti]>rank[rootj]){
		parent[rootj]=rooti;
	}else{
		parent[rootj]=rooti;
		rank[rooti]++;
	}
}


void kruskalMST(int **cost, int V) {
	int parent[V],rank[V];
	for(int i=0;i<V;i++){
		parent[i]=i;
		rank[i]=0;
	}

	int edgeCount=0,minCost=0;
	while(edgeCount<V-1){
		int min=9999;
		int u=-1,v=-1;
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				if(find(parent,i)!=find(parent,j)&&cost[i][j]<min){
					min=cost[i][j];
					u=i;
					v=j;
				}
			}
		}
		if(u!=-1&&v!=-1){
			union1(parent,rank,u,v);
			printf("Edge %d:(%d, %d) cost:%d\n",edgeCount,u,v,min);
			minCost+=min;
			edgeCount++;
			cost[u][v]=cost[v][u]=9999;
		}
	}
	printf("Minimum cost= %d\n",minCost);
}


int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
