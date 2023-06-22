//BOJ 10808
//https://www.acmicpc.net/problem/10808

#include <iostream>
#include <string>

using namespace std;

string word;
int ans[26];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
	getline(cin, word);

	for (char c : word)
	{
		ans[c - 'a']++;
	}

	for (int i = 0; i < 26; i++) 
	{
		cout << ans[i] << " ";
	}


	return 0;
}
