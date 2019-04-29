#include<iostream>
#include<algorithm>

using namespace std;

string str[20001];
int N;

bool compare(string a, string b){
	// short length first
	if(a.length() < b.length()) return 1;
	else if(a.length() > b.length()) return 0;
	else return a < b; // automatically sorted
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
