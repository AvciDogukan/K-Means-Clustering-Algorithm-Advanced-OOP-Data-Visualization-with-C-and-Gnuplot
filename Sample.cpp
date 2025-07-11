#include "Sample.h"
#include <stdexcept>

using namespace std;

/**
 * @brief Constructs a Sample object.
 * @param i The index of the sample.
 * @param ID The initial cluster ID (default is -1 for unassigned).
 * @param X The x-coordinate of the sample.
 * @param Y The y-coordinate of the sample.
 */
Sample::Sample(int i,int ID, double X, double Y)
: index(i), x(X), y(Y)
{
	
}

/**
 * @brief Destructor for the Sample class.
 */
Sample::~Sample()
{
}

/**
 * @brief Sets the cluster ID of the sample.
 * @param ID The cluster ID to assign.
 */
void Sample::setClusterID(int ID)
{
	clusterID = ID;
}

/**
 * @brief Gets the index of the sample.
 * @return The index of the sample.
 */
int Sample::getIndex(void) const
{
	return index;
}

/**
 * @brief Gets the cluster ID of the sample.
 * @return The cluster ID of the sample.
 */
int Sample::getClusterID(void) const
{
	return clusterID;
}

/**
 * @brief Gets the x-coordinate of the sample.
 * @return The x-coordinate of the sample.
 */
double Sample::getXofSample(void) const
{
	return x;
}

/**
 * @brief Gets the y-coordinate of the sample.
 * @return The y-coordinate of the sample.
 */
double Sample::getYofSample(void) const
{
	return y;
}

/**
 * @brief Overloads the << operator to output a Sample object.
 * @param OUTPUT The output stream to write to.
 * @param a The Sample object to write.
 * @return A reference to the output stream.
 *
 * Outputs the sample in the format:
 * Index : <index>, x : <x>, y : <y>, Cluster : <clusterID>
 */
ostream& operator<<(ostream &OUTPUT, const Sample &a)
{
	OUTPUT << "Index : " << a.getIndex() << ", x : " << a.getXofSample()
		<< ", y : " << a.getYofSample() << ", Cluster : " << a.getClusterID() << endl;
		
	return OUTPUT;
}
