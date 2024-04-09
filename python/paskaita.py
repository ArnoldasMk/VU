import os
import copy
import glob
import imageio
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import tqdm

def make_movie(direktorija, movie_name, fps, delete_png):
    name_list = sorted(glob.glob(os.path.join(direktorija, '*.png')))
    image_list = [imageio.imread(name) for name in name_list]
    imageio.mimsave(
        os.path.join(direktorija, f'{movie_name}.gif'),
        image_list,
        loop=0,
        fps=fps,
    )
    if delete_png:
        for name in name_list:
            os.remove(name)

class Universe:

    def __init__(self):
        self.laikas = 0   # [s]
        self.objektu_sarasas = []

    def sudek_objektus(self, objektu_sarasas):
        self.objektu_sarasas = [copy.deepcopy(objektas) for objektas in objektu_sarasas]

    def vaizduoja(self, step, direktorija):
        fig, ax1 = plt.subplots(figsize=(9, 4))

        for objektas in self.objektu_sarasas:
            ax1.scatter(*objektas.pos)
            ax1.plot(objektas.logeris['x'][-20:], objektas.logeris['y'][-20:], lw=0.5)

        ax1.set_xlim(-200e9, 200e9)
        ax1.set_ylim(-200e9, 200e9)
        ax1.set_xlabel('$x$ [m]')
        ax1.set_ylabel('$y$ [m]')
        ax1.tick_params(direction='in', top=True, right=True)
        ax1.set_title(f'$t$ = {self.laikas:.2f} s')

        fig.savefig(os.path.join(direktorija, f'{step:03d}.png'), dpi=100)
        plt.clf()
        del fig

    def sukasi(self, delta_t, n_steps, direktorija, do_movie):
        os.makedirs(direktorija, exist_ok=True)

        for step in tqdm.tqdm(range(n_steps)):
            self.laikas += delta_t

            for objektas1 in self.objektu_sarasas:
                for objektas2 in self.objektu_sarasas:
                    if objektas1.name != objektas2.name:
                        objektas1.compute_force(objektas2)

            for objektas in self.objektu_sarasas:
                objektas.juda(self.laikas, delta_t)

            if do_movie:
                self.vaizduoja(step, direktorija)

        if do_movie:
            make_movie(direktorija, '0-movie', fps=15, delete_png=True)

class Objektas:

    def __init__(self, name, mass, pos_start, v_start, a_start):
        self.name = name
        self.mass = mass
        self.pos = np.array(pos_start)
        self.v = np.array(v_start)
        self.a = np.array(a_start)
        self.force_list = []
        self.logeris = {
            'laikas': [0],
            'x': [pos_start[0]],
            'y': [pos_start[1]],
            'vx': [v_start[0]],
            'vy': [v_start[1]],
            'ax': [a_start[0]],
            'ay': [a_start[1]],
            'E': [self.get_energy()]
        }

    def get_energy(self):
        e_kin = 0.5 * self.mass * np.sum(self.v**2)
        e_pot = 0
        return e_kin + e_pot

    def compute_force(self, other):
        G = 6.67e-11
        dpos = other.pos - self.pos
        R = np.sqrt(np.sum(dpos**2))
        F = G * self.mass * other.mass / R**2
        self.force_list.append((dpos / R) * F)

    def juda(self, laikas, delta_t):
        F = np.sum(self.force_list, axis=0)
        self.force_list = []
        self.a = F / self.mass
        self.v += self.a * delta_t
        self.pos += self.v * delta_t
        self.logeris['laikas'].append(laikas)
        self.logeris['x'].append(self.pos[0])
        self.logeris['y'].append(self.pos[1])
        self.logeris['vx'].append(self.v[0])
        self.logeris['vy'].append(self.v[1])
        self.logeris['ax'].append(self.a[0])
        self.logeris['ay'].append(self.a[1])
        self.logeris['E'].append(self.get_energy())

universe = Universe()

def create_objektas(name, mass, pos_start, v_start, a_start):
    return Objektas(
        name=name,
        mass=mass,
        pos_start=np.array(pos_start),
        v_start=np.array(v_start),
        a_start=np.array(a_start)
    )

obj1 = create_objektas('Saule', 1.989e30, [0, 0], [0, 0], [0, 0])

v_start = [0, 150e9 * 2 * np.pi / (365.25 * 24 * 60 * 60)]
obj2 = create_objektas('Zeme', 5.972e24, [150e9, 0], v_start, [0, 0])
obj3 = create_objektas('Zeme2', 5.972e24, [150e9, 1e9], v_start, [0, 0])
obj4 = create_objektas('Zeme3', 5.972e24, [150e9, -1e9], v_start, [0, 0])

objektu_sarasas = [obj1, obj2, obj3, obj4]

universe.sudek_objektus(objektu_sarasas)

universe.sukasi(
    delta_t=24 * 60 * 60,
    n_steps=1,
    direktorija='eksperimentas3',
    do_movie=True
)