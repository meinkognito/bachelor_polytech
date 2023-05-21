from sklearn.cluster import KMeans
import matplotlib.pyplot as plt
import pandas as pd

data = pd.read_csv('data/pluton.csv').to_numpy()

kmeans = KMeans(n_clusters=3, random_state=0, n_init="auto").fit(data)
print(kmeans.labels_)

fig = plt.figure()
ax = plt.axes(projection='3d')
ax.scatter(data[:, 0], data[:, 1], data[:, 2])
plt.savefig('results/figure.png')

kmeans2 = KMeans(n_clusters=3, random_state=0, n_init="auto", max_iter=1).fit(data)
print(kmeans2.labels_)
