# include<stdio.h>
void knapsack(int n, float weight[], float profit[], float capacity) {
	float total_profit=0.0;
	int i;
	for(i=0;i<n;i++){
		if(capacity==0){
			break;
		}
		if(weight[i]<=capacity){
			capacity-=weight[i];
			total_profit+=profit[i];
		}else{
			total_profit+=profit[i]*(capacity/weight[i]);
			capacity=0;
		}
	}

	printf("Maximum profit is:- %.6f\n",total_profit);
}

int main() {
	float weight[20], profit[20], capacity;
	int num, i, j;
	float ratio[20], temp;
	printf("Enter the no. of objects: ");
	scanf("%d", &num);
	printf("Enter the weights and profits of each object:\n");
	for (i = 0; i < num; i++) {
		scanf("%f %f", &weight[i], &profit[i]);
	}
	printf("Enter the capacity of knapsack:");
	scanf("%f", &capacity);
	for (i = 0; i < num; i++) {
		ratio[i] = profit[i] / weight[i];
	}

	for (i = 0; i < num; i++) {
		for (j = i + 1; j < num; j++) {
			if (ratio[i] < ratio[j]) {
				temp = ratio[j];
				ratio[j] = ratio[i];
				ratio[i] = temp;
				temp = weight[j];
				weight[j] = weight[i];
				weight[i] = temp;
				temp = profit[j];
				profit[j] = profit[i];
				profit[i] = temp;
			}
		}
	}
	knapsack(num, weight, profit, capacity);
	return(0);
}
