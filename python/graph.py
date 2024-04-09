
#%%
import numpy as np
import matplotlib.pyplot as plt

plt.axis([-2 * np.pi, 2 * np.pi, -1, 1])


x_values = np.linspace(-2 * np.pi, 2 * np.pi, 100)

for i in range(len(x_values)):
    y = np.sin(x_values[:i]*5)
    #plt.scatter(x_values[:i], y, color='blue')
    plt.plot(x_values[:i], y, color= 'b', linewidth = '1')
    plt.pause(0.001)

plt.ylim(-10, 10)

plt.show()
