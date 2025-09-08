
#include <stdio.h>
#define INF 99999
#define MAX_N 20 // Maximum value for N
void floydWarshall(int graph[MAX_N][MAX_N],int n){
	int dist[MAX_N][MAX_N];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dist[i][j]=graph[i][j];
		}
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if (dist[i][k] != INF && dist[i][k] + dist[k][j] < dist[i][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	printf("The following matrix shows the shortest distances between all pairs of the vertices.\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(dist[i][j]==INF)
				printf("%5s","INF");
			else
				printf("%5d",dist[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int n,e;
	int graph[MAX_N][MAX_N];

	printf("Enter the number of vertices : ");
	scanf("%d",&n);
	printf("Enter the number of edges : ");
	scanf("%d",&e);

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)
				graph[i][j]=0;
			else
				graph[i][j]=INF;
		}
	}
	for(int i=0;i<e;i++){
		int u,v,w;
		printf("Enter source : ");
		scanf("%d",&u);
		printf("Enter destination : ");
		scanf("%d", &v);
		printf("Enter weight : ");
		scanf("%d",&w);
		graph[u-1][v-1]=w;
	}
	floydWarshall(graph, n);
	return 0;
}
