#  给定一个n个字符组成的串A，一个m个字符的串B，
#  从A中到出B字符串出现的第一个位置。如果不存在，则返回-1
# 请用蛮力法和Sunday算法进行代码实现
#
# 蛮力法
# 对子字符串中每个字符都进行比较，看能否匹配

def string_match(string,sub_str):
    len_sub=len(sub_str)
    len_string=len(string)
    for i in range(len_string-len_sub+1):
        match_count=0
        for j in range(len_sub):
            if string[i+j]==sub_str[j]:
                match_count+=1
        
        if match_count==len_sub:
            return i+1
    return -1
if __name__=='__main__':
    print(string_match("adbcbdc", "dc"))

#蛮力法时间复杂度为O(nm),
#优点是思路简单，每次循环时对A与B的每个字符串进行比较。
#缺点是时间开销大。