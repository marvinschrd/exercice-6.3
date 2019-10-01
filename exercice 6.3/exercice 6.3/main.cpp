#include <iostream>
#include <time.h>
#include <vector>

void BubbleSort(std::vector<int>table, int userInputNumbers);
void InsertionSort(std::vector<int>table, int userInputNumbers);

int main() {
	int userInput = 0;
	int userInputNumbers = 0;
	srand(time(NULL));

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
		/*std::cout << table[i] << "\n";*/
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
