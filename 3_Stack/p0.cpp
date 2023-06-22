//BOJ 4949
//https://www.acmicpc.net/problem/4949

#include <iostream>
#include <string>
#include <stack>


using namespace std;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string sentence;

	while (1)
	{
		stack<char> barket;
		getline(cin, sentence);
		if (sentence == ".")
		{
			break;
		}

		string ans = "yes";

		for (char c : sentence)
		{
			if (c == '(')
			{
				barket.push(c);
			}
			else if (c == '[')
			{
				barket.push(c);
			}
			else if (c == ')')
			{
				if (barket.empty())
				{
					ans = "no";
					break;
				}

				if (barket.top() == '(')
				{
					barket.pop();
				}
				else
				{
					ans = "no";
					break;
				}
			}
			else if (c == ']')
			{
				if (barket.empty())
				{
					ans = "no";
					break;
				}

				if (barket.top() == '[')
				{
					barket.pop();
				}
				else
				{
					ans = "no";
					break;
				}
			}
		}

		if (!barket.empty())
		{
			ans = "no";
		}

		cout << ans << '\n';

	}
	return 0;
}
