#include <cstddef>
#include <cstring>

struct String {
	size_t size;
	char *str;

	String(const char *str = "")
	{
		size = strlen(str);
		this->str = new char[size + 1];
		strcpy(this->str, str);
	}
	String(size_t n, char c)
	{
		size = n;
		this->str = new char[size + 1];
		for (int i = 0; i < size; ++i)
			str[i] = c;
		str[size] = '\0';
	}
	~String()
	{
		delete []str;
	}

	void append(String &other)
	{
		char *result = new char[size + other.size + 1];
		strcpy(result, str);
		strcpy(result + size, other.str);
		size += other.size;
		delete[] str;
		str = result;
	}
};