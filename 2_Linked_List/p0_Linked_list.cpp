#include <iostream>
#include <string>

using namespace std;

int M;
string word;

typedef struct List
{
	char dat;

	List* prev;
	List* next;
};

void insert(List* pos_node, char dat)
{
	List* left_node = pos_node->prev;
	List* right_node = pos_node;
	List* new_node = new List;

	new_node->dat = dat;
	new_node->prev = left_node;
	new_node->next = right_node;

	left_node->next = new_node;
	right_node->prev = new_node;
}

List* erase(List* pos_node)
{
	List* left_node = pos_node->prev;
	List* right_node = pos_node->next;

	left_node->next = right_node;
	right_node->prev = left_node;

	delete(pos_node);

	return right_node;
}

List* header_node;
List* tail_node;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	header_node = new List;
	tail_node = new List;

	getline(cin, word);
	
	header_node->prev = nullptr;
	header_node->next = tail_node;
	tail_node->prev = header_node;
	tail_node->next = nullptr;


	for (char c:word)
	{
		insert(tail_node, c);
	}
	List* cursor;
	cursor = tail_node;

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		char cmd;
		cin >> cmd;

		if (cmd == 'L')
		{
			if (cursor != header_node->next)
			{
				cursor = cursor->prev;
			}
		}
		else if (cmd == 'D')
		{
			if (cursor != tail_node)
			{
				cursor = cursor->next;
			}
		}
		else if (cmd == 'B')
		{
			if (cursor != header_node->next)
			{
				cursor = cursor->prev;
				cursor = erase(cursor);
			}
		}
		else if (cmd == 'P')
		{
			char dat;
			cin >> dat;

			insert(cursor, dat);
		}
	}

	List* iter_temp = header_node->next;
	while (iter_temp != tail_node)
	{
		cout << iter_temp->dat;
		List* temp = iter_temp;
		iter_temp = iter_temp->next;
		delete(temp);
	}

	delete(header_node);
	delete(tail_node);


	return 0;
}
