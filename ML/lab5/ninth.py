# 9
import pandas as pd
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeRegressor
from sklearn.svm import SVR

dataset = pd.read_csv('nsw74psid1.csv', sep=',').to_numpy()
dataset_answer = dataset[:, -1]
dataset = dataset[:, [0, 1, 2, 3, 4, 5, 6, 7, 8]]
train_X, test_X, train_y, test_y = train_test_split(dataset, dataset_answer, train_size=0.8)
linear_regression = LinearRegression().fit(train_X, train_y)
svr_regression = SVR(C=1, kernel="rbf", epsilon=0.01).fit(train_X, train_y)
tree_regression = DecisionTreeRegressor().fit(train_X, train_y)

print("Коэффициент детерминации  линейной регресии: ", linear_regression.score(train_X, train_y))
print("Коэффициент детерминации  SVR: ", svr_regression.score(train_X, train_y))
print("Коэффициент детерминации  дерева регресии: ", tree_regression.score(train_X, train_y))
print("\n")
print("Коэффициент детерминации  линейной регресии: ", linear_regression.score(test_X, test_y))
print("Коэффициент детерминации  SVR: ", svr_regression.score(test_X, test_y))
print("Коэффициент детерминации  дерева регресии: ", tree_regression.score(test_X, test_y))
