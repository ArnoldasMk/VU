import numpy as np
import dearpygui.dearpygui as dpg
import dearpygui.demo as demo

sindatax = np.linspace(0, 2 * np.pi, 100)
sindatay = 0.5 + 0.5 * np.sin(sindatax)

dpg.create_context()
dpg.create_viewport(title='Custom Title', width=1920, height=1080)

with dpg.window(label='Example Window'):
    dpg.add_text('Hello, dearpygui!')

    with dpg.plot(label="Scatter Series", height=400, width=-1):
        dpg.add_plot_legend()
        dpg.plot_axis(dpg.mvXAxis, label="x")
        with dpg.plot_axis(dpg.mvYAxis, label="y"):
            dpg.add_scatter_series(sindatax, sindatay, label="0.5 + 0.5 * sin(x)")
dpg.setup_dearpygui()
dpg.show_viewport()
dpg.start_dearpygui()
dpg.destroy_context()