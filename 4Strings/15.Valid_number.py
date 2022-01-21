# https://www.interviewbit.com/problems/valid-number/
import re

def isNumber_simple(A):
    try:
        # This will take care of all conditions
        float(A) 
        # Case1 = except when there is decimal not followed by a digit
        if(A[-1]=='.'):
            return 0
        # Case1 - in the base of the exponent decimal 
        for i in range(len(A)):
            if(A[i]=='e'):
                if(A[i-1]=='.'):
                    return 0
        # otherwise
        return 1
    
    except:
        return 0



