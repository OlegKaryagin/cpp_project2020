#include <vector>

using namespace std;


void Quicky(vector<int>& data, int low, int high)
{
	int first =low - 1;
	for (int second = low; second < high; second++)
	{
		if (data[second] <= data[high])
		{
			if (first != second)
			{
				first++;
				swap(data[first],data[second]);
			}
		}
	}
	swap(data[first + 1],data[high]);
	if (first  - low > 0)
	{
		Quicky(data, low, first);
	}
	if (high - first > 2)
	{
		Quicky(data, first + 2, high);
	}
	return;
}

vector <int> QuickSortByKaryagin(vector<int> data)
{
	Quicky(data, 0, data.size() - 1);
	return data;
}