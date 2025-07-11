#ifndef CLUSTER_H
#define CLUSTER_H
#include <iostream>
#include <vector>

#include "Sample.h"

using namespace std;

/// @class Cluster
/// @brief Represents a cluster in the K-Means algorithm, including its ID, center coordinates, and associated samples.
class Cluster
{
	/// Overloaded << operator for printing a Cluster object.
    /// @param OUTPUT The output stream to write to.
   	/// @param c The Cluster object to be printed.
    /// @return A reference to the output stream.
	friend ostream& operator<<(ostream &OUTPUT, const Cluster &c);
	
	public:
		
		/// @brief Constructor for the Cluster class.
    	/// @param ID The unique identifier for the cluster.
    	/// @param X The x-coordinate of the cluster center.
    	/// @param Y The y-coordinate of the cluster center.
		Cluster(int ID, double X, double Y);
		
		/// @brief Destructor for the Cluster class.
		~Cluster();
		
		/// @brief Adds a sample to the cluster.
    	/// @param sample A pointer to the sample to add.
		void addSample(Sample* sample);
		
		/// @brief Clears all samples associated with the cluster.
		void clearSamples(void);
		
		/// @brief Calculates the new center of the cluster based on its samples.
    	/// @return True if the center has changed, otherwise false.
		bool calculateCenter(void);
		
		/// @brief Retrieves the x-coordinate of the cluster's center.
   		/// @return The x-coordinate as a double.
		double getXofCluster(void) const;
		
		/// @brief Retrieves the y-coordinate of the cluster's center.
    	/// @return The y-coordinate as a double.
		double getYofCluster(void) const;
		
		/// Get Function for ClusterID
		int getIDofCluster(void) const;
		
		

		
		void print(void) const;
	private:
		
		/// @brief The unique identifier for the cluster.
		int clusterID;
		
		/// @brief The x-coordinate of the cluster's center.
		double centerX;
		
		/// @brief The y-coordinate of the cluster's center.
		double centerY;
		
		/// @brief A vector of pointers to samples associated with the cluster.
		vector<Sample*> samples;
		
};

#endif
