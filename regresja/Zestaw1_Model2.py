import csv
import matplotlib.pyplot as plt
listax = []
listay = []
listaf = []
listar = []
def przypisz(plik):
    listax.clear()
    listay.clear()
    if plik ==1:
        file = open("data1.csv", newline='')
    if plik ==2:
        file = open("data2.csv", newline='')
    reader = csv.reader(file)
    for row in reader:
        x = float(row[0])
        y = float(row[1])
        listax.append(x)
        listay.append(y)

def srednia(lista):
    return sum(lista)/len(lista)

def wariancja(lista):
    war = 0
    for i in range(0, len(lista)):
        war += (lista[i]-srednia(lista))**2
    return war/len(lista)
def odstan(lista):
    return wariancja(lista)**(1/2)

def kowariancja(lista1,lista2):
    kowar = 0
    for i in range(0, len(lista1)):
        kowar += (lista1[i]-srednia(lista1))*(lista2[i]-srednia(lista2))
    return kowar/len(lista1)

def policz_a(lista1,lista2):
    return kowariancja(lista1,lista2)/wariancja(lista1)

def policz_b(lista1,lista2):
    return srednia(lista2)-policz_a(lista1,lista2)*srednia(lista1)

def funkcja(lista, a,b):
    listaf.clear()
    for i in range(0,len(lista)):
        listaf.append(lista[i]*a+b)

def odmax(lista2,lista3):
    odchylenie = 0
    for i in range(0,len(lista2)):
        if(abs(lista2[i]-lista3[i])>odchylenie):
            odchylenie=abs(lista2[i]-lista3[i])
    return odchylenie

def sbr(lista2,lista3):
    blad = []
    for i in range (0,len(lista2)):
        blad.append((lista2[i]-lista3[i])**2)
    return srednia(blad)

def R2(lista2,lista3):
    licznik = 0
    mianownik = 0
    for i in range(0,len(lista2)):
        licznik+= (lista2[i]-lista3[i])**2
        mianownik += (lista2[i]-srednia(lista2))**2
    return 1-licznik/mianownik

def Roznica(lista2,lista3):
    listar.clear()
    for i in range(0, len(lista2)):
       a = (lista2[i]-lista3[i])
       listar.append(a)

def RysujWykres(lista1,lista2,lista3,lista4):
    Roznica(lista2, lista3)
    plt.scatter(lista1, lista2, color='green',label = "punkty")
    plt.plot(lista1, lista3, color='red',label ="regresja")
    plt.xlabel("Współrzędna X")
    plt.ylabel("Współrzędna Y")
    plt.title("Wykres regresja liniowa i punkty")
    plt.legend()
    plt.show()
    plt.hist(lista4)
    plt.xlabel("Wartość różnicy")
    plt.ylabel("Liczba różnic")
    plt.title("Różnice")
    plt.show()

for i in range (1,3):
    print("Dane ", i)
    przypisz(i)
    a=policz_a(listax,listay)
    b=policz_b(listax,listay)
    print("a = ", a)
    print("b = ", b)
    funkcja(listax, a, b)
    print("Odchylenie max: ", odmax(listay, listaf))
    print("Średni błąd kwadratowy: " , sbr(listay,listaf))
    print("Wartość współczynnka R2: ",R2(listay,listaf))
    print(" ")
    RysujWykres(listax,listay,listaf,listar)
