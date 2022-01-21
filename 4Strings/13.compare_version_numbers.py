# https://www.interviewbit.com/problems/compare-version-numbers/


def compareVersion(self, A, B):
    # extract the each revision of the versions
    v1= [int(f) for f in A.split(".")]
    v2= [int(f) for f in B.split(".")]
    N = min(len(v1), len(v2))

    # compare the elements of version
    for i in range(N):
        if v1[i]>v2[i]:
            return 1
        elif(v2[i]>v1[i]):
            return -1
    
    # Now if the above condition does not satisfy 
    if( len(v1)==len(v2) or (len(v1)>len(v2) and sum(v1[len(v2):])==0) or  (len(v2)>len(v1) and sum(v2[len(v1):])==0 )  ):
        return 0
    elif (len(v1)>len(v2)):
        return 1
    else:
        return -1
