// 假设最终数为 162，为了防止对方得到大于等于 162的数，则上一步，一方应该让数尽量不大于 162 /
// 9 = 18，如果大于等于 18，则对方可以乘以 9 即可大于等于 162，再往上一步，一方应该尽量选择将数
// 相乘后得到大于等于 9 的数，因为这样，另一方无论选择那个乘数，终将导致乘积大于等于 18，因为 9 /
// 9 = 1，即谁先乘，谁将获胜。
// 对于给定的数N，对于 Stan 来说，先达到数 N，则是胜利，回归到上一步，如果 Stan 先达到 N / 9，
// 则失败，继续上一步，若 Stan 先达到 N / 9 / 2，则胜利，使用递归解决即可。

#include <iostream>
#include <cmath>

using namespace std;

void ones(int number, bool win)
{
	if (number <= 9 && win)
	{
		cout << "Stan wins." << endl;
		return;
	}
	if (number <= 2 && !win)
	{
		cout << "Ollie wins." << endl;
		return;
	}
	if (win)
		ones(ceil(number / 9.0), !win);
	else
		ones(ceil(number / 2.0), !win);
}

int main(int ac, char *av[])
{
	int number;
	while (cin >> number)
		ones(number, true);
	return 0;
}
