#include <iostream>
#include <vector>
#include <numeric>
#include "Span.hpp"

static void printResult(const std::string &test, bool passed)
{
	std::cout << "[" << (passed ? "PASS" : "FAIL") << "] " << test << "\n";
}

int main(void)
{
	// --- subject example ---
	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		printResult("subject example: shortestSpan == 2", sp.shortestSpan() == 2);
		printResult("subject example: longestSpan == 14", sp.longestSpan() == 14);
	}

	// --- overflow: adding too many numbers ---
	{
		Span sp(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		try {
			sp.addNumber(4);
			printResult("addNumber: throws when full", false);
		} catch (const std::exception &e) {
			printResult("addNumber: throws when full", true);
		}
	}

	// --- too few numbers for span ---
	{
		Span sp(5);
		try {
			sp.shortestSpan();
			printResult("shortestSpan: throws on empty", false);
		} catch (const std::exception &e) {
			printResult("shortestSpan: throws on empty", true);
		}
		try {
			sp.longestSpan();
			printResult("longestSpan: throws on empty", false);
		} catch (const std::exception &e) {
			printResult("longestSpan: throws on empty", true);
		}
		sp.addNumber(42);
		try {
			sp.shortestSpan();
			printResult("shortestSpan: throws on single element", false);
		} catch (const std::exception &e) {
			printResult("shortestSpan: throws on single element", true);
		}
		try {
			sp.longestSpan();
			printResult("longestSpan: throws on single element", false);
		} catch (const std::exception &e) {
			printResult("longestSpan: throws on single element", true);
		}
	}

	// --- addNumbers with iterator range ---
	{
		std::vector<int> src = {5, 1, 8, 3, 9};
		Span sp(5);
		sp.addNumbers(src.begin(), src.end());
		printResult("addNumbers: shortestSpan == 2", sp.shortestSpan() == 2);
		printResult("addNumbers: longestSpan == 8",  sp.longestSpan() == 8);
	}

	// --- addNumbers overflow mid-range ---
	{
		std::vector<int> src = {1, 2, 3, 4, 5};
		Span sp(3);
		try {
			sp.addNumbers(src.begin(), src.end());
			printResult("addNumbers: throws when overflowing mid-range", false);
		} catch (const std::exception &e) {
			printResult("addNumbers: throws when overflowing mid-range", true);
		}
	}

	// --- large dataset: 10,000 numbers ---
	{
		const unsigned int SIZE = 10000;
		Span sp(SIZE);
		std::vector<int> big(SIZE);
		std::iota(big.begin(), big.end(), 0); // 0..9999
		sp.addNumbers(big.begin(), big.end());
		printResult("large dataset: shortestSpan == 1", sp.shortestSpan() == 1);
		printResult("large dataset: longestSpan == 9999", sp.longestSpan() == 9999);
	}

	// --- copy constructor ---
	{
		Span sp1(3);
		sp1.addNumber(10);
		sp1.addNumber(20);
		sp1.addNumber(30);
		Span sp2(sp1);
		printResult("copy constructor: longestSpan == 20", sp2.longestSpan() == 20);
	}

	// --- assignment operator ---
	{
		Span sp1(3);
		sp1.addNumber(100);
		sp1.addNumber(1);
		Span sp2(1);
		sp2 = sp1;
		printResult("assignment operator: longestSpan == 99", sp2.longestSpan() == 99);
	}

	return 0;
}
