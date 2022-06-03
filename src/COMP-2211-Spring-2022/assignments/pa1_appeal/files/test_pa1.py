# -*- coding: utf-8 -*-
# test_pa1.py

import pytest
import numpy as np
import pa1_tasks
import pa1_sol

@pytest.fixture
def dataset():
    data = np.loadtxt("heart_disease_dataset.csv", delimiter=',', skiprows=1)
    return pa1_sol.standardize_dataset(data[:, :-1]), data[:, -1]

@pytest.fixture
def X_train(dataset):
    return (dataset[0])[:300]

@pytest.fixture
def y_train(dataset):
    return (dataset[1])[:300]
    
@pytest.fixture
def X_test(dataset):
    return (dataset[0])[300:]

@pytest.fixture
def y_test(dataset):
    return (dataset[1])[300:]

@pytest.fixture
def dataset_large():
    data_large = np.loadtxt("income_census_test_dataset.csv", delimiter=',', skiprows=1)
    return pa1_sol.standardize_dataset(data_large[:, :-1]), data_large[:, -1]

@pytest.fixture
def X_train_large(dataset_large):
    return (dataset_large[0])[:5400]

@pytest.fixture
def y_train_large(dataset_large):
    return (dataset_large[1])[:5400]

@pytest.fixture
def X_test_large(dataset_large):
    return (dataset_large[0])[5400:]

@pytest.fixture
def y_test_large(dataset_large):
    return (dataset_large[1])[5400:]

@pytest.fixture
def y_train_large_for_y_test_large(y_train_large, y_test_large):
    return y_train_large[:y_test_large.shape[0]]

@pytest.fixture
def dataset_large_raw():
    return np.loadtxt("income_census_test_dataset.csv", delimiter=',', skiprows=1)

# Task 1
def test_standardize_dataset(dataset_large_raw):
    assert np.allclose(pa1_tasks.standardize_dataset(dataset_large_raw), pa1_sol.standardize_dataset(dataset_large_raw), rtol=1e-05, atol=1e-08, equal_nan=True)

# Task 2
def test_calculate_euclidean_distance(X_train, y_train, X_test):
    k = 17
    knn_model_train = pa1_tasks.KNNClassifier(k)
    knn_model_train.fit(X_train, y_train)
    knn_model_train_sol = pa1_sol.KNNClassifier(k)
    knn_model_train_sol.fit(X_train, y_train)
    assert np.allclose(knn_model_train.calculate_euclidean_distance(X_test), knn_model_train_sol.calculate_euclidean_distance(X_test), rtol=1e-05, atol=1e-08, equal_nan=True)

def test_calculate_euclidean_distance_large(X_train_large, y_train_large, X_test_large):
    k = 77
    knn_model_train = pa1_tasks.KNNClassifier(k)
    knn_model_train.fit(X_train_large, y_train_large)
    knn_model_train_sol = pa1_sol.KNNClassifier(k)
    knn_model_train_sol.fit(X_train_large, y_train_large)
    assert np.allclose(knn_model_train.calculate_euclidean_distance(X_test_large), knn_model_train_sol.calculate_euclidean_distance(X_test_large), rtol=1e-05, atol=1e-08, equal_nan=True)

def test_find_k_nearest_neighbor_labels(monkeypatch, X_train, y_train, X_test):
    k = 17
    knn_model_train = pa1_tasks.KNNClassifier(k)
    knn_model_train.fit(X_train, y_train)
    knn_model_train_sol = pa1_sol.KNNClassifier(k)
    knn_model_train_sol.fit(X_train, y_train)
    monkeypatch.setattr(knn_model_train, "calculate_euclidean_distance", knn_model_train_sol.calculate_euclidean_distance)
    assert np.array_equal(knn_model_train.find_k_nearest_neighbor_labels(X_test), knn_model_train_sol.find_k_nearest_neighbor_labels(X_test), equal_nan=True)

def test_find_k_nearest_neighbor_labels_large(monkeypatch, X_train_large, y_train_large, X_test_large):
    k = 77
    knn_model_train = pa1_tasks.KNNClassifier(k)
    knn_model_train.fit(X_train_large, y_train_large)
    knn_model_train_sol = pa1_sol.KNNClassifier(k)
    knn_model_train_sol.fit(X_train_large, y_train_large)
    monkeypatch.setattr(knn_model_train, "calculate_euclidean_distance", knn_model_train_sol.calculate_euclidean_distance)
    assert np.array_equal(knn_model_train.find_k_nearest_neighbor_labels(X_test_large), knn_model_train_sol.find_k_nearest_neighbor_labels(X_test_large), equal_nan=True)

def test_predict(monkeypatch, X_train_large, y_train_large, X_test_large):
    k = 77
    knn_model_train = pa1_tasks.KNNClassifier(k)
    knn_model_train.fit(X_train_large, y_train_large)
    knn_model_train_sol = pa1_sol.KNNClassifier(k)
    knn_model_train_sol.fit(X_train_large, y_train_large)
    monkeypatch.setattr(knn_model_train, "calculate_euclidean_distance", knn_model_train_sol.calculate_euclidean_distance)
    monkeypatch.setattr(knn_model_train, "find_k_nearest_neighbor_labels", knn_model_train_sol.find_k_nearest_neighbor_labels)
    assert np.array_equal(knn_model_train.predict(X_test_large), knn_model_train_sol.predict(X_test_large), equal_nan=True)

# Task 3
def test_generate_confusion_matrix(y_train_large_for_y_test_large, y_test_large):
    assert pa1_tasks.generate_confusion_matrix(y_train_large_for_y_test_large, y_test_large) == pa1_sol.generate_confusion_matrix(y_train_large_for_y_test_large, y_test_large)

def test_calculate_accuracy_score(monkeypatch, y_train_large_for_y_test_large, y_test_large):
    monkeypatch.setattr(pa1_tasks, "generate_confusion_matrix", pa1_sol.generate_confusion_matrix)
    assert np.isclose(pa1_tasks.calculate_accuracy_score(y_train_large_for_y_test_large, y_test_large), pa1_sol.calculate_accuracy_score(y_train_large_for_y_test_large, y_test_large), rtol=1e-05, atol=1e-08, equal_nan=False)

def test_calculate_MCC_score(monkeypatch, y_train_large_for_y_test_large, y_test_large):
    monkeypatch.setattr(pa1_tasks, "generate_confusion_matrix", pa1_sol.generate_confusion_matrix)
    assert np.isclose(pa1_tasks.calculate_MCC_score(y_train_large_for_y_test_large, y_test_large), pa1_sol.calculate_MCC_score(y_train_large_for_y_test_large, y_test_large), rtol=1e-05, atol=1e-08, equal_nan=False)

# Task 4
def test_generate_folds(X_train, y_train):
    k_list = [5, 17, 29]
    d = 10
    dfoldcv = pa1_tasks.DFoldCV(X_train, y_train, k_list, d)
    train_d_folds, test_d_folds = dfoldcv.generate_folds()
    dfoldcv_sol = pa1_sol.DFoldCV(X_train, y_train, k_list, d)
    train_d_folds_sol, test_d_folds_sol = dfoldcv_sol.generate_folds()
    assert len(train_d_folds) == len(train_d_folds_sol)
    assert len(test_d_folds) == len(test_d_folds_sol)
    assert np.all([np.array_equal(train_d_folds[i], train_d_folds_sol[i], equal_nan=False) for i in range(d)])
    assert np.all([np.array_equal(test_d_folds[i], test_d_folds_sol[i], equal_nan=False) for i in range(d)])

def test_generate_folds_large(X_train_large, y_train_large):
    k_list = [9, 77, 539]
    d = 100
    dfoldcv = pa1_tasks.DFoldCV(X_train_large, y_train_large, k_list, d)
    train_d_folds, test_d_folds = dfoldcv.generate_folds()
    dfoldcv_sol = pa1_sol.DFoldCV(X_train_large, y_train_large, k_list, d)
    train_d_folds_sol, test_d_folds_sol = dfoldcv_sol.generate_folds()
    assert len(train_d_folds) == len(train_d_folds_sol)
    assert len(test_d_folds) == len(test_d_folds_sol)
    assert np.all([np.array_equal(train_d_folds[i], train_d_folds_sol[i], equal_nan=False) for i in range(d)])
    assert np.all([np.array_equal(test_d_folds[i], test_d_folds_sol[i], equal_nan=False) for i in range(d)])

def test_cross_validate(monkeypatch, X_train, y_train):
    monkeypatch.setattr(pa1_tasks, "KNNClassifier", pa1_sol.KNNClassifier)
    monkeypatch.setattr(pa1_tasks, "generate_confusion_matrix", pa1_sol.generate_confusion_matrix)
    monkeypatch.setattr(pa1_tasks, "calculate_accuracy_score", pa1_sol.calculate_accuracy_score)
    monkeypatch.setattr(pa1_tasks, "calculate_MCC_score", pa1_sol.calculate_MCC_score)
    k_list = [5, 17, 29]
    d = 10
    dfoldcv = pa1_tasks.DFoldCV(X_train, y_train, k_list, d)
    dfoldcv_sol = pa1_sol.DFoldCV(X_train, y_train, k_list, d)
    monkeypatch.setattr(dfoldcv, "generate_folds", dfoldcv_sol.generate_folds)
    assert np.allclose(dfoldcv.cross_validate(), dfoldcv_sol.cross_validate(), rtol=1e-05, atol=1e-08, equal_nan=True)

def test_cross_validate_large(monkeypatch, X_train_large, y_train_large):
    monkeypatch.setattr(pa1_tasks, "KNNClassifier", pa1_sol.KNNClassifier)
    monkeypatch.setattr(pa1_tasks, "generate_confusion_matrix", pa1_sol.generate_confusion_matrix)
    monkeypatch.setattr(pa1_tasks, "calculate_accuracy_score", pa1_sol.calculate_accuracy_score)
    monkeypatch.setattr(pa1_tasks, "calculate_MCC_score", pa1_sol.calculate_MCC_score)
    k_list = [9, 77, 539]
    d = 100
    dfoldcv = pa1_tasks.DFoldCV(X_train_large, y_train_large, k_list, d)
    dfoldcv_sol = pa1_sol.DFoldCV(X_train_large, y_train_large, k_list, d)
    monkeypatch.setattr(dfoldcv, "generate_folds", dfoldcv_sol.generate_folds)
    assert np.allclose(dfoldcv.cross_validate(), dfoldcv_sol.cross_validate(), rtol=1e-05, atol=1e-08, equal_nan=True)

def test_validate_best_k(monkeypatch, X_train_large, y_train_large):
    monkeypatch.setattr(pa1_tasks, "KNNClassifier", pa1_sol.KNNClassifier)
    monkeypatch.setattr(pa1_tasks, "generate_confusion_matrix", pa1_sol.generate_confusion_matrix)
    monkeypatch.setattr(pa1_tasks, "calculate_accuracy_score", pa1_sol.calculate_accuracy_score)
    monkeypatch.setattr(pa1_tasks, "calculate_MCC_score", pa1_sol.calculate_MCC_score)
    k_list = [9, 77, 539]
    d = 100
    dfoldcv = pa1_tasks.DFoldCV(X_train_large, y_train_large, k_list, d)
    dfoldcv_sol = pa1_sol.DFoldCV(X_train_large, y_train_large, k_list, d)
    monkeypatch.setattr(dfoldcv, "generate_folds", dfoldcv_sol.generate_folds)
    monkeypatch.setattr(dfoldcv, "cross_validate", dfoldcv_sol.cross_validate)
    assert dfoldcv.validate_best_k() == dfoldcv_sol.validate_best_k()

# Stress test is separate as pytest doesn't natively support timeouts.
