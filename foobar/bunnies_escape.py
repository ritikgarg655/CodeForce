from collections import deque
def solution(map):
    w = len(map[0])
    h = len(map)
    visited = set()
    q = deque([])
    q.append([0,0,1,0]) # x,y,distance(ans),is wall removed(1)
    while q:
        position = q.popleft()
        # print(position)
        if (position[0],position[1]) in visited:
            continue
        
        if position[0] == w-1 and position[1] == h-1:
            return position[2]
        
        visited.add((position[0],position[1]))
        # left
        if position[0]>0:
            if map[position[1]][position[0]]==1:
                if position[3] == 1:
                    continue
                q.append([position[0]-1,position[1],position[2]+1,1])
            else:
                q.append([position[0]-1,position[1],position[2]+1,position[3]])
                    
        # right
        if position[0]<w-1:
            if map[position[1]][position[0]]==1:
                if position[3] == 1:
                    continue
                q.append([position[0]+1,position[1],position[2]+1,1])
            else:
                q.append([position[0]+1,position[1],position[2]+1,position[3]])
                    
        # top
        if position[1]>0 :
            if map[position[1]][position[0]]==1:
                if position[3] == 1:
                    continue
                q.append([position[0],position[1]-1,position[2]+1,1])
            else:
                q.append([position[0],position[1]-1,position[2]+1,position[3]])
                    
        # bottom
        if position[1]<h-1 :
            if map[position[1]][position[0]]==1:
                if position[3] == 1:
                    continue
                q.append([position[0],position[1]+1,position[2]+1,1])
            else:
                q.append([position[0],position[1]+1,position[2]+1,position[3]])
    return float('inf') 
print(solution([[0,0,0],[1,0,1],[1,1,0],[1,1,0],[1,1,0]]))