#include<iostream>
using namespace std;
int A[1000000];
void merge(int *A, int a, int b){
	if(a == b) return;
	int mid = (a+b)/2;
	merge(A, a, mid);
	merge(A, mid+1, b);

	int left = a, right = mid+1, k = 0;
	int* buf = new int[b-a+1];
	
	while(left <= mid && right <= b) buf[k++] = A[left] <= A[right] ? A[left++] : A[right++];
	while(left <= mid) buf[k++] = A[left++];
	while(right <= b) buf[k++] = A[right++];
	
	for(int i=0; i<k; i++)
		A[a+i] = buf[i];
	delete buf;
}

int main(void){
	int N;
	
	cin >> N;
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	for(int i=0; i<N; i++)
		cin >> A[i];
	
	merge(A, 0, N-1);
	
	for(int i=0; i<N; i++)
		cout << A[i] << "\n";
}
