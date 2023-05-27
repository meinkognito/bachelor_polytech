import pandas as pd
import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split


def RSS(real, predicate):
    answer = 0
    for i in range(len(real)):
        answer += (real[i] - predicate[i]) * (real[i] - predicate[i])
    return answer


arr = pd.read_csv("data/reglab.txt", delimiter="\t").to_numpy()
for i in [[1], [2], [3], [4], [1, 2], [1, 3], [1, 4], [2, 3], [2, 4], [3, 4], [1, 2, 3], [1, 2, 4], [1, 3, 4],
          [1, 2, 3, 4]]:
    train_X, test_X, train_y, test_y = train_test_split(arr[:, np.r_[i]], arr[:, 0], train_size=0.8)
    # train_X = train_X.reshape(-1, 1)
    # test_X = test_X.reshape(-1, 1)
    model = LinearRegression().fit(train_X, train_y)
    rss = RSS(test_y, model.predict(test_X))
    print(" ".join(["x" + str(k) for k in i]) + " " + str(rss))
