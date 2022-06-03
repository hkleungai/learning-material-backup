# -*- coding: utf-8 -*-
# pa1_sol.py

import numpy as np

def standardize_dataset(input_array):
  mean_array = np.mean(input_array, axis=0, keepdims=True)
  std_array = np.std(input_array, axis=0, ddof=1, keepdims=True)
  standardized_array = (input_array - mean_array)/std_array
  return standardized_array

class KNNClassifier:
  def __init__(self, k):
    self.k = k

  def fit(self, X_train, y_train):
    self.X_train = X_train
    self.y_train = y_train

  def calculate_euclidean_distance(self, X_test):
    #X_temp1 = np.expand_dims(X_test, axis=1) # (num_rows_test, 1, num_feature_columns)
    #X_temp2 = np.square(self.X_train - X_temp1) # (num_rows_test, num_rows_train, num_feature_columns)
    #X_temp3 = np.sum(X_temp2, axis=2, keepdims=False) # (num_rows_test, num_rows_train)
    #X_result = np.sqrt(X_temp3) # (num_rows_test, num_rows_train)
    #return np.sqrt(np.sum(np.square(self.X_train - np.expand_dims(X_test, axis=1)), axis=2, keepdims=False))
    return np.linalg.norm(self.X_train - np.expand_dims(X_test, axis=1), axis=2)

  def find_k_nearest_neighbor_labels(self, X_test):
    #k_indices = np.argsort(self.calculate_euclidean_distance(X_test), axis=1)[:, :self.k]
    #result = np.take(self.y_train, k_indices, mode="wrap")
    return np.take(self.y_train[:, np.newaxis], np.argsort(self.calculate_euclidean_distance(X_test), axis=1)[:, :self.k], mode="wrap")

  def predict(self, X_test):
    y_neighbors_sum = np.sum(self.find_k_nearest_neighbor_labels(X_test), axis=1, keepdims=False)
    y_predict = np.zeros_like(y_neighbors_sum)
    for i in range(y_predict.shape[0]):
      if y_neighbors_sum[i] > self.k/2:
        y_predict[i] = 1
    return y_predict

def generate_confusion_matrix(y_predict, y_actual):
  tp = tn = fp = fn = 0 # True Positive, True Negative, False Positive, False Negative
  for i in range(y_predict.shape[0]):
    if y_predict[i] == y_actual[i]:
      if y_predict[i] == 1:
        tp += 1
      else:
        tn += 1
    else:
      if y_predict[i] == 1:
        fp += 1
      else:
        fn += 1
  #tp = np.sum((np.logical_and((y_predict == 1), (y_actual == 1))))
  #tn = np.sum((np.logical_and((y_predict == 0), (y_actual == 0))))
  #fp = np.sum((np.logical_and((y_predict == 1), (y_actual == 0))))
  #fn = np.sum((np.logical_and((y_predict == 0), (y_actual == 1))))
  # In this particular case, a single Python for loop is faster than 4 sets of vectorized Numpy functions.
  return tp, tn, fp, fn

def calculate_accuracy_score(y_predict, y_actual):
  tp, tn, fp, fn = generate_confusion_matrix(y_predict, y_actual)
  return (tp + tn)/(tp + tn + fp + fn)

def calculate_MCC_score(y_predict, y_actual):
  tp, tn, fp, fn = generate_confusion_matrix(y_predict, y_actual)
  return (tp * tn - fp * fn) / np.sqrt((tp + fp) * (tp + fn) * (tn + fp) * (tn + fn))

class DFoldCV:
  def __init__(self, X, y, k_list, d):
    self.X = X
    self.y = y
    self.k_list = k_list
    self.d = d

  def generate_folds(self):
    dataset = np.concatenate((self.X, self.y[:, np.newaxis]), axis=1)
    dataset_d_folds = np.array_split(dataset, self.d, axis=0)
    train_d_folds = [np.concatenate((dataset_d_folds[0:fold] + dataset_d_folds[fold+1:self.d]), axis=0) for fold in range(self.d)] # Python list "+" operator performs list concatenation.
    #test_d_folds = [dataset_d_folds[fold] for fold in range(self.d)]
    return train_d_folds, dataset_d_folds #test_d_folds
  
  def cross_validate(self):
    train_d_folds, test_d_folds = self.generate_folds()
    scores = np.zeros((len(self.k_list), self.d))

    for k_index, k in enumerate(self.k_list):
      knn_model = KNNClassifier(k)
      for fold in range(self.d):
        X_train, y_train = (train_d_folds[fold])[:, :-1], (train_d_folds[fold])[:, -1]
        X_test, y_test = (test_d_folds[fold])[:, :-1], (test_d_folds[fold])[:, -1]
        knn_model.fit(X_train, y_train)
        scores[k_index, fold] = calculate_MCC_score(knn_model.predict(X_test), y_test)
    return scores

  def validate_best_k(self):
    #scores = self.cross_validate()
    #scores_sum = np.mean(scores, axis=1, keepdims=False)
    #k_index = np.argmax(scores_mean)
    #k_best = self.k_list[k_index]
    return self.k_list[np.argmax(np.mean(self.cross_validate(), axis=1, keepdims=False))]
