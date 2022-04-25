import numpy as np

def med(vec):
    #print(vec)
    cont = 0
    media = 0
    # Ciclo que se puede omitir si directamente ponemos la cantidad de ultrasónicos
    for i in vec:
        cont = cont + 1
        print(cont)
    
    print(cont)
    return ((vec.sum()) / cont)

# Prueba de valores de los ultrasónicos
# Alch no sé como piensas pasarle los valores reales pa no le sé al pov xd
# Pero creo recordar que tenías una declaración de cada uno de ellos por ahí, así que jala papi
vec = np.array([51, 5, 15, 51, 51, 51, 51])

#print(vec.sum())

print(med(vec))


"""
la entrada esperada es un vector de tamaño 7, con las medidas mas recientes de los ultrasonicos (son 7), cada uno con un rango de (0,51) cm.
Cada vector ya trae un angulo dependiendodel indice, son los siguientes:

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
