#include<bits/stdc++.h>
using namespace std;
const int mx = 100;

int main()
{
    setlocale(LC_ALL, "chs");
    int a, b, t;
    wchar_t ws[mx];
    scanf("%d%*c", &t);
    for (int cas = 1; cas <= t; ++cas)
    {
        if (swscanf(fgetws(ws, mx, stdin), L"%d%*lc%d%*lc", &a, &b) == 1)
            b = 0;
        cout << "Case " << cas << ": " << a * 0.5 + b * 0.05 << '\n';
    }
    return 0;
}
