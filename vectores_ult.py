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

def med(vec):
    #print(vec)
    cont = 0
    media = 0
    # Ciclo que se puede omitir si directamente ponemos la cantidad de ultrasónicos
    for i in vec:
        cont = cont + 1
        media = i + media
        print(cont)
        print(media)
    
    print(cont)
    return (media / cont)

def cos(grados):
    return math.cos(math.radians(grados))

def sen(grados):
    return math.sin(math.radians(grados))

#Arco function that return the degree of the input
def arco(grados):
    return math.degrees(math.atan(grados))

# Prueba de valores de los ultrasónicos
# Alch no sé como piensas pasarle los valores reales pa no le sé al pov xd
# Pero creo recordar que tenías una declaración de cada uno de ellos por ahí, así que jala papi

vec = [51, 5, 15, 51, 51, 51, 51]
angulos = [90, 225, 180, 135, 45, 0, 315]

vec_prueba = [100, 80, 150]
angulos_prueba = [70, 210, 310]

#print(med(vec))

# Vx es la agrupacion de todos los vectores 
Vx = 0
Vy = 0
sum_Vx = 0
sum_Vy = 0

# for para sacar la suma del vector Vx y Vy
for i in range(len(vec_prueba)):
    Vx = vec_prueba[i] * cos(angulos_prueba[i])
    Vy = vec_prueba[i] * sen(angulos_prueba[i])
    print('La operacion hasta el momento acumula: ' + str(Vx))
    sum_Vx = sum_Vx + Vx
    sum_Vy = sum_Vy + Vy
print('Valor de la suma del vector de X: ' + str(sum_Vx))
print('Valor de la suma del vector de Y: ' + str(sum_Vy))

Vr = ((((sum_Vx)**2) + ((sum_Vy)**2)) ** (0.5))

div = sum_Vy / sum_Vx
A = arco(div)

if A < 0:
    A = A + 180

print('Valor del vector resultante: ' + str(Vr))
print('Valor del angulo: ' + str(A))

