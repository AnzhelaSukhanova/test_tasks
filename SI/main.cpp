#include <filesystem>
#include "tasks.h"

void TestPrintBinary()
{
	for (int i = -100; i <= 100; i+=40)
	{
		std::cout << i << " -- ";
		PrintBinary(i);
	}
};

void TestRemoveDups()
{
	for (int i = 1; i < 5; ++i)
	{
		std::string str =
			std::string(i, 'A') + ' ' + std::string(i, 'B') + ' ' + std::string(i, 'C');
		char *data = &str[0];
		RemoveDups(data);
		printf("%s\n", data);
	}
};

void TestSerialize(std::string path)
{
	ListNode* node1 = new ListNode("Hey, ");
	ListNode* node2 = new ListNode("you, ", node2);
	ListNode* node3 = new ListNode("you're ");
	ListNode* node4 = new ListNode("finally ", node3);
	ListNode* node5 = new ListNode("awake.", node1);

	List* list = new List();
	list->Append(node1);
	list->Append(node2);
	list->Append(node3);
	list->Append(node4);
	list->Append(node5);

	path += "/logfile.json";
	FILE* file = fopen(path.c_str(), "wb");
	list->Serialize(file);
	fclose(file);

	file = fopen(path.c_str(), "rb");
	List* newList = new List();
	newList->Deserialize(file);
	fclose(file);

	list->Serialize(stdout);
	std::cout << "\n";
	newList->Serialize(stdout);
	std::cout << "\n";
};


int main()
{
	TestPrintBinary();
	std::cout << "\n";
	TestRemoveDups();
	std::cout << "\n";
	std::filesystem::path curPath = std::filesystem::current_path();
	TestSerialize(curPath.string());
	return 0;
}
