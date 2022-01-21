import time 
NOW = time.time()
SOLUTIONS = 0

def canBeExtended(perm):
    j=len(perm)-1
    for i in range(j):
        if abs(i-j)==abs(perm[i]-perm[j]):
            return False
    return True

def preetyPrint(perm):
    result=[]    
    for i in range(len(perm)):
        temp=['.' for f in range(len(perm))]
        temp[perm[i]]= 'Q'
        result.append("".join(temp))
    return result

def generate_permutations(perm,result,n):
    if len(perm)==n:
        print(perm)
        global SOLUTIONS
        SOLUTIONS+=1
        result.append(preetyPrint(perm))
        return 
    for i in range(n):
        if i not in perm:
            perm.append(i) 
            if canBeExtended(perm):
                generate_permutations(perm, result,n)
            perm.pop()



result=[]
generate_permutations(perm=[], result=result, n=4)
print(result)
print("Time Taken ", time.time()-NOW)
print("Total solutions found ", SOLUTIONS)
