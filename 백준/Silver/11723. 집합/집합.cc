#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

unsigned int d = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	string c;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> c;

		if (c == "add")
		{
			cin >> x;
			d |= (1 << x);
		}
		else if (c == "remove")
		{
			cin >> x;
			d &= ~(1 << x);
		}
		else if (c == "check")
		{
			cin >> x;
			if (d & (1 << x))
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		else if (c == "toggle")
		{
			cin >> x;
			d ^= (1 << x);
		}
		else if (c == "all")
		{
			d = (1 << 21) - 1;
		}
		else if (c == "empty")
		{
			d = 0;
		}
	}
}
