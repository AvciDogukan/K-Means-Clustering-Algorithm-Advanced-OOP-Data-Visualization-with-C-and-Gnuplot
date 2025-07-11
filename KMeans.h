#ifndef KMEANS_H
#define KMEANS_H
#include <iostream>
#include "Cluster.h"
#include <fstream>
#include <cmath>
#include <limits>
#include <stdexcept>

using namespace std;

/**
 * @class KMeans
 * @brief Implements the K-Means clustering algorithm.
 */
class KMeans
{
	public:
		
		 /**
     	* @brief Constructor for the KMeans class.
     	* @param fileName The file containing the data points.
     	* @param k The number of clusters to form.
     	* @throws invalid_argument if k is less than or equal to zero.
     	*/
		KMeans(const string& fileName, int k);
		
		 /**
     	* @brief Destructor for the KMeans class.
     	*/
		~KMeans();
		
		 /**
     	* @brief Loads data points (samples) from a file.
     	* @param fileName The name of the file to read data from.
     	* @throws runtime_error if the file cannot be opened.
     	*/
		void loadSamples(const string &fileName);
		
		/**
     	* @brief Initializes clusters using the first k data points as initial centroids.
     	*/
		void initializeClusters(void);
		
		/**
     	* @brief Assigns each data point to the nearest cluster.
     	* 
     	* Clears all cluster samples before assigning new ones.
     	*/
		void assignSamplesToClusters(void);
		
		/**
     	* @brief Updates the centroids of all clusters.
     	* @return True if any centroid changes, false otherwise.
     	*/
		bool updateClusterCenters(void);
		
		/**
     	* @brief Runs the K-Means algorithm until convergence.
     	* 
     	* The algorithm stops when cluster centroids no longer change.
     	*/
		void run(void);
		
		/**
     	* @brief Prints the clustering results to the console.
     	*/
		void printResults() const;
		
		/**
     	* @brief Saves clustering results to a file.
     	* @param outputFile The name of the file to save the results.
     	* @throws runtime_error if the file cannot be opened.
     	*/
		void saveResultsToFile(const string& outputFile) const;
		
		/**
     	* @brief Saves clustering results for plotting with external tools.
     	* @param plotFile The name of the file to save plot-friendly data.
     	* 
     	* Saves data in the format: x-coordinate, y-coordinate, cluster ID.
     	*/
		void saveResultsForPlotting(const string& plotFile) const;
		
		/**
     	* @brief Gets the list of samples (data points).
     	* @return A constant reference to the vector of samples.
     	*/
		const vector<Sample>& getSamples(void) const ;
		
		/**
     	* @brief Gets the list of clusters.
     	* @return A constant reference to the vector of clusters.
     	*/
		const vector<Cluster>& getClusters(void) const;
		
	private:
		
		/**
     	* @brief Number of clusters.
     	*/
		int K;
		
		/**
     	* @brief Vector of samples (data points).
     	*/
		vector<Sample> samples;
		
		 /**
     	* @brief Vector of clusters.
     	*/
		vector<Cluster> clusters;
};

#endif
