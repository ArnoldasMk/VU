#%%
import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.animation import FuncAnimation

theta = np.linspace(0, 2*np.pi)

# initial data
x = np.cos(theta - np.pi/2)
y = np.sin(theta - np.pi/2)
z = theta

# creating the first plot and frame
fig, ax = plt.subplots(subplot_kw=dict(projection='3d'))
graph = ax.stem(x, y, z)[0]

# updates the data and graph
def update(frame):
    global graph

    # updating the data
    theta_new = np.linspace(0, 2*np.pi + frame/50)
    x_new = np.cos(theta_new - np.pi/2)
    y_new = np.sin(theta_new - np.pi/2)
    z_new = theta_new

    # updating the graph
    graph.remove()  # remove the old stem plot
    graph = ax.stem(x_new, y_new, z_new)[0]

anim = FuncAnimation(fig, update, frames=np.linspace(0, 2*np.pi, 100), repeat=False)
plt.show()




# %%
#%%

import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.animation import FuncAnimation

theta = np.linspace(0, 2*np.pi)

# initial data
x = np.cos(theta - np.pi/2)
y = np.sin(theta - np.pi/2)
z = theta

# creating the first plot and frame
fig, ax = plt.subplots(subplot_kw=dict(projection='3d'), dpi=300)
graph = ax.plot(x, y, z, color='red')[0]

# updates the data and graph
def update(frame):
    global graph

    # updating the data
    theta_new = np.linspace(0, 2*np.pi + frame/50)
    x_new = np.cos(theta_new - np.pi/2)
    y_new = np.sin(theta_new - np.pi/2)
    z_new = theta_new

    # updating the graph
    graph.remove()  # remove the old stem plot
    graph = ax.plot(x_new, y_new, z_new, color='red')[0]

anim = FuncAnimation(fig, update, frames=60000, interval=5, repeat=False)
plt.show()


