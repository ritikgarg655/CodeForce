n = int(input())
result = []


def rep(l,c,sl): # here c is initial and return last, c is string
    c_ret = c
    for i in range(l-1): 
        c_up = c_ret[1:]
        c_up+=c_ret*(sl-1)
        sl = int(c_ret[0])
        c_ret = c_up
        print(c_ret,i,sl)
    return c_ret[0],len(c_ret)

for i in range(n): 
    x = int(input())
    s = input()
    #while(l<x): # representing new s as a function of c , prev s and sl similar also for c
    #    l += 1
    sl , len_c = rep(x,s[1:],int(s[0]))
    final = x + len_c*int(sl)
    print(sl,len_c,x)

    a = final%(pow(10,9)+7)
    result.append(a)

for i in result: 
    print(i)