# https://www.interviewbit.com/problems/simplify-directory-path/
# https://www.geeksforgeeks.org/simplify-directory-path-unix-like/

"""

"/a/./"   --> means stay at the current directory 'a'
"/a/b/.." --> means jump to the parent directory
              from 'b' to 'a'
"////"    --> consecutive multiple '/' are a  valid  
              path, they are equivalent to single "/".


By looking at examples we can see that the above simplification process just behaves like a stack. Whenever we encounter any file’s name, we simply push it into the stack. when we come across ” . ” we do nothing. When we find “..” in our path, we simply pop the topmost element as we have to jump back to parent’s directory. 
When we see multiple “////” we just ignore them as they are equivalent to one single “/”. After iterating through the whole string the elements remaining in the stack is our simplified absolute path. We have to create another stack to reverse the elements stored inside the original stack and then store the result inside a string.
"""


def simplifyPath(A):
    # creating name of each directory and dropping "." which arises when we have "./"
    # in the string, also dropping "" arises when we have "/" in starting and ending # position of string or we have multiple "///.."
    A=[f for f in A.split("/") if (f!="." and f!="")]
    res=""
    count=0
    while(len(A)):
        if A[-1]=="..":
            # counting the number of ".." till first directory
            while(len(A)):
                if A[-1]!="..":
                    break
                count=count+1
                A.pop()
            # removing/going back to parent directory
            while(count and len(A)):
                if(A[-1]==".."):
                    break
                count=count-1
                A.pop()
        else:
            res="/"+A.pop()+res
    if res=="":
        res="/"
    return res


    




# A="/a/./b/../../c/"
# A="/fic/././iak/../../hgy/blg/../vzt/../tod/.././.././bsc/./krk/../lnb/zhj/./../lqm/tbo/ujr/./.."
A="/bku/./zjy/mia/cfr/../jss/sdg/wks/.././././../lyf/jzt/bxk/qfd/gpz/ypt/./nzh/xcn/../../../exk/../xoi/././snn/../../dbb/ayw/jhv/././evi/."
print(simplifyPath(A))
