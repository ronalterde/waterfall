#!/usr/bin/env python3

import sys
import numpy as np
import matplotlib.pyplot as plt

RAW_FILE = sys.argv[1]
BLOCK_SIZE = int(sys.argv[2])

if __name__ == "__main__":
    f = open(RAW_FILE, 'rb')
    raw_bytes = f.read()

    floats = [float(i) for i in raw_bytes]
    chunks = [floats[i:i + BLOCK_SIZE] for i in range(0, len(floats), BLOCK_SIZE)]
    mat = np.matrix(chunks)
    plt.matshow(mat)
    plt.show()
