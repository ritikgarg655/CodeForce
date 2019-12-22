total_string = int(input())
string = []
for i in range(total_string): 
    string.append(raw_input())

final_string = []
for i in range(total_string): 
    break_point = string[i].index(' ')
    swaping = False
    done = False
    last = False
    s = string[i][0:break_point]
    c = string[i][break_point+1:] #equal wala chwck karna bake he
    for j in range(min(len(s),len(c))): 
        if s[j] == c[j]:
            if j == len(s)-1: 
                last = True 
                final_string.append(s)
            pass
        else : 
            if s[j]<c[j]: 
                final_string.append(s) 
                break
            else: 
                for k in range(j+1 , len(s)): # for checking wheather less is available or not
                    if swaping == True: 
                        break
                    if s[k]<c[j]: 
                        s[j] , s[k] = s[k] , s[j] 
                        swaping = True
                        done = True
                        break
                if done == False and swaping == False: 
                    for k in range(j+1,len(s)): 
                        if s[k] == c[j]: 
                            s[j] , s[k] = s[k] , s[j] 
                            swaping = True
                            n = n+1
                            break
                if swaping == False : 
                    final_string.append('---')
                    break
                if done == True:  
                    final_string.append(s)
                    break 

    if last == True: 
        final_string.append(s)


print(final_string)
            