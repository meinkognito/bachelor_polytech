from sklearn.naive_bayes import GaussianNB
from sklearn.neighbors import KNeighborsClassifier
from sklearn.ensemble import BaggingClassifier
from sklearn.model_selection import train_test_split
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.metrics import accuracy_score
from sklearn.tree import DecisionTreeClassifier

arr = pd.read_csv("data/glass.csv").drop("Id", axis=1).to_numpy()


def test(model):
    acc_train = []
    acc_test = []
    for i in range(1, 150):
        train_X, test_X, train_y, test_y = train_test_split(arr[:, 0:-1], arr[:, -1], train_size=0.8)
        clf = BaggingClassifier(estimator=model, n_estimators=i).fit(train_X, train_y)
        pred = clf.predict(test_X)
        acc_test.append(accuracy_score(test_y, pred))
        pred = clf.predict(train_X)
        acc_train.append(accuracy_score(train_y, pred))
    fig = plt.figure()
    fig.show()
    ax = fig.add_subplot(111)
    x = np.arange(1, 150, 1)
    ax.plot(x, acc_train, c='b', label="Train")
    ax.plot(x, acc_test, c='r', label="Test")
    plt.ylabel("Accuracy")
    plt.xlabel("Estimators count")
    plt.draw()
    plt.legend()
    plt.show()


# test(GaussianNB())
test(KNeighborsClassifier(n_neighbors=3))
# test(DecisionTreeClassifier())
