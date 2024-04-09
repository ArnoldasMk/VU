import numpy as np
import matplotlib.pyplot as plt


class Model:

    def __init__(self, k, b):
        self.k = k
        self.b = b

    def evaluate(self, x):
        return self.k * x + self.b
        # modelis turi duoti vienareiksmiska y prie duoto x - be atsitiktinumo


class Experiment:

    def __init__(self, model, sigma_error_true):
        self.model = model
        self.sigma_error_true = sigma_error_true

    def run(self, x_min, x_max, num_points):
        x_list = np.linspace(x_min, x_max, num_points)
        y_true_list = self.model.evaluate(x_list)  # laisvo kritimo pagreitis tikrasis (gamtos)

        sigma_error_true = 0.5   # neapibreztumas, kuri nusakome Gauso skirstiniu
        # (kai yra daug neapibreztuma sukelianciu veiksniu)
        # klaidos, kurias padarome atlikdami matavimus
        error_list = np.random.normal(0, sigma_error_true, num_points)

        # neturim galimybes tiksliai nustatyti kokia klaida padareme atlikdami konkretu matavima
        y_measured_list = y_true_list + error_list   # tai ka ismatuojame (nufotografuojame)

        plt.scatter(x_list, y_measured_list, c='k', alpha=1)
        plt.plot(x_list, y_true_list, c='g')
        plt.xlabel('x')
        plt.ylim(5, 15)

        # duomenu analize
        y_data_mean = np.mean(y_measured_list)

        plt.axhline(y_data_mean, c='r')

model = Model(k=0, b=9.8)
experiment = Experiment(model=model, sigma_error_true=0.5)
experiment.run(x_min=0, x_max=10, num_points=20)
