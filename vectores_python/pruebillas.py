import math

def sen(grados):
    return math.sin(math.radians(grados))

def cos(grados):
    return math.cos(math.radians(grados))

def arco(grados):
    return math.degrees(math.atan(div))

#def arcotan(grados):
    #return round math.degrees((math.atan(grados)))
    #return math.atan(math.radians(grados))
    #return math.atan(grados)
#print(100*cos(70))

vec_prueba = [60, 40]
angulos_prueba = [20 , 70]

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
div = sum_Vy / sum_Vx

#print('Valor de tan: ' + str(div))

Vr = ((((sum_Vx)**2) + ((sum_Vy)**2)) ** (0.5))

print('El valor del vector resultante es: ' + str(Vr))
print('Valor de angulo es: ' + str(arco(div)))