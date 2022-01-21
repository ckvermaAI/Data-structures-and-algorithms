# coursera

import time 

EMPTY = 0
LD = 1
RD = 2
SOLUTIONS=0
NOW = time.time()

def can_add_left_diagonal(perm, size):
    length=len(perm)
    # up
    if 0 <= (length - (size + 1)) < length and perm[length - (size + 1)] == RD:
        return False
    # up left
    if (length - 1) % size > 0 and (0 <= (length - (size + 2)) < length and perm[length - (size + 2)] == LD):
        return False
    # beside
    if (length - 1) % size > 0 and (0 <= (length - 2) < length and perm[length - 2] == RD):
        return False
    
    return True


def can_add_right_diagonal(perm, size):
    length=len(perm)
    # up
    if 0 <= (length - (size + 1)) < length and perm[length - (size + 1)] == LD:
        return False
    # up right
    if length%size > 0  and ( 0<= (length-size)<length and perm[length-size]==RD) :
        return False 
    # beside 
    if (length-1)%size > 0 and ( 0<=(length-2)<length and perm[length-2])==LD:
        return False
    
    return True


def canBeExtended(diagonal, perm, size):
    if diagonal==LD and can_add_left_diagonal(perm, size):
        return True
    elif diagonal==RD and can_add_right_diagonal(perm, size):
        return True
    elif diagonal==EMPTY:
        return True
    return False
    

def prettyPrint(perm,size):
    print(perm)
    for i in range(len(perm)):
        if perm[i]==LD:
            print("\\", end=" ")
        elif perm[i]==RD:
            print("/", end=" ")
        elif perm[i]==EMPTY:
            print(" ", end=" ")
        # new line/ new row
        if (i+1) % size == 0:
            print("")
    print("")


def addDiagonal(perm, size, n, diagonal_count):
    if diagonal_count==n:
        global SOLUTIONS
        global NOW 
        SOLUTIONS+=1
        print("Yes! Found solution #%s! N = %s in %s" %(SOLUTIONS, n, time.time()-NOW))
        NOW=time.time()
        prettyPrint(perm,size)
        return 
    if len(perm)==size*size or (size*size)-len(perm)<n-diagonal_count:
        return 
    
    for d in [LD, RD, EMPTY]:
        perm.append(d) 
        if canBeExtended(d, perm, size):
            if d!=EMPTY:
                diagonal_count+=1
            addDiagonal(perm, size, n, diagonal_count)
            if d!=EMPTY:
                diagonal_count-=1
        perm.pop()



def solve(perm, size, n):
    addDiagonal(perm, size, n, diagonal_count=0)
    global SOLUTIONS
    print("Total Solutions found: %s" %SOLUTIONS)


solve(perm=[], size=5, n=16)
