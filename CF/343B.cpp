const int mx = int(1e5) + 5;

char ss[mx];
stack<char> s;

int main()
{
	char c;
	SS(ss);
	for (int i = 0; ss[i]; ++i)
	{
		s.push(ss[i]);
		while (s.size() >= 2)
		{
			c = s.top(), s.pop();
			if (c == s.top()) s.pop();
			else {s.push(c); break;}
		}
	}
	puts(s.empty() ? "Yes" : "No");
	return 0;
}
