import math

T = int(input())
for t in range(1, T+1):
	N = int(input())
	n = int(N - math.log2(N))
	b = []
	while n > 0:
		b.append(n % 2)
		n //= 2
	print("Case #{}:".format(t))
	left = True
	s, p2 = 0, 1
	for r in range(len(b)):
		print(r+1, 1 if left else r+1)
		if b[r] == 1:
			s += p2
			for k in range(r):
				print(r+1, 2+k if left else r-k)
			left = not left
		else: s += 1
		p2 *= 2
	for a in range(N-s):
		print(len(b)+1+a, 1 if left else len(b)+1+a)