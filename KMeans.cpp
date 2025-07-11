#include "KMeans.h"
#include "Cluster.h"
#include "Sample.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <limits>
#include <stdexcept>

using namespace std;

/**
 * @file KMeans.cpp
 * @brief Implementation of the KMeans clustering algorithm.
 */

/**
 * @brief Constructs a KMeans object and initializes clusters.
 * @param fileName Name of the input file containing sample data.
 * @param k Number of clusters for the algorithm.
 * @throws invalid_argument If the number of clusters (K) is less than or equal to 0.
 */
KMeans::KMeans(const string& fileName, int k)
    : K(k) {
    if (K <= 0) {
        throw invalid_argument("K must be a positive number.");
    }

    loadSamples(fileName);   // Load data from file
    initializeClusters();    // Initialize the first clusters
}

/**
 * @brief Destructor for the KMeans class.
 */
KMeans::~KMeans() {}

/**
 * @brief Loads sample data from a file.
 * @param fileName Name of the file containing sample data.
 * @throws runtime_error If the file cannot be opened.
 *
 * The file should have the format:
 * ```
 * index x y
 * ```
 */
void KMeans::loadSamples(const string &fileName) {
    ifstream file(fileName);
    if (!file) {
        throw runtime_error("File not found: " + fileName);
    }

    int index;
    double x, y;
	
    while (file >> index >> x >> y) {
        samples.emplace_back(index,-1, x, y); // Create Sample objects and add them to the vector
    }

    file.close();
}

/**
 * @brief Initializes clusters using the first K samples.
 */
void KMeans::initializeClusters() {
    for (int i = 0; i < K; ++i) {
        clusters.emplace_back(i + 1, samples[i].getXofSample(), samples[i].getYofSample());
    }
}

/**
 * @brief Assigns each sample to the nearest cluster.
 *
 * Calculates the Euclidean distance between each sample and all cluster centers, 
 * then assigns the sample to the nearest cluster.
 */
void KMeans::assignSamplesToClusters() {
    // First clear the samples in all clusters
    for (auto &cluster : clusters) {
        cluster.clearSamples();
    }

    // Assign each sample to the nearest cluster
    for (auto &sample : samples) {
        double minDistance = numeric_limits<double>::max();
        int bestClusterID = -1;

        for (const auto &cluster : clusters) {
            double distance = sqrt(pow(sample.getXofSample() - cluster.getXofCluster(), 2) +
                                   pow(sample.getYofSample() - cluster.getYofCluster(), 2));

            if (distance < minDistance) {
                minDistance = distance;
                bestClusterID = cluster.getIDofCluster();
            }
        }

        
        sample.setClusterID(bestClusterID); 			///< Assign the sample to the nearest cluster.
        clusters[bestClusterID - 1].addSample(&sample); ///< Add the sample to the cluster.
    }
}

/**
 * @brief Updates the centers of all clusters.
 * @return True if any cluster center has changed, false otherwise.
 */
bool KMeans::updateClusterCenters() {
    
	for (auto &cluster : clusters) {
        if(cluster.calculateCenter())
        {
        	return true;
		}
    }
} 

/**
 * @brief Runs the K-Means clustering algorithm.
 *
 * Repeatedly assigns samples to clusters and updates cluster centers until no centers change.
 */
void KMeans::run() {
    bool changed;
    do {
        changed = false;

        assignSamplesToClusters(); 		///< Assign samples to the nearest cluster.

        // Update and check cluster centers
        // Second way
        /*for (auto &cluster : clusters) {
            if (cluster.calculateCenter()) {
                changed = true;
            }
        } */
        changed = updateClusterCenters(); ///< Update cluster centers.
        
    } while (changed);
}

/**
 * @brief Prints clustering results to the console.
 *
 * Displays the clusters and their assigned samples.
 */
void KMeans::printResults() const {
    cout << "Cluster Results: \n";
    for (const auto &cluster : clusters) {
        cluster.print();
    }

    cout << "\nSamples: \n";
    for (const auto &sample : samples) {
        cout << sample;
    }
}

/**
 * @brief Saves clustering results to a file.
 * @param outputFile Name of the output file.
 * @throws runtime_error If the file cannot be opened.
 *
 * Saves cluster details and sample assignments to the specified file.
 */
void KMeans::saveResultsToFile(const string& outputFile) const
{
	ofstream outFile(outputFile);
	
	if(!outFile.is_open())
	{
		throw runtime_error("Error : Could not open file :" + outputFile);		
	}
	
	outFile << "Cluster Values\n";
	
	for(const auto& cluster : getClusters())
	{
		outFile << cluster;
	}
	
	outFile << "Sample Values \n";
	 for (const auto& sample : getSamples()) 
	{
        outFile << sample;
    }
        
        outFile.close();
}

/**
 * @brief Saves clustering results in a format suitable for plotting.
 * @param plotFile Name of the output file for plotting.
 * @throws runtime_error If the file cannot be opened.
 *
 * The format of the output file is:
 * ```
 * x-coordinate y-coordinate cluster-ID
 * ```
 */
void KMeans::saveResultsForPlotting(const string& plotFile) const {
    ofstream outFile(plotFile);

    if (!outFile.is_open()) {
        throw runtime_error("Error: Could not open file: " + plotFile);
    }

    // Save data in a plain format: x-coordinate, y-coordinate, cluster ID
    for (const auto& sample : getSamples()) {
        outFile << sample.getXofSample() << " " 
                << sample.getYofSample() << " " 
                << sample.getClusterID() << endl;
    }

    outFile.close();
}

/**
 * @brief Gets the vector of samples.
 * @return A constant reference to the vector of samples.
 */
const vector<Sample>& KMeans::getSamples(void) const
{
	return samples;
}

/**
 * @brief Gets the vector of clusters.
 * @return A constant reference to the vector of clusters.
 */
const vector<Cluster>& KMeans::getClusters(void) const
{
	return clusters;
}

