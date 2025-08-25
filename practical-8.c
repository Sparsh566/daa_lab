#include<stdio.h>

int knapsack(int N,int W,int val[],int wt[]){
	int dp[N+1][W+1];
	for (int i=0;i<=N;i++){
		for(int w=0;w<=W;w++){
			if(i==0 || w==0)
				dp[i][w]=0;
			else if(wt[i-1]<=w)
				dp[i][w]=(val[i-1]+dp[i-1][w-wt[i-1]]>dp[i-1][w])? val[i-1]+dp[i-1][w-wt[i-1]] : dp[i-1][w];
			else
				dp[i][w]=dp[i-1][w];
		}
	}
	return dp[N][W];
}

int main(){
	int N,W;
	scanf("%d",&N);
	int val[N],wt[N];
	for(int i=0;i<N;i++)
		scanf("%d",&val[i]);
	for(int i=0;i<N;i++)
		scanf("%d",&wt[i]);
	scanf("%d",&W);
	int result=knapsack(N,W,val,wt);
	printf("%d\n",result);
	return 0;
}
