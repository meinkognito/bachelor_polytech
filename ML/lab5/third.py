# 3
import pandas as pd
from matplotlib import pyplot as plt
from sklearn.linear_model import LinearRegression

arr = pd.read_csv("data/cygage.txt", delimiter="\t").to_numpy()
model = LinearRegression().fit(arr[:, 1].reshape(-1, 1), arr[:, 0])
pred = model.predict(arr[:, 1].reshape(-1, 1))
plt.scatter(arr[:, 1], arr[:, 0], color="black")
plt.plot(arr[:, 1], pred, color="blue", linewidth=3)
plt.show()
print(model.score(arr[:, 1].reshape(-1, 1), arr[:, 0]))

model2 = LinearRegression().fit(arr[:, 1].reshape(-1, 1), arr[:, 0], arr[:, 2])
pred2 = model2.predict(arr[:, 1].reshape(-1, 1))
plt.scatter(arr[:, 1], arr[:, 0], color="black")
plt.plot(arr[:, 1], pred2, color="red", linewidth=2, label="weighted")
plt.plot(arr[:, 1], pred, color="blue", linewidth=2, label="non-weighted")
plt.legend()
plt.show()

print(model2.score(arr[:, 1].reshape(-1, 1), arr[:, 0], arr[:, 2]))
