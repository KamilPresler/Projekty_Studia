import csv
import numpy
from numpy import linalg
import matplotlib.pyplot as plt
listax1 = []
listax1sq = []
listay = []
listax2 = []
listax2sq = []
listax1x2 = []
listaf = []
listar =[]
def przypisz(plik):
    listax1.clear()
    listay.clear()
    listax2.clear()
    listax1sq.clear()
    listax2sq.clear()
    listax1x2.clear()
    if plik ==1:
        file = open("data3.csv", newline='')
    if plik ==2:
        file = open("data4.csv", newline='')
    reader = csv.reader(file)
    for row in reader:
        x1 = float(row[0])
        x2 = float(row[1])
        y = float(row[2])
        listax1.append(x1)
        listay.append(y)
        listax2.append(x2)
        listax1sq.append(x1**2)
        listax2sq.append(x2**2)
        listax1x2.append((x1*x2))
def srednia(lista):
    return sum(lista)/len(lista)

def wariancja(lista):
    war = 0
    for i in range(0, len(lista)):
        war += (lista[i]-srednia(lista))**2
    return war/len(lista)
def odstan(lista):
    return wariancja(lista)**(1/2)

def policz(lista1,lista2,lista3,lista4,lista5,lista6):
    X = numpy.zeros(shape=(len(lista1), 6))
    Y = numpy.zeros(shape=(len(lista5), 1))
    for i in range(0, len(lista1)):
        X[i] = [1, lista1[i], lista2[i],lista3[i],lista4[i],lista5[i]]
        Y[i] = [lista6[i]]
    A = linalg.inv((X.transpose() @ X)) @ X.transpose() @ Y
    return A

def funkcja(lista1,lista2,lista3,lista4,lista5,lista6,a,b,c,d,e,f):
    listaf.clear()
    for i in range(0, len(lista1)):
        listaf.append(lista1[i] * a + lista2[i] * b + lista3[i] * c + lista4[i] * d + lista5[i]*e + f)


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

def RysujWykres(lista1,lista2,lista3,lista4,lista5):
    Roznica(lista2,lista3)
    fig = plt.figure()
    ax = fig.add_subplot(projection='3d')
    ax.scatter(lista1, lista5, lista2, color="green", label='Punkty')
    ax.scatter(lista1, lista5, lista3, color="red", label='Regresja')
    ax.set_xlabel('Współrzędna X1')
    ax.set_ylabel('Współrzędna X2')
    ax.set_zlabel('Współrzędna Y')
    plt.title("Wykres regresja liniowa i punkty")
    plt.legend()
    plt.show()
    plt.hist(lista4)
    plt.xlabel("Wartość różnicy")
    plt.ylabel("Liczba różnic")
    plt.title("Różnice")
    plt.show()
for i in range(1, 3):
    print("Dane", i+2)
    przypisz(i)
    M = policz(listax1sq,listax1x2,listax2sq,listax1,listax2,listay)
    a = float(M[1])
    b = float(M[2])
    c = float(M[3])
    d = float(M[4])
    e = float(M[5])
    f = float(M[0])
    print("a = ", a)
    print("b = ", b)
    print("c = ", c)
    print("d = ", d)
    print("e = ", e)
    print("f = ", f)
    funkcja(listax1sq,listax1x2,listax2sq,listax1,listax2,listay,a,b,c,d,e,f)
    print("Odchylenie max: ", odmax(listay, listaf))
    print("Średni błąd kwadratowy: ", sbr(listay, listaf))
    print("Wartość współczynnka R2: ", R2(listay, listaf))
    print(" ")
    RysujWykres(listax1, listay, listaf, listar,listax2)

