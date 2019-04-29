#include<iostream>
#include<algorithm>

using namespace std;

string str[20001];
int N;

int getSum(string a){
	int length = a.length(), sum = 0;
	for(int i=0; i<length; i++){
		if(a[i] - '0' <= 9 && a[i] - '0' >= 0){
			sum += a[i] - '0';
		}
	}
	return sum;
}
bool compare(string a, string b){
	// short length first
	if(a.length() < b.length()) return 1;
	else if(a.length() > b.length()) return 0;
	else{ // automatically sorted
		int aSum = getSum(a);
		int bSum = getSum(b);
		if(aSum != bSum){
			return aSum < bSum;
		}else{
			return a < b;
		}
	}
}
int main(void){
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> str[i];
	sort(str, str+N, compare);
	
	for(int i=0; i<N; i++){
		if(i > 0 && str[i] == str[i-1]) continue;
		cout << str[i] << "\n";
	}
}
