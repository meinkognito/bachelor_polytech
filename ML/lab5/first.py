import numpy as np
import pandas as pd
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split

arr = pd.read_csv("data/reglab1.txt", delimiter="\t").to_numpy()

print()
print("z x -> y")
train_X, test_X, train_y, test_y = train_test_split(arr[:, 0:2], arr[:, 2], train_size=0.8)
model = LinearRegression().fit(train_X, train_y)
# print(model.score(train_X, train_y))
print(model.score(test_X, test_y))

print()
print("z y -> x")
train_X, test_X, train_y, test_y = train_test_split(arr[:, np.r_[0,2]], arr[:, 1], train_size=0.8)
model = LinearRegression().fit(train_X, train_y)
# print(model.score(train_X, train_y))
print(model.score(test_X, test_y))

print()
print("x y -> z")
train_X, test_X, train_y, test_y = train_test_split(arr[:, np.r_[1,2]], arr[:, 0], train_size=0.8)
model = LinearRegression().fit(train_X, train_y)
# print(model.score(train_X, train_y))
print(model.score(test_X, test_y))

print()
print("z -> x")

train_X, test_X, train_y, test_y = train_test_split(arr[:, 0], arr[:, 1], train_size=0.8)
train_X = train_X.reshape(-1, 1)
test_X = test_X.reshape(-1, 1)
model = LinearRegression().fit(train_X, train_y)
# print(model.score(train_X, train_y))
print(model.score(test_X, test_y))

print()
print("y -> x")

train_X, test_X, train_y, test_y = train_test_split(arr[:, 2], arr[:, 1], train_size=0.8)
train_X = train_X.reshape(-1, 1)
test_X = test_X.reshape(-1, 1)
model = LinearRegression().fit(train_X, train_y)
# print(model.score(train_X, train_y))
print(model.score(test_X, test_y))

print()
print("x -> y")

train_X, test_X, train_y, test_y = train_test_split(arr[:, 1], arr[:, 2], train_size=0.8)
train_X = train_X.reshape(-1, 1)
test_X = test_X.reshape(-1, 1)
model = LinearRegression().fit(train_X, train_y)
# print(model.score(train_X, train_y))
print(model.score(test_X, test_y))
