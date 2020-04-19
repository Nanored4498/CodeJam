T = int(input())

for t in range(1, T+1):
	R, S = map(int, input().split())
	n = ((S-1)*R+1) // 2
	print("Case #{}: {}".format(t, n))
	b = R+1
	n = S*R
	while b < n:
		a = 2 * (b // R)
		if b % R == 0: a -= 1
		print(a, b-a)
		b += 2
	if b == n:
		print(S-1, n - S)