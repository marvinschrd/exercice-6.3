#include <iostream>
#include <time.h>
#include <vector>

void BubbleSort(std::vector<int>table, int userInputNumbers);
void InsertionSort(std::vector<int>table, int userInputNumbers);
int partition(std::vector<int>& table, const int firstIndex, int lastIndex);
void quick_sort(std::vector<int>& table, const int firstIndex, int lastIndex, int tableSize);
void show_table(std::vector<int> table, int userInputNumbers);

int main() {
	int userInput = 0;
	int userInputNumbers = 0;
	srand(time(NULL));

	std::cout << "Bubble sort = 1 ; Insertion sort = 2 ; Quick sort = 3 \n";
	std::cout << "Choose the sort type you want to use : \n";
	std::cin >> userInput;
	std::cout << " Now choose how many numbers you want to sort : \n";
	std::cin >> userInputNumbers;

	std::vector<int>table;
	table.resize(userInputNumbers);

	for (int i = 0; i < userInputNumbers; i++)
	{
		int randomNumber = rand();


		table[i] = randomNumber;
		
	}

	switch (userInput)
	{
	case(1):
		BubbleSort(table, userInputNumbers);
		break;
	case(2):
		InsertionSort(table, userInputNumbers);
		break;
	case(3):
		const int firstIndex = 0;
		quick_sort(table, firstIndex, userInputNumbers - 1, userInputNumbers);
		show_table(table, userInputNumbers);
		break;
	}



	return EXIT_SUCCESS;
}

void BubbleSort(std::vector<int>table, int userInputNumbers) {




	for (int i = 0; i < userInputNumbers - 1; i++)
	{
		for (int j = 0; j < (userInputNumbers - i - 1); j++)
		{
			if (table[j] > table[j + 1])
			{
				std::swap(table[j], table[j + 1]);

			}

		}

	}

	for (int i = 0; i < userInputNumbers; i++)
	{
		std::cout << table[i] << "\n";

	}
}

void InsertionSort(std::vector<int>table, int userInputNumbers) {

	int j = 0;

	for (int i = 0; i < userInputNumbers; i++)
	{
		int test = 0;

		test = table[i];
		j = i - 1;

		while (j >= 0 && table[j] > test)
		{
			table[j + 1] = table[j];
			j--;

		}
		table[j + 1] = test;

	}

	for (int i = 0; i < userInputNumbers; i++)
	{

		std::cout << table[i] << "\n";
	}
}


void quick_sort(std::vector<int>& table, const int firstIndex, int lastIndex, int userInputNumbers)
{
	if (firstIndex < lastIndex)
	{
		int partIndex = partition(table, firstIndex, lastIndex);
		quick_sort(table, firstIndex, partIndex - 1, userInputNumbers);
		quick_sort(table, partIndex + 1, lastIndex, userInputNumbers);
	}
}

int partition(std::vector<int>& table, const int firstIndex, int lastIndex)
{
	int pivot = table[lastIndex];
	long long int index = firstIndex - 1;

	for (int i = firstIndex; i <= lastIndex - 1; i++)
	{
		if (table[i] < pivot)
		{
			index++;
			std::swap(table[index], table[i]);
		}
	}
	std::swap(table[index + 1], table[lastIndex]);
	return (index + 1);
}

void show_table(std::vector<int> table, int tablesize)
{
	for (int i = 0; i < table.size(); i++)
	{
		std::cout << table[i] << "\n";
	}
}



