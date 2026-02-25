#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n)
{
}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
	(void)n;
}

int Span::shortestSpan() const
{
	return 0;
}

int Span::longestSpan() const
{
	return 0;
}
