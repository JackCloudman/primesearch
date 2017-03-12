#Funcion para buscar los numeros primos
def buscarprimos(limite):
    #Iniciamos la lista de los numeros primos con el numero 2
    listaprimos = [2]
    #Empezamos a buscar primos desde el numero 3
    i = 3
    #Iremos avanzando de i hasta el limite
    while i <= limite:
        es_primo = True
        sqrt_limite = int(i**(0.5) + 1)
        #Para cada primo que tengamos en la lista 
        for primo in listaprimos:
            #Revisaremos que no su division no tenga residuo 0, si tiene residu 0 el ciclo for se rompe y seguimos con otro numero
            if i % primo == 0:
                es_primo = False
                break
               #Si se excede el limite salimos
            if primo >= sqrt_limite: 
                break
          #Si se conservo como "True" se guardara en la lista de primos      
        if es_primo:
            listaprimos.append(i)
        #aumentamos en 2 unidades para     
        i += 2
    print(listaprimos)
limite=int(input("Dame un numero: "))
buscarprimos(limite)
