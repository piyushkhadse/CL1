#include<iostream>
using namespace std;

#define MAXSIZE 10
int numberOfItems;
float capacityOfKnapsack,profit[MAXSIZE],weight[MAXSIZE];
int solution[MAXSIZE]={0};
int fp = -1, fw = 0;

void getInput() {
	int i;
	cout<<"Enter the capacity of Knapsack: ";
	cin>>capacityOfKnapsack;
	cout<<"Enter Number of Items: ";
	cin>>numberOfItems;
	for(i=1;i<=numberOfItems;i++) {
		cout<<"Enter (Weight, Profit) for Item "<<i<< ": ";
		cin>>weight[i]>>profit[i];
	}
}

void sortInput() {
	float ratio[numberOfItems+1];
	int i,j;
	for(i=1;i<=numberOfItems;i++)
		ratio[i]=(float)profit[i]/weight[i];
	for(i=1;i<=numberOfItems;i++) {
		for(j=1;j<=numberOfItems;j++) {
			if(ratio[j]<ratio[j+1]) {
				int temp;
				temp=profit[j];
				profit[j]=profit[j+1];
				profit[j+1]=temp;
				temp=weight[j];
				weight[j]=weight[j+1];
				weight[j+1]=temp;
				float tmp;
				tmp=ratio[j];
				ratio[j]=ratio[j+1];
				ratio[j+1]=tmp;	
			}
		}
	}
	cout<<"Input is: \n";
	cout<<"Tuple\tWeight\tProfit\tRatio\n";
	for(i=1;i<=numberOfItems;i++)
		cout<<i<<"\t"<<weight[i]<<"\t"<<profit[i]<<"\t"<<ratio[i]<<"\n";
}

float UBound(float current_wt,float current_pr,int current_item) {
	float cw=current_wt;
	float cp=current_pr;
	for(int i = current_item+1; i <= numberOfItems; i++) {
		if(cw + weight[i] <= capacityOfKnapsack) {
			cw = cw + weight[i];
			cp = cp + profit[i];
		}
	}
	return cp;
}

int y[MAXSIZE]={0};
void knapsackBranchAndBound(int k, int cp, int cw) {
	if(cw + weight[k] <= capacityOfKnapsack) {
		y[k] = 1;
		if(k < numberOfItems)
			knapsackBranchAndBound( k + 1, cp + profit[k], cw + weight[k]);
		if((cp + profit[k] > fp) && (k == numberOfItems)){
			fp = cp + profit[k];
			fw = cw + weight[k];
			for(int j = 1; j <= k; j++)
				solution[j] = y[j];
		}
	}
	if(UBound(cw, cp, k) >= fp){
		y[k] = 0;
		if(k < numberOfItems)
			knapsackBranchAndBound( k + 1, cp, cw);
		if((cp > fp) && (k == numberOfItems)){
			fp = cp;
			fw = cw;
			for(int j = 1; j <= k; j++)
				solution[j] = y[j];
		}
	}
}

int main() {
	getInput();
	sortInput();
	knapsackBranchAndBound(1, 0, 0);
	cout<<"\nSolution= ";
	for(int i = 1; i <= numberOfItems; i++)
		cout<<solution[i]<<"\t";
	cout<<"\nFinal Profit: "<<fp<<"\nFinal Weight: "<<fw<<endl;
	return 0;
}

/* OUTPUT

student@student:~$ g++ -o 01Knapsack 01Knapsack.cpp 
student@student:~$ ./01Knapsack
Enter the capacity of Knapsack: 8
Enter Number of Items: 5
Enter (Weight, Profit) for Item 1: 4 9
Enter (Weight, Profit) for Item 2: 3 8
Enter (Weight, Profit) for Item 3: 6 9
Enter (Weight, Profit) for Item 4: 2 3
Enter (Weight, Profit) for Item 5: 5 10
Input is: 
Tuple	Weight	Profit	Ratio
1	3	8	2.66667
2	4	9	2.25
3	5	10	2
4	6	9	1.5
5	2	3	1.5

Solution= 1	0	1	0	0	
Final Profit: 18
Final Weight: 8
student@student:~$ 

*/
