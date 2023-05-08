#include <iostream>
#include <queue>
#define MAX_SIZE (128)

int main(void)
{
	int c;
	int total_sum = 0;
	int count[128] = {0, };
	std::priority_queue<int, std::vector<int>,std::greater<int> > pq;

	while ((c = getc(stdin)) != EOF)
		count[(int)c]++;
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		if (count[i])
			pq.push(count[i]);
	}
	while (pq.size() > 1)
	{
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		int sum = a + b;
		total_sum += sum;
		pq.push(sum);
	}
	std::cout << total_sum;
	return (0);
}