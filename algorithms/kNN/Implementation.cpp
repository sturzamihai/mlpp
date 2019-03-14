#include "UnleashingML.h"
#include "kNN.h"

int main() {
	CSVReader csv;
	auto data = csv.readCSV("data.csv");
	auto splittedData = csv.splitData(data, 3);
	auto unconvertedX = std::get<0>(splittedData);
	auto y = std::get<1>(splittedData);
	auto X = csv.convertToFloat(unconvertedX);
	KNearestNeighbors model;
	model.fit(X, y, 3);
	std::vector<float> test;
	test.push_back(6.1), test.push_back(3.0), test.push_back(4.9), test.push_back(1.8);
	std::cout << model.predict(test) << std::endl;
	std::system("pause");
}