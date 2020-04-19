T = int(input())

for x in range(T):
	N, L = map(int, input().split())
	cipher = list(map(int, input().split()))
	prod0 = [0]*(L+1)
	prod0[1] = cipher[0]
	i = 2
	while i < L:
		prod0[i+1] = (cipher[i] * prod0[i-1]) / cipher[i-1]
		i += 2
	prod1 = [0]*(L+1)
	prod1[0] = cipher[0]
	prod1[2] = cipher[1]
	i = 3
	while i < L:
		prod1[i+1] = (cipher[i] * prod1[i-1]) / cipher[i-1]
	print(prod0)