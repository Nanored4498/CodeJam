from math import gcd

def inv(c):
	if c == 'F': return 'T'
	return 'F'

fac = [1]
for i in range(120):
	fac.append(fac[-1] * (i+1))
def C(t, q):
	return fac[q] // (fac[t] * fac[q-t])

T = int(input())
for t in range(1, T+1):
	N, Q = map(int, input().split())
	A, S = [], []
	for _ in range(N):
		a, s = input().split()
		A.append(a)
		S.append(int(s))
	if N < 3:
		a, s = "", 0
		for i in range(N):
			if 2*S[i] < Q:
				A[i] = ''.join(map(inv, A[i]))
				S[i] = Q - S[i]
			if S[i] > s: a, s = A[i], S[i]
		print("Case #{}: {} {}/1".format(t, a, s))
	else:
		q = [0] * 4
		cl = [None] * Q
		for i in range(Q):
			c = (A[1][i] == A[0][i]) + 2 * (A[2][i] == A[0][i])
			q[c] += 1
			cl[i] = c
		a1 = q[0] + (q[1] + q[2] - S[1] - S[2]) // 2
		a2 = (S[0] + S[1] - q[0] - q[2]) // 2
		a3 = (S[0] + S[2] - q[0] - q[1]) // 2
		num, w = [0]*4, 0
		for t4 in range(q[3]+1):
			ts = [a1 + t4, a2 - t4, a3 - t4, t4]
			mul = 1
			for i in range(4):
				if ts[i] < 0 or ts[i] > q[i]:
					mul = 0
					break
				mul *= C(ts[i], q[i])
			for i in range(4):
				num[i] += mul * ts[i]
			w += mul
		r = [2 * num[i] < q[i] * w for i in range(4)]
		y = ""
		for i in range(Q):
			if r[cl[i]]: y += inv(A[0][i])
			else: y += A[0][i]
		z = 0
		for i in range(4):
			if r[i]: z += q[i] * w - num[i]
			else: z += num[i]
		g = gcd(z, w)
		z //= g
		w //= g
		print("Case #{}: {} {}/{}".format(t, y, z, w))
