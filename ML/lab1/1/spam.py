from sklearn.naive_bayes import GaussianNB
from sklearn.model_selection import train_test_split

import numpy as np
import matplotlib.pyplot as plt
import random
import pandas as pd

dataset_path = "data/spam.csv"
arr = pd.read_csv(dataset_path)
arr['type'] = arr['type'].map({'spam': 1, 'nonspam': 0})

data = arr.to_numpy()
random.shuffle(data)

size = data[:, 1:-2].shape[0]
accuracy_train = []
accuracy_test = []
for tr in np.arange(0.1, 1.0, 0.1):
    border = int(size * tr)
    train_X, test_X, train_y, test_y = train_test_split(data[:, 1:-2], data[:, -1], train_size=tr)
    gnb = GaussianNB()
    gnb.fit(train_X, train_y)
    y_pred = gnb.predict(train_X)
    accuracy_train.append((train_y == y_pred).sum() / train_X.shape[0])

    y_pred_2 = gnb.predict(test_X)
    accuracy_test.append((test_y == y_pred_2).sum() / test_X.shape[0])

fig = plt.figure()
ax = fig.add_subplot(111)
x = np.arange(0.1, 1, 0.1)
ax.plot(x, accuracy_train, c='b')
ax.plot(x, accuracy_test, c='r')
plt.ylabel("Accuracy")
plt.xlabel("Train size")
plt.savefig("result/spam_graph.png")
