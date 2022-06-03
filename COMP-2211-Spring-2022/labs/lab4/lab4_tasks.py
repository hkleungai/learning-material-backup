from sklearn import datasets


def isNotebook():
    # This function would return True if it's run inside a notebook or ipython environment. False if it's in normal Python interpreter. Otherwise, it'll raise an Error.
    try:
        shell = get_ipython().__class__.__name__
        if shell == "ZMQInteractiveShell" or shell == "TerminalInteractiveShell":
            return True
        else:
            raise NotImplementedError
    except NameError:
        return False


if isNotebook():
    import matplotlib.pyplot as plt


def plot_diagram(X, y=None, k=None):
    if not isNotebook():
        return
    from itertools import cycle

    cycol = cycle("rgbcmk")
    if y is not None:
        if k is None:
            k = y.max() + 1
        for i, c in zip(range(k), cycol):
            plt.scatter(*X[y == i].T, c=c)


def plot_points(points, marker="o"):
    if not isNotebook():
        return
    plt.scatter(*points, c="w", marker=marker)
    pass


if isNotebook():
    secret_number = 42
else:
    import pickle

    # with open("secret_number.pkl", "rb") as f:
    #     secret_number = pickle.load(f)
    secret_number = 1234567

X, y = datasets.make_blobs(
    10000, 2, centers=3, random_state=secret_number
)  # Create a dataset with  3 blobs of cluster

# %%
class KCluster:
    def __init__(self, k, X, ndim=2):
        self.k = k
        self.ndim = ndim
        # TODO: Choose k data points from X as the initial centroids. (Hints: use numpy.random.randint)
        self.centroid = X[np.random.randint(0, len(X), size=(k,))]

    def run(self, X):
        # TODO: 1. Find the difference between each data point and centroid, assign the result to diff
        # Hints:
        #   - the shape of diff should be (self.k, X.shape[0], self.ndim).
        #   - notice that X and centroid can't be subtract directly, what can we do if the shape mismatched?
        #   - what's the rules of it? In what condition the content of the dimension will be copied? How should the data be copied?
        diff = X - self.centroid.reshape(self.k, 1, self.ndim)
        # TODO: 2. Calculate the Euclidean distance between each data point and centroid, assign the result to dist.
        # Hints:
        #   - Euclidean distance = ((x2 - x1)**2 + (y_2 - y_1)**2) ** 0.5. (Option 1)
        #   - you can also check the documentation of numpy.linalg.norm. (Option 2)
        #       - In which axis should the norm be calculated?
        # TODO (optional): You can also calculate the distance between each data point and centroid directly without following the instruction above.
        dist = np.linalg.norm(diff, axis=2)  # option 1
        dist = (diff ** 2).sum(axis=2) ** 0.5  # option 2
        # TODO: 3. Assign the index of the closest centroid to each data point.
        # Hints: use numpy.argmin to find the index of the closest centroid for each data point. In which axis should we find the minimum?
        output = dist.argmin(axis=0)
        # TODO: 4. Update each centroid using the mean of each cluster.
        # Hints:
        #  - we mentioned a method to choose specific elements from an array.
        #  - we mentioned that there were lots of function from NumPy for statistics. mean, std, median, etc. In what axis should we find the statistics?
        for i in range(self.k):
            self.centroid[i] = np.mean(X[output.T == i], axis=0)
        return output


# %%
def SSE(X, y, k, centroids):
    sse = 0
    # TODO: For each cluster, calculate distance (square of difference, i.e. Euclidean/L2-distance) of samples to the datapoints and accumulate the sum to `sse`. (Hints: use numpy.sum and for loop)
    # Hints:
    #   - This is very similar to the step 4 of Task 1.1
    for i in range(k):
        sse += np.sum((X[y.T == i] - centroids[i]) ** 2)
    return sse


# %% [markdown]
# ## Results
#
# After you finished writing the functions, you should see three individual blobs of points and an SSE of 20087.304945947668

# %%
import numpy as np

np.random.seed(secret_number)  # Set seeds to expect the same result everytime
kmean = KCluster(3, X)
initial_points = kmean.centroid.copy()
for n in range(100):
    output = kmean.run(X)
print("SSE: ", sse := round(SSE(X, output, 3, kmean.centroid), 5))
# print("SSE: ", 1)

plot_diagram(X, output, 3)
plot_points(kmean.centroid.T, marker="+")
plot_points(initial_points.T, marker="o")

# %%
# np.random.seed(2)  # Set seeds to expect the same result everytime
# kmean = KCluster(3, X)
# initial_points = kmean.centroid.copy()
# for n in range(500):
#     output = kmean.run(X)
#
# plot_diagram(X, output, 3)
# plot_points(kmean.centroid.T, marker="+")
# plot_points(initial_points.T, marker="o")
#
# # %%
# from sklearn import cluster
#
# X, y = datasets.make_moons(10000, noise=0.05)
# kmean = KCluster(2, X)
# for n in range(100):
#     output = kmean.run(X)
#
# plot_diagram(X, output, 2)  # The two clusters are obviously not correctly separated.
