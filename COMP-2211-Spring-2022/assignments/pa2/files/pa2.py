"""This is where you write graded codes for your PA2

"""

import numpy as np
import tensorflow as tf
from tensorflow import keras


############################
##         Task 1         ##
############################


def reshape_x(x_train_raw, x_val_raw, x_test_raw):
    """Reshape images to proper shapes

    Parameters
    ----------
    x_train_raw : np.ndarray
    x_val_raw : np.ndarray
    x_test_raw : np.ndarray

    Returns
    -------
    A 3-tuple of reshaped x_train_raw, x_val_raw, x_test_raw, respectively
    """
    ### START YOUR CODE HERE
    print("\033[93mSeems you haven't implement reshape_x!\033[0m") # The \033[93m and \033[0m codes tell the terminal to set print color to yellow and reset, respectively. XD
    return (
        np.zeros((x_train_raw.shape[0], 28, 28, 1)),
        np.zeros((x_val_raw.shape[0], 28, 28, 1)),
        np.zeros((x_test_raw.shape[0], 28, 28, 1)),
    )
    ### END YOUR CODE HERE


############################
##         Task 2         ##
############################


def encode_y(y_train_raw, y_val_raw, y_test_raw, N_labels):
    """One-hot encode the labels

    Parameters
    ----------
    y_train_raw : np.ndarray
    y_val_raw : np.ndarray
    y_test_raw : np.ndarray

    Returns
    -------
    A 3-tuple of encoded y_train_raw, y_val_raw, y_test_raw, respectively
    """
    ### START YOUR CODE HERE
    print("\033[93mSeems you haven't implement encode_y!\033[0m")
    return (
        tf.zeros((y_train_raw.shape[0], N_labels)),
        tf.zeros((y_val_raw.shape[0], N_labels)),
        tf.zeros((y_test_raw.shape[0], N_labels)),
    )
    ### END YOUR CODE HERE


############################
##         Task 3         ##
############################


# These imports makes life easier
# For you don't need to write keras.Sequential, layers.RandomFlip, etc.
# But Sequential, RandomFlip, etc. directly.
# You can ignore them if not needed, or import additional stuff if you like
from keras import Sequential
from keras.layers import RandomFlip, RandomRotation


def AugmentationLayer():
    """Creates a keras model for data augmentation

    Returns
    -------
    keras.Model
        A keras model created by Sequential(),
        containing the data augmentation pipeline.
    """
    ### START YOUR CODE HERE
    print("\033[93mSeems you haven't implement AugmentationLayer!\033[0m")
    return Sequential([

    ])
    ### END YOUR CODE HERE


############################
##         Task 4         ##
############################


# These imports makes life easier
# You can ignore them if not needed, or import additional stuff if you like
from keras import Sequential
from keras.layers import (
    Rescaling,
    Conv2D,
    MaxPooling2D,
    Flatten,
    Dense,
    Dropout,
)


def build_model(N_labels):
    """Creates and returns a model described above

    Parameters
    ----------
    N_labels : int
        The number of possible labels.
        Used when creating the last Dense layer.

    Returns
    -------
    keras.Model
        The Sequential model created
    """
    ### START YOUR CODE HERE
    print("\033[93mSeems you haven't implement build_model!\033[0m")
    model = Sequential([

    ])
    ### END YOUR CODE HERE
    model.build((None, 28, 28, 1))
    return model


############################
##         Task 5         ##
############################


def compile_model(model, lr):
    """Compile a model according to the description above

    Parameters
    ----------
    model : keras.Model
        The model to compile
    lr : float
        The learning rate
    """
    ### START YOUR CODE HERE
    print("\033[93mSeems you haven't implement compile_model!\033[0m")
    model.compile()
    ### END YOUR CODE HERE


############################
##         Task 6         ##
############################


def train_model(model, epochs, x_train, y_train, x_val, y_val):
    """Train the model according to the description above.
    NOTE: Please return your `model.fit(...)` call
    for us to grade >.<

    Parameters
    ----------
    model : keras.Model
        The model to train
    epochs : int
        The number of epochs to train
    x_train : np.ndarray
    y_train : np.ndarray
    x_val : np.ndarray
    y_val : np.ndarray

    Returns
    -------
    keras.callback.History
        You don't need to care about the return value.
        But just make sure you do return the return value
        of `model.fit`.
    """
    ### START YOUR CODE HERE
    print("\033[93mSeems you haven't implement train_model!\033[0m")
    # return model.fit(...)
    ### END YOUR CODE HERE


############################
##         Task 7         ##
############################


def evaluate_model(model, x_test, y_test):
    """Evaluate the model according to the description above

    Parameters
    ----------
    model : keras.Model
        The model to evaluate
    x_test : np.ndarray
    y_test : np.ndarray
    """
    ### START YOUR CODE HERE
    print("\033[93mSeems you haven't implement evaluate_model!\033[0m")
    score = [999999, 0]
    # score = model.evaluate()
    ### END YOUR CODE HERE
    print("Test loss:", score[0])
    print("Test accuracy:", score[1])


############################
##         Task 8         ##
############################


def predict_images(model, x):
    """Predict the model given images in shape (k, 28, 28, 1)

    Parameters
    ----------
    model : keras.Model
        The model for prediction
    x : np.ndarray
        The array of input images

    Returns
    -------
    np.ndarray
        The predicted models in shape (k,)
    """
    ### START YOUR CODE HERE
    print("\033[93mSeems you haven't implement predict_images!\033[0m")
    return np.zeros((x.shape[0],), dtype=int)
    ### END YOUR CODE HERE
