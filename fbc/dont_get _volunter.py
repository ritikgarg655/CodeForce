def dfs(src,dst,curr_post,*visited):
    if(curr_post == dst ):
        return 0;
    if(not *visited[curr_post] == 0):
        return *visited[curr_post]
    else:
        # number of posibility
        min1 = 9999
        if(curr_post % 8 >= 1 and curr_post//8 <6):
            next_post = curr_post + 15
            a = dfs(src,dst,next_post,*visited)
            if(a!=-1 and a<min1):
                min1 = a
        if( curr_post % 8 >=1 and curr_post//8 >1):
            next_post = curr_post - 17
            a = dfs(src,dst,next_post,*visited)
            if(a!=-1 and a<min1):
                min1 = a
        
        if( curr_post % 8 >1 and curr_post//8 <7 ):
            next_post = curr_post + 6
            a = dfs(src,dst,next_post,*visited)
            if(a!=-1 and a<min1):
                min1 = a
        
        if( curr_post % 8 >1 and curr_post//8 >0 ):
            next_post = curr_post - 10
            a = dfs(src,dst,next_post,*visited)
            if(a!=-1 and a<min1):
                min1 = a
            
        if(curr_post % 8 <= 6 and curr_post//8 <6):
            next_post = curr_post + 15
            a = dfs(src,dst,next_post,*visited)
            if(a!=-1 and a<min1):
                min1 = a
        
        if( curr_post % 8 <=6 and curr_post//8 >1):
            next_post = curr_post - 17
            a = dfs(src,dst,next_post,*visited)
            if(a!=-1 and a<min1):
                min1 = a
        
        if( curr_post % 8 <6 and curr_post//8 <7 ):
            next_post = curr_post + 6
            a = dfs(src,dst,next_post,*visited)
            if(a!=-1 and a<min1):
                min1 = a
        
        if( curr_post % 8 <6 and curr_post//8 >0 ):
            next_post = curr_post - 10
            a = dfs(src,dst,next_post,*visited)
            if(a!=-1 and a<min1):
                min1 = a
        
        if(not min1 == 9999):
            *visited[curr_post] = min1
            return min1+1
        else:
            *visited[curr_post] = -1
            return -1

def solution(src, dest):
    #Your code here
    visited = [0] * 64
    return dfs(src,dst,src,*visited)

print(solution(0,63))