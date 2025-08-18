#include <limits.h> 
#include <stdio.h>
#define MAX 20
int V, E;
int graph[MAX][MAX];
#define INFINITY 99999
void printPath(int parent[],int j){
	int path[MAX];
	int pathIndex=0;

	while(j!=-1){
		path[pathIndex++]=j;
		j=parent[j];
	}
	for(int i=0;i<pathIndex;i++){
		printf("%d",path[i]);
		if(i<pathIndex-1){
			printf("<-");
		}
	}
}

void dijkstra(int G[MAX][MAX], int n, int startnode) {
	int distance[MAX],visited[MAX],parent[MAX];
	for(int i=1;i<=n;i++){
		distance[i]=INFINITY;
		visited[i]=0;
		parent[i]=-1;
	}
	distance[startnode]=0;

	for(int count=1;count<=n-1;count++){
		int min = INFINITY,u=-1;
		for(int i=1;i<=n;i++){
			if(!visited[i]&&distance[i]<=min){
				min=distance[i];
				u=i;
			}
		}
		if(u==-1)
			break;

		visited[u]=1;
		for(int v=1;v<=n;v++){
			if(!visited[v]&&G[u][v]&&distance[u]+G[u][v]<distance[v]){
				distance[v]=distance[u]+G[u][v];
				parent[v]=u;
			}
		}
	}
	printf("Node\tDistance\tPath\n");
	for(int i=1;i<=n;i++){
		if(i==startnode)
			continue;
		printf("   %d\t",i);
		if(distance[i]==INFINITY){
			printf("     INF\tNO PATH\n");
		}else{
			printf("       %d\t",distance[i]);
			printPath(parent, i);
			printf("\n");
		}
	}
}
int main() { 
	int s, d, w, i, j;
	printf("Enter the number of vertices : ");
	scanf("%d", &V);
	printf("Enter the number of edges : ");
	scanf("%d", &E);
	for(i = 1 ; i <= V; i++) {
		for(j = 1; j <= V; j++) {
			graph[i][i] = 0;
		}
	}
	for(i = 1; i <= E; i++) {
		printf("Enter source : ");
		scanf("%d", &s);
		printf("Enter destination : ");
		scanf("%d", &d);
		printf("Enter weight : ");
		scanf("%d", &w);
		if(s > V || d > V || s <= 0 || d <= 0) {
			printf("Invalid index. Try again.\n");
			i--;
			continue;
		} else {
			graph[s][d] = w;
		}
	}
	printf("Enter the source :");
	scanf("%d", &s);
	dijkstra(graph, V, s); 
	return 0; 
} 
