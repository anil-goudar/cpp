import numpy as np
import itertools

Xpts=[1.1, 2.01, 1.13, 1.6, 2.1, 2.5, 2.6, 2.7, 1.9, 0.5, 0.2, 0.3]
Ypts=[1.6, 2.1, 2.5, 2.6]

Points = np.array(list(itertools.product(Xpts, Ypts)))
np.save('data1.npy', Points)
array_loaded = np.load('data1.npy')
print(array_loaded)