import matplotlib.pyplot as plt
def plot(l):
    plt.hist(l)
    plt.title("Marks Chart")
    plt.xlabel("Value")
    plt.ylabel("Frequency")
    plt.show()

plot([10,20,25,25,30,30,30,40,50])
