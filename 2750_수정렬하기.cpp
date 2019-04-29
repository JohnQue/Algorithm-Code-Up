#include<iostream>
using namespace std;

void merge(int *A, int a, int b){
	if(a == b) return;
	int mid = (a+b)/2;
	merge(A, a, mid);
	merge(A, mid+1, b);

	int *buf = new int[b-a+1];
	int left = a, right = mid+1, k = 0;
	
	while(left <= mid && right <= b) buf[k++] = A[left] <= A[right] ? A[left++] : A[right++];
	while(left <= mid) buf[k++] = A[left++];
	while(right <= b) buf[k++] = A[right++];
	
	for(int i=0; i<k; i++)
		A[a+i] = buf[i];
	delete buf;
}

int main(void){
	int N;
	int A[1001];
	
	cin >> N;
	
	for(int i=0; i<N; i++)
		cin >> A[i];
	
	merge(A, 0, N-1);
	
	for(int i=0; i<N; i++)
		cout << A[i] << endl;
}
