from sklearn.cluster import KMeans
from sklearn.cluster import DBSCAN
from sklearn.metrics import silhouette_score
from sklearn.cluster import AgglomerativeClustering

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

cl1 = pd.read_csv('data/clustering_1.csv', delimiter="\t").to_numpy()
cl2 = pd.read_csv('data/clustering_2.csv', delimiter="\t").to_numpy()
cl3 = pd.read_csv('data/clustering_3.csv', delimiter="\t").to_numpy()

kmeans_cl1 = KMeans(n_clusters=3, random_state=0, n_init="auto").fit(cl1)
kmeans_cl2 = KMeans(n_clusters=3, random_state=0, n_init="auto").fit(cl2)
kmeans_cl3 = KMeans(n_clusters=3, random_state=0, n_init="auto").fit(cl3)

# elbow for cl1
limit = int((cl1.shape[0] // 2) ** 0.5)

wcss = {}

for k in range(1, limit + 1):
    model = KMeans(n_clusters=k, n_init="auto")
    model.fit(cl1)
    wcss[k] = model.inertia_

plt.plot(wcss.keys(), wcss.values(), 'gs-')
plt.xlabel('Values of "k"')
plt.ylabel('Inertia')
plt.savefig('results/elbow_1.png')
plt.show()

limit = int((cl1.shape[0] // 2) ** 0.5)

for k in range(2, limit + 1):
    model = KMeans(n_clusters=k, n_init="auto")
    model.fit(cl1)
    pred = model.predict(cl1)
    score = silhouette_score(cl1, pred)
    print('Silhouette Score for k = {}: {:<.3f}'.format(k, score))

# elbow for cl2
limit = int((cl1.shape[0] // 2) ** 0.5)

wcss = {}

for k in range(2, limit + 1):
    model = KMeans(n_clusters=k, n_init="auto")
    model.fit(cl2)
    wcss[k] = model.inertia_

plt.plot(wcss.keys(), wcss.values(), 'gs-')
plt.xlabel('Values of "k"')
plt.ylabel('Inertia')
plt.savefig('results/elbow_2.png')
plt.show()

limit = int((cl2.shape[0] // 2) ** 0.5)

for k in range(2, limit + 1):
    model = KMeans(n_clusters=k, n_init="auto")
    model.fit(cl2)
    pred = model.predict(cl2)
    score = silhouette_score(cl2, pred)
    print('Silhouette Score for k = {}: {:<.3f}'.format(k, score))

# elbow for cl3
limit = int((cl1.shape[0] // 2) ** 0.5)

wcss = {}

for k in range(2, limit + 1):
    model = KMeans(n_clusters=k, n_init="auto")
    model.fit(cl3)
    wcss[k] = model.inertia_

plt.plot(wcss.keys(), wcss.values(), 'gs-')
plt.xlabel('Values of "k"')
plt.ylabel('Inertia')
plt.savefig('results/elbow_3.png')
plt.show()

limit = int((cl3.shape[0] // 2) ** 0.5)

# determining number of clusters
# using silhouette score method
for k in range(2, limit + 1):
    model = KMeans(n_clusters=k, n_init="auto")
    model.fit(cl3)
    pred = model.predict(cl3)
    score = silhouette_score(cl3, pred)
    print('Silhouette Score for k = {}: {:<.3f}'.format(k, score))


def makePlot(dataset_new, clusters):
    model = KMeans(n_clusters=clusters, n_init="auto")
    pred = model.fit_predict(dataset_new)
    colours = ['red', 'blue', 'green', 'yellow', 'orange', 'magenta']

    for i in np.unique(model.labels_):
        plt.scatter(dataset_new[pred == i, 0],
                    dataset_new[pred == i, 1],
                    c=colours[i])

    plt.scatter(model.cluster_centers_[:, 0],
                model.cluster_centers_[:, 1],
                s=200,  # marker size
                c='black')

    plt.title('K Means clustering')
    plt.xlabel('X1')
    plt.ylabel('X2')
    plt.show()


makePlot(cl1, 2)
makePlot(cl2, 3)
makePlot(cl3, 6)


def makePlot2(dataset_new, eps, min_samples):
    model = DBSCAN(eps=eps, min_samples=min_samples)
    pred = model.fit_predict(dataset_new)
    colours = ['red', 'blue', 'green', 'yellow', 'orange', 'magenta']

    for i in np.unique(model.labels_):
        plt.scatter(dataset_new[pred == i, 0],
                    dataset_new[pred == i, 1],
                    c=colours[i])

    # plt.scatter(model.cluster_centers_[:, 0],
    #             model.cluster_centers_[:, 1],
    #             s = 200,  # marker size
    #             c = 'black')

    plt.title('DBSCAN clustering')
    plt.xlabel('X1')
    plt.ylabel('X2')
    plt.show()


makePlot2(cl1, 0.002, 15)
makePlot2(cl2, 0.5, 5)
makePlot2(cl3, 0.5, 5)

# Иерархическая кластеризация

hierarchical_cluster = AgglomerativeClustering(n_clusters=2, linkage='ward')
labels = hierarchical_cluster.fit_predict(cl1)

plt.scatter(cl1[:, 0], cl1[:, 1], c=labels)
plt.title('Hierarchical clustering')
plt.xlabel('X1')
plt.ylabel('X2')
plt.show()

# Иерархическая кластеризация

hierarchical_cluster = AgglomerativeClustering(n_clusters=3, linkage='ward')
labels = hierarchical_cluster.fit_predict(cl2)

plt.scatter(cl2[:, 0], cl2[:, 1], c=labels)
plt.title('Hierarchical clustering')
plt.xlabel('X1')
plt.ylabel('X2')
plt.show()

# Иерархическая кластеризация

hierarchical_cluster = AgglomerativeClustering(n_clusters=2, linkage='single')
labels = hierarchical_cluster.fit_predict(cl3)

plt.scatter(cl3[:, 0], cl3[:, 1], c=labels)
plt.title('Hierarchical clustering')
plt.xlabel('X1')
plt.ylabel('X2')
plt.show()
