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

# Prueba de valores de los ultrasónicos
# Alch no sé como piensas pasarle los valores reales pa no le sé al pov xd
# Pero creo recordar que tenías una declaración de cada uno de ellos por ahí, así que jala papi

vec = [51, 5, 15, 51, 51, 51, 51]

print(med(vec))