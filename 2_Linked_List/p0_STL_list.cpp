#include <iostream>
#include <string>
#include <list>

using namespace std;

int M;
string word;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	getline(cin, word);

	list<char> list_char;

	for (char c : word)
	{
		list_char.push_back(c);
	}

	list<char>::iterator cursor;
	cursor = list_char.end();//iterator이 가리키는 문자열의 오른쪽에 커서가 있음

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		char cmd;

		cin >> cmd;

		if (cmd == 'L')
		{
			if (cursor != list_char.begin())
			{
				cursor--;
			}
		}
		else if (cmd == 'D')
		{
			if (cursor != list_char.end())
			{
				cursor++;
			}
		}
		else if (cmd == 'B')
		{
			if (cursor != list_char.begin())
			{
				cursor--;
				cursor = list_char.erase(cursor);//list에서 첫 값이나 끝 값을 erase 함수를 통해 삭제할 시 삭제된 값의 주소 그래도 가리키므로 반드시 erase 함수의 return value를 받아 iterator가 제대로 된 값을 가리킬 수 있도록 해야한다.
			}
		}
		else if(cmd == 'P')
		{
			char dat;
			cin >> dat;

			list_char.insert(cursor, dat);
		}
	}

	for (char c : list_char)
	{
		cout << c;
	}



	return 0;
}
