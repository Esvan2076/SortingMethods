#include <iostream>
#include <string>
#include <fmt/core.h>
#include <fmt/color.h>

#include "input_utils.hpp"
#include "sorter.hpp"

int main()
{
    const std::string menu =
        "\n======== MAIN MENU ========\n"
		"[1] Add Number\t"
		"[2] Print\n"
		"[3] Bubble\t"
		"[4] Insertion\n"
		"[5] Merge\t"
		"[6] Quick\n"
		"[7] Seleccion\t"
		"[0] Exit\n"
		"===========================\n";

	short res = 0;
	Sorter list;

	do {
		fmt::print(fg(fmt::color::coral), menu);
		fmt::print(fg(fmt::color::light_sky_blue), "Option > ");
		std::string input;
		std::getline(std::cin, input);

		res = transInputToShort(input);
		clearConsole();

		switch (res) {
		case 1: {
			fmt::print("You selected option 1: Add Number\n");
			Number num{ createNumber() };
			num.print();
			list.add(num);
			break;
		}
		case 2:
			fmt::print("You selected option 2: Print Numbers\n");
			list.print();
			break;
		case 3:
			fmt::print("You selected option 3: Bubble Sort\n");
			list.bubbleSort();
			break;
		case 4:
			fmt::print("You selected option 4: Insertion Sort\n");
			list.insertionSort();
			break;
		case 5:
			fmt::print("You selected option 5: Merge Sort\n");
			list.mergeSort();
			break;
		case 6:
			fmt::print("You selected option 6: Quick Sort\n");
			list.quickSort();
			break;
		case 7:
			fmt::print("You selected option 7:\n");
			break;
		case 0:
			fmt::print("Exiting program...\n");
			break;
		default:
			fmt::print(fg(fmt::color::red), "Invalid option, try again\n");
			pause();
			break;
		}
	} while (res != 0);
}