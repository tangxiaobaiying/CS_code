#Sunday算法
#1首先将两个字符串对齐（使用两个指针），比较两个字符串的首个字符。（其中A指针位置为a，B指针位置为b）
#2  若首个匹配，则进行第二个字符的比较
#3  若首个字符不匹配，则判断字符串A在m+1(m为字符串B的长度)位置的字符是否匹配字符串B中的字符。
#4       若不匹配，则将字符串B的起始位置与字符串A的b+2位置对其，则程序转移到第2步，直至匹配
#5       若匹配，则记录下B中被匹配到字符的位置c，将B的首个字符与字符串A的位置a+c-1对齐
def string_match(string,sub_str):
    len_sub = len(sub_str)
    len_string = len(string)
    # for i in range(len_string-len_sub+1):
    i=0
    while True:
        if i>=len_string-len_sub+1:
            return -1
        # print('--------->',i)
        match_count=True
        for j in range(len_sub):
            if string[i + j] != sub_str[j]:
                match_count =False
                break
        if not match_count:
            t = i + len_sub
            m=0
            if t < len_string:
                for j in range(len_sub):
                    if string[t] == sub_str[j]:
                        # i = i + len_sub - j
                        m= t - j
                    else:
                        # if t!=0:        #判断条件,避免覆盖if条件的t值
                        #     continue    #
                        if m!=0:
                            continue
                        if j == len_sub - 1:
                        #   i = i + len_sub     取变量t是为了固定每次循环中的i值。
                            m=t
                i=m
            else:
                return -1
        else:
            return i
if __name__=='__main__':
    print(string_match("mississippi","issip"))
    # string_match("adbcbdc", "dc")