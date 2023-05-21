import numpy as np
from keras.utils import np_utils
import matplotlib.pyplot as plt
from sklearn.metrics import accuracy_score, confusion_matrix
import tensorflow as tf
import pandas
import keras.models as M
import keras.layers as L
import keras.backend as K
from prettytable import PrettyTable


def predict(x, y, model, name):
    predictions = model.predict(x, batch_size=32)
    pred_list = []
    class1_x1 = []
    class1_x2 = []
    class0_x1 = []
    class0_x2 = []
    y_val_oh = np_utils.to_categorical(y, 2)
    pred = np_utils.to_categorical(predictions.argmax(axis=1), 2)
    for i in range(len(predictions)):
        if pred[i][0] == 0:
            pred_list.append(1)
            class1_x1.append(x["X1"][i])
            class1_x2.append(x["X2"][i])
        else:
            pred_list.append(0)
            class0_x1.append(x["X1"][i])
            class0_x2.append(x["X2"][i])
    plt.clf()
    plt.title(name)
    plt.subplot(2, 1, 1)
    plt.title("Predicted")
    plt.scatter(class0_x1, class0_x2, c='r')
    plt.scatter(class1_x1, class1_x2, c='b')
    class1_x1 = []
    class1_x2 = []
    class0_x1 = []
    class0_x2 = []
    for i in range(len(y)):
        if y[i] == 1:
            class1_x1.append(x["X1"][i])
            class1_x2.append(x["X2"][i])
        else:
            class0_x1.append(x["X1"][i])
            class0_x2.append(x["X2"][i])
    plt.subplot(2, 1, 2)
    plt.title("Actual")
    plt.scatter(class0_x1, class0_x2, c='r')
    plt.scatter(class1_x1, class1_x2, c='b')
    plt.show()
    print("Accuracy: ", accuracy_score(y_val_oh, pred))
    c_matrix = confusion_matrix(y, pred_list)
    print("confusion matrix\n", c_matrix)
    return accuracy_score(y_val_oh, pred)


def task_1():
    table = PrettyTable()
    accuracy = []
    loss = []
    optimeziers = ["sgd", "nadam", "adadelta", "adam", "adamax"]
    activations = ["elu", "tanh", "softmax", "selu", "softplus", "softsign",
                   "sigmoid", "linear"]
    table.field_names = ["optimizer name", "elu", "tanh", "softmax", "selu",
                         "softplus", "softsign", "sigmoid",
                         "linear"]
    EPOCHS = 1000
    for optimezier in optimeziers:
        for activation in activations:
            data = pandas.read_csv("data/nn_0.csv")
            x = data[["X1", "X2"]]
            y = data["class"].values
            for i in range(len(y)):
                if y[i] == -1:
                    y[i] = 0
            y_oh = np_utils.to_categorical(y, 2)
            K.clear_session()
            model = M.Sequential()
            model.add(L.Dense(2, activation=activation))
            model.compile(loss="categorical_crossentropy",
                          optimizer=optimezier,
                          metrics=["accuracy"])
            H = model.fit(
                x,
                y_oh,
                batch_size=32, epochs=EPOCHS, verbose=1
                # 64 объекта для подсчета градиента на каждом шаге epochs=10,
                # 10 проходов по датасету
            )
            accuracy.append(predict(x, y, model, activation))
            loss.append(H.history["loss"][len(H.history["loss"]) - 1])

        table.add_row(
            [optimezier, accuracy[0], accuracy[1], accuracy[2], accuracy[3],
             accuracy[4], accuracy[5], accuracy[6],
             accuracy[7]])
        table.add_row([optimezier, loss[0], loss[1], loss[2], loss[3],
                       loss[4], loss[5], loss[6], loss[7]])
        accuracy = []
        loss = []
    print(table)


def task_2():
    EPOCHS = 20
    (x_train, y_train), (x_val, y_val) = tf.keras.datasets.fashion_mnist.load_data()
    y_train_oh = np_utils.to_categorical(y_train, 10)
    y_val_oh = np_utils.to_categorical(y_val, 10)
    K.clear_session()
    model = M.Sequential()
    model.add(L.Dense(512, input_dim=784, activation='elu'))
    model.add(L.Dense(128, activation='elu'))
    model.add(L.Dense(10, activation='softmax'))
    model.compile(loss="categorical_crossentropy",
                  optimizer="adam",
                  metrics=["accuracy"])
    x_train_float = x_train.astype(np.float) / 255 - 0.5
    x_val_float = x_val.astype(np.float) / 255 - 0.5
    H = model.fit(
        x_train_float.reshape(-1, 28 * 28),
        y_train_oh,
        batch_size=64,
        epochs=EPOCHS,
        validation_data=(x_val_float.reshape(-1, 28 * 28), y_val_oh)

    )
    # строим графики потерь и точности
    N = np.arange(0, EPOCHS)
    plt.style.use("ggplot")
    plt.figure()
    plt.plot(N, H.history["loss"], label="train_loss")
    plt.plot(N, H.history["val_loss"], label="val_loss")
    plt.plot(N, H.history["accuracy"], label="train_acc")
    plt.plot(N, H.history["val_accuracy"], label="val_acc")
    plt.title("Training Loss and Accuracy (Simple NN)")
    plt.xlabel("Epoch #")
    plt.ylabel("Loss/Accuracy")
    plt.legend()
    plt.show()


if __name__ == '__main__':
    task_1()
