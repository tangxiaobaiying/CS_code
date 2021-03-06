## numpy 常用函数

+ column_stack( (a , b) )

  列合并

+ row_stack( (a , b) )

  行合并

  ```python
  >>> import numpy as np
  >>> a=np.arange(16).reshape(4,-1)
  >>> a
  array([[ 0,  1,  2,  3],
         [ 4,  5,  6,  7],
         [ 8,  9, 10, 11],
         [12, 13, 14, 15]])
  >>> b=np.arange(16,32).reshape(4,-1)
  >>> b
  array([[16, 17, 18, 19],
         [20, 21, 22, 23],
         [24, 25, 26, 27],
         [28, 29, 30, 31]])
  >>> test=np.row_stack((a,b))#行合并
  >>> test
  array([[ 0,  1,  2,  3],
         [ 4,  5,  6,  7],
         [ 8,  9, 10, 11],
         [12, 13, 14, 15],
         [16, 17, 18, 19],
         [20, 21, 22, 23],
         [24, 25, 26, 27],
         [28, 29, 30, 31]])
  >>> test=np.column_stack((a,b))#列合并
  >>> test
  array([[ 0,  1,  2,  3, 16, 17, 18, 19],
         [ 4,  5,  6,  7, 20, 21, 22, 23],
         [ 8,  9, 10, 11, 24, 25, 26, 27],
         [12, 13, 14, 15, 28, 29, 30, 31]])
  
  ```

+ np.zeros(shape=（a,b,c...）,dtype=（默认为float类型）,order=(默认为“C”))

  **numpy.zeros()的作用：通常是把数组转换成想要的矩阵；默认元素全部为0**

  shape是指形状：一维，二维等等。

+ np.ones((shape=（a,b,c...）,dtype=（默认为float类型）,order=))

  同上，初始值为1

+ np.reshape()

  变量名.reshape((m,n)),返回一个m行n列的数组 ,其中mxn必须要等于原数组元素个数。

  变量名.reshape((-1)),返回一个一维数组 

  变量名.reshape((-1,n)),返回一个n列的数组，行数自动给定

  变量名.reshape((n,-1)),返回一个n行的数组，列数自动给定
  
+ numpy.linalg.inv()

  求矩阵的逆

+ numpy.dot(a,b)

  求矩阵的点乘

+ X.transpose()

  求矩阵的转置

+ numpy.square()

  求矩阵的平方

+ numpy.average()

  求矩阵的平均值



