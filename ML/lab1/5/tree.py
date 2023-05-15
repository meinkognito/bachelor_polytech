from sklearn import tree
from sklearn.model_selection import GridSearchCV
from sklearn.metrics import accuracy_score

import matplotlib.pyplot as plt
import pandas as pd
import random

arr = pd.read_csv("data/glass.csv")
arr = arr.drop('Id', axis=1)
data = arr.to_numpy()
random.shuffle(data)
size = data[:, 0:2].shape[0]
border = int(0.8 * size)

res = []
for i in range(1, 15):
    clf = tree.DecisionTreeClassifier(max_depth=i)
    clf.fit(data[:border, 0:-1], data[:border, -1])
    pred = clf.predict(data[border:, 0:-1])
    tmp = (pred == data[border:, -1]).sum() / data[border:, -1].shape[0]
    res.append(tmp)
    print(str(i) + " " + str(tmp))
    # plt.rcParams["figure.figsize"] = (20, 40)
    # tree.plot_tree(clf, class_names=["1", "2", "3", "4", "5", "6", "7"])
    plt.savefig("result/tree" + str(i) + ".png")

print(clf.get_depth())

plt.rcParams["figure.figsize"] = (10, 5)
fig = plt.figure()
ax = fig.add_subplot(111)
x = range(1, 15)
ax.plot(x, res, c='b', label="train")

plt.xlabel("max_depth")
plt.ylabel("Accuracy")
plt.legend()
plt.savefig("result/graph.png")

pred = clf.predict(data[border:, 0:-1])
(pred == data[border:, -1]).sum() / data[border:, -1].shape[0]

arr = pd.read_csv("data/spam7.csv")
data = arr.to_numpy()
random.shuffle(data)
size = data[:, 0:2].shape[0]
border = int(0.8 * size)

clf = tree.DecisionTreeClassifier(splitter="random")
clf.fit(data[:border, 0:-1], data[:border, -1])
plt.rcParams["figure.figsize"] = (20, 40)
tree.plot_tree(clf, class_names=["y", "n"])
plt.savefig("result/tree.png")

clf.get_depth()

pred = clf.predict(data[border:, 0:-1])
print(accuracy_score(data[border:, -1], pred))

(pred == data[border:, -1]).sum() / data[border:, -1].shape[0]

params = {
    'criterion': ['gini', 'entropy'],
    'max_depth': [None, 2, 4, 6, 8, 10, 15, 30],
    'max_features': [None, 'sqrt', 'log2', 0.2, 0.4, 0.6, 0.8],
    'splitter': ['best', 'random']
}

clf = GridSearchCV(
    estimator=tree.DecisionTreeClassifier(),
    param_grid=params,
    n_jobs=5,
    verbose=1,
)

clf.fit(data[:border, 0:-1], data[:border, -1])
print(clf.best_params_)
pred = clf.predict(data[border:, 0:-1])
print(accuracy_score(data[border:, -1], pred))
