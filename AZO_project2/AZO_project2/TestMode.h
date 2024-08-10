#ifndef TESTMODE_H
#define TESTMODE_H

#include <string>

class TestMode {
public:
    void runTests(const int* liczbyWierzcholkow, int liczbaWierzcholkowCount, const double* gestosciGrafu, int gestosciGrafuCount, const std::string& outputFile);

private:
    void testAlgorithms(int liczbaWierzcholkow, double gestosc, double& dijkstraMI, double& dijkstraLS, double& bellmanMI, double& bellmanLS, double& primMI, double& primLS, double& kruskalMI, double& kruskalLS);
    void logResults(const std::string& algorithmName, double duration, std::ofstream& outFile);
};

#endif
