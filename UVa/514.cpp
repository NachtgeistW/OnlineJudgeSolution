/*
Sample Input
5
1 2 3 4 5
5 4 1 2 3
0
6
6 5 4 3 2 1
0
0
Sample Output
Yes
No
Yes
*/
#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<string>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);
	int N;
	while (cin >> N && N != 0)
	{
		int o1[1000], o2[1000];
		stack<int> stk;
		int temp;
		//用来存放指定的进栈序列
		for (int i = 1; i <= N; i++)
		{
			cin >> o1[i];
		}
		//用来存放指定的出栈序列
		for (int i = 1; i <= N; i++)
		{
			cin >> o2[i];
		}

		bool ok = true;
		int in = 1, out = 1;
		//当火车没有全出来之前
		while (out <= N)
		{
			//如果进栈的和指定出栈的火车序列是同一辆，那么直接开过去
			if (o2[out] == o1[in])
			{
				in++;
				out++;
			}
			//如果栈顶的火车是指定要出栈的，那么弹出栈顶
			else if (!stk.empty() && stk.top() == o2[out])
			{
				stk.pop();
				out++;
			}
			//如果不符合以上两种情况，但是还有车等待进栈，那么进栈（怀疑有10）
			else if (in <= N)
			{
				stk.push(o1[in]);
				in++;
			}
			//如果不符合以上所有条件，则直接判失败
			else
			{
				ok = false;
				break;
			}
		}
		printf("%s.\n", ok ? "Yes" : "No");
	}
    getchar();
	return 0;
}