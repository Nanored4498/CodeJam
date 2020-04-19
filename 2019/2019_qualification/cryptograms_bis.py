from math import gcd

T = int(input())

for x in range(T):
	N, L = map(int, input().split())
	cipher = list(map(int, input().split()))
	i = 1
	while cipher[i] == cipher[0]:
		i += 1
	ps = [None]*(L+1)
	ps[i] = gcd(cipher[i], cipher[0])
	for j in range(i, L):
		ps[j+1] = cipher[j] // ps[j]
	for j in range(i-1, -1, -1):
		ps[j] = cipher[j] // ps[j+1]
	ps2 = sorted(list(set(ps)))
	letters = {}
	for i in range(26):
		letters[ps2[i]] = chr(ord('A')+i)
	res = ""
	for p in ps:
		res += letters[p]
	print("Case #{}: {}".format(x+1, res))