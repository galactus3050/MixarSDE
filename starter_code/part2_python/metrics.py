import numpy as np

def compute_metrics(mesh):
    return {
        "mesh": mesh,
        "stretch": np.random.rand(),
        "area": np.random.rand()
    }
