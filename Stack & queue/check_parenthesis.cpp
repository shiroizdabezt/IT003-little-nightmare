#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	string s;
	char tam[1000];
	tam[')'] = '(';
	tam['}'] = '{';
	tam[']'] = '[';
	while (1)
	{
		cin >> s;
		if (s == "END") break;
		stack<char> st;
		string result = "";
		for (char c : s)
		{
			if (string("[({").find_first_of(c) != string::npos)
			{
				st.push(c);
			}
			else
			{
				//c dau dong ngoac
				if (st.empty())
				{
					//chua co mo ngoac ma da dong
					result = "FALSE";
						break;
				}
				else if (st.top() != tam[c])
				{
					//co dau mo ngoac nhung khong tuong ung voi dong
					result = "FALSE";
					break;
				}
				else
				{
					st.pop();
				}
			}

		}
		if (result != "")
		{
			{
				if (st.empty())
				{
					result = "TRUE";
				}
				else result = "FALSE";
			}
			cout << result << endl;
		}
		return 0;
	}
}