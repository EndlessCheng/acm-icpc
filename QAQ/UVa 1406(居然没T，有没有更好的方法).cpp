const int MASK = 1 << 16;
int a[100005], c[17][MASK], N;

int main()
{
	for (int CAS = 1; scanf(" %d", &N) == 1 && N != -1; CAS++)
	{
		memset(c, 0, sizeof(c));
		for (int n = 0; n < N; n++)
		{
			scanf(" %d", &a[n]);
			for (int i = 0; i < 16; i++)
				c[i][a[n] % (1 << (i + 1))]++;
		}
		long long ans = 0, add = 0;
		char ch;
		for (int b; scanf(" %c", &ch) == 1 && ch != 'E' && scanf(" %d", &b) == 1;)
		{
			if (ch == 'Q')
			{
				int more = add % (1 << (b + 1)), MAX = (1 << (b + 1));
				for (int i = 0; i < MAX; i++)
					if ((more + i) & (1 << b))
						ans += c[b][i];
			}
			else
			{
				add += b;
				add %= MASK;
			}
		}
		printf("Case %d: %lld\n", CAS, ans);
	}
	return 0;
}
