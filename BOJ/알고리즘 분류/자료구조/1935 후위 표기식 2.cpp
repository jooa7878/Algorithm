#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

int N;
string str;
unordered_map<char, int> umap;

void solution() {

	stack<double> stk;

	for (int i = 0; i < str.length(); i++)
	{
		if (isalpha(str[i]))
		{
			stk.push((double)umap[str[i]]);
		}
		else
		{
			double first = stk.top(); stk.pop();
			double second = stk.top(); stk.pop();
			double result = 0.0;
			switch (str[i])
			{
				case '+':
					result = first + second;
					break;
				case '-':
					result = second - first;
					break;
				case '*':
					result = first * second;
					break;
				case '/':
					result = second / first;
					break;
				default:
					break;
			}

			stk.push(result);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << stk.top();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;

	cin >> str;

	for (int i = 0; i < N; i++)
	{
		cin >> umap[i+65];
	}

	solution();
}
