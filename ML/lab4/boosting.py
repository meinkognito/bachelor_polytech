from sklearn.naive_bayes import GaussianNB
from sklearn.ensemble import AdaBoostClassifier
from sklearn.model_selection import train_test_split
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.metrics import accuracy_score
from sklearn.tree import DecisionTreeClassifier

data = pd.read_csv("data/vehicle.csv")

data.replace('van', 0, inplace=True)
data.replace('saab', 1, inplace=True)
data.replace('bus', 2, inplace=True)
data.replace('opel', 3, inplace=True)

arr = data.to_numpy()


def test2(model):
    acc_train = []
    acc_test = []
    for i in range(50, 150):
        train_X, test_X, train_y, test_y = train_test_split(arr[:, 0:-1], arr[:, -1], train_size=0.8)
        clf = AdaBoostClassifier(estimator=model, n_estimators=i).fit(train_X, train_y)
        pred = clf.predict(test_X)
        acc_test.append(accuracy_score(test_y, pred))
        pred = clf.predict(train_X)
        acc_train.append(accuracy_score(train_y, pred))
    fig = plt.figure()
    fig.show()
    ax = fig.add_subplot(111)
    x = np.arange(50, 150, 1)
    ax.plot(x, acc_train, c='b', label="Train")
    ax.plot(x, acc_test, c='r', label="Test")
    plt.ylabel("Accuracy")
    plt.xlabel("Train size")
    plt.draw()
    plt.legend()
    plt.show()


test2(GaussianNB())
test2(DecisionTreeClassifier())
