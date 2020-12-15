#include <vector>

using namespace std;


vector <int>QuickSort(vector<int> mass)
{
	vector<int> sorted = mass;
	vector<int> Stack;
	Stack.push_back(0);
	Stack.push_back(sorted.size() - 1);
	while (!Stack.empty())
	{
		int last = Stack.back();
		Stack.pop_back();
		int first = Stack.back();
		Stack.pop_back();
		int it_i = first - 1;
		for (int it_j = first; it_j < last; it_j++)
		{
			if (sorted[it_j] <= sorted[last])
			{
				if (it_i != it_j)
				{
					it_i++;
					swap(sorted[it_i], sorted[it_j]);
				}
			}
		}
		swap(sorted[it_i + 1], sorted[last]);
		int p = it_i + 1;
		if (p - first > 1)
		{
			Stack.push_back(first);
			Stack.push_back(p - 1);
		}
		if (last - p > 1)
		{
			Stack.push_back(p + 1);
			Stack.push_back(last);
		}
	}
	return sorted;
}