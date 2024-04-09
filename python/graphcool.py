import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.animation import FuncAnimation
import threading
import numpy as np

theta = np.linspace(0, 2*np.pi)

# initial data
x = np.cos(theta - np.pi/2)
y = np.sin(theta - np.pi/2)
z = theta

# creating the first plot and frame
fig, ax = plt.subplots(subplot_kw=dict(projection='3d'), dpi=300)
graph, = ax.plot(x, y, z, color='red')

# updates the data and graph
def update(frame):
    global graph

    # updating the data
    theta_new = np.linspace(0, 2*np.pi + frame/50)
    x_new = np.cos(theta_new - np.pi/2)
    y_new = np.sin(theta_new - np.pi/2)
    z_new = theta_new

    # updating the graph
    graph.set_data(x_new, y_new)
    graph.set_3d_properties(z_new)
    ax.set_xlim([min(x_new), max(x_new)])
    ax.set_ylim([min(y_new), max(y_new)])
    ax.set_zlim([min(z_new), max(z_new)])

    # Set title with frame number
    ax.set_title('Frame {}'.format(frame))

def animate():
    anim = FuncAnimation(fig, update, frames=8000, interval=1, repeat=False)
    plt.show()

# Create a separate thread for animation
animation_thread = threading.Thread(target=animate)
animation_thread.start()
