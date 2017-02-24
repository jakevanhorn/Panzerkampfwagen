#include <iostream>
#include <vector>

using namespace std;

int main()
{

	int a = 9;

	vector <int> testV;

	testV.push_back(int(6));
	testV.emplace_back(4);

	cout << testV[0] << "  " << testV[1];

	while (true){ }

	return 10;
}
