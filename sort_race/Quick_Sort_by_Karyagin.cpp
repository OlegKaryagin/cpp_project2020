#include <vector>

using namespace std;


void Quicky(vector<int>& data, int b, int e)
{
	int it_i = b - 1;
	for (int it_j = b; it_j < e; it_j++)
	{
		if (data[it_j] <= data[e])
		{
			if (it_i != it_j)
			{
				it_i++;
				swap(data[it_i],data[it_j]);
			}
		}
	}
	swap(data[it_i + 1],data[e]);
	if (it_i  - b > 0)
	{
		Quicky(data, b, it_i);
	}
	if (e - it_i > 2)
	{
		Quicky(data, it_i + 2, e);
	}
	return;
}

vector <int> QuickSort(vector<int> data)
{
	Quicky(data, 0, data.size() - 1);
	return data;
}