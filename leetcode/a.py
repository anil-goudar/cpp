import string
def breakPalindrome(palindrome):
        if len(palindrome) == 0 or len(palindrome) == 1:
            return ""
        ls = []
        for a in palindrome:
            ls.append(a)
        
        
        replace = list(string.ascii_lowercase)
        
        ln = len(ls)           
        
        for i in range(ln):
            idx = replace.index(ls[i])
            j = 0
            if idx > 0:
                while j < idx:
                    curr = ls.copy()
                    curr[i] = replace[j]
                    idx -= 1
                    j += 1
                    st = "".join(curr)
                    if st != st[::-1]:
                        return st
            elif idx == 0 and i > 0 and (ls[i] not in ls[i+1:]):
                curr = ls.copy()
                curr[i] = "b"
                st = "".join(curr)
                if st != st[::-1]:
                    return st
                
        return ""

sr = "aabaa"
print(breakPalindrome(sr))