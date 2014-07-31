ll ans;
void gcd(ll a, ll b) {if (b) ans += a / b, gcd(b, a % b);}

int main()
{
	ll a, b;
	SLL(a, b);
	gcd(a, b);
	PL(ans);
	return 0;
}
