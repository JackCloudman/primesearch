def buscarprimos(limitee):
    listaprimos = [2]
    i = 3
    while i <= limite:
        es_primo = True
        sqrt_limite = int(i**(0.5) + 1)
        for primo in listaprimos:
            if i % primo == 0:
                es_primo = False
                break
            if primo >= sqrt_limite: 
                break
        if es_primo:
            listaprimos.append(i)
        i += 2
    print(listaprimos)
limite=int(input("Dame un numero: "))
buscarprimos(limite)