# 7
import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
from sklearn.linear_model import LinearRegression

dataset = np.array(pd.read_csv("data/cars.csv", header=0))

model = LinearRegression().fit(np.reshape(dataset[:, 0], (-1, 1)), dataset[:, 1])

plt.scatter(dataset[:, 0], dataset[:, 1], color="black")
plt.plot(dataset[:, 0], model.predict(np.reshape(dataset[:, 0], (-1, 1))), label="Linear regression", color="red")
plt.xlabel("Speed")
plt.ylabel("Distance")

plt.show()
print("Braking distance length for 40 mph: ", model.predict([[40]]), sep="")
