# https://www.interviewbit.com/problems/integer-to-roman/
# https://projecteuler.net/about=roman_numerals

def intToRoman(A):
    ones = ['None','I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX']
    tens = ['None','X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC']
    huns = ['None','C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM']
    thos = ['None', 'M', 'MM', 'MMM']
    B=str(A)
    res=""
    N=len(B)
    for i in range(N):
        num = int(B[i])
        if(num==0):
            continue
        if(N-i==4):
            res+=thos[num]
        elif (N-i==3):
            res+=huns[num]
        elif (N-i==2):
            res+=tens[num]
        elif (N-i==1):
            res+=ones[num]
    return res


print(intToRoman(990))
