#include<cstdio>
#include<cassert>
typedef long long ll;

ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}

struct frac
{
	ll up, low;
	frac(ll up = 0, ll low = 1)
	{
		if (low < 0) up = -up, low = -low;
		assert(low);
		ll g = gcd(abs(up), low);
		this->up = up / g, this->low = low / g;
	}
	void output()
	{
		ll z = up / low;
		up %= low;
		if (up)
		{
			if (z) printf("%lld %lld/%lld\n", z, up, low);
			else printf("%lld/%lld\n", up, low);
			//if (z) printf("%I64d %I64d/%I64d\n", z, up, low);
			//else printf("%I64d/%I64d\n", up, low);
		}
		else printf("%lld\n", z);
	}
	frac operator + (const frac &b) const
	{
		return frac(up * b.low + low * b.up, low * b.low);
	}
	frac operator - (const frac &b) const
	{
		return frac(up * b.low - low * b.up, low * b.low);
	}
	frac operator * (const frac &b) const
	{
		return frac(up * b.up, low * b.low);
	}
	frac operator / (const frac &b) const
	{
		return frac(up * b.low, low * b.up);
	}
	bool operator < (const frac &b) const
	{
		return up * b.low < low * b.up;
	}
	bool operator == (const frac &b) const
	{
		return up * b.low == low * b.up;
	}
	bool operator > (const frac& b) const
	{
		return b < *this;
	}
	bool operator <= (const frac& b) const
	{
		return !(b < *this);
	}
	bool operator >= (const frac &b) const
	{
		return !(*this < b);
	}
	bool operator != (const frac &b) const
	{
		return up * b.low != low * b.up;
	}
	frac operator += (const frac &b)
	{
		return *this = *this + b;
	}
	frac operator -= (const frac &b)
	{
		return*this = *this - b;
	}
	frac operator *= (const frac &b)
	{
		return *this = *this * b;
	}
	frac operator /= (const frac &b)
	{
		return *this = *this / b;
	}
};
