"""
la entrada esperada es un vector de tamaño 7, con las medidas mas recientes de los ultrasonicos (son 7), cada uno con un rango de (0,51) cm.
Cada vector ya trae un angulo dependiendo del indice, son los siguientes:
0: 90°
1: 225°
2: 180°
3: 135°
4: 45°
5: 0°
6: 315°
   3   0   4
    \  |  /
2 --       -- 5
    /     \ 
    1      6
    
la salida que se espera es una tupla que representen la magnitud y el angulo del vector resultante por ejemplo:
(5, 90) # significa que el vector resultante es de magnitud 5 y con angulo de 90 grados
"""

import math


def cos(grados):
    return math.cos(math.radians(grados))


def sen(grados):
    return math.sin(math.radians(grados))


# Arco function that return the degree of the input
def arco(grados):
    return math.degrees(math.atan(grados))


def calculate_vector(distance_vector: list[float], angle_vector: list[int]) -> tuple[float, float, float, float]:
    vx = 0
    vy = 0
    sum_vx = 0
    sum_vy = 0

    # for para sacar la suma del vector Vx y Vy
    for i in range(len(distance_vector)):
        vx = distance_vector[i] * cos(angle_vector[i])
        vy = distance_vector[i] * sen(angle_vector[i])
        sum_vx = sum_vx + vx
        sum_vy = sum_vy + vy

    result_vector = (sum_vx**2 + sum_vy**2) ** 0.5

    div = sum_vy / sum_vx
    angle_result_vector = arco(div)

    if sum_vy < 0:
        angle_result_vector += 180

    return sum_vx, sum_vy, angle_result_vector, result_vector


# Prueba de valores de los ultrasónicos
# Alch no sé como piensas pasarle los valores reales pa no le sé al pov xd
# Pero creo recordar que tenías una declaración de cada uno de ellos por ahí, así que jala papi
def main():
    vec = [0.0, 51, 52, 51, 51, 51, 51]
    angulos = [90, 225, 180, 135, 45, 0, 315]

    sum_vx, sum_vy, angle_result_vector, result_vector = calculate_vector(vec, angulos)

    print(f"El vector resultante es de magnitud {result_vector} y con angulo de {angle_result_vector} grados")
    print(f"Los componentes del vector son {sum_vx} en X, {sum_vy} en Y")


if __name__ == "__main__":
    main()
