def removePalindromeSub(s):
        if s == s[::-1]:
            return 1
        ls = list(s)
        lns = len(ls)
        c = 0
        while lns:
            while i < j:
                ln = len(ls)
                i = 0
                j = ln - 1
                if ls[i] == ls[j]:
                    del ls[j]
                    del ls[i]
                    i += 1
                    j -= 1
                    
                else:
                    j -= 1
            c +=1
            lns = len(ls)
        return c
print(removePalindromeSub("baabb"))