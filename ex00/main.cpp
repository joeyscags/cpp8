/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeyscags <jcupp@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:39:29 by joeyscags         #+#    #+#             */
/*   Updated: 2026/02/25 00:31:47 by joeyscags        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

static void printResult(const std::string &test, bool passed)
{
	std::cout << "[" << (passed ? "PASS" : "FAIL") << "] " << test << "\n";
}

int main(void)
{
	// --- vector tests ---
	std::vector<int> vec = {3, 7, 1, 9, 42, 7};

	try {
		auto it = easyfind(vec, 42);
		printResult("vector: find 42", *it == 42);
	} catch (const std::exception &e) {
		printResult("vector: find 42", false);
	}

	try {
		auto it = easyfind(vec, 7);
		printResult("vector: find first occurrence of 7", *it == 7 && it == vec.begin() + 1);
	} catch (const std::exception &e) {
		printResult("vector: find first occurrence of 7", false);
	}

	try {
		easyfind(vec, 99);
		printResult("vector: not found throws", false);
	} catch (const std::exception &e) {
		printResult("vector: not found throws", true);
	}

	// --- list tests ---
	std::list<int> lst = {10, 20, 30, 40, 50};

	try {
		auto it = easyfind(lst, 30);
		printResult("list: find 30", *it == 30);
	} catch (const std::exception &e) {
		printResult("list: find 30", false);
	}

	try {
		easyfind(lst, 0);
		printResult("list: not found throws", false);
	} catch (const std::exception &e) {
		printResult("list: not found throws", true);
	}

	// --- deque tests ---
	std::deque<int> deq = {5, 15, 25};

	try {
		auto it = easyfind(deq, 5);
		printResult("deque: find 5", *it == 5);
	} catch (const std::exception &e) {
		printResult("deque: find 5", false);
	}

	try {
		easyfind(deq, 100);
		printResult("deque: not found throws", false);
	} catch (const std::exception &e) {
		printResult("deque: not found throws", true);
	}

	// --- empty container ---
	std::vector<int> empty;
	try {
		easyfind(empty, 1);
		printResult("vector: empty container throws", false);
	} catch (const std::exception &e) {
		printResult("vector: empty container throws", true);
	}

	return 0;
}
