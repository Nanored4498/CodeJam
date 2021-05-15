T = int(input())
for t in range(1, T+1):
	N, P = map(int, input().split())
	G = list(map(int, input().split()))
	L = [0]*P
	for g in G:
		L[g % P] += 1
	if P == 2:
		res = L[0] + L[1] // 2
		if L[1] % 2 != 0: res += 1
	elif P == 3:
		m = min(L[1], L[2])
		res = L[0] + m
		res += (L[1]+L[2] - 2*m) // 3
		if (L[1]+L[2] - 2*m) % 3 != 0: res += 1
	else:
		mi, ma = sorted([L[1], L[3]])
		ma -= mi
		m2 = min(ma // 2, L[2])
		res = L[0] + mi + m2 + (ma-2*m2)//4 + (L[2]-m2)//2
		if (L[2]-m2)%2 != 0 or (ma-2*m2)%4 != 0: res += 1
	print("Case #{}: {}".format(t, res)) 