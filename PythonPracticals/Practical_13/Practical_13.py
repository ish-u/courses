import math
import matplotlib.pyplot as plt

def sin():
    plt.title("sin(x)")
    plt.axline((0,0),(1000,0),color='r')
    plt.axline((0,-2),(0,2),color='r')
    plt.plot([math.sin(math.radians(x)) for x in range(1000)])
    plt.show()

def cos():
    plt.title("cos(x)")
    plt.axline((0,0),(1000,0),color='r')
    plt.axline((0,-2),(0,2),color='r')
    plt.plot([math.cos(math.radians(x)) for x in range(1000)])
    plt.show()

def exp():
    plt.title("exp(x)")
    plt.axline((0,0),(20,0),color='r')
    plt.plot([math.exp(x) for x in range(10)])
    plt.show()

def p():
    plt.title("poly(x)")
    plt.axline((0,0),(20,0),color='r')
    plt.plot([(x*x) for x in range(-100,100)])
    plt.show()


sin()
cos()
p()
exp()