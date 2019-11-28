import numpy as np
from matplotlib import pylab as pl
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from matplotlib import cm



x=[]
y=[]
yf=[]
l=1.0
t=6.0
nx=101
nt=300
dx=l/nx

datos = np.loadtxt("datos.dat")
malla = np.reshape(datos, (nx, nt))
t1 = np.linspace(0, t, nt)
l1 = np.linspace(0, l, nx)
ll, tt = np.meshgrid(t1, l1)   #grid para la grafica


plt.figure()
for ix in range(nx):
    x.append(dx*ix)
    y.append(malla[ix][0])
    yf.append(malla[ix][nt-1])
    plt.plot(x,y)
    plt.plot(x,yf)
    plt.xlabel("X(m)")
    plt.ylabel("Despl(m)")
    #plt.gca().legend(("ti"))
plt.savefig("normal.png")




img = plt.figure()
xx = img.gca(projection='3d')
xx.set_xlabel('tiempo(seg)')
xx.set_ylabel('X(m)')
xx.set_zlabel('Despl(m)')
surf = xx.plot_surface(ll, tt, malla,cmap=cm.coolwarm)
img.colorbar(surf)
plt.savefig("plot3d.png")


