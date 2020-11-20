//2019072351_김정훈_12838
#include <stdio.h>

int a[30001];

void Heapify(int i, int n){
    int parent = 1;
    int left = i*2;
    int right = i*2+1;
    if(left <= n && a[left] < a[i]) parent = left;
    else parent = i;

    if(right <= n && a[right] < a[parent]) parent = right;

    if (parent != i){
        int temp = a[i];
        a[i] = a[parent];
        a[parent] = temp;
        Heapify(parent,n);
    }
    else return;
}

void BuildHeap(int n)
{
	int i;
	for(i = n/2; i >= 1; i--){
		Heapify(i, n);
	}
}

int extractMin(int n)
{
	int temp = a[n];
	a[n] = a[1];
	a[1] = temp;
	
	Heapify(1, n - 1);
	return a[n];
}

int main()
{
	int N;
	int S;
	scanf("%d",&N);
	char value[N][4];
	for(int i = 1; i <= N; i++)
	{
		scanf("%s %d",&value[i],&a[i]);
	}

	scanf("%d",&S);

	int fixedLength = 0;
	int temp = N-1;
	if(temp == 0) fixedLength = S;
	while(temp > 0){
		temp /= 2;
		fixedLength += S;
	}
	
	int huffmanLength = 0;
	BuildHeap(N);

	while(N>1){
		temp = 0;
		temp += extractMin(N);
		temp += extractMin(N-1);
		N--;
		a[N] = temp;
		if(N>=2) Heapify(N/2,N);
		huffmanLength += temp;
	}
	
	printf("%d\n%d", fixedLength, huffmanLength);
	return 0;
}
