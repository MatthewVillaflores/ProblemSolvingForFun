#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::string input_string;
	std::cin >> input_string;
	int k_sum = atoi(input_string.c_str());
#ifdef LOG
	printf("got k: %d\n", k_sum);
#endif

	std::vector<int> sorted_n;

	std::cin >> input_string;

	while(!std::cin.eof())
	{
		int num_insert = atoi(input_string.c_str());
		if(sorted_n.empty())
		{
			sorted_n.push_back(num_insert);
			std::cin >> input_string;
			continue;
		}

		std::vector<int>::iterator itr = sorted_n.begin();
		while(num_insert >= *itr && itr != sorted_n.end())
		{
			itr++;
		}
		sorted_n.insert(itr, num_insert);
		std::cin >> input_string;

#ifdef LOG
		for(std::vector<int>::iterator itr = sorted_n.begin(); itr != sorted_n.end(); itr++)
		{
			printf("%d ", *itr);
		}
		printf("\n");
#endif
	}
	std::vector<int>::iterator min = sorted_n.begin();
	std::vector<int>::iterator max = sorted_n.end()-1;

	while(min != max || *min < *max)
	{
#ifdef LOG
		printf("comparing: %d %d\n", *min, *max);
#endif

		if((*min+*max) == k_sum)
		{
			printf("true\n");
			return 1;
		}
		else if((*min+*max) > k_sum)
		{
			max--;
		}
		else
		{
			min++;
		}

	}

	printf("false\n");
	return -1;
}
