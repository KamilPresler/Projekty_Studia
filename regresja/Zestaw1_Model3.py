import csv
import math
import numpy
from numpy import linalg
import matplotlib.pyplot as plt
listax = []
listay = []
listasin = []
listaf = []
listar = []
def przypisz(plik):
    listax.clear()
    listay.clear()
    listasin.clear()
    if plik ==1:
        file = open("data1.csv", newline='')
    if plik ==2:
        file = open("data2.csv", newline='')
    reader = csv.reader(file)
    for row in reader:
        x = float(row[0])
        y = float(row[1])
        sinx = math.sin(float(row[0]))
        listax.append(x**2)
        listay.append(y)
        listasin.append(sinx)

def srednia(lista):
    return sum(lista)/len(lista)

def wariancja(lista):
    war = 0
    for i in range(0, len(lista)):
        war += (lista[i]-srednia(lista))**2
    return war/len(lista)
def odstan(lista):
    return wariancja(lista)**(1/2)

def policz(lista1,lista2,lista3):
    X = numpy.zeros(shape=(len(lista1), 3))
    Y = numpy.zeros(shape=(len(lista3), 1))
    for i in range(0, len(lista1)):
        X[i] = [1, lista1[i], lista2[i]]
        Y[i] = [lista3[i]]
    A = linalg.inv((X.transpose() @ X)) @ X.transpose() @ Y
    return A

def funkcja(lista1,lista2,a,b,c):
    listaf.clear()
    for i in range(0, len(lista1)):
        listaf.append(lista1[i] * a + lista2[i] * b + c)


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
    przypisz(1)


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

for i in range(1, 3):
    print("Dane", i)
    przypisz(i)
    M = policz(listax,listasin,listay)
    a=float(M[1])
    b=float(M[2])
    c=float(M[0])
    print("a = ", a)
    print("b = ", b)
    print("c = ", c)
    funkcja(listax, listasin, a, b, c)
    print("Odchylenie max: ", odmax(listay, listaf))
    print("Średni błąd kwadratowy: ", sbr(listay, listaf))
    print("Wartość współczynnka R2: ", R2(listay, listaf))
    print(" ")
    RysujWykres(listax, listay, listaf, listar)



