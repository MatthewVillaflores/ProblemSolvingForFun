#include <stdio.h>
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> input_arr;	
	
	int in;
	std::cin >> in;
	
	while(!std::cin.eof())
	{
		input_arr.push_back(in);
		std::cin >> in;
	}

#ifdef LOG
	for(std::vector<int>::iterator itr = input_arr.begin();
			itr != input_arr.end();
			itr++)
	{
		printf("%d ", *itr);
	}
	printf("\n");
#endif

	std::vector<int> output_arr;

	for(int i=0; i<input_arr.size(); i++)
	{
		int prod = 1;
		for(int j=0; j<input_arr.size(); j++)
		{
			if(i == j)
			{
				j++;
			}
			if(j >= input_arr.size())
			{
				continue;
			}
			prod *= input_arr[j];
		}
		output_arr.push_back(prod);
	}

	for(std::vector<int>::iterator itr = output_arr.begin();
			itr != output_arr.end();
			itr++)
	{
		printf("%d ", *itr);
	}
	printf("\n");


}
