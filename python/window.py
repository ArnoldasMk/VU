import numpy as np
import dearpygui.dearpygui as dpg

sindatax = np.linspace(0, 2 * np.pi, 1000)
sindatay = 0.5 + 0.5 * np.sin(sindatax)
width = 1920
height = 1080
dpg.create_context()
dpg.create_viewport(title='Custom Title', width=width, height=height)

with dpg.window(label='Example Window', autosize=True):

    with dpg.plot(label="Scatter Series", height=height, width=width):  # Modified width and height parameters
        dpg.add_plot_legend()
        x_axis = dpg.add_plot_axis(dpg.mvXAxis, label="x")
        y_axis = dpg.add_plot_axis(dpg.mvYAxis, label="y")
        dpg.add_scatter_series(sindatax, sindatay, label="0.5 + 0.5 * sin(x)", parent=x_axis)

dpg.setup_dearpygui()
dpg.show_viewport()
dpg.start_dearpygui()
dpg.destroy_context()