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