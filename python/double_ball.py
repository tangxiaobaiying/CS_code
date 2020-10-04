import random
import time

for i in range(5):
    num_red=[]
    for i in range(6):
        data=random.randint(1,33)
        time.sleep(1)
        while True:
            if data in num_red:
                data = random.randint(1, 33)
            else:
                break
        num_red.append(data)
        # print(data)
    num_blue=random.randint(1,16)
    print(num_red,'--',num_blue)

# test=str(input('jdskfj:'))
# if test=='':
#     test='error'
# print(test)