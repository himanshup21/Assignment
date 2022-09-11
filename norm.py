import math
import numpy as np

# Generating random float (2*100) matrix having entries in between (0,100)
A = np.random.rand(100,2)*100

max_p_norm = [] # for max p-norm ||Ax||, 0th entry is for infinity norm

for p in range(7):
    max_norm = 0
    for i in range(1000):
        # Generating random unit vector
        x = np.random.random(2)
        # Normalization
        if p==0 : x = x/np.linalg.norm(x, ord = np.inf)
        else : x = x/np.linalg.norm(x, ord = p)

        Ax = np.dot(A,x)    # Matrix Multiplication

        # Evaluation of p-norm ||Ax|| 
        if p==0 :
            p_norm = np.linalg.norm(Ax, ord = np.infty)
        else :
            p_norm = np.linalg.norm(Ax, ord = p)
        
        if (p_norm > max_norm):     # Tracking max value
            max_norm = p_norm

    max_p_norm.append(max_norm)

# max p-norm ||Ax||
print("max ||Ax|| for inf norm ",max_p_norm[0])
[print(f"max ||Ax|| for {i} norm {max_p_norm[i]}") for i in range(1,7)]
print("\n")

# exact p-norm ||Ax||
exact_norm = [np.linalg.norm(A, ord=i) for i in [np.infty,1,2]]

print("||A|| inf norm ",exact_norm[0])
[print(f"||A|| {i} norm {exact_norm[i]}") for i in range(1,3)]

