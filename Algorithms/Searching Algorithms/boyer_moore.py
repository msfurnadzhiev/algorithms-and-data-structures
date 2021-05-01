def boyer_moore(text, pattern):
    
    n = len(text)
    m = len(pattern)

    if m == 0:
        return 0
    
    dic = {}

    for i in range(m):
        dic[pattern[i]] = i

    i = m - 1
    j = m - 1

    while i < n:
        if text[i] == pattern[j]:
            if j == 0:
               return i
            i -= 1
            j -= 1
        else:
            k = dic.get(text[i], -1)
            i += m - min(j, k+1)
            j = m - 1
    
    return -1


if __name__ == "__main__":

    text = "cozacocacolacococacola"
    pattern = "cocacola"

    print(boyer_moore(text, pattern))
