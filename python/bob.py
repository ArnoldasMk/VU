import dearpygui.dearpygui as dpg

# Callback function for the button
def button_callback(sender, app_data, user_data):
    input_text = dpg.get_value("input_text")
    print(f"Button clicked! Input text: {input_text}")

# Creating the main window
dpg.create_context()

with dpg.window(label="Main Window", width=400, height=300):
    dpg.add_text("Hello, this is a simple Dear PyGui example.")
    dpg.add_input_text(label="Enter text here", tag="input_text")
    dpg.add_button(label="Click Me", callback=button_callback)

dpg.create_viewport(title='Simple GUI', width=600, height=400)
dpg.setup_dearpygui()
dpg.show_viewport()
dpg.start_dearpygui()
dpg.destroy_context()
