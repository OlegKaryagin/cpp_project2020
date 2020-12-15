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
		int high = Stack.back();
		Stack.pop_back();
		int low = Stack.back();
		Stack.pop_back();
		int first = low - 1;
		for (int last = low; last < high; last++)
		{
			if (sorted[last] <= sorted[high])
			{
				if (first != last)
				{
					first++;
					swap(sorted[first], sorted[last]);
				}
			}
		}
		swap(sorted[first + 1], sorted[high]);
		int p = first + 1;
		if (p - low > 1)
		{
			Stack.push_back(low);
			Stack.push_back(p - 1);
		}
		if (high - p > 1)
		{
			Stack.push_back(p + 1);
			Stack.push_back(high);
		}
	}
	return sorted;
}