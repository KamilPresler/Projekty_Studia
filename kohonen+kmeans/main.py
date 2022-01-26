import math
import os
from math import pi, cos, sin, sqrt
from random import random
from typing import Tuple

import imageio
import matplotlib
import numpy as np

matplotlib.use("TkAgg")
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from scipy.spatial import distance

p1 = []
x1 = []
y1 = []
p2 = []
x2 = []
y2 = []
nni1 = []
avgInactive = []
quanErr = []


# Generowanie Punktów
def get_random_point(center: Tuple[float, float], radius: float) -> Tuple[float, float]:
    shift_x, shift_y = center

    a = random() * 2 * pi
    r = radius * sqrt(random())

    return r * cos(a) + shift_x, r * sin(a) + shift_y


# Tworzymy klasę algorytmu Kohonena
class Kohonen:
    def __init__(self, neuronNumber, inputData, alfa, lamb, minPotential):
        self.lamb = lamb
        self.maxLamb = lamb
        self.minLamb = 0.1
        self.allSteps = 0
        self.alfa = alfa
        self.maxAlfa = alfa
        self.minAlfa = 0.1
        self.minPotential = minPotential
        self.neuronNumber = neuronNumber
        self.inputData = inputData
        # Generowanie sieci z rozkładu Gaussa
        self.neuronWeights = np.random.normal(np.mean(self.inputData), np.std(self.inputData),
                                              size=(self.neuronNumber, len(self.inputData[0])))
        self.distance = []
        self.winner = -1
        self.neighborhood = []
        self.winnerDistance = []
        self.error = []
        # Deklaracja potencjału
        self.potential = np.ones(self.neuronNumber)
        # Deklaracja aktywności
        self.activation = np.ones(self.neuronNumber)
        self.animationPlots = []

    # Liczenie dystansu
    def calculateDistance(self, inputNeurons, interval, distanceCalculation):
        for i in interval:
            distanceCalculation.append(distance.euclidean(i, inputNeurons))

    # Znalezienie zwycięzcy
    def findWinnner(self):
        sortedDistance = np.argsort(np.asarray(self.distance))
        for i in sortedDistance:
            if self.activation[i] != 0:
                self.winner = i
                break

    # Sąsiedztwo
    def kohonenNeighborhood(self):
        for i in self.winnerDistance:
            self.neighborhood.append(math.exp(-1 * (i ** 2) / (2 * self.lamb ** 2)))

    # Czyszczenie list i zmiana współczynników, po wykonaniu kazdego kroku
    def clearLists(self, step):
        self.neuronActivation()
        self.inActive()
        self.distance.clear()
        self.neighborhood.clear()
        self.winnerDistance.clear()
        self.lamb = self.maxLamb * (self.minLamb / self.maxLamb) ** (step / self.allSteps)
        self.alfa = self.maxAlfa * (self.minAlfa / self.maxAlfa) ** (step / self.allSteps)

    # Zmiana wag
    def updateWeights(self, inputNeurons):
        for i in range(len(self.neuronWeights)):
            if self.activation[i] == 1:
                self.neuronWeights[i] = self.neuronWeights[i] + self.neighborhood[i] * self.alfa * (
                            inputNeurons - self.neuronWeights[i])

    # Martwe neurony -- zmiana potencjału
    def deadNeurons(self):
        for i in range(len(self.potential)):
            if i == self.winner:
                self.potential[i] = self.potential[i] - self.minPotential
            else:
                self.potential[i] = self.potential[i] + (1 / self.neuronNumber)

    # Aktywacja neuronu
    def neuronActivation(self):
        for i in range(len(self.potential)):
            if self.potential[i] < self.minPotential:
                self.activation[i] = 0
            else:
                self.activation[i] = 1

    def calculateError(self):
        localErr = 0
        errorDist = []
        for inputNeurons in self.inputData:
            for i in self.neuronWeights:
                errorDist.append(distance.euclidean(i, inputNeurons))
            localErr += min(errorDist) ** 1
            errorDist.clear()
            self.error.append(localErr / len(self.inputData))

    def inActive(self):
        z = 0
        for i in range(len(self.potential)):
            if self.activation[i] == 0:
                z += 1
        avgInactive.append(z)

    def train(self, epochNumber):
        self.allSteps = epochNumber * len(self.inputData)
        combinedData = list(self.inputData)
        step = 0
        self.calculateError()
        for epoch in range(epochNumber):
            np.random.shuffle(combinedData)
            for inputNeurons in combinedData:
                self.calculateDistance(inputNeurons=inputNeurons, interval=self.neuronWeights,
                                       distanceCalculation=self.distance)
                self.findWinnner()
                self.calculateDistance(inputNeurons=self.neuronWeights[self.winner], interval=self.neuronWeights,
                                       distanceCalculation=self.winnerDistance)
                self.kohonenNeighborhood()
                self.deadNeurons()
                self.updateWeights(inputNeurons=inputNeurons)
                self.clearLists(step=step)
                self.animationPlots.append(np.copy(self.neuronWeights))
                step += 1
            self.calculateError()
            quanErr.append(np.mean(self.error))

    def animatePlot(self):
        fig, ax = plt.subplots()
        ax.set(xlim=(-5, 5), ylim=(-3, 3))
        ax.plot(self.inputData[:, 0], self.inputData[:, 1], 'ro')
        line, = ax.plot([], [], 'bo')

        def animate(frame):
            if frame > len(self.animationPlots) - 1:
                frame = len(self.animationPlots) - 1
            line.set_data(self.animationPlots[frame][:, 0], self.animationPlots[frame][:, 1])
            ax.set_title("Input Data: " + str((frame + 1)))
            return line

        ani = animation.FuncAnimation(fig, animate, len(self.animationPlots), interval=1, repeat=False)
        plt.show()


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.minimialDistance = 0

    # Obliczanie odleglosci euklidesowej od poszczegolnych centrow
    def calculateDistance(self, center):
        pointVector = []
        centerVector = []
        pointVector.append(self.x)
        pointVector.append(self.y)
        centerVector.append(center.x)
        centerVector.append(center.y)
        return distance.euclidean(pointVector, centerVector)

    # Najmniejsza odległość
    def closestCenter(self, centers):
        dist = []
        for center in centers:
            dist.append(self.calculateDistance(center))
        self.minimialDistance = min(dist)


class Center:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.pointsAssigned = []
        self.qError = 0
        self.LocationX = []
        self.LocationY = []

    # Przypisz punkt

    def assignPoint(self, points):
        self.pointsAssigned.append(points)

    # Wyczyść listę

    def assignLocationX(self):
        self.LocationX.append(self.x)

    def assignLocationY(self):
        self.LocationY.append(self.y)

    def clearPoints(self):
        self.pointsAssigned.clear()

    # Obliczenie nowych wspołrzędnych śrdoka skupień

    def calculatePosition(self):
        self.assignLocationX()
        self.assignLocationY()

        if len(self.pointsAssigned) == 0:
            return

        sumX = 0
        sumY = 0

        for point in self.pointsAssigned:
            sumX += point.x
            sumY += point.y
        self.x = sumX / len(self.pointsAssigned)
        self.y = sumY / len(self.pointsAssigned)

    def calculateError(self):
        sum = 0
        for point in self.pointsAssigned:
            sum += math.pow(point.calculateDistance(self),1)
            self.qError = sum


class KMean:
    def __init__(self, pointsMatrix, numberCentroids, alfa):
        self.points = pointsMatrix
        self.numberCentroids = numberCentroids
        self.alfa = alfa
        # Warunek Stopu

        # Losowanie pozycji centroidów
        self.centers = self.createCenters()
        # Lista obrazów do animacji
        self.images = []
        # Licznik epok
        self.epochCounter = 0
        # II Warunek stopu - ustabilizowanie centrów
        self.isNotStabilized = True
        # Blad
        self.qError = 0
        self.errList = []
        # Lista nieaktywnych centroid
        self.inactiveCentroid = []

    # Generowanie centroid
    def createCenters(self):
        pointsX = []
        pointsY = []
        centers = []
        for point in self.points:
            pointsX.append(point.x)
            pointsY.append(point.y)
        for i in range(self.numberCentroids):
            center = [np.random.uniform(-5 * self.alfa, 5 * self.alfa),
                      np.random.uniform(-3 * self.alfa, 3 * self.alfa)]
            centers.append(Center(center[0], center[1]))
        return np.asarray(centers)

    # Funkcja tworząca na bieżąco tablicę współrzędnych
    def pointsArray(self, data):
        points = []
        for i in data:
            indPoint = []
            indPoint.append(i.x)
            indPoint.append(i.y)
            points.append(indPoint)
        return np.asarray(points)

    # Główny algorytm
    # 1.Liczba skupień
    # 2.Wstepne środki skupień
    # 3-5 Powtarzane
    def train(self):
        self.firstPlot()
        while self.isNotStabilized:
            self.isNotStabilized = False
            self.qError = 0
            # Czyszyczenie punktów
            for center in self.centers:
                center.clearPoints()
            # 3.Odleglości od śrdoka skupień
            for point in self.points:
                point.closestCenter(self.centers)
                # 4.Przypisanie punktów do najbliższego centrum
                for center in self.centers:
                    if (point.calculateDistance(center) == point.minimialDistance):
                        center.assignPoint(point)
            # 5.Nowe pozycje
            for center in self.centers:
                previousX = center.x
                previousY = center.y
                center.calculatePosition()
                if center.x != previousX and center.y != previousY:
                    self.isNotStabilized = True
                center.calculateError()
                self.qError += center.qError
            self.qError /= len(self.points)
            self.errList.append(self.qError)

            # Zwiększamy Counter
            self.epochCounter += 1
            if self.epochCounter == 1:
                colorList = []
                for i in range(0, self.numberCentroids):
                    colorList.append(self.generateColor())
            # Plotowanie wykresu po każdym przejściu
            self.animationPlot(colorList)
        # Rysowanie centrów
        #self.drawCenters(colorList)
        # Gif po Whilu
        self.createGif()
        # Policzenie sredniej liczby nieaktywnych centroidów
        self.countAvgIna()
        # Przekazanie wartości błędu
        self.countAvgErr()

    # Funckja rysująca pierwszy wykres - osobno aby wyróżnić początek
    def firstPlot(self):
        pointsPlot = self.pointsArray(self.points)
        plt.plot(pointsPlot[:, 0], pointsPlot[:, 1], "^", markersize=2, color="gray")
        centersPlot = self.pointsArray(self.centers)
        plt.plot(centersPlot[:, 0], centersPlot[:, 1], ".", markersize=9, color="black")
        plt.xlabel('x')
        plt.ylabel('y')
        plt.title("epoka" + str(self.epochCounter))
        plt.savefig(str(self.epochCounter) + str(self.numberCentroids) + ".png")
        plt.clf()
        self.images.append(imageio.imread(str(self.epochCounter) + str(self.numberCentroids) + ".png"))

    # Funckja rysująca kolejne wykresy
    def animationPlot(self, colorList):
        centersPlot = self.pointsArray(self.centers)
        z = 0
        for i in range(0, self.numberCentroids):
            if i == 0:
                j = -1
                for center in self.centers:
                    j += 1
                    pointsPlot = self.pointsArray(center.pointsAssigned)
                    try:
                        plt.plot(pointsPlot[:, 0], pointsPlot[:, 1], "^", markersize=2, color=colorList[j])
                    except IndexError:
                        z += 1
                    pass
                self.inactiveCentroid.append(z)
            plt.plot(centersPlot[i, 0], centersPlot[i, 1], ".", markersize=9, color=colorList[i])
        plt.xlabel('x')
        plt.ylabel('y')
        plt.title("Epoka: " + str(self.epochCounter))
        plt.savefig(str(self.epochCounter) + str(self.numberCentroids) + ".png")
        plt.clf()
        self.images.append(imageio.imread(str(self.epochCounter) + str(self.numberCentroids) + ".png"))

    def drawCenters(self, colorList):
        i = 0
        for center in self.centers:
            plt.plot(center.LocationX, center.LocationY, color=colorList[i], label=str(i + 1))
            i += 1
        plt.xlabel('x')
        plt.ylabel('y')
        plt.legend()
        plt.title('Położenie centrów')
        plt.show()

    def generateColor(self):
        random_color = list(np.random.choice(range(1000), size=3))
        random_color[0] /= 1000
        random_color[1] /= 1000
        random_color[2] /= 1000
        return random_color

    def createGif(self):
        imageio.mimsave(str(self.numberCentroids) + ".gif", self.images, 'GIF', duration=0.5)
        for i in range(0, self.epochCounter):
            os.remove(str(i) + str(self.numberCentroids) + ".png")

    def countAvgIna(self):
        avgInactive.append(sum(self.inactiveCentroid) / len(self.inactiveCentroid))

    def countAvgErr(self):
        quanErr.append(sum(self.errList) / len(self.errList))


def createPoints(lista):
    pointsArray = []
    for i in range(len(lista)):
        pointsArray.append(Point(lista[i][0], lista[i][1]))
    return np.asarray(pointsArray)


def srednia(lista):
    return sum(lista) / len(lista)


def odstan(lista):
    odchylenie = 0
    for j in range(0, len(lista)):
        odchylenie += (lista[j] - srednia(lista)) ** 2
    odchylenie = (odchylenie / (len(lista))) ** (1 / 2)
    return odchylenie


def minimum(lista):
    s = sorted(lista)
    return s[0]


def plotError(lista1, lista2):
    plt.plot(lista1, lista2)
    plt.xlabel("Liczba Centroidów")
    plt.ylabel("Błąd kwantyzacji")
    plt.show()


def preparePoints():
    # Zapisywanie wygenerowanych punktów
    p1.clear()
    x1.clear()
    y1.clear()
    p2.clear()
    x2.clear()
    y2.clear()
    for i in range(0, 200):
        p1.append(get_random_point((0, 0), 2))
        x1.append(p1[i][0])
        y1.append(p1[i][1])
        if i < 100:
            p2.append(get_random_point((-3, 0), 1))
        else:
            p2.append(get_random_point((3, 0), 1))
        x2.append(p2[i][0])
        y2.append(p2[i][1])


def Kohonen1():
    clear()
    for i in range(1, 11):
        kohonen = Kohonen(neuronNumber=2 * i, inputData=M1, alfa=0.1, lamb=1, minPotential=0.75)
        kohonen.train(1)
       # kohonen.animatePlot()
        nni1.append(2 * i)
    plotError(nni1, quanErr)
    clear()
    for i in range(1, 11):
        kohonen = Kohonen(neuronNumber=2 * i, inputData=M2, alfa=0.1, lamb=1, minPotential=0.75)
        kohonen.train(1)
        # kohonen.animatePlot()
        nni1.append(2 * i)
    plotError(nni1, quanErr)


def Kohonen2():
    clear()
    for j in range(0, 5):
        for i in range(1, 101):
            kohonen = Kohonen(neuronNumber=20, inputData=M1, alfa=round(0.1 + 2 * j / 10, 1), lamb=0.1 + i / 10,
                              minPotential=0.75)
            kohonen.train(1)
            print("Wykonano ", round(j * 10 + i / 10, 1), "%")
        print("Dla alfa = ", 0.1 + 2 * j / 10)
        print("Błąd")
        print("Srednia: ", srednia(quanErr))
        print("Odchylenie standardowe: ", odstan(quanErr))
        print("Minimum: ", minimum(quanErr))
        print("Nieaktywne neurony")
        print("Srednia: ", srednia(avgInactive))
        print("Odchylenie standardowe: ", odstan(avgInactive))
    clear()
    for j in range(0, 5):
        for i in range(1, 101):
            kohonen = Kohonen(neuronNumber=20, inputData=M2, alfa=round(0.1 + 2 * j / 10, 1), lamb=0.1 + i / 10,
                              minPotential=0.75)
            kohonen.train(1)
            print("Wykonano ", round(50 + j * 10 + i / 10, 1), "%")
        print("Dla alfa = ", 0.1 + 2 * j / 10)
        print("Srednia: ", srednia(quanErr))
        print("Odchylenie standardowe: ", odstan(quanErr))
        print("Minimum: ", minimum(quanErr))
        print("Srednia: ", srednia(avgInactive))
        print("Odchylenie standardowe: ", odstan(avgInactive))


def Kmean1():
    clear()
    for i in range(1, 11):
        kMean = KMean(pointsMatrix=createPoints(p1), numberCentroids=2 * i, alfa=1)
        kMean.train()
        print("Wykonano:", i * 5, "%")
        nni1.append(2 * i)
    plotError(nni1, quanErr)
    clear()
    for i in range(1, 11):
        kMean = KMean(pointsMatrix=createPoints(p2), numberCentroids=2 * i, alfa=1)
        kMean.train()
        print("Wykonano:", 50 + i * 5, "%")
        nni1.append(2 * i)
    plotError(nni1, quanErr)


def Kmean2():
    clear()
    for i in range(1, 101):
        preparePoints()
        # Tworzenie macierzy z wygenerowanych punktów
        M1 = np.zeros(shape=(len(p1), 2))
        M2 = np.zeros(shape=(len(p2), 2))
        for j in range(0, len(p1)):
            M1[i] = [x1[i], y1[i]]
        for j in range(0, len(p2)):
            M2[i] = [x2[i], y2[i]]
        kMean = KMean(pointsMatrix=createPoints(p1), numberCentroids=20, alfa=i / 100)
        kMean.train()
        print("Wykonano:", i / 2, "%")
    print("Zbiór 1:")
    print("Błąd")
    print("Średnia Wartość:", srednia(quanErr))
    print("Minimum: ", minimum(quanErr))
    print("Odchylenie standardowe: ", odstan(quanErr))
    print("Nieaktywne centra")
    print("Średnia Wartość:", srednia(avgInactive))
    print("Odchylenie standardowe: ", odstan(avgInactive))
    clear()
    for i in range(1, 101):
        preparePoints()
        # Tworzenie macierzy z wygenerowanych punktów
        M1 = np.zeros(shape=(len(p1), 2))
        M2 = np.zeros(shape=(len(p2), 2))
        for j in range(0, len(p1)):
            M1[i] = [x1[i], y1[i]]
        for j in range(0, len(p2)):
            M2[i] = [x2[i], y2[i]]
        kMean = KMean(pointsMatrix=createPoints(p2), numberCentroids=20, alfa=i / 100)
        kMean.train()
        print("Wykonano:", 50 + i / 2, "%")
    print("Zbiór 2:")
    print("Błąd")
    print("Średnia Wartość:", srednia(quanErr))
    print("Minimum: ", minimum(quanErr))
    print("Odchylenie standardowe: ", odstan(quanErr))
    print("Nieaktywne centra")
    print("Średnia Wartość:", srednia(avgInactive))
    print("Odchylenie standardowe: ", odstan(avgInactive))


def Kmean3():
    clear()
    kMean = KMean(pointsMatrix=createPoints(p1), numberCentroids=2, alfa=1)
    kMean.train()
    clear()
    kMean = KMean(pointsMatrix=createPoints(p1), numberCentroids=10, alfa=1)
    kMean.train()
    clear()
    kMean = KMean(pointsMatrix=createPoints(p2), numberCentroids=2, alfa=1)
    kMean.train()
    clear()
    kMean = KMean(pointsMatrix=createPoints(p2), numberCentroids=10, alfa=1)
    kMean.train()


def clear():
    avgInactive.clear()
    quanErr.clear()
    nni1.clear()
    quanErr.clear()


preparePoints()
# Tworzenie macierzy z wygenerowanych punktów
M1 = np.zeros(shape=(len(p1), 2))
M2 = np.zeros(shape=(len(p2), 2))
for i in range(0, len(p1)):
    M1[i] = [x1[i], y1[i]]
for i in range(0, len(p2)):
    M2[i] = [x2[i], y2[i]]
#Kohonen1()
#Kohonen2()
#Kmean1()
#Kmean2()
#Kmean3() # Do wykresu centrów odkomentować linię 330