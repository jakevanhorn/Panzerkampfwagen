#include <iostream>
#include <vector>

using namespace std;

int main()
{

	int a = 9;

	vector <int> testV;

	testV.push_back(a);
	a = 7;
	testV.push_back(a);

	cout << testV[0] << "  " << testV[1];

	while (true){ }

	return 10;
}
