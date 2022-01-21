# https://www.interviewbit.com/problems/atoi/

def atoi(A):
    start=0
    for i in range(len(A)):
        if(A[i]==' '):
            continue
        else:
            start=i
            break
    first_char=A[start:]    
    end=len(first_char)
    for i in range(1,len(first_char)):
        if(first_char[i] in ['0','1','2','3','4','5','6','7','8','9']):
            continue
        else:
            end=i
            break   
    try:
        Y=int(first_char[:end])
        if(first_char[:end]>'2147483647'):
            return 2147483647
        elif(Y<-2147483648) :
            return -2147483648
        else:
            return Y
    except:
        return 0


A="-54332872018247709407 4 54"
print(atoi(A))
