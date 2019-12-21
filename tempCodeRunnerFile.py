tot_input = int(input())
arr_input = []
for i in range(tot_input):
    arr_input.append(raw_input())
tot_rem_per = []
ind_rem_per = []
for i in range(tot_input):
    j = 0
    count = 0
    index = []
    while True :
        if arr_input[i][j:j+5] == 'twone' and j<=len(arr_input[i])-5:
            count += 1 
            index.append(j)
            j=j+4
        elif arr_input[i][j:j+3]=='one' or arr_input[i][j:j+3]=='two':
            count += 1
            index.append(j)
            j = j+2
        if j <= len(arr_input[i])-4:
            j =j+1
        else :
            break
    tot_rem_per.append(count)
    ind_rem_per.append(index)
for i in range(tot_input):
    print(tot_rem_per[i])
    for j in range(len(ind_rem_per[i])): 
        print(ind_rem_per[i][j]),
    print('')  
print(tot_rem_per , ind_rem_per)