#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
public:
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void			addNumber(int n);
	int				shortestSpan() const;
	int				longestSpan() const;

private:
	unsigned int		_maxSize;
	std::vector<int>	_numbers;
};

#endif
