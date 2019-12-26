def swap_str(string , first_ind , second_ind):
    new_string = ''
    for i in range(len(string)): 
        if i == first_ind: 
            new_string = new_string + string[second_ind]
        elif i == second_ind: 
            new_string = new_string +string[first_ind]
        else : 
            new_string = new_string + string[i]
    return new_string


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
    c = string[i][break_point+1:] #equal wala check karna bake he
    for j in range(min(len(s),len(c))):
        if s[j] == c[j]:
            if j == len(s)-1:
                last = True
                done = True
                final_string.append(s)
            elif j == min(len(s),len(c))-1:
                last = True
                final_string.append('---')
            else :
                pass
        else : 
            if s[j]<c[j]: 
                final_string.append(s) 
                break
            else: 
                for k in range(j+1 , len(s)): # for checking wheather less is available or not
                    if swaping == True: 
                        break
                    elif s[k]<c[j]: 
                        s = swap_str(s,j,k)
                        swaping = True
                        done = True
                        break
                if done == False and swaping == False: # Swaping of equal to know that wheather after swaping became equall
                    for k in range(j+1,len(s)): 
                        if s[k] == c[j]:
                            s = swap_str(s,j,k)
                            swaping = True
                            break
                if swaping == True and done == False : 
                    final_string.append('---')
                    break 
                if done == True:  
                    final_string.append(s)
                    break 


for i in range(len(final_string)): 
    print(final_string[i])
            