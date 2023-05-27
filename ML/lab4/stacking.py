import pandas as pd
from sklearn.metrics import accuracy_score
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.preprocessing import LabelEncoder
from sklearn.linear_model import LogisticRegression
from sklearn.ensemble import StackingClassifier
from sklearn.svm import SVC
from sklearn.tree import DecisionTreeClassifier

labelencoder = LabelEncoder()

train = pd.read_csv("data/titanic_train.csv")
test_data = pd.read_csv("data/titanic_test.csv")

train = train.drop("PassengerId", axis=1).drop("Name", axis=1).drop("Ticket", axis=1).drop("Cabin", axis=1)
test_data = test_data.drop("PassengerId", axis=1).drop("Name", axis=1).drop("Ticket", axis=1).drop("Cabin", axis=1)

age_mean_train_male = train[train["Sex"] == "male"]["Age"].mean()
age_mean_train_female = train[train["Sex"] == "female"]["Age"].mean()
train.loc[(train["Sex"] == "male") & (train['Age'].isna()), "Age"] = age_mean_train_male
train.loc[(train["Sex"] == "female") & (train['Age'].isna()), "Age"] = age_mean_train_female

age_mean_test_male = test_data[test_data["Sex"] == "male"]["Age"].mean()
age_mean_test_female = test_data[test_data["Sex"] == "female"]["Age"].mean()
test_data.loc[(test_data["Sex"] == "male") & (test_data['Age'].isna()), "Age"] = age_mean_test_male
test_data.loc[(test_data["Sex"] == "female") & (test_data['Age'].isna()), "Age"] = age_mean_test_female

train.loc[train["Sex"] == "male", "Sex"] = 0
train.loc[train["Sex"] == "female", "Sex"] = 1

test_data.loc[test_data["Sex"] == "male", "Sex"] = 0
test_data.loc[test_data["Sex"] == "female", "Sex"] = 1

train.loc[:, "Embarked"] = labelencoder.fit_transform(train.loc[:, "Embarked"])
test_data.loc[:, "Embarked"] = labelencoder.transform(test_data.loc[:, "Embarked"])

train = train.dropna()
test_data = test_data.dropna()

train = train.to_numpy()
test_data = test_data.to_numpy()

train = train.astype(float)
test_data = test_data.astype(float)


def test3(models):
    acc_train = []
    acc_test = []
    train_X, train_y = train[:, 1:-1], train[:, 0]
    clf = StackingClassifier(estimators=models, final_estimator=LogisticRegression()).fit(train_X, train_y)
    # pred = clf.predict(test_data)
    # print("Test acc: ", accuracy_score(test_y, pred))
    pred = clf.predict(train_X)
    print("Train acc: ", accuracy_score(train_y, pred))


estimators = [
    ('svr', KNeighborsClassifier()),
    ('asd', SVC(probability=True)),
    ('gnb', DecisionTreeClassifier()),
]
acc_train = []
acc_test = []
X_train, X_test, y_train, y_test = train_test_split(test_data[:, 1:-1], test_data[:, 0], train_size=0.8)
clf = StackingClassifier(estimators=estimators, final_estimator=LogisticRegression()).fit(X_train, y_train)
pred = clf.predict(X_test)
print("Test acc: ", accuracy_score(y_test, pred))
pred = clf.predict(X_train)
print("Train acc: ", accuracy_score(y_train, pred))
