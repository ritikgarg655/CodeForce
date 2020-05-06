# BFS which will go in all posiible postion.
def bfs(src,dst,visited):
    queue = []
    queue.append([src,0])
    while len(queue)>0:
        temp_list = queue.pop(0)
        curr_post = temp_list[0]
        distance = temp_list[1]
        if(curr_post==dst):
            return distance
        if(visited[curr_post]==0):
            # If early not visited, adding all 8 possibke position.

            visited[curr_post] = 1
            
            #    -
            #    -
            #   --
            if(curr_post % 8 >= 1 and curr_post//8 <6):
                next_post = curr_post + 15
                queue.append([next_post,distance+1])
            
            #   --
            #    -
            #    -
            if( curr_post % 8 >=1 and curr_post//8 >1):
                next_post = curr_post - 17
                queue.append([next_post,distance+1])
            
            
            #    -
            #  ---
            if( curr_post % 8 >1 and curr_post//8 <7 ):
                next_post = curr_post + 6
                queue.append([next_post,distance+1])
            
            
            #  ---
            #    -
            if( curr_post % 8 >1 and curr_post//8 >0 ):
                next_post = curr_post - 10
                queue.append([next_post,distance+1])
                
            
            #    -
            #    -
            #    --
            if(curr_post % 8 <= 6 and curr_post//8 <6):
                next_post = curr_post + 17
                queue.append([next_post,distance+1])
            
            
            #    --
            #    -
            #    -
            if( curr_post % 8 <=6 and curr_post//8 >1):
                next_post = curr_post - 15
                queue.append([next_post,distance+1])
            
            #    -
            #    ---
            if( curr_post % 8 <6 and curr_post//8 <7 ):
                next_post = curr_post + 10
                queue.append([next_post,distance+1])
            
            #    ---
            #    -
            if( curr_post % 8 <6 and curr_post//8 >0 ):
                next_post = curr_post - 6
                queue.append([next_post,distance+1])
            
    return -1
def solution(src, dest):
    #Your code here
    visited = [0 for x in range(65)]    
    return bfs(src,dest,visited)

print(solution(0,1))