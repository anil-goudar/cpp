def freqAlphabets(s):
        maps = {'1': 'a', '2': 'b', '3': 'c', '4': 'd', '5': 'e', 
                '6': 'f', '7': 'g', '8': 'h', '9': 'i', '10':'j',
                '11':'k', '12':'l', '13':'m', '14':'n','15':'o',
                '16':'p', '17':'q', '18':'r', '19':'s','20':'t',
                '21':'u', '22':'v', '23':'w', '24':'x', '25':'y', '26':'z'}
        
        res = ''
        
        splitted = s.split('#')

        for spl in splitted:
            if len(spl) > 2:
                for i in range(len(spl)-2):
                    res += maps[spl[i]]
                res += maps[spl[i+1:]]
            elif spl:
                res += maps[spl]
        
        return res


def lengthOfLongestSubstring(s):
        left, right = 0, 0
        longest = 0
        chars = set()
        while left < len(s) and right < len(s):
            if s[right] not in chars:
                chars.add(s[right])
                right += 1
                longest = max(longest, right - left)
            else:
                chars.remove(s[left])
                left += 1
        return longest


def firstDuplicate(arr):
    for i in range(len(arr)):
        if arr[abs(arr[i])-1] < 0:
            return arr[i]
        else:
            arr[arr[i]-1] = -arr[arr[i]-1]
    return -1

s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"
#print(freqAlphabets(s))

s = "ohxvhjdml"
print(lengthOfLongestSubstring(s))

a = [1,2,2,2,3,3]
b = [2,1,3,5,3,2]
c = [1,2,3,4,5,6]
#print(firstDuplicate(a))
print(firstDuplicate(b))
#print(firstDuplicate(c))