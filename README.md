# K-Means Clustering Algorithm

Author : Dogukan Avci
Date : 22.12.2024
OOP Lab Final

## Introduction
Welcome to the **K-Means Clustering Algorithm** project, an advanced implementation of one of the most popular unsupervised machine learning algorithms. This project is designed to demonstrate clustering concepts, file-based data processing, and visualization using **C++** and **Gnuplot**.

The algorithm partitions a dataset into a specified number of clusters (**K**) by:
- Assigning data points to the nearest cluster center.
- Iteratively recalculating cluster centroids until convergence.

---

## Features
### Dynamic Clustering
- **Iterative Clustering**: Repeats assignment and centroid calculation steps until stability is reached.
- **Euclidean Distance**: Assigns data points to clusters based on their proximity to cluster centers.
- **Dynamic Updates**: Automatically adjusts cluster centers as data points are reassigned.

### File-Based Input and Output
- **Input Data Format**:
  - Reads input from a text file with the format: `index x-coordinate y-coordinate`.
- **Output Data**:
  - Saves detailed clustering results in a user-specified file.
  - Generates a plot-friendly file for visualization.

### Visualization
- **Gnuplot Integration**:
  - Creates a Gnuplot script to visualize clustering results.
  - Outputs clusters in different colors for better understanding.

---

## Technical Overview
### Classes
#### 1. `Sample`
Represents a data point with the following attributes:
- Index
- Cluster assignment (ID)
- Coordinates (x, y)

Key Methods:
- `getXofSample()`, `getYofSample()`: Retrieve coordinates of the sample.
- `setClusterID()`: Assign a cluster to the sample.
- Overloaded `<<` operator for easy printing.

#### 2. `Cluster`
Represents a cluster with:
- Unique ID
- Center coordinates (x, y)
- Associated samples

Key Methods:
- `addSample(Sample* sample)`: Adds a sample to the cluster.
- `calculateCenter()`: Recalculates the cluster's center based on assigned samples.
- Overloaded `<<` operator for cluster printing.

#### 3. `KMeans`
Manages the clustering algorithm with:
- A vector of `Sample` objects (data points).
- A vector of `Cluster` objects.

Key Methods:
- `initializeClusters()`: Initializes clusters with the first K samples.
- `assignSamplesToClusters()`: Assigns data points to the nearest cluster.
- `updateClusterCenters()`: Updates cluster centroids.
- `run()`: Executes the K-Means algorithm until convergence.

---

## How It Works
### Algorithm Steps
1. **Initialization**:
   - Load samples from the input file.
   - Use the first K samples as initial cluster centers.
2. **Assignment**:
   - Calculate the Euclidean distance between each sample and all cluster centers.
   - Assign each sample to the nearest cluster.
3. **Update**:
   - Recalculate cluster centers as the mean of all samples in the cluster.
   - Repeat until no cluster center changes.

---

## File Formats
### Input Data
The input file should have the following format:
```plaintext
index x-coordinate y-coordinate
