from sklearn.naive_bayes import GaussianNB
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix, ConfusionMatrixDisplay, roc_curve, RocCurveDisplay, \
    precision_recall_curve, PrecisionRecallDisplay

import numpy as np
import matplotlib.pyplot as plt
import random

data = []
for i in range(0, 20):  # class -1
    x1 = np.random.normal(10, 3, 1)[0]
    x2 = np.random.normal(14, 3, 1)[0]
    data.append([x1, x2, -1])
for i in range(0, 80):  # class 1
    x1 = np.random.normal(19, 4, 1)[0]
    x2 = np.random.normal(16, 4, 1)[0]
    data.append([x1, x2, 1])

data = np.array(data)
plt.scatter(data[0:20, 0], data[0:20, 1], color="red", label="Class -1", alpha=0.3)
plt.scatter(data[20:, 0], data[20:, 1], color="lime", label="Class 1", alpha=0.3)
plt.legend()
plt.ylabel('x2')
plt.xlabel('x1')
plt.savefig("result/dots.png")

gnb = GaussianNB()
random.shuffle(data)

train_X, test_X, train_y, test_y = train_test_split(data[:, 0:2], data[:, 2], train_size=80)
gnb.fit(train_X, train_y)
pred = gnb.predict(test_X)
print((pred == test_y).sum() / 20)

cm = confusion_matrix(test_y, pred)
disp = ConfusionMatrixDisplay(cm).plot()
plt.savefig("result/confusion_matrix.png")

fpr, tpr, _ = roc_curve(data[80:, 2], pred)
display = RocCurveDisplay(fpr=fpr, tpr=tpr, estimator_name='ROC').plot()
plt.plot([0, 1], [0, 1], linestyle=":", color='g', label="Random guess")
plt.plot([0, 0, 1], [0, 1, 1], color='r', label="Ideal classifier")
plt.legend()
plt.savefig("result/roc_curve.png")

prec, recall, _ = precision_recall_curve(data[80:, 2], pred)
pr_display = PrecisionRecallDisplay(precision=prec, recall=recall).plot()
plt.savefig("result/precision_recall_curve.png")
