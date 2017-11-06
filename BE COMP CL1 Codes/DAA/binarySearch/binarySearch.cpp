#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
#include<omp.h>
#include<algorithm>
using namespace std;

class binarySearch{
	int num[200], n, low, high, key;
	public:
	void getData();
	void menu();
	int binarySearchR(int *a, int low, int high, int key);
	void binarySearchNR(int *a, int low, int high, int key);
};

void binarySearch :: getData(){
	low = 0;
	cout<<"Enter number of elements: ";
	cin>>n;
	high=n-1;
	//cout<<"Enter "<<n<<" numbers: ";
	cout<<"Numbers are: ";
	for(int i=0; i<n; i++){
		//cin>>num[i];
		num[i] = rand()%200;
		cout<<num[i]<<" ";
	}

	sort(num, num+n); //Sorting Vectors and STL Containers
	cout<<"\n\nSorted List is: ";
	for(int i=0; i<n; i++)
		cout<<num[i]<<" ";
}

void binarySearch :: menu(){
	int choice;char ch;
	do{
		cout<<"\n\n1. Recursive\n2. Non-Recursive\nEnter Choice: ";
		cin>>choice;
		cout<<"Enter Key to Search: ";
		cin>>key;
		double start, finish;
		switch(choice){
			case 1:	start = omp_get_wtime();
				sleep(1);
				binarySearchR(num, low, high, key);
				finish = omp_get_wtime();
			break;
			case 2:	start = omp_get_wtime();
				sleep(1);
				binarySearchNR(num, low, high, key);
				finish = omp_get_wtime();
			break;
			case 3: exit(0);
			break;
			default: cout<<"\nChoice does not exist.\n";
			break;
		}
		cout<<"\nExecution Time: \t "<<finish-start<<endl; 
		cout<<"\nDo you want to Continue?(y/n)=> ";
		cin>>ch;
	}while(ch == 'y');
}


int binarySearch :: binarySearchR(int *a, int low, int high, int key){
	int mid;
	mid = (low+high)/2;
	if(key==a[mid]){
		cout<<"***** Key found at location: "<<mid+1<<" *****"<<endl;
		return 0;
	}
	else if(key<a[mid]){
		high=mid-1;
	}
	else if(key>a[mid]){
		low=mid+1;
	}
	if(low>high){
		cout<<"*****Key Not Found*****"<<endl;
		return 0;
	}
	binarySearchR(a, low, high, key);
}

void binarySearch :: binarySearchNR(int *a, int low, int high, int key){
	int mid;
	while(low<high){
		mid = (low+high)/2;
		if(key==a[mid]){
			cout<<"***** Key found at location: "<<mid+1<<" *****"<<endl;
			return;
		}
		else if(key<a[mid]){
			high=mid-1;
		}
		else if(key>a[mid]){
			low=mid+1;
		}
	}
	cout<<"*****Key Not Found*****"<<endl;
}

int main(){
	binarySearch ob;
	ob.getData();
	ob.menu();
	return 0;
}

/* OUTPUT

student@student:~$ g++ -o binarySearch binarySearch.cpp -fopenmp
student@student:~$ ./binarySearch
Enter number of elements: 200
Numbers are: 183 86 177 115 193 135 186 92 49 21 162 27 90 59 163 126 140 26 172 136 11 168
 167 29 182 130 62 123 67 135 129 2 22 58 69 167 193 56 11 42 29 173 21 119 184 137 198 124
 115 170 13 126 91 180 156 73 62 170 196 81 105 125 84 127 136 105 46 129 113 57 124 95 182
 145 14 167 34 164 43 150 87 8 76 178 188 184 3 51 154 199 132 60 76 168 139 12 26 186 94 139
 195 170 34 178 67 1 97 102 117 92 52 156 101 80 86 41 65 89 44 19 40 129 31 117 97 171 81 75
 109 127 167 56 97 153 186 165 106 83 19 24 128 71 132 29 103 19 70 168 108 115 140 149 196
 123 18 45 46 51 121 155 179 88 164 28 41 150 193 100 34 164 124 114 187 56 143 91 27 165 59
 136 32 151 37 28 75 7 74 121 58 195 29 37 35 193 18 28 143 11 128 129 

Sorted List is: 1 2 3 7 8 11 11 11 12 13 14 18 18 19 19 19 21 21 22 24 26 26 27 27 28 28 28 
29 29 29 29 31 32 34 34 34 35 37 37 40 41 41 42 43 44 45 46 46 49 51 51 52 56 56 56 57 58 58 
59 59 60 62 62 65 67 67 69 70 71 73 74 75 75 76 76 80 81 81 83 84 86 86 87 88 89 90 91 91 92 
92 94 95 97 97 97 100 101 102 103 105 105 106 108 109 113 114 115 115 115 117 117 119 121 121 
123 123 124 124 124 125 126 126 127 127 128 128 129 129 129 129 130 132 132 135 135 136 136 
136 137 139 139 140 140 143 143 145 149 150 150 151 153 154 155 156 156 162 163 164 164 164 
165 165 167 167 167 167 168 168 168 170 170 170 171 172 173 177 178 178 179 180 182 182 183 
184 184 186 186 186 187 188 193 193 193 193 195 195 196 196 198 199 

1. Recursive
2. Non-Recursive
Enter Choice: 1
Enter Key to Search: 177
***** Key found at location: 176 *****

Execution Time: 	 1.00019

Do you want to Continue?(y/n)=> y


1. Recursive
2. Non-Recursive
Enter Choice: 2
Enter Key to Search: 177
***** Key found at location: 176 *****

Execution Time: 	 1.00018

Do you want to Continue?(y/n)=> y


1. Recursive
2. Non-Recursive
Enter Choice: 1
Enter Key to Search: 175
*****Key Not Found*****

Execution Time: 	 1.00018

Do you want to Continue?(y/n)=> y


1. Recursive
2. Non-Recursive
Enter Choice: 2
Enter Key to Search: 175
*****Key Not Found*****

Execution Time: 	 1.00015

Do you want to Continue?(y/n)=> n
student@student:~$ 

*/
