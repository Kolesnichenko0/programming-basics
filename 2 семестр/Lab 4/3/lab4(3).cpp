//Counting the number of repetitions of values 

#include <iostream>
#include <map>
#include <set>
#include <fstream>

using std::map;
using std::set;
using std::ifstream;
using std::cout;

int main() {
	//associative array to store the number of repetitions of each value
	map<int, int> occurrences;
	//a set of numbers that will be excluded from the repetition count
	set<int> exclusionList = { 2, 6, 9, 11, 3 };

	ifstream in("data.txt");
	if (!in) {
		//print a message if the file could not be opened
		cout << "Cannot open the file." << std::endl;
		return 1;
	}

	int value;
	while (in >> value) {
		if (exclusionList.count(value) != 0) { //check if the value should be excluded
			cout << "A number from the list of exceptions was encountered:" << value << "\n";
		}
		else {
			//increment the repetition counter for this value
			occurrences[value]++;
		}
	}

	std::cout << "\nResults of counting repetitions:" << std::endl;
	//iterate over the elements of the associative array
	for (auto it = occurrences.begin(); it != occurrences.end(); it++) {
		cout << "Value: " << it->first << " Number of repetitions: " << it->second << std::endl;
	}
	return 0;
}

