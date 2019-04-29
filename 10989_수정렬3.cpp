//10989
#include<iostream>
using namespace std;
int N;
int count[10001];

int main(void){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int num;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> num; 
		count[num]++;
	}
	
	for(int i=1; i<10001; i++)
		if(count[i] != 0) 
			for(int j=0; j<count[i]; j++)
				cout << i << "\n";
} 
