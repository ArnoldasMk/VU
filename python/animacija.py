import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

class AnimatedFunctionPlot:
    def __init__(self, ax, function, function_name, x_limit=(-10, 10), y_limit=(-10, 10), frames=100):
        self.ax = ax
        self.function = function
        self.function_name = function_name
        self.x_values = np.linspace(x_limit[0], x_limit[1], frames)
        self.points, = self.ax.plot([], [], 'bo', label='', color = 'g')  

        self.ax.set_title(f'Function Plot: {self.function_name}', fontsize=15, y=-0.15)
        self.ax.figure.suptitle(f'Plot of {self.function_name}(x)', fontsize=15, y=0.92)
        self.ax.set_xlabel('x')
        self.ax.set_ylabel(f'{self.function_name}(x)')

        self.ax.set_xlim(*x_limit)
        self.ax.set_ylim(*y_limit)

        self.animation = FuncAnimation(self.ax.figure, self.update, frames=len(self.x_values),
                                       init_func=self.init, blit=True, interval=20)

        self.animation_running = True
        self.animation.event_source.stop()  

    def init(self):
        self.points.set_data([], [])
        return self.points,

    def update(self, frame):
        y_values = self.function(self.x_values[:frame])
        self.points.set_data(self.x_values[:frame], y_values)

        if frame == len(self.x_values) - 1:
            self.animation.event_source.stop()
            self.animation_running = False

        return self.points,

    def show_animation(self):
        self.ax.legend().set_visible(True)  
        plt.show()  

fig, ax = plt.subplots(figsize=(10, 6))
animated_function = AnimatedFunctionPlot(ax, np.sin , 'x^2' , x_limit=(-3, 3), y_limit=(-1.1, 1.1))
animated_function.show_animation()

# animated_function = AnimatedFunctionPlot(ax, np.cos)
# animated_function.show_animation()

# fig, ax = plt.subplots(figsize=(10, 6))
# animated_function = AnimatedFunctionPlot(ax, np.sin)
# animated_function.show_animation()
