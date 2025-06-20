import numpy as np
import time as t

dim1=np.random.randint(300, 500)
dim2=np.random.randint(300, 500)
dim3=np.random.randint(300, 500)
mat_a=np.random.randn(dim1,dim2)*10
mat_a=mat_a.astype(np.int64)
mat_b=np.random.randn(dim2,dim3)*10
mat_b=mat_b.astype(np.int64)
start=t.time()
mat_c=np.matmul(mat_a,mat_b)
end=t.time()

np.savetxt('src/aux_py/matrix_a.txt',mat_a)
np.savetxt('src/aux_py/matrix_b.txt',mat_b)
np.savetxt('src/aux_py/matrix_c.txt',mat_c)
print(end-start)