#include<iostream>
#include<stdio.h>
#include<vector>
#include <algorithm>
#include <bitset>
#include <math.h>
using namespace std;
int const itemCount=11;
char* item[]={(char *)"Mango", (char *)"Onion", (char *)"Jar", (char *)"Key-Chain", (char *)"Eggs", (char *)"Chocolates", (char *)"Nuts", (char *)"Apple", (char *)"Toothbrush", (char *)"Corn", (char *)"Knife"};
class apriori{
	int transItem[15][itemCount], i, j, transCount, minSup, minConfidence;
	vector< vector<int> > cs1;
	vector< vector<int> > l1;
	vector< vector<int> > cs2;
	vector< vector<int> > l2;
	vector< vector<int> > cs3;
	vector< vector<int> > l3;
	vector< vector<int> > cs4;
	vector< vector<int> > l4;
	vector< vector<int> > cs5;
	vector< vector<int> > l5;
	vector< vector<int> > A;
	vector< vector<int> > B;
	public:
	void getData();
	void display();
	void candSet();
	void associationRules();
};

void apriori:: getData(){
	cout<<"Enter Number of Transactions: ";
	cin>>transCount;
	for(i=0; i<transCount; i++){
		for(j=0; j<itemCount; j++){
			transItem[i][j]=0;
		}
	}
	
	int itemTemp[itemCount];
	for(i=0; i<itemCount; i++)
		cout<<item[i]<<"\t";
	for(i=0; i<transCount; i++){
		cout<<"\n1. Mango\t2. Onion\t3. Jar \t4. Key-Chain\t5. Eggs\t\t6. Chocolates\t7. Nuts\t8. Apple\t9. Toothbrush\t10. Corn\t11. Knife\nEnter Item Codes for Transaction '"<<i+1<<"' (Enter 0 to End Transaction): ";
		for(j=0; j<itemCount; j++){
			cin>>itemTemp[j];
			if(itemTemp[j]==0)
				j=itemCount;
			else
				transItem[i][itemTemp[j]-1]=1;
		}
	}
}

void apriori :: display(){
	cout<<"Transactions Array with items: \n";
	for(i=0; i<transCount; i++){
		printf("T%d: ",i);
		for(j=0; j<itemCount; j++){
			if(transItem[i][j])
				cout<<item[j]<<"\t";
		}
		cout<<endl;
	}
}

void apriori :: candSet(){
	cout<<"Enter Minimum Support Count(in %): ";
	cin>>minSup;
	minSup = (float)minSup / 100 * transCount;
	cout<<"\nCandidate Set C1:\n";
	//generating Candidates 1

	for(i=0;i<itemCount; i++){
		vector<int> temp;
		temp.push_back(i);
		temp.push_back(0);
		cs1.push_back(temp);
	}

	for(i=0; i<transCount; i++){
		for(j=0; j<itemCount; j++){
			if(transItem[i][j]==1)
				cs1[j][1]++;
		}
	}

	for(i=0;i<itemCount; i++){
		printf("{ %10s } = %d\n",item[cs1[i][0]],cs1[i][1]);
	}
	
	int l1Count=0;
	cout<<"\nAfter Pruning L1:\n";
	for(i=0;i<itemCount; i++){
		if(cs1[i][1]>=minSup){
			vector<int> row;
			row.push_back(cs1[i][0]);
			row.push_back(cs1[i][1]);
			l1.push_back(row);
			printf("{ %10s } = %d\n",item[l1[l1Count][0]],l1[l1Count][1]);
			l1Count++;
		}
	}
	
	cout<<"\nCandidate Set C2:\n";
	
	//generating Candidates 2
	for(i=0; i<l1.size(); i++){
		for(j=i+1; j<l1.size(); j++){
			vector<int> temp;
			if(l1[i][0]<l1[j][0]){
				temp.push_back(l1[i][0]);
				temp.push_back(l1[j][0]);
				temp.push_back(0);
				cs2.push_back(temp);
			}
		}
	}

	//finding count for candidates 2
	for(i=0; i<transCount; i++){
		for(j=0; j<cs2.size(); j++){
			if(transItem[i][cs2[j][0]]==1 && transItem[i][cs2[j][1]]==1)
				cs2[j][2]++;
		}
	}
	//display cs2
	for(i=0; i<cs2.size(); i++){
		printf(" { %10s, %10s } = %d\n", item[cs2[i][0]], item[cs2[i][1]], cs2[i][2]);
	}
	
	int l2Count = 0;
	cout<<"\nAfter Pruning L2:\n";
	for(i=0; i<cs2.size(); i++){
		if(cs2[i][2]>=minSup){
			vector<int> row;
			row.push_back(cs2[i][0]);
			row.push_back(cs2[i][1]);
			row.push_back(cs2[i][2]);
			l2.push_back(row);
			printf(" { %10s, %10s } = %d\n", item[l2[l2Count][0]], item[l2[l2Count][1]], l2[l2Count][2]);
			l2Count++;
		}
	}
	
	//Candidate 3
	
	cout<<"\nCandidate Set C3:\n";
	
	//generating Candidates 3
	for(i=0; i<l2.size(); i++){
		for(j=i+1; j<l2.size(); j++){
			vector<int> temp;
			if(l2[i][0]==l2[j][0] && l2[i][1]<l2[j][1]){
				temp.push_back(l2[i][0]);
				temp.push_back(l2[i][1]);
				temp.push_back(l2[j][1]);
				temp.push_back(0);
				cs3.push_back(temp);
			}
		}
	}

	//finding count for candidates 3 in transactions
	for(i=0; i<transCount; i++){
		for(j=0; j<cs3.size(); j++){
			if(transItem[i][cs3[j][0]]==1 && transItem[i][cs3[j][1]]==1 && transItem[i][cs3[j][2]]==1)
				cs3[j][3]++;
		}
	}
	//display cs3
	for(i=0; i<cs3.size(); i++){
		//printf(" { %d, %d, %d } = %d\n", cs3[i][0]+1, cs3[i][1]+1, cs3[i][2]+1, cs3[i][3]);
		printf(" { %10s, %10s, %10s } = %d\n", item[cs3[i][0]], item[cs3[i][1]], item[cs3[i][2]], cs3[i][3]);
	}
	
	int l3Count = 0;
	cout<<"\nAfter Pruning L3:\n";
	for(i=0; i<cs3.size(); i++){
		if(cs3[i][3]>=minSup){
			vector<int> row;
			row.push_back(cs3[i][0]);
			row.push_back(cs3[i][1]);
			row.push_back(cs3[i][2]);
			row.push_back(cs3[i][3]);
			l3.push_back(row);
			//printf(" { %d, %d, %d } = %d\n", l3[l3Count][0]+1, l3[l3Count][1]+1, l3[l3Count][2]+1, l3[l3Count][3]);
			printf(" { %10s, %10s, %10s } = %d\n", item[l3[l3Count][0]], item[l3[l3Count][1]], item[l3[l3Count][2]], l3[l3Count][3]);
			l3Count++;
		}
	}
	
	//Candidate 4
	
	cout<<"\nCandidate Set C4:\n";
	
	//generating Candidates 4
	for(i=0; i<l3.size(); i++){
		for(j=i+1; j<l3.size(); j++){
			vector<int> temp;
			if(l3[i][0]==l3[j][0] && l3[i][1]==l3[j][1] && l3[i][2]<l3[j][2]){
				temp.push_back(l3[i][0]);
				temp.push_back(l3[i][1]);
				temp.push_back(l3[i][2]);
				temp.push_back(l3[j][2]);
				temp.push_back(0);
				cs4.push_back(temp);
			}
		}
	}

	//finding count for candidates 4 in transactions
	for(i=0; i<transCount; i++){
		for(j=0; j<cs4.size(); j++){
			if(transItem[i][cs4[j][0]]==1 && transItem[i][cs4[j][1]]==1 && transItem[i][cs4[j][2]]==1 && transItem[i][cs4[j][3]]==1)
				cs4[j][4]++;
		}
	}
	//display cs4
	for(i=0; i<cs4.size(); i++){
		//printf(" { %d, %d, %d, %d } = %d\n", cs4[i][0]+1, cs4[i][1]+1, cs4[i][2]+1, cs4[i][3]+1, cs4[i][4]);
		printf(" { %10s, %10s, %10s, %10s } = %d\n", item[cs4[i][0]], item[cs4[i][1]], item[cs4[i][2]], item[cs4[i][3]], cs4[i][4]);
	}
	
	int l4Count = 0;
	cout<<"\nAfter Pruning L4:\n";
	for(i=0; i<cs4.size(); i++){
		if(cs4[i][4]>=minSup){
			vector<int> row;
			row.push_back(cs4[i][0]);
			row.push_back(cs4[i][1]);
			row.push_back(cs4[i][2]);
			row.push_back(cs4[i][3]);
			row.push_back(cs4[i][4]);
			l4.push_back(row);
			//printf(" { %d, %d, %d, %d } = %d\n", l4[l4Count][0]+1, l4[l4Count][1]+1, l4[l4Count][2]+1, l4[l4Count][3]+1, l4[l4Count][4]);
			printf(" { %10s, %10s, %10s, %10s } = %d\n", item[l4[l4Count][0]], item[l4[l4Count][1]], item[l4[l4Count][2]], item[l4[l4Count][3]], l4[l4Count][4]);
			l4Count++;
		}
	}

	//Candidate 5
	
	cout<<"\nCandidate Set C5:\n";
	//generating Candidates 5
	for(i=0; i<l4.size(); i++){
		for(j=i+1; j<l4.size(); j++){
			vector<int> temp;
			if(l4[i][0]==l4[j][0] && l4[i][1]==l4[j][1] && l4[i][2]==l4[j][2] && l4[i][3]<l4[j][3]){
				temp.push_back(l4[i][0]);
				temp.push_back(l4[i][1]);
				temp.push_back(l4[i][2]);
				temp.push_back(l4[i][3]);
				temp.push_back(l4[j][3]);
				temp.push_back(0);
				cs5.push_back(temp);
			}
		}
	}

	//finding count for candidates 5 in transactions
	for(i=0; i<transCount; i++){
		for(j=0; j<cs5.size(); j++){
			if(transItem[i][cs5[j][0]]==1 && transItem[i][cs5[j][1]]==1 && transItem[i][cs5[j][2]]==1 && transItem[i][cs5[j][3]]==1 && transItem[i][cs5[j][4]]==1)
				cs5[j][5]++;
		}
	}
	//display cs5
	for(i=0; i<cs5.size(); i++){
		//printf(" { %d, %d, %d, %d, %d } = %d\n", cs5[i][0]+1, cs5[i][1]+1, cs5[i][2]+1, cs5[i][3]+1, cs5[i][4]+1, cs5[i][5]);
		printf(" { %10s, %10s, %10s, %10s, %10s } = %d\n", item[cs5[i][0]], item[cs5[i][1]], item[cs5[i][2]], item[cs5[i][3]], item[cs5[i][4]], cs5[i][5]);
	}
	
	int l5Count = 0;
	cout<<"\nAfter Pruning L5:\n";
	for(i=0; i<cs5.size(); i++){
		if(cs5[i][5]>=minSup){
			vector<int> row;
			for(j=0; j<6; j++)	
				row.push_back(cs5[i][j]);
			l5.push_back(row);
			//printf(" { %d, %d, %d, %d, %d } = %d\n", l5[l5Count][0]+1, l5[l5Count][1]+1, l5[l5Count][2]+1, l5[l5Count][3]+1, l5[l5Count][4]+1, l5[l5Count][5]);
			printf(" { %10s, %10s, %10s, %10s, %10s } = %d\n", item[l5[l5Count][0]], item[l5[l5Count][1]], item[l5[l5Count][2]], item[l5[l5Count][3]], item[l5[l5Count][4]], l5[l5Count][5]);
			l5Count++;
		}
	}
}

void  apriori:: associationRules(){
	for( i = 0; i < l5.size(); i++ ){
		for( j = 1; j <= pow(2,l5[i].size()-1)-2; j++ ){
			bitset<5> valueAB (j);
			vector<int> tempA;
			vector<int> tempB;
			for(int k=0; k<valueAB.size(); k++){	
				if(valueAB.test(k))
					tempA.push_back(l5[i][k]);
				else
					tempB.push_back(l5[i][k]);
			}
			A.push_back(tempA);
			B.push_back(tempB);	
		}
	}
	cout<<"Enter Minimum Confidence Amount(in %): ";
	cin>>minConfidence;
	cout<<"\nAssociation Rules\t\t\t\t\tConfidence(%)\n";
	for( i = 0; i<A.size(); i++){
		int supAUB = 0, supA = 0;
		for(int x = 0; x < transCount; x++){
			int flag = 0;
			for( j = 0; j < A[i].size(); j++){
				if(transItem[x][A[i][j]] == 1)
					flag = 1;
				else{
					flag = 0;
					break;
				}
			}
			if(flag==1){
				supA++;
				for( j = 0; j < B[i].size(); j++){
					if(transItem[x][B[i][j]] == 1)
						flag = 1;
					else{
						flag = 0;
						break;
					}
				}
			}
			if(flag==1)
				supAUB++;	
		}
		float conf = (float)supAUB / (float)supA * 100;
		if(conf >= minConfidence){
			printf("{ ");
			for( j = 0; j<A[i].size()-1; j++){
				printf("%s, ", item[A[i][j]]);
			}
			printf("%s } -> { ", item[A[i][j]]);
			for( j = 0; j<B[i].size()-1; j++){
				printf("%s, ", item[B[i][j]]);
			}
			printf("%s }\t%f\n", item[B[i][j]], conf);
		}
	}
}

int main(){
	apriori a;
	a.getData();
	a.display();
	a.candSet();
	a.associationRules();
}

/* OUTPUT

student@B4L0106:~$ g++ -o aprioriAlgorithm aprioriAlgorithm.cpp 
student@B4L0106:~$ ./aprioriAlgorithm 
Enter Number of Transactions: 5
Mango	Onion	Jar	Key-Chain	Eggs	Chocolates	Nuts	Apple	Toothbrush	Corn	Knife	
1. Mango	2. Onion	3. Jar 	4. Key-Chain	5. Eggs		6. Chocolates	7. Nuts	8. Apple	9. Toothbrush	10. Corn	11. Knife
Enter Item Codes for Transaction '1' (Enter 0 to End Transaction): 1 2 3 4 5 6
0

1. Mango	2. Onion	3. Jar 	4. Key-Chain	5. Eggs		6. Chocolates	7. Nuts	8. Apple	9. Toothbrush	10. Corn	11. Knife
Enter Item Codes for Transaction '2' (Enter 0 to End Transaction): 7 2 3 4 5 6
0

1. Mango	2. Onion	3. Jar 	4. Key-Chain	5. Eggs		6. Chocolates	7. Nuts	8. Apple	9. Toothbrush	10. Corn	11. Knife
Enter Item Codes for Transaction '3' (Enter 0 to End Transaction): 1 8 4 5
0

1. Mango	2. Onion	3. Jar 	4. Key-Chain	5. Eggs		6. Chocolates	7. Nuts	8. Apple	9. Toothbrush	10. Corn	11. Knife
Enter Item Codes for Transaction '4' (Enter 0 to End Transaction): 1 9 10 4 6
0

1. Mango	2. Onion	3. Jar 	4. Key-Chain	5. Eggs		6. Chocolates	7. Nuts	8. Apple	9. Toothbrush	10. Corn	11. Knife
Enter Item Codes for Transaction '5' (Enter 0 to End Transaction): 10 2 2 4 11 5
0
Transactions Array with items: 
T0: Mango	Onion	Jar	Key-Chain	Eggs	Chocolates	
T1: Onion	Jar	Key-Chain	Eggs	Chocolates	Nuts	
T2: Mango	Key-Chain	Eggs	Apple	
T3: Mango	Key-Chain	Chocolates	Toothbrush	Corn	
T4: Onion	Key-Chain	Eggs	Corn	Knife	
Enter Minimum Support Count(in %): 40

Candidate Set C1:
{      Mango } = 3
{      Onion } = 3
{        Jar } = 2
{  Key-Chain } = 5
{       Eggs } = 4
{ Chocolates } = 3
{       Nuts } = 1
{      Apple } = 1
{ Toothbrush } = 1
{       Corn } = 2
{      Knife } = 1

After Pruning L1:
{      Mango } = 3
{      Onion } = 3
{        Jar } = 2
{  Key-Chain } = 5
{       Eggs } = 4
{ Chocolates } = 3
{       Corn } = 2

Candidate Set C2:
 {      Mango,      Onion } = 1
 {      Mango,        Jar } = 1
 {      Mango,  Key-Chain } = 3
 {      Mango,       Eggs } = 2
 {      Mango, Chocolates } = 2
 {      Mango,       Corn } = 1
 {      Onion,        Jar } = 2
 {      Onion,  Key-Chain } = 3
 {      Onion,       Eggs } = 3
 {      Onion, Chocolates } = 2
 {      Onion,       Corn } = 1
 {        Jar,  Key-Chain } = 2
 {        Jar,       Eggs } = 2
 {        Jar, Chocolates } = 2
 {        Jar,       Corn } = 0
 {  Key-Chain,       Eggs } = 4
 {  Key-Chain, Chocolates } = 3
 {  Key-Chain,       Corn } = 2
 {       Eggs, Chocolates } = 2
 {       Eggs,       Corn } = 1
 { Chocolates,       Corn } = 1

After Pruning L2:
 {      Mango,  Key-Chain } = 3
 {      Mango,       Eggs } = 2
 {      Mango, Chocolates } = 2
 {      Onion,        Jar } = 2
 {      Onion,  Key-Chain } = 3
 {      Onion,       Eggs } = 3
 {      Onion, Chocolates } = 2
 {        Jar,  Key-Chain } = 2
 {        Jar,       Eggs } = 2
 {        Jar, Chocolates } = 2
 {  Key-Chain,       Eggs } = 4
 {  Key-Chain, Chocolates } = 3
 {  Key-Chain,       Corn } = 2
 {       Eggs, Chocolates } = 2

Candidate Set C3:
 {      Mango,  Key-Chain,       Eggs } = 2
 {      Mango,  Key-Chain, Chocolates } = 2
 {      Mango,       Eggs, Chocolates } = 1
 {      Onion,        Jar,  Key-Chain } = 2
 {      Onion,        Jar,       Eggs } = 2
 {      Onion,        Jar, Chocolates } = 2
 {      Onion,  Key-Chain,       Eggs } = 3
 {      Onion,  Key-Chain, Chocolates } = 2
 {      Onion,       Eggs, Chocolates } = 2
 {        Jar,  Key-Chain,       Eggs } = 2
 {        Jar,  Key-Chain, Chocolates } = 2
 {        Jar,       Eggs, Chocolates } = 2
 {  Key-Chain,       Eggs, Chocolates } = 2
 {  Key-Chain,       Eggs,       Corn } = 1
 {  Key-Chain, Chocolates,       Corn } = 1

After Pruning L3:
 {      Mango,  Key-Chain,       Eggs } = 2
 {      Mango,  Key-Chain, Chocolates } = 2
 {      Onion,        Jar,  Key-Chain } = 2
 {      Onion,        Jar,       Eggs } = 2
 {      Onion,        Jar, Chocolates } = 2
 {      Onion,  Key-Chain,       Eggs } = 3
 {      Onion,  Key-Chain, Chocolates } = 2
 {      Onion,       Eggs, Chocolates } = 2
 {        Jar,  Key-Chain,       Eggs } = 2
 {        Jar,  Key-Chain, Chocolates } = 2
 {        Jar,       Eggs, Chocolates } = 2
 {  Key-Chain,       Eggs, Chocolates } = 2

Candidate Set C4:
 {      Mango,  Key-Chain,       Eggs, Chocolates } = 1
 {      Onion,        Jar,  Key-Chain,       Eggs } = 2
 {      Onion,        Jar,  Key-Chain, Chocolates } = 2
 {      Onion,        Jar,       Eggs, Chocolates } = 2
 {      Onion,  Key-Chain,       Eggs, Chocolates } = 2
 {        Jar,  Key-Chain,       Eggs, Chocolates } = 2

After Pruning L4:
 {      Onion,        Jar,  Key-Chain,       Eggs } = 2
 {      Onion,        Jar,  Key-Chain, Chocolates } = 2
 {      Onion,        Jar,       Eggs, Chocolates } = 2
 {      Onion,  Key-Chain,       Eggs, Chocolates } = 2
 {        Jar,  Key-Chain,       Eggs, Chocolates } = 2

Candidate Set C5:
 {      Onion,        Jar,  Key-Chain,       Eggs, Chocolates } = 2

After Pruning L5:
 {      Onion,        Jar,  Key-Chain,       Eggs, Chocolates } = 2
Enter Minimum Confidence Amount(in %): 60

Association Rules					Confidence(%)
{ Onion } -> { Jar, Key-Chain, Eggs, Chocolates }	66.666672
{ Jar } -> { Onion, Key-Chain, Eggs, Chocolates }	100.000000
{ Onion, Jar } -> { Key-Chain, Eggs, Chocolates }	100.000000
{ Onion, Key-Chain } -> { Jar, Eggs, Chocolates }	66.666672
{ Jar, Key-Chain } -> { Onion, Eggs, Chocolates }	100.000000
{ Onion, Jar, Key-Chain } -> { Eggs, Chocolates }	100.000000
{ Onion, Eggs } -> { Jar, Key-Chain, Chocolates }	66.666672
{ Jar, Eggs } -> { Onion, Key-Chain, Chocolates }	100.000000
{ Onion, Jar, Eggs } -> { Key-Chain, Chocolates }	100.000000
{ Onion, Key-Chain, Eggs } -> { Jar, Chocolates }	66.666672
{ Jar, Key-Chain, Eggs } -> { Onion, Chocolates }	100.000000
{ Onion, Jar, Key-Chain, Eggs } -> { Chocolates }	100.000000
{ Chocolates } -> { Onion, Jar, Key-Chain, Eggs }	66.666672
{ Onion, Chocolates } -> { Jar, Key-Chain, Eggs }	100.000000
{ Jar, Chocolates } -> { Onion, Key-Chain, Eggs }	100.000000
{ Onion, Jar, Chocolates } -> { Key-Chain, Eggs }	100.000000
{ Key-Chain, Chocolates } -> { Onion, Jar, Eggs }	66.666672
{ Onion, Key-Chain, Chocolates } -> { Jar, Eggs }	100.000000
{ Jar, Key-Chain, Chocolates } -> { Onion, Eggs }	100.000000
{ Onion, Jar, Key-Chain, Chocolates } -> { Eggs }	100.000000
{ Eggs, Chocolates } -> { Onion, Jar, Key-Chain }	100.000000
{ Onion, Eggs, Chocolates } -> { Jar, Key-Chain }	100.000000
{ Jar, Eggs, Chocolates } -> { Onion, Key-Chain }	100.000000
{ Onion, Jar, Eggs, Chocolates } -> { Key-Chain }	100.000000
{ Key-Chain, Eggs, Chocolates } -> { Onion, Jar }	100.000000
{ Onion, Key-Chain, Eggs, Chocolates } -> { Jar }	100.000000
{ Jar, Key-Chain, Eggs, Chocolates } -> { Onion }	100.000000
student@B4L0106:~$

*/
