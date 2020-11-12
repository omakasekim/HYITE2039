//code is under construction, probably doesn't work. 

#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

int min(int x, int y)
{
	return x < y ? x : y;
}

int AssemblyLine(int** a, int** t, int *e, int *x, int N)
{
	int T1[N], T2[N], idx;
	
	T1[0] = e[0] + a[0][0];
	T2[0] = e[1] + a[1][0];
	
	printf(" T1idx = %d and T2idx = %d ", T1[0], T2[0]);
	for(idx = 1; idx < N; ++idx)
	{
		T1[idx] = min(T1[idx-1] + a[0][idx], T2[idx-1] + t[1][idx] + a[0][idx]);
		T2[idx] = min(T2[idx-1] + a[1][idx], T1[idx-1] + t[0][idx] + a[1][idx]);
		printf(" T1idx = %d and T2idx = %d ", T1[idx], T2[idx]);
	}	
	
	return min(T1[N-1] + x[0], T2[N-1] + x[1]);
}

int main()
{
	int N;
	scanf("%d", &N);
	
	//printf("\nScanned value of N\n");
	
	int* e = (int*)malloc(sizeof(int)*2);
	int* x = (int*)malloc(sizeof(int)*2);
	
	//printf("\nAllocated memory to e and x\n");
	
	for(int i = 0; i < 2; i++)
		scanf("%d", &e[i]);
	for(int i = 0; i < 2; i++)
		scanf("%d", &x[i]);
		
	//printf("\nScanned values for e, %d %d \n and x, %d %d ",e[0],e[1],x[0],x[1]);
	
	int** a = (int**)malloc(2*sizeof(int*)*N);
	a[0] = (int*)malloc(sizeof(int)*N);
	a[1] = (int*)malloc(sizeof(int)*N);
	
	//printf("\nAllocated memory to double pointer a\n");
	
	for(int i = 0; i < N; i++)
		scanf("%d", &a[0][i]);
	for(int i = 0; i < N; i++)
		scanf("%d", &a[1][i]);
		
	/*printf("\nScanned values for array a1 and a2\n");
	for(int i = 0; i < N; i++)
		printf(" %d %d ",a[0][i],a[1][i]);*/
		
	int** t = (int**)malloc(2*sizeof(int*)*N);
	t[0] = (int*)malloc(sizeof(int)*N);
	t[1] = (int*)malloc(sizeof(int)*N);
	
	//printf("\nAllocated memory to double pointer t\n");
	
	for(int i = 0; i < N-1; i++)
		scanf("%d", &t[0][i]);
	for(int i = 0; i < N-1; i++)
		scanf("%d", &t[1][i]);
	
	/*printf("Scanned values for array t1 and t2\n");
	for(int i = 0; i < N-1; i++)
		printf(" %d %d ",t[0][i],t[1][i]);*/
	
	printf("\n%d\n",AssemblyLine(a,t,e,x,N));
	
}
