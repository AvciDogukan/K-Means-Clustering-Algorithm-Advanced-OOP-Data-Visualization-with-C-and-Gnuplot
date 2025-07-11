#ifndef SAMPLE_H
#define SAMPLE_H
#include <iostream>
using namespace std;

class Sample
{	

	/// @class Sample
	/// @brief Represents a data point with its cluster assignment and coordinates.(Non member)
	friend ostream& operator<<(ostream &OUTPUT, const Sample &a);
	
	public:
		
		/// @brief Constructor for the Sample class.
    	/// @param i The unique index of the sample.
    	/// @param ID The cluster ID the sample belongs to.
    	/// @param X The x-coordinate of the sample.
    	/// @param Y The y-coordinate of the sample.
		Sample(int i,int ID, double X, double Y);
		
		/// @brief Destructor for the Sample class.
		~Sample();
		
		/// @brief Sets the cluster ID for the sample.
    	/// @param ID The cluster ID to set.
		void setClusterID(int ID);
		
		/// @brief Retrieves the index of the sample.
    	/// @return The index of the sample as an integer.
		int getIndex(void) const;
		
		/// @brief Retrieves the cluster ID of the sample.
   		/// @return The cluster ID as an integer.
		int getClusterID(void) const;
		
		/// @brief Retrieves the x-coordinate of the sample.
    	/// @return The x-coordinate as a double.
		double getXofSample(void) const;
		
		/// @brief Retrieves the y-coordinate of the sample.
    	/// @return The y-coordinate as a double.
		double getYofSample(void) const;
		
	private:
		
		/// @brief The unique identifier for the sample (e.g., 0-39).
		int index;
		
		/// @brief The cluster ID the sample is assigned to (based on K-means clustering).
		int clusterID;
		
		/// @brief The x-coordinate of the sample.
		double x;
		
		/// @brief The y-coordinate of the sample.
		double y;
		
};

#endif
