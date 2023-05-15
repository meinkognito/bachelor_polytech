from sklearn import svm
from sklearn.inspection import DecisionBoundaryDisplay
from sklearn.metrics import confusion_matrix, ConfusionMatrixDisplay

import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

# A

# arr = pd.read_csv("data/svmdata_a.txt", delimiter="\t")
# train = arr.to_numpy()
# test = pd.read_csv('data/svmdata_a_test.txt', delimiter="\t").to_numpy()
#
# classifier_svm = svm.SVC(kernel="linear", C=1.0)
# classifier_svm.fit(train[:, 0:-1], train[:, -1])
#
# disp = DecisionBoundaryDisplay.from_estimator(
#     classifier_svm,
#     train[:, 0:-1],
#     response_method="predict",
#     cmap=plt.cm.coolwarm,
#     alpha=0.8,
#     xlabel="X1",
#     ylabel="X2"
# )
# plt.scatter(train[:, 0], train[:, 1], c=train[:, 2], cmap=plt.cm.coolwarm, s=20, edgecolors="k")
# plt.savefig("result/a/decision_boundary.png")
#
# print(classifier_svm.support_vectors_)
# print(classifier_svm.n_support_)
#
# pred_test = classifier_svm.predict(test[:, 0:-1])
# pred_train = classifier_svm.predict(train[:, 0:-1])
#
# cm = confusion_matrix(train[:, 2], pred_train)
# cm_display = ConfusionMatrixDisplay(cm).plot()
# plt.savefig("result/a/confusion_matrix_pred_train.png")
#
# cm = confusion_matrix(test[:, 2], pred_test)
# cm_display = ConfusionMatrixDisplay(cm).plot()
# plt.savefig("result/a/confusion_matrix_pred_test.png")
#
# # B
#
# arr = pd.read_csv("data/svmdata_b.txt", delimiter="\t")
# train = arr.to_numpy()
# test = pd.read_csv('data/svmdata_b_test.txt', delimiter="\t").to_numpy()
#
# res_test = []
# res_train = []
# for i in np.arange(1.0, 600.0, 1.0):
#     svm1 = svm.SVC(kernel="linear", C=i)
#     svm1.fit(train[:, 0:-1], train[:, -1])
#
#     pred_test = svm1.predict(test[:, 0:-1])
#     pred_train = svm1.predict(train[:, 0:-1])
#     res_test.append((pred_test == test[:, -1]).sum() / test[:, 1].shape[0])
#     res_train.append((pred_train == train[:, -1]).sum() / train[:, 1].shape[0])
#
# fig = plt.figure()
# ax = fig.add_subplot(111)
# x = range(1, 600)
# ax.plot(x, res_train, c='b', label="train")
# ax.plot(x, res_test, c='r', label="test")
# plt.xlabel("C")
# plt.ylabel("Accuracy")
# plt.legend()
# plt.savefig("result/b/decision_boundary.png")
#
# # C
#
# arr = pd.read_csv("data/svmdata_c.txt", delimiter="\t")
# train = arr.to_numpy()
# test = pd.read_csv('data/svmdata_c_test.txt', delimiter="\t").to_numpy()
#
# x_train = train[:, 0:-1]
# y_train = train[:, -1]
#
# C = 30  # SVM regularization parameter
# models = (
#     svm.SVC(kernel="linear", C=C),
#     svm.SVC(kernel="rbf", C=C),
#     svm.SVC(kernel="poly", degree=1, C=C),
#     svm.SVC(kernel="poly", degree=2, C=C),
#     svm.SVC(kernel="poly", degree=3, C=C),
#     svm.SVC(kernel="poly", degree=4, C=C),
#     svm.SVC(kernel="poly", degree=5, C=C),
#     svm.SVC(kernel="sigmoid", C=C),
# )
#
# models = (clf.fit(x_train, y_train) for clf in models)
#
# titles = (
#     "Linear",
#     "Gaussian",
#     "Poly 1",
#     "Poly 2",
#     "Poly 3",
#     "Poly 4",
#     "Poly 5",
#     "Sigmoid",
# )
#
# fig, sub = plt.subplots(2, 4)
# fig.set_figwidth(20)
# fig.set_figheight(20)
# plt.subplots_adjust(wspace=0.1, hspace=0.1)
#
# X0, X1 = train[:, 0], train[:, 1]
#
# for clf, title, ax in zip(models, titles, sub.flatten()):
#     disp = DecisionBoundaryDisplay.from_estimator(
#         clf,
#         x_train,
#         response_method="predict",
#         cmap=plt.cm.coolwarm,
#         alpha=0.8,
#         ax=ax,
#         xlabel="X1",
#         ylabel="X2",
#     )
#     ax.scatter(X0, X1, c=y_train, cmap=plt.cm.coolwarm, s=20, edgecolors="k")
#     ax.set_xticks(())
#     ax.set_yticks(())
#     ax.set_title(title)
#
# plt.savefig("result/c/graph.png")
#
# # D
#
# arr = pd.read_csv("data/svmdata_d.txt", delimiter="\t")
# train = arr.to_numpy()
# test = pd.read_csv('data/svmdata_d_test.txt', delimiter="\t").to_numpy()
#
# x_train = train[:, 0:-1]
# y_train = train[:, -1]
#
# C = 1  # SVM regularization parameter
# models = (
#     svm.SVC(kernel="linear", C=C),
#     svm.SVC(kernel="rbf", C=C),
#     svm.SVC(kernel="poly", degree=1, C=C),
#     svm.SVC(kernel="poly", degree=2, C=C),
#     svm.SVC(kernel="poly", degree=3, C=C),
#     svm.SVC(kernel="poly", degree=4, C=C),
#     svm.SVC(kernel="poly", degree=5, C=C),
#     svm.SVC(kernel="sigmoid", C=C),
# )
#
# models = (clf.fit(x_train, y_train) for clf in models)
#
# titles = (
#     "Linear",
#     "Gaussian",
#     "Poly 1",
#     "Poly 2",
#     "Poly 3",
#     "Poly 4",
#     "Poly 5",
#     "Sigmoid",
# )
#
# fig, sub = plt.subplots(2, 4)
# fig.set_figwidth(20)
# fig.set_figheight(20)
# plt.subplots_adjust(wspace=0.1, hspace=0.1)
#
# X0, X1 = train[:, 0], train[:, 1]
#
# for clf, title, ax in zip(models, titles, sub.flatten()):
#     disp = DecisionBoundaryDisplay.from_estimator(
#         clf,
#         x_train,
#         response_method="predict",
#         cmap=plt.cm.coolwarm,
#         alpha=0.8,
#         ax=ax,
#         xlabel="X1",
#         ylabel="X2",
#     )
#     ax.scatter(X0, X1, c=y_train, cmap=plt.cm.coolwarm, s=20, edgecolors="k")
#     ax.set_xticks(())
#     ax.set_yticks(())
#     ax.set_title(title)
#
# plt.savefig("result/d/graph.png")

# E

arr = pd.read_csv("data/svmdata_e.txt", delimiter="\t")
train = arr.to_numpy()
test = pd.read_csv('data/svmdata_e_test.txt', delimiter="\t").to_numpy()

x_train = train[:, 0:-1]
y_train = train[:, -1]

C = 1000  # SVM regularization parameter
gamma = 10
models = (
    svm.SVC(kernel="linear", C=C, gamma=gamma),
    svm.SVC(kernel="rbf", C=C, gamma=gamma),
    svm.SVC(kernel="poly", degree=1, C=C, gamma=gamma),
    svm.SVC(kernel="poly", degree=2, C=C, gamma=gamma),
    svm.SVC(kernel="poly", degree=3, C=C, gamma=gamma),
    svm.SVC(kernel="poly", degree=4, C=C, gamma=gamma),
    svm.SVC(kernel="poly", degree=5, C=C, gamma=gamma),
    svm.SVC(kernel="sigmoid", C=C, gamma=gamma),
)

models = (clf.fit(x_train, y_train) for clf in models)

titles = (
    "Linear",
    "Gaussian",
    "Poly 1",
    "Poly 2",
    "Poly 3",
    "Poly 4",
    "Poly 5",
    "Sigmoid",
)

fig, sub = plt.subplots(2, 4)
fig.set_figwidth(20)
fig.set_figheight(20)
plt.subplots_adjust(wspace=0.1, hspace=0.1)

X0, X1 = train[:, 0], train[:, 1]

for clf, title, ax in zip(models, titles, sub.flatten()):
    disp = DecisionBoundaryDisplay.from_estimator(
        clf,
        x_train,
        response_method="predict",
        cmap=plt.cm.coolwarm,
        alpha=0.8,
        ax=ax,
        xlabel="X1",
        ylabel="X2",
    )
    ax.scatter(X0, X1, c=y_train, cmap=plt.cm.coolwarm, s=20, edgecolors="k")
    ax.set_xticks(())
    ax.set_yticks(())
    ax.set_title(title)

plt.savefig("result/e/graph.png")
