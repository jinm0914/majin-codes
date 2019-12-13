'''
=========================
Automatic Text Offsetting
=========================

This example demonstrates mplot3d's offset text display.
As one rotates the 3D figure, the offsets should remain oriented the
same way as the axis label, and should also be located "away"
from the center of the plot.

This demo triggers the display of the offset text for the x and
y axis by adding 1e5 to X and Y. Anything less would not
automatically trigger it.
'''
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np
from matplotlib import cm

fig = plt.figure()
ax = fig.gca(projection='3d')

X, Y = np.mgrid[-10:20:0.25,-5.4:5.4:0.25]
Z = 0.1*(np.sin(np.pi*2/3.6*Y-1.8)+1)

ax.plot_surface(X , Y , Z, cmap=cm.coolwarm, cstride=2, rstride=2)

ax.set_xlabel("X label")
ax.set_ylabel("Y label")
ax.set_zlabel("Z label")
ax.set_zlim(0, 2)

plt.show()
