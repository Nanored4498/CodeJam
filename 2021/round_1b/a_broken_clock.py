T = int(input())

def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    return x % m

M = (360 * 12) * 10**10
i11 = modinv(11, M)
i719 = modinv(719, M)

for t in range(1, T+1):
	a = list(map(int, input().split()))
	found = False
	for i in range(3):
		for j in range(3):
			if i == j: continue
			k = 3-i-j
			t1 = ((a[j] - a[i]) * i11) % M
			t2 = ((a[k] - a[i]) * i719) % M
			if t1 != t2: continue
			h = t1 // (M//12)
			m = (12 * t1) % M
			m //= (M//60)
			s = (720 * t1) % M
			s //= (M//60)
			n = t1 % (10**9)
			print("Case #{}: {} {} {} {}".format(t, h, m, s, n))
			found = True
			break
		if found: break