n = input()
a = map(int, raw_input().split())
aa = map(abs, a)
print sum(aa) - (1 - n % 2) * len([i for i in a if i < 0]) % 2 * 2 * min(aa)
