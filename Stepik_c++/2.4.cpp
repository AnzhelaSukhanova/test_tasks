unsigned strlen(const char *str)
{
	char c = *str;
	int len = 0;
	while (c != '\0')
	{
		++len;
		++str;
		c = *str;
	}
	return len;
}

void strcat(char *to, const char *from)
{
	unsigned to_len = strlen(to);
	unsigned from_len = strlen(from);
	unsigned size = to_len + from_len + 1;
	for (int i = to_len; i < size; ++i)
		to[i] = from[i - to_len];
}

int strstr(const char *text, const char *pattern)
{
	unsigned text_len = strlen(text);
	unsigned pattern_len = strlen(pattern);
	if (!pattern_len)
		return 0;
	if (pattern_len > text_len)
		return -1;
	int j = 0, ind = 0;
	for (int i = 0; i < text_len; ++i)
	{
		if (text[i] == pattern[j] && j != 0)
		{
			if (j == pattern_len - 1)
				return ind;
			++j;
		}
		else if (text[i] == pattern[0])
		{
			ind = i;
			if (pattern_len == 1)
				return ind;
			j = 1;
		}
		else
			j = 0;
		if (pattern_len - j > text_len - i)
			return -1;
	}
	return -1;
}
