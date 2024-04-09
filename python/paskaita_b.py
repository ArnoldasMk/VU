import os
import copy
import glob
import tqdm
import imageio
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt


def make_movie(direktorija, movie_name, fps, delete_png):
    image_list = []
    name_list = sorted(glob.glob(f'{direktorija}/*.png'))   # TODO
    for name in name_list:
        image = imageio.imread(name)
        image_list.append(image)
    imageio.mimsave(
        f'{direktorija}/{movie_name}.gif',
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
        # TODO uztikrinti, kad objektu vardai (name) yra unikalus,
        # t.y. nera besidubliuojanciu
        for objektas in objektu_sarasas:
            objektas = copy.deepcopy(objektas)
            self.objektu_sarasas.append(objektas)

    def vaizduoja(self, step, direktorija):
        fig, (ax1, ax2) = plt.subplots(
            1, 2,
            figsize=(9, 4)   # coliai / inches
        )

        # x, y -> pos[0], pos[1]
        # vx, vy -> v[0], v[1]
        # ax, ay -> a[0], a[1]

        for objektas in self.objektu_sarasas:
            ax1.scatter(
                objektas.pos[0],
                objektas.pos[1],
            )
            ax1.plot(
                objektas.logeris['x'][-20:],   # [paiso 5 paskutiniu zingsniu uodegas]
                objektas.logeris['y'][-20:],
                lw=0.5
            )
        ax1.set_xlim(-200e9, 200e9)
        ax1.set_ylim(-200e9, 200e9)
        ax1.set_xlabel('$x$ [m]')
        ax1.set_ylabel('$y$ [m]')
        ax1.tick_params(
            direction='in',
            top=True,
            right=True
        )
        ax1.set_title(f'$t$ = {self.laikas:.2f} s')
        # ax2.set_title(f'$E$ = {self.objektu_sarasas[0].get_energy():.3f} J')
        fig.savefig(f'{direktorija}/{step:03d}.png', dpi=100)
        plt.clf()
        del fig

    def sukasi(self, delta_t, n_steps, direktorija, do_movie):
        if not os.path.exists(direktorija):
            os.mkdir(direktorija)
        # delta_t [s]
        for step in tqdm.tqdm(range(n_steps)):
            self.laikas += delta_t

            for objektas1 in self.objektu_sarasas:
                for objektas2 in self.objektu_sarasas:
                    if objektas1.name != objektas2.name:
                        # print(objektas1.name, objektas2.name)
                        objektas1.compute_force(objektas2)

            for objektas in self.objektu_sarasas:
                objektas.juda(self.laikas, delta_t)

            if do_movie:
                self.vaizduoja(step, direktorija)
        if do_movie:
            make_movie(direktorija, '0-movie', fps=15, delete_png=True)


class Objektas:

    def __init__(self,
                 name,
                 mass,
                 pos_start,
                 v_start,
                 a_start):

        self.name = name
        self.mass = mass       # [kg]
        self.pos = pos_start   # [m]
        self.v = v_start       # [m/s]
        self.a = a_start       # [m/s^2]

        self.force_list = []   # kaupiame kitu objektu traukos jegas

        self.logeris = {
            'laikas': [0],   # TODO laikas 0
            'x': [pos_start[0]],
            'y': [pos_start[1]],
            'vx': [v_start[0]],
            'vy': [v_start[1]],
            'ax': [a_start[0]],
            'ay': [a_start[1]],
            'E': [self.get_energy()]
        }

    def get_energy(self):
        # TODO testuoti
        v2 = np.sum(self.v**2)
        e_kin = self.mass * v2 / 2
        # e_pot = self.mass # TODO ???? gravitacinio lauko potencine energija
        e_pot = 0   # TODO
        return e_kin + e_pot

    def compute_force(self, other):
        # kokia jega self objektas bus veikiamas other objekto
        # F = G * m1 * m2 / R^2
        # F = [Fx, Fy]
        G = 6.67e-11   # [m^3 kg^-1 s^-2]
        m1 = self.mass
        m2 = other.mass
        # vektorius (dx, dy) is self i other
        # dx = other.x - self.x   # [m]
        # dy = other.y - self.y

        dpos = other.pos - self.pos
        # pos = [x, y]
        # dpos = [dx, dy]
        # dpos**2 = [dx**2, dy**2]

        # atstumas R
        # R = np.sqrt(dx**2 + dy**2)   # [m]
        R = np.sqrt(np.sum(dpos**2))

        # vienetinis krypties (rx, ry) vektorius
        # rx = dx / R    # [be matavimo vienetu]
        # ry = dy / R

        # rx, ry = dx / R, dy / R
        # rx, ry = [dx, dy] / R
        r = dpos / R

        F = G * m1 * m2 / R**2   # [N]

        # is panasiu trikampiu (nes jega veikia isilgai R)
        # fx / F = dx / R = rx
        # fy / F = dy / R = ry
        # fx = rx * F
        # fy = ry * F

        # F = [rx, ry] * F
        F = r * F

        # F = [fx, fy]
        self.force_list.append(F)

    def juda(self, laikas, delta_t):
        # suskaiciuoti jegu atstojamaja
        # ir padalinus is mases gauti pagreiti
        # self.force_list = []

        # print('\n\n\n')
        # print(self.force_list)

        # jegu atstojamoji, kuri veikia objekta
        # Fx = 0
        # Fy = 0
        # for F in self.force_list:
        #     fx, fy = F
        #     Fx += fx
        #     Fy += fy

        # eilutes - objektai, stulpeliai - xyz komponentes
        force_matrix = np.array(self.force_list)
        # [Fx, Fy] - atstojamosios jegos komponentes
        F = np.sum(force_matrix, axis=0)

        self.force_list = []

        # self.ax = Fx / self.mass
        # self.ay = Fy / self.mass

        # [ax, ay]
        self.a = F / self.mass

        # self.vx += self.ax * delta_t
        # self.vy += self.ay * delta_t

        print(self.v)
        print(self.a * delta_t)


        self.v += self.a * delta_t

        # self.x += self.vx * delta_t
        # self.y += self.vy * delta_t

        self.pos += self.v * delta_t

        # v = [vx, vy, vz]

        self.logeris['laikas'].append(laikas)
        self.logeris['x'].append(self.pos[0])
        self.logeris['y'].append(self.pos[1])
        self.logeris['vx'].append(self.v[0])
        self.logeris['vy'].append(self.v[1])
        self.logeris['ax'].append(self.a[0])
        self.logeris['ay'].append(self.a[1])
        self.logeris['E'].append(self.get_energy())


universe = Universe()

obj1 = Objektas(
    name='Saule',
    mass=1.989e30,
    pos_start=np.array([0., 0.]),  # TODO iskelti np.array i __init__
    v_start=np.array([0., 0.]),  # m/s
    a_start=np.array([0., 0.]), # m/s / s
)

obj2 = Objektas(
    name='Zeme',
    mass=5.972e24,
    pos_start=np.array([150e9, 0]),  # TODO iskelti np.array i __init__
    v_start=np.array([0, 150e9 * 2 * 3.141 / (365.25 * 24 * 60 * 60)]),  # m/s
    a_start=np.array([0., 0.]), # m/s / s
)

obj3 = Objektas(
    name='Zeme2',
    mass=5.972e24,
    pos_start=np.array([150e9, 1e9]),  # TODO iskelti np.array i __init__
    v_start=np.array([0, 150e9 * 2 * 3.141 / (365.25 * 24 * 60 * 60)]),  # m/s
    a_start=np.array([0., 0.]), # m/s / s
)

obj4 = Objektas(
    name='Zeme3',
    mass=5.972e24,
    pos_start=np.array([150e9, -1e9]),  # TODO iskelti np.array i __init__
    v_start=np.array([0, 150e9 * 2 * 3.141 / (365.25 * 24 * 60 * 60)]),  # m/s
    a_start=np.array([0., 0.]), # m/s / s
)

objektu_sarasas = [obj1, obj2, obj3, obj4]

universe.sudek_objektus(objektu_sarasas)

universe.sukasi(
    delta_t=24 * 60 * 60,
    n_steps=100,
    direktorija='eksperimentas4',
    do_movie=True
)

# 1 paleist pav paisyma su kinematika
# 2 gravitacines jegos skaiciavimas

# TODO kodel 2 kunu jegos sarase, kai du kunai

# pavaizduoti greicius
# kaip pasikeicia periodas pakeitus greiti prie to paties atstumo