import pandas as pd
from matplotlib import pyplot as plt
from sklearn.linear_model import Ridge, LinearRegression
from sklearn.model_selection import train_test_split

# 4
arr = pd.read_csv("data/longley.csv")
arr = arr.drop("Population", axis=1)
arr = arr.to_numpy()
train_X, test_X, train_y, test_y = train_test_split(arr[:, 0:-1], arr[:, -1], train_size=0.5)

model1 = LinearRegression().fit(train_X, train_y)
print(model1.score(test_X, test_y))
print(model1.score(train_X, train_y))

res = []
res2 = []
for i in range(0, 26):
    model = Ridge(alpha=(10 ** (-3 + 0.2 * i))).fit(train_X, train_y)
    res.append(model.score(test_X, test_y))
    res2.append(model.score(train_X, train_y))
plt.plot(range(0, 26), res, label="test")
plt.plot(range(0, 26), res2, label="train")
plt.xlabel("lambda")
plt.ylabel("accuracy")
plt.legend()
plt.show()
