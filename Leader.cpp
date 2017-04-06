#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int solution(int A[], int n)
{
	constexpr int N = 12;
	int currentVals[N] = { 0 };
	int common[N];
	int boom = 0;
	for (size_t i = 0; i < N; i++)
	{
		++currentVals[A[i]];
		if (currentVals[A[i]] > boom)
		{
			boom = currentVals[A[i]];
			common[i] = A[i];
		}
		else if (currentVals[A[i]] == boom)
		{
			common[i] = -1;
		}
		else if (currentVals[A[i]] < boom)
		{
			common[i] = common[i - 1];
		}
	}

	currentVals[N] = { 0 };
	common[N];
	boom = 0;
	for (int i = n - 1; i >= 0; i--) {
		++currentVals[A[i]];
		if (currentVals[A[i]] > boom)
		{
			boom = currentVals[A[i]];
			common[i] = A[i];
		}
		else if (currentVals[A[i]] == boom)
		{
			common[i] = -1;
		}
		else if (currentVals[A[i]] < boom)
		{
			common[i] = common[i + 1];
		}
	}
	for (auto me : common)
	{
		cout << me << "\n";
	}
	return -10;
}

struct sta
{
	sta(size_t s)
	{
		v.resize(s);
	}
	char po()
	{
		--pointer;
		if (pointer == -1)
			return 'f';
		return v[pointer];
	}
	void p(char c)
	{
		v[pointer] = c;
		++pointer;
	}
	vector<char> v;
	int pointer = 0;
};

int solution(vector<int> &A)
{
	int N = A.size();
	if (N < 3)
		return 0;
	sort(A.begin(), A.end());
	for (int i = 3; i != N; ++i)
	{
		if (A[i - 1] + A[i - 2] > A[i])
			return 1;
	}
	return 0;
}

int solution2(string &S) {
	if (S.size() % 2 != 0)
		return 0;
	else
	{
		for (int i = 0, j = S.size() - 1; i < j; ++i, --j)
			if (S[i] != S[j])
				return 0;
	}
	return 1;
}

#include <cmath>
int main()
{

	//string test = "{[()()]}";
	//int a[] = { 4, 3, 4, 4, 4, 2, 5, 5, 5, 5, 5, 5 };
	//int N = 6;
	//cout << solution(a, N);
	int N, T;
	//cin >> N;
	N = 100;
	vector<int> v(N, -1);
	vector<int> d{ 100, 5, 6, 1, 30 };
	int i = 0;
	while (N--)
	{
		//cin >> T;
		if (i == 5)
		{
			cout << "REWER";
		}
		T = d[i];
		++i;
		//index in array of node we are on
		int currentNode = 0;
		//where we are in array in terms of height
		int currentHeight = 1;

		while (true)
		{
			auto & val = v[currentNode];
			if (val == -1)
			{
				cout << "i is: " << i << endl;
				val = T;
				break;
			}
			else if (T > val)
			{
				//go to right
				int previousNodes = 0;
				int leftoverNode = 1;
				if (currentHeight > 2)
				{
					previousNodes = pow(2, (currentHeight - 1)) - 2;
				}
				if (currentHeight > 1)
					leftoverNode = currentNode - previousNodes;

				int nodesHere = pow(2, (currentHeight - 1));

				currentNode += nodesHere - leftoverNode + leftoverNode * 2;
			}
			else if (T < val)
			{
				int nodesBefore = pow(2, currentHeight - 1) - 2;
				int maxNodeThisRow = pow(2, currentHeight) - 2;
				currentNode = maxNodeThisRow + (currentNode - nodesBefore) * 2 - 1;
			}
			++currentHeight;
		}
	}
	return 0;
}