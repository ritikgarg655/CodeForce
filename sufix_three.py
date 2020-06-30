n = int(input())
result = []
for i in range(n): 
    string = input()
    if string[-2:] == 'po': 
        result.append(0)
    elif string[-4:] == 'desu' or string[-4:] == 'masu': 
        result.append(1)
    else: 
        result.append(2)

words = ['FILIPINO','JAPANESE','KOREAN']
for i in range(n): 
    print(words[result[i]])
