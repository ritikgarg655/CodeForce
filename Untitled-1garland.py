n = input()
lis = list(map(int,input().split))
act = list(range(n))
missing = []
missing_odd =0
missing_even = 0
for i in act:
    if act not in lis:
        missing.append(i)
        if i%2==0: 
            missing_even += 1
        else: 
            missing_odd += 1

print(lis,act,missing_even,missing_odd)