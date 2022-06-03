# -*- coding: utf-8 -*-

import numpy as np
import pa1_tasks
import pa1_sol

if __name__ == "__main__":
    dataset = np.loadtxt("income_census_test_dataset.csv", delimiter=',', skiprows=1)
    X, y = pa1_sol.standardize_dataset(dataset[:, :-1]), dataset[:, -1]
    X_train, y_train = X[:5400], y[:5400]
    X_test, y_test = X[5400:], y[5400:]
    
    d_fold_cv = pa1_tasks.DFoldCV(X_train, y_train, [k for k in range(11, 540, 20)], 100)
    knn_model = pa1_tasks.KNNClassifier(d_fold_cv.validate_best_k())
    knn_model.fit(X_train, y_train)
    MCC_score = pa1_sol.calculate_MCC_score(knn_model.predict(X_test), y_test)
    print(np.isclose(MCC_score, 0.4305582794547567, rtol=1e-05, atol=1e-08, equal_nan=False))
    
    print("Stress Test Complete.")
