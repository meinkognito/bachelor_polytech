from sklearn.model_selection import train_test_split
from keras.datasets import mnist
from keras.layers import Dense
from tabulate import tabulate
from tensorflow import keras
from keras import models
from keras import layers

import pandas as pd

# 1

# data = pd.read_csv('data/nn_1.csv').to_numpy()
# X, x, Y, y = train_test_split(data[:, 0:2], data[:, 2], train_size=0.8)
# y[y == -1] = 0
# Y[Y == -1] = 0
#
# activation = ["elu", "exponential", "gelu", "linear", "relu", "selu", "sigmoid", "softmax", "softplus", "softsign",
#               "swish", "tanh"]
# optimizers = ["adam", "adadelta", "adagrad", "adamax", "sgd", "nadam"]
# rows = []
# for i in activation:
#     row = [i]
#     for j in optimizers:
#         model = keras.Sequential()
#         model.add(Dense(1, activation=i))
#         model.compile(loss='binary_crossentropy', optimizer=j, metrics=['accuracy'])
#         model.fit(X, Y, epochs=128, batch_size=None, verbose=0)
#         scores = model.evaluate(x, y)
#         row.append(scores[1])
#         # print("%s %s \n%s: %.2f%%" % (i, j, model.metrics_names[1], scores[1] * 100))
#     rows.append(row)
# print(tabulate(rows, headers=optimizers, tablefmt='orgtbl'))

# 2

# data = pd.read_csv('data/nn_1.csv').to_numpy()
# X, x, Y, y = train_test_split(data[:, 0:2], data[:, 2], train_size=0.8)
# y[y == -1] = 0
# Y[Y == -1] = 0
#
# activation = ["elu", "exponential", "gelu", "linear", "relu", "selu", "sigmoid", "softmax", "softplus", "softsign",
#               "swish", "tanh"]
# optimizers = ["adam", "adadelta", "adagrad", "adamax", "sgd", "nadam"]
# rows = []
# for i in activation:
#     row = [i]
#     for j in optimizers:
#         model = keras.Sequential()
#         model.add(Dense(1, activation=i))
#         model.compile(loss='binary_crossentropy', optimizer=j, metrics=['accuracy'])
#         model.fit(X, Y, epochs=1000, batch_size=None, verbose=0)
#         scores = model.evaluate(x, y)
#         row.append(scores[1])
#         print("%s %s \n%s: %.2f%%" % (i, j, model.metrics_names[1], scores[1] * 100))
#     rows.append(row)
# print(tabulate(rows, headers=optimizers, tablefmt='orgtbl'))

# ----

# data = pd.read_csv('data/nn_1.csv').to_numpy()
# X, x, Y, y = train_test_split(data[:, 0:2], data[:, 2], train_size=0.8)
# y[y == -1] = 0
# Y[Y == -1] = 0
#
# activation = ["elu", "exponential", "gelu", "linear", "relu", "selu", "sigmoid", "softmax", "softplus", "softsign",
#               "swish", "tanh"]
# optimizers = ["adam", "adadelta", "adagrad", "adamax", "sgd", "nadam"]
#
# model = keras.Sequential()
# model.add(Dense(64, activation="relu"))
# model.add(Dense(64, activation="softsign"))
# model.add(Dense(1, activation="sigmoid"))
# model.compile(loss='binary_crossentropy', optimizer="adam", metrics=['accuracy'])
# model.fit(X, Y, epochs=100, batch_size=None, verbose=0)
# scores = model.evaluate(x, y)

# print("%s %s \n%s: %.2f%%" % (i, j, model.metrics_names[1], scores[1] * 100))

# # 3
#
(x_train, y_train), (x_test, y_test) = mnist.load_data()

x_train = x_train / 255
x_test = x_test / 255

y_train_cat = keras.utils.to_categorical(y_train, 10)
y_test_cat = keras.utils.to_categorical(y_test, 10)

model = models.Sequential()
model.add(layers.Flatten(input_shape=(28, 28, 1)))
model.add(layers.Dense(128, activation="relu"))
model.add(layers.Dense(64, activation="relu"))
model.add(layers.Dense(10, activation="softmax"))
model.compile(optimizer="adam", loss="categorical_crossentropy",
              metrics=['accuracy'])

history = model.fit(x_train, y_train_cat, batch_size=32, epochs=5, validation_split=0.2)

model.evaluate(x_test, y_test_cat)
