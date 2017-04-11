cases=int(input().strip())
for x in range(cases):
	num=int(input().strip())
	if num < 38:
		print(num)
	elif (num+1)%5==0 :
		print(num+1)
	elif (num+2)%5==0 :
		print(num+2)
	else:
		print(num)