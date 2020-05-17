T = int(input())
for t in range(1, T+1):
	L, R = map(int, input().split())
	if L >= R:
		n = int((2*(L-R)) ** .5)
		L -= (n*(n+1))//2
		while L >= R and L > n:
			n += 1
			L -= n
		if L >= R:
			print("Case #{}: {} {} {}".format(t, n, L, R))
			continue
		while n > 0 and (L+n) < R:
			L += n
			n -= 1
	else:
		n = int((2*(R-L)) ** .5)
		R -= (n*(n+1))//2
		while R-(n+1) > L and R > n:
			n += 1
			R -= n
		if R-(n+1) > L:
			print("Case #{}: {} {} {}".format(t, n, L, R))
			continue
		while n > 0 and R <= L:
			R += n
			n -= 1
	a, b, c = .5, n+.5, -(L+R)
	d = b**2 - 4*a*c
	m = int((-b + d**.5) / (2*a))
	m2 = m//2
	L -= n*m2 + m2*(m2+1)
	R -= (n-1)*(m-m2) + (m-m2)*(m-m2+1)
	x = [L, R]
	while x[(m+1)%2] >= n+m+1:
		x[(m+1)%2] -= n+m+1
		m += 1
	while x[m%2] < 0:
		x[m%2] += n+m
		m -= 1
	n += m
	L, R = x
	print("Case #{}: {} {} {}".format(t, n, L, R))