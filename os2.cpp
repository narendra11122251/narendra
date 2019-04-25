// C++ program to illustrate Banker's Algorithm ...
#include<iostream> 
using namespace std; 
 
const int P = 5; 

const int R = 4; 



void calculateNeed(int need[P][R], int maxm[P][R], 
				int allot[P][R]) 
{ 
	
	for (int i = 0 ; i < P ; i++) 
		for (int j = 0 ; j < R ; j++) 

			
			need[i][j] = maxm[i][j] - allot[i][j]; 
} 


bool isSafe(int processes[], int avail[], int maxm[][R], 
			int allot[][R]) 
{ 
	int need[P][R]; 

	
	calculateNeed(need, maxm, allot); 

	
	bool finish[P] = {0}; 

	
	int safeSeq[P]; 

	
	int work[R]; 
	for (int i = 0; i < R ; i++) 
		work[i] = avail[i]; 

	 
	int count = 0; 
	while (count < P) 
	{ 
		 
		bool found = false; 
		for (int p = 0; p < P; p++) 
		{ 
		
			if (finish[p] == 0) 
			{ 
				
				int j; 
				for (j = 0; j < R; j++) 
					if (need[p][j] > work[j]) 
						break; 

				 
				if (j == R) 
				{ 
					
					for (int k = 0 ; k < R ; k++) 
						work[k] += allot[p][k]; 

					
					safeSeq[count++] = p; 

				 
					finish[p] = 1; 

					found = true; 
				} 
			} 
		} 

		
		if (found == false) 
		{ 
			cout << "System is not in safe state"; 
			return false; 
		} 
	} 

	
	cout<<""<<endl;
	cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"Available "<<"\t process "<<"\t Allocation"<<"\t Max"<<endl;
		cout<<"\t\t\t\t   A B C D"<<"\t A B C D"<<endl;
	cout<<"A 1 \t\tP0 \t\t   0 0 1 2 \t 0 0 1 2"<<"\nB 5 \t\tP1 \t\t   1 0 0 0 \t 1 7 5 0"<<"\nC 2 \t\tP2 \t\t   1 3 5 4 \t 2 3 5 6"<<"\nD 0\t\tP3 \t\t   0 6 3 2 \t 0 6 5 2"<<endl;
	cout<<"\t\tP4 \t\t   0 0 1 4 \t 0 6 5 6"<<endl;
	cout<<""<<endl;
	cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<""<<endl;
	cout<<""<<endl;
	cout << "System is in safe state.\n\nSafe"
		" sequence is: "; 
	for (int i = 0; i < P ; i++) 
		cout <<"P"<<safeSeq[i] << " "; 

	return true; 
} 


int main() 
{ 
	int processes[] = {0, 1, 2, 3, 4}; 


	int avail[] = {1,5,2,0}; 

	
	int maxm[][R] = {{0,0,1,2},  
					{1,7,5,0}, 
					{2,3,5,6}, 
					{0,6,5,2},
					{0,6,5,6}}; 
						
	int allot[][R] = {{0,0,1,2}, 
					{1,0,0,0}, 
					{1,3,5,4}, 
					{1,6,3,2}, 
					{0,0,1,4}}; 	
	isSafe(processes, avail, maxm, allot); 
	
	return 0; 
} 

