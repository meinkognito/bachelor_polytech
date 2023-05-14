from sklearn.metrics import accuracy_score, confusion_matrix, ConfusionMatrixDisplay, precision_score, recall_score
from sklearn.neighbors import KNeighborsClassifier
from sklearn.naive_bayes import GaussianNB
from sklearn import tree

import matplotlib.pyplot as plt
import pandas as pd
import random

arr = pd.read_csv("data/bank_scoring_train.csv", delimiter="\t")
data = arr.to_numpy()
random.shuffle(data)

X = data[:, 1:]
y = data[:, 0]

gnb = GaussianNB()
tree = tree.DecisionTreeClassifier()
knn = KNeighborsClassifier()

gnb.fit(X, y)
tree.fit(X, y)
knn.fit(X, y)

arr = pd.read_csv("data/bank_scoring_test.csv", delimiter="\t")
data = arr.to_numpy()
random.shuffle(data)

X_test = data[:, 1:]
y_test = data[:, 0]

pred = gnb.predict(X_test)

# pred = tree.predict(X_test)
# print(accuracy_score(y_test, pred))

# pred = knn.predict(X_test)
# print(accuracy_score(y_test, pred))

print(accuracy_score(y_test, pred))
print(precision_score(y_test, pred))
print(recall_score(y_test, pred))

cm = confusion_matrix(y_test, pred)
cm_display = ConfusionMatrixDisplay(cm).plot()
plt.savefig("result/confusion_matrix.png")
