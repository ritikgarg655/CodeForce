n = int(input())
result = []

for i in range(n):
    o = input()
    stri = input()
    maxp = 0
    for j in range(len(stri)-1): 
        loc_max_p = 0
        if stri[j] == 'A' and stri[j+1]!= 'A': 
            for k in range(j+1,len(stri)): 
                if stri[k]=='A': 
                    break
                else: 
                    loc_max_p += 1
            if loc_max_p>maxp : 
                maxp = loc_max_p
    result.append(maxp)
for i in result:
    print(i)