#include<iostream>
#include<omp.h>
#include<stdlib.h>
#include<stdio.h>
#define MAX 50
using namespace std;

class QuickSort{
	int A[MAX];
	public:
	void quickSort(int *A, int p, int r);
	int partition (int *A,int p,int r);

};

int main(){
	int A[MAX], n=MAX;
	QuickSort Q;

	for(int i=0; i<n; i++){
		A[i]=rand()%1000;
	}
	
	double start = omp_get_wtime();
	Q.quickSort(A, 0, n-1);
	
	double finish = omp_get_wtime();
	
	cout<<"\nSorted Elements are: ";
	for(int i=0; i<n; i++){
		cout<<A[i]<<" ";
	}cout<<endl;
	
	cout<<"\n\nExecution Time: \t "<<finish-start<<endl; 
	return 0;
}

void QuickSort::quickSort(int *A, int p, int r){
	if(p<r){
		int q=partition(A,p,r);
		
		omp_set_nested(1);
		
		#pragma omp parallel sections
		{
			#pragma omp section 
			{
				printf("Left Part of pivot with index %d is executed by thread ID=%d\n",q,omp_get_thread_num());
				quickSort(A,p,q-1);
			}
			#pragma omp section
			{
				printf("Right Part of pivot with index %d is executed by thread ID=%d\n",q,omp_get_thread_num());
				quickSort(A,q+1,r);
			}
		}
	}
}

int QuickSort:: partition (int *A,int p,int r){
	int x = A[r];
	int i=p-1;
	int temp;
	for(int j=p; j<=r-1; j++){
		if(A[j]<=x){
			i++;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	temp = A[i+1];
	A[i+1] = A[r];
	A[r] = temp;
	return (i+1);
}

/* OUTPUT

student@B4L0106:~$ g++ -o concurrentQuickSort concurrentQuickSort.cpp -fopenmp
student@B4L0106:~$ ./concurrentQuickSort 
Right Part of pivot with index 20 is executed by thread ID=0
Left Part of pivot with index 20 is executed by thread ID=1
Left Part of pivot with index 22 is executed by thread ID=1
Right Part of pivot with index 22 is executed by thread ID=2
Left Part of pivot with index 34 is executed by thread ID=1
Right Part of pivot with index 34 is executed by thread ID=0
Left Part of pivot with index 27 is executed by thread ID=1
Left Part of pivot with index 36 is executed by thread ID=1
Right Part of pivot with index 36 is executed by thread ID=1
Right Part of pivot with index 27 is executed by thread ID=2
Left Part of pivot with index 31 is executed by thread ID=1
Left Part of pivot with index 40 is executed by thread ID=1
Right Part of pivot with index 40 is executed by thread ID=2
Right Part of pivot with index 31 is executed by thread ID=2
Left Part of pivot with index 28 is executed by thread ID=1
Right Part of pivot with index 28 is executed by thread ID=1
Left Part of pivot with index 37 is executed by thread ID=0
Right Part of pivot with index 37 is executed by thread ID=1
Right Part of pivot with index 44 is executed by thread ID=0
Left Part of pivot with index 44 is executed by thread ID=1
Left Part of pivot with index 33 is executed by thread ID=1
Right Part of pivot with index 33 is executed by thread ID=1
Left Part of pivot with index 49 is executed by thread ID=1
Right Part of pivot with index 49 is executed by thread ID=0
Left Part of pivot with index 29 is executed by thread ID=1
Right Part of pivot with index 29 is executed by thread ID=1
Left Part of pivot with index 42 is executed by thread ID=2
Right Part of pivot with index 42 is executed by thread ID=1
Left Part of pivot with index 38 is executed by thread ID=1
Right Part of pivot with index 38 is executed by thread ID=0
Left Part of pivot with index 26 is executed by thread ID=2
Left Part of pivot with index 48 is executed by thread ID=1
Left Part of pivot with index 15 is executed by thread ID=1
Right Part of pivot with index 26 is executed by thread ID=1
Right Part of pivot with index 15 is executed by thread ID=0
Left Part of pivot with index 12 is executed by thread ID=3
Left Part of pivot with index 23 is executed by thread ID=0
Right Part of pivot with index 23 is executed by thread ID=1
Right Part of pivot with index 12 is executed by thread ID=0
Right Part of pivot with index 48 is executed by thread ID=3
Left Part of pivot with index 47 is executed by thread ID=2
Right Part of pivot with index 47 is executed by thread ID=1
Right Part of pivot with index 19 is executed by thread ID=0
Left Part of pivot with index 19 is executed by thread ID=1
Left Part of pivot with index 3 is executed by thread ID=2
Right Part of pivot with index 13 is executed by thread ID=0
Left Part of pivot with index 13 is executed by thread ID=2
Right Part of pivot with index 3 is executed by thread ID=1
Left Part of pivot with index 25 is executed by thread ID=1
Right Part of pivot with index 25 is executed by thread ID=2
Left Part of pivot with index 16 is executed by thread ID=1
Right Part of pivot with index 16 is executed by thread ID=3
Left Part of pivot with index 46 is executed by thread ID=1
Right Part of pivot with index 46 is executed by thread ID=2
Left Part of pivot with index 8 is executed by thread ID=2
Right Part of pivot with index 8 is executed by thread ID=3
Left Part of pivot with index 0 is executed by thread ID=2
Right Part of pivot with index 0 is executed by thread ID=3
Right Part of pivot with index 17 is executed by thread ID=2
Left Part of pivot with index 17 is executed by thread ID=1
Left Part of pivot with index 7 is executed by thread ID=1
Right Part of pivot with index 7 is executed by thread ID=0
Left Part of pivot with index 2 is executed by thread ID=0
Left Part of pivot with index 4 is executed by thread ID=0
Right Part of pivot with index 2 is executed by thread ID=1
Right Part of pivot with index 4 is executed by thread ID=2
Left Part of pivot with index 9 is executed by thread ID=2
Right Part of pivot with index 9 is executed by thread ID=0
Left Part of pivot with index 6 is executed by thread ID=1
Right Part of pivot with index 6 is executed by thread ID=3
Left Part of pivot with index 10 is executed by thread ID=1
Right Part of pivot with index 10 is executed by thread ID=0

Sorted Elements are: 11 22 27 42 58 59 67 69 123 135 167 172 198 211 229 315 324 335 362 368
370 373 383 386 393 421 421 426 429 456 492 530 537 540 567 649 690 736 763 777 782 784 793
802 862 886 915 919 926 929 


Execution Time: 	 0.00440313
student@B4L0106:~$ 

*/
