from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt
import pandas as pd

dataset_path = "data/glass.csv"
arr = pd.read_csv(dataset_path)
arr = arr.drop('Id', axis=1)
data = arr.to_numpy()
size = data[:, 0:2].shape[0]
border = int(0.8 * size)

error = []

for i in range(1, 30):
    neigh = KNeighborsClassifier(n_neighbors=i)
    train_X, test_X, train_y, test_y = train_test_split(data[:, 0:-1], data[:, -1], train_size=0.8)
    neigh.fit(train_X, train_y)
    pred = neigh.predict(test_X)
    error.append(1 - (test_y == pred).sum() / test_X.shape[0])

fig = plt.figure()
fig.show()
ax = fig.add_subplot(111)
x = range(1, 30)
ax.plot(x, error, c='b')
plt.savefig("result/error_graph.png")

for i in ['minkowski', 'euclidean', 'manhattan', 'chebyshev']:
    neigh = KNeighborsClassifier(n_neighbors=1, metric=i)
    neigh.fit(train_X, train_y)
    pred = neigh.predict(test_X)
    print(i + ': ' + str((test_y == pred).sum() / test_X.shape[0]))

neigh = KNeighborsClassifier(n_neighbors=1, metric='manhattan')
neigh.fit(train_X, train_y)

neigh.predict([[1.516, 11.7, 1.01, 1.19, 72.59, 0.43, 11.44, 0.02, 0.1]])
