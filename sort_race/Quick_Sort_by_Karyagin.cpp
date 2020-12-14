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
		int j = Stack.back();
		Stack.pop_back();
		int i = Stack.back();
		Stack.pop_back();
		int it_i = i - 1;
		for (int it_j = i; it_j < j; it_j++)
		{
			if (sorted[it_j] <= sorted[j])
			{
				if (it_i != it_j)
				{
					it_i++;
					int temp = sorted[it_i];
					sorted[it_i] = sorted[it_j];
					sorted[it_j] = temp;
				}
			}
		}
		int tempo = sorted[it_i + 1];
		sorted[it_i + 1] = sorted[j];
		sorted[j] = tempo;
		int p = it_i + 1;
		if (p - i > 1)
		{
			Stack.push_back(i);
			Stack.push_back(p - 1);
		}
		if (j - p > 1)
		{
			Stack.push_back(p + 1);
			Stack.push_back(j);
		}
	}
	return sorted;
}