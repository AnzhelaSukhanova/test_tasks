#include <iostream>

size_t BUFFER_SIZE = 10;

char *resize(const char *str, size_t size, size_t new_size)
{
	char *new_str = new char[new_size];
	size_t cur_size = new_size < size? new_size: size;
	for (int i = 0; i < cur_size; ++i)
		new_str[i] = str[i];
	delete[] str;
	return new_str;
}

char *getline()
{
	char *str = new char[BUFFER_SIZE];
	char c;
	int i = 0;
	for (; std::cin.get(c) && c != '\n'; ++i)
	{
		if (i >= BUFFER_SIZE)
		{
			size_t new_size = BUFFER_SIZE + 10;
			str = resize(str, BUFFER_SIZE, new_size);
			BUFFER_SIZE = new_size;
		}
		str[i] = c;
	}
	str[i] = '\0';
	return str;
}
