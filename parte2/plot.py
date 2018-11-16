import numpy as np

import matplotlib
matplotlib.use("Agg")

import matplotlib.pyplot as plt

N=np.ones(7)
for i in range(len(N)):
    N[i]*=(10**(i+2))

# Leer archivos 
integrals = []
for i in range(len(N)):
    fname = 'File_%d.txt'%(i+2)
    a = np.loadtxt(fname)
    integrals.append(a)
    
def integral_analitica():
    return 155/6

# Calculo de error porcentual
a=integral_analitica()
diferencias=np.zeros(len(N))
for i in range(len(N)):
    b=integrals[i]
    diferencias[i] =  (np.abs((a-b)/a))

    
# Grafica
plt.plot(N,diferencias)
plt.xscale("log")
plt.yscale("log")
plt.xlabel("N")
plt.ylabel("Error porcentual")
plt.savefig("error_vs_N.pdf")
    