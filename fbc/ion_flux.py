def dfs(q,ht,temp_ht,num,ans):
    if ht+1 == temp_ht:
        return 0 
    a = dfs(q,ht,temp_ht+1,num,ans)
    b = dfs(q,ht,temp_ht+1,num,ans)
    if a in q:
        ans[q.index(a)] = num[0]+1
    if b in q:
        ans[q.index(b)] = num[0]+1
    num[0] = num[0]+1
    return num[0]
    
def solution(h, q):
    # Your code here
    total_node = pow(2,h)-1
    num = [0]
    ans = [-1] * len(q)
    dfs(q,h,1,num,ans)
    return ans


print(solution(3,[1,4,7]))