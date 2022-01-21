# https://projecteuler.net/about=roman_numerals
# https://www.interviewbit.com/problems/roman-to-integer/

# solution 1
class Solution:

	def romanToInt(self, A):
		d = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}
		ans =0
		for i in range(len(A)-1):
			# check if next character is of higher
			if d[A[i]]<d[A[i+1]]:
				ans -= d[A[i]]
			else:
				ans += d[A[i]]
		ans += d[A[-1]]
		return ans



# solution 2
def first_occurence(A, toFind, Master, res, last_pos):
    pos=-1
    for i in range(len(A)):
        if A[i] in toFind:
            pos=i
            break
    if(pos!=-1 and pos<=last_pos):
        res.append(str(Master.index(A[pos:last_pos]))+Master[0] )
        return pos
    else:
        return last_pos

def RomanToInt(A):
    ones = ['','I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX']
    tens = ['0','X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC']
    huns = ['00','C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM']
    thos = ['000', 'M', 'MM', 'MMM']
    res=[]
    end=len(A)
    end=first_occurence(A,['I','V'], ones, res=res,last_pos=end)
    end=first_occurence(A,['X','L'], tens, res=res, last_pos=end)
    end=first_occurence(A,['C','D'], huns, res=res, last_pos=end)
    end=first_occurence(A,['M'],  thos, res=res,last_pos=end)
    res.reverse()
    num=0
    for i in range(len(res)):
        num+=int(res[i])
    return num

