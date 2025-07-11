#include "Cluster.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Constructs a Cluster object.
 * @param ID The unique ID of the cluster.
 * @param X The x-coordinate of the cluster center.
 * @param Y The y-coordinate of the cluster center.
 */
Cluster::Cluster(int ID, double X, double Y)
: clusterID(ID), centerX(X), centerY(Y)
{
	
}

/**
 * @brief Destructor for the Cluster class.
 */
Cluster::~Cluster()
{
}

/**
 * @brief Adds a sample to the cluster.
 * @param sample Pointer to the sample to add.
 *
 * The sample is appended to the internal vector of samples belonging to the cluster.
 */
void Cluster::addSample(Sample* sample)
{	
	samples.push_back(sample);
}

/**
 * @brief Clears all samples from the cluster.
 *
 * Removes all elements from the internal vector of samples.
 */
void Cluster::clearSamples(void)
{	
	samples.clear();
}

/**
 * @brief Calculates and updates the center of the cluster.
 * @return True if the center of the cluster has changed, false otherwise.
 *
 * The new center is computed as the mean of the x and y coordinates of the samples in the cluster.
 * If the calculated center differs from the previous center, the method returns true.
 */
bool Cluster::calculateCenter(void) {
    if (samples.empty()) 
	{
		return false;	
	}

    double sumX = 0, sumY = 0;
    for (const auto& sample : samples) { 
        sumX += sample->getXofSample();
        sumY += sample->getYofSample();
    }

    double newCenterX = sumX / samples.size();
    double newCenterY = sumY / samples.size();

    bool changed = (newCenterX != centerX || newCenterY != centerY); 
    centerX = newCenterX;
    centerY = newCenterY;

    return changed;
}

/**
 * @brief Gets the x-coordinate of the cluster center.
 * @return The x-coordinate of the cluster center.
 */
double Cluster::getXofCluster(void) const
{
	return centerX;
}

/**
 * @brief Gets the y-coordinate of the cluster center.
 * @return The y-coordinate of the cluster center.
 */
double Cluster::getYofCluster(void) const
{
	return centerY;
}

/**
 * @brief Gets the unique ID of the cluster.
 * @return The ID of the cluster.
 */
int Cluster::getIDofCluster(void) const
{
	return clusterID;
}

/**
 * @brief Prints the cluster details using the overloaded << operator.
 */
void Cluster::print(void) const   
{
	cout << *this;
}

/**
 * @brief Overloads the << operator to output a Cluster object.
 * @param OUTPUT The output stream to write to.
 * @param c The Cluster object to write.
 * @return A reference to the output stream.
 *
 * Outputs the cluster in the format:
 * Cluster ID : <clusterID>, Center : (<centerX>,<centerY>)
 */
ostream& operator<<(ostream &OUTPUT, const Cluster &c)
{
	OUTPUT << "Cluster ID : " << c.getIDofCluster()
	<< ", Center : (" << c.getXofCluster() << "," << c.getYofCluster() << ")"<< endl;
	
	return OUTPUT;
}


