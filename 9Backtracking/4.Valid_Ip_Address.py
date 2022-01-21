# https://www.interviewbit.com/problems/valid-ip-addresses/
import time

def canBeExtended(A, perm):
    remain_interval = 4 - len(perm)
    remain_points = len(A)-perm[-1]
    # if points are greater than interval or interval are greater than points
    if remain_points/3 > remain_interval or remain_points<remain_interval:
        return False 
    # check recently added interval generate valid IP or not 
    start=0
    end = perm[-1]
    # it will check all the first 3 interval
    if len(perm)>1:
        start=perm[-2]
    num=int(A[start:end])
    if num<0 or num>255 or len(str(num))!=len(A[start:end]):
        return False 
    # last interval checking
    if(len(perm)==3):
        start=perm[-1]
        num=int(A[start:])
        if num<0 or num>255 or len(str(num))!=len(A[start:]):
            return False 
    return True



def generate_combinations(A, perm, res):
    """
    We are finding the split points where we want to place "."
    in the given string
    """
    if len(perm)==3:
        temp=".".join([ A[:perm[0]], A[perm[0]:perm[1]], A[perm[1]:perm[2]], A[perm[2]:] ])
        res.append(temp)
        return
    # setting start
    if len(perm)==0:
        start=1
    else: 
        start=perm[-1]+1
    # Loop 
    for i in range(start, len(A)):
        perm.append(i) 
        if canBeExtended(A,perm):
            generate_combinations(A,perm, res) 
        perm.pop()


# A="25525511135"
# A="25011255255"
A="0100100"
result=[]
t=time.time()
generate_combinations(A,perm=[], res=result)
print(result)
print("time taken ", time.time()-t)