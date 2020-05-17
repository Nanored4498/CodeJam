def f(S,a):
	if len(S) == 0: return ""
	m = min(S)
	res = "("*m
	sub = []
	for s in S:
		if s == m:
			res += f(sub,a+m) + str(m+a)
			sub = []
		else: sub.append(s-m)
	res += f(sub,a+m) + ")"*m
	return res

T = int(input())
for t in range(1, T+1):
	S = [ord(s) - ord('0') for s in input()]
	res = f(S,0)
	print("Case #{}: {}".format(t, res))