/**
 * @file main.cpp
 * @brief Entry point for executing the K-Means clustering algorithm and visualizing results.
 * 
 * This program performs K-Means clustering on input data, saves the results to files, and
 * visualizes the clustering output using Gnuplot.
 * 
 * @author [Doðukan Avcý]
 * @date [22.12.2024]
 */

#include <iostream>
#include <fstream>
#include <cstdlib> // for system() 
#include "KMeans.h"

using namespace std;

/**
 * @brief Creates a Gnuplot script to visualize clustering results and executes it.
 * 
 * @param dataFile The name of the data file containing clustering results in the format:
 *                 `x-coordinate y-coordinate clusterID`
 * 
 * The function generates a Gnuplot script and executes it to display the clustering results
 * as a scatter plot. Each cluster is visualized with a unique color.
 */
 
void plotWithGnuplot(const string& dataFile) {
    ofstream gnuplotScript("plot_script.gnu");
    if (!gnuplotScript) {
        cerr << "Gnuplot script dosyasý oluþturulamadý!" << endl;
        return;
    }

    // Write Gnuplot commands to the script
    gnuplotScript << "set title 'K-Means Clustering Result'\n";
    gnuplotScript << "set xlabel 'X Coordinate'\n";
    gnuplotScript << "set ylabel 'Y Coordinate'\n";
    gnuplotScript << "set palette defined (0 'red', 1 'green', 2 'blue', 3 'yellow', 4 'purple')\n";
    gnuplotScript << "plot '" << dataFile 
                  << "' using 1:2:3 with points palette pointtype 7 pointsize 1 title 'Clusters'\n";
    gnuplotScript << "pause -1\n"; // Keeps the plot window open
    gnuplotScript.close();

    // Execute the Gnuplot script
    system("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\" plot_script.gnu");
}


int main() {
    try {
        string inputFile = "40.txt";     		///< Name of the input data file
        string outputFile = "output.txt";		///< Name of the file to save detailed clustering results
		string plotFile = "plotFile.txt"; 		///< Name of the file to save results for Gnuplot
        int K = 3;                       		///< Number of clusters

        // Create a KMeans object and execute the algorithm
        KMeans kmeans(inputFile, K);
        kmeans.run();

        // Print results to the console
        kmeans.printResults();
        
         // Save results to files
		kmeans.saveResultsToFile(outputFile);
		
		// Save results to file for plotting
		kmeans.saveResultsForPlotting(plotFile);
		
		
        // Visualize results using Gnuplot
        plotWithGnuplot(plotFile);

        cout << "\nK-Means clustering result successfully displayed!" << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}

