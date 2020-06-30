tot = int(input())
result = []

def ascending_ti(ti,index): 
    for i in range(len(ti)): 
        min_index = i
        for j in range(i+1,len(ti)): 
            if ti[min_index] > ti[j]: 
                min_index = j
        ti[i] , ti[min_index] = ti[min_index] , ti[i]
        index[i] , index[min_index] = index[min_index] , index[i]
    return ti , index 

for _ in range(tot):
    n,t,a,b = list(map(int,input().split()))
    lis = list(map(int,input().split()))
    ti = list(map(int,input().split()))
    tot_sim = 0
    last_ind = -1
    for i in range(len(lis)): 
        if lis[i]==0: 
            tot_sim +=1
    
    score = 0
    last_satisfied_score = 0
    current_time = 0
    ti_asec , lis = ascending_ti(ti,lis)
    time = [a,b]
    simple =0
    last_current_time =0
    for i in range(n):
        current_time = current_time+time[lis[i]]
        if current_time <= ti_asec[i]: 
            last_satisfied_score+=1
            last_current_time = current_time
            last_ind = i
        score +=1
    if current_time<=t: 
        result.append(score)
    else: 
        high_rem = [last_current_time]
        new_last_ind =[last_ind]
        new_score1 = [last_satisfied_score]
        for i in range(last_ind+1): 
            new_score = 0
            if lis[i]==1:
                temp_time = 0
                for j in range(i):
                    temp_time += time[lis[j]]
                    new_score += 1
                for j in range(i): 
                    if lis[j]==0:
                        simple +=1
                if ti_asec[i]>temp_time:
                    remaing_simple = tot_sim - simple 
                    for j in range(i,len(ti)): 
                        if remaing_simple>0: 
                            if lis[j]==0 and (temp_time+a<ti_asec[i]):
                                temp_time += a
                                new_score += 1
                                remaing_simple -= 1
                        else: 
                            break
                high_rem.append(temp_time)
                new_last_ind.append(i-1)
                new_score1.append(new_score)
        last_satisfied_score = max(new_score1)
        i = new_score1.index(last_satisfied_score)
        last_ind = new_last_ind[i]
        last_current_time = high_rem[i]
        for i in range(last_ind+1): 
            if lis[i]==0: 
                simple +=1
        '''if tot_sim>simple: 
            new_time = ti_asec[last_ind+1]
            remaing_simple = tot_sim-simple
            for i in range(last_ind+1,len(ti)): 
                if remaing_simple>0:
                    if lis[i]==0 and (last_current_time+a<new_time): 
                        last_current_time +=a
                        last_satisfied_score+=1
                        remaing_simple-= 1 
                else: 
                    break 
        ''' 
        new_time = ti_asec[last_ind+1]
        for i in range(last_ind+1,len(ti)): 
            if last_current_time+time[lis[i]] < ti_asec[i+1]: 
                last_satisfied_score += 1
                last_current_time+=time[lis[i]]
                last_ind = i
            else : 
                break
        for i in range(last_ind+1,len(ti)): 
            if lis[i]==0: 
                if (last_current_time+a<new_time):  
                    last_current_time +=a
                    last_satisfied_score+=1
                    remaing_simple-= 1 
                elif (last_current_time+b<new_time):
                    last_current_time +=b
                    last_satisfied_score+=1
                    remaing_simple-= 1 

        result.append(last_satisfied_score)
for i in range(len(result)): 
    print(result[i])