# 6
import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
from sklearn.linear_model import LinearRegression

tp = {"Q1": 0.0, "Q2": 0.25, "Q3": 0.5, "Q4": 0.75}
dataset = np.array(pd.read_csv("data/JohnsonJohnson.csv", header=0))
for i in range(len(dataset)):
    dataset[i, 0] = float(dataset[i, 0][:-3])

dataset_q1 = dataset[[i for i in range(0, len(dataset), 4)], :]
dataset_q2 = dataset[[i for i in range(1, len(dataset), 4)], :]
dataset_q3 = dataset[[i for i in range(2, len(dataset), 4)], :]
dataset_q4 = dataset[[i for i in range(3, len(dataset), 4)], :]

plt.plot(dataset_q1[:, 0], dataset_q1[:, 1], label="Q1")
plt.plot(dataset_q2[:, 0], dataset_q2[:, 1], label="Q2")
plt.plot(dataset_q3[:, 0], dataset_q3[:, 1], label="Q3")
plt.plot(dataset_q4[:, 0], dataset_q4[:, 1], label="Q4")
plt.legend()
plt.show()

model_q1 = LinearRegression().fit(np.reshape(dataset_q1[:, 0], (-1, 1)), dataset_q1[:, 1])
plt.plot(dataset_q1[:, 0], model_q1.predict(np.reshape(dataset_q1[:, 0], (-1, 1))), label="Q1")

model_q2 = LinearRegression().fit(np.reshape(dataset_q2[:, 0], (-1, 1)), dataset_q2[:, 1])
plt.plot(dataset_q2[:, 0], model_q2.predict(np.reshape(dataset_q2[:, 0], (-1, 1))), label="Q2")

model_q3 = LinearRegression().fit(np.reshape(dataset_q3[:, 0], (-1, 1)), dataset_q3[:, 1])
plt.plot(dataset_q3[:, 0], model_q3.predict(np.reshape(dataset_q3[:, 0], (-1, 1))), label="Q3")

model_q4 = LinearRegression().fit(np.reshape(dataset_q4[:, 0], (-1, 1)), dataset_q4[:, 1])
plt.plot(dataset_q4[:, 0], model_q4.predict(np.reshape(dataset_q4[:, 0], (-1, 1))), label="Q4")

plt.legend()
plt.show()

print("Forecast for 2016 profits:",
      "\nQ1: ", model_q1.predict([[2016]]), "\nQ2: ", model_q2.predict([[2016]]),
      "\nQ3: ", model_q3.predict([[2016]]), "\nQ4: ", model_q4.predict([[2016]]),
      "\nYear: ", model_q1.predict([[2016]]) + model_q2.predict([[2016]])
      + model_q3.predict([[2016]]) + model_q4.predict([[2016]]),
      sep="")

# temp_dataset = []
# for i in range(len(dataset[:, 3])):
#     temp_dataset.append(np.sum(dataset[i]))
# temp_dataset = np.array(temp_dataset).reshape(len(temp_dataset), -1)
# classif5 = LinearRegression().fit(data5, temp_dataset)