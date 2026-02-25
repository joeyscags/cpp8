#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

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

	template <typename Iterator>
	void			addNumbers(Iterator begin, Iterator end)
	{
		while (begin != end)
		{
			if (_numbers.size() >= _maxSize)
				throw std::overflow_error("Span is full, cannot add more numbers");
			_numbers.push_back(*begin);
			++begin;
		}
	}

private:
	unsigned int		_maxSize;
	std::vector<int>	_numbers;
};

#endif
