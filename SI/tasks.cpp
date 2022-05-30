#include <cassert>
#include "tasks.h"

size_t INT_SIZE = 16;

// ones' complement
void PrintBinary(int number)
{
	char* result = (char*)malloc(sizeof(char) * INT_SIZE);
	int num = abs(number);
	for (int i = 0; i < INT_SIZE; ++i)
	{
		int nextInt = num%2;
		char nextChar;
		if ((number < 0 && nextInt) || (number >= 0 && !nextInt))
			nextChar = '0';
		else
			nextChar = '1';
		result[INT_SIZE - 1 - i] = nextChar;
		num /= 2;
	}
	if (num)
	{
		std::cerr << "Number size exceeds " + std::to_string(INT_SIZE) << ".\n";
		assert(false);
	}
	printf("%s\n", result);
	free(result);
}

void RemoveDups(char* str)
{
	size_t strLen = strlen(str);
	char lastValue = str[0];
	int j = 1;
	for (int i = 1; i < strLen; ++i)
	{
		char curValue = str[i];
		if (curValue != lastValue)
		{
			str[j] = curValue;
			++j;
			lastValue = curValue;
		}
	}
	if (j < strLen)
		str[j] = '\0';
};

void List::Serialize(FILE *file) {
	fprintf(file, "{head: {%d: [%d, \"%s\"]}, tail: {",
			nodeID[head], nodeID[head->rand], head->data.c_str());
	auto curNode = tail;
	while (curNode != nullptr)
	{
		auto format = curNode->next == nullptr?
			"%d: [%d, \"%s\"]}}":
			"%d: [%d, \"%s\"], ";
		fprintf(file, format, nodeID[curNode], nodeID[curNode->rand], curNode->data.c_str());
		curNode = curNode->next;
	}
}

void List::Deserialize(FILE *file)
{
	this->Erase();
	char ch, lastCh;
	fscanf(file, "%c", &ch);
	while (ch != '}')
	{
		bool endReached;
		do
		{
			lastCh = ch;
			fscanf(file, "%c", &ch);
			endReached = ch == '}' && lastCh == '}';
		}
		while (ch != '{' && !(ch == ',' && lastCh == ']') && !endReached);
		if (endReached)
			continue;

		int ID, randID;
		fscanf(file, "%d: [%d, \"", &ID, &randID);
		std::string data;
		fscanf(file, "%c", &ch);
		while (ch != '"')
		{
			data += ch;
			fscanf(file, "%c", &ch);
		}
		ListNode* curNode = new ListNode(data, idNode[randID]);
		this->Append(curNode, ID);
	}
}