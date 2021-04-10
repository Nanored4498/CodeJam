T = int(input())
for t in range(1, T+1):
	N, C = map(int, input().split())
	if C < N-1 or C > (N*(N+1))//2 - 1:
		print("Case #{}: {}".format(t, "IMPOSSIBLE"))
		continue
	L = [i+1 for i in range(N)]
	C -= N-1;
	for i in range(N-1):
		a = N-2-i
		b = a + min(i+1, C)
		C -= b-a
		for k in range((b-a+1)//2):
			L[a+k], L[b-k] = L[b-k], L[a+k]
	L = ' '.join(str(x) for x in L)
	print("Case #{}: {}".format(t, L))