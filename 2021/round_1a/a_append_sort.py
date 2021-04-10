T = int(input())
for t in range(1, T+1):
	N = int(input())
	X = list(map(int, input().split()))
	ans = 0
	for i in range(1, N):
		if X[i] > X[i-1]: continue
		a, b = map(str, X[i-1:i+1])
		pa = a[:len(b)]
		dl = len(a) - len(b)
		if pa < b:
			ans += dl
			X[i] *= 10 ** dl
		elif pa > b or a[len(b):] == '9' * dl:
			ans += dl+1
			X[i] *= 10 ** (dl+1)
		else:
			ans += dl
			X[i] = X[i-1]+1
	print("Case #{}: {}".format(t, ans))