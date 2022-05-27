#include <iostream>
#include <cstring>
#include <map>
#include <utility>

void PrintBinary(int number);
void RemoveDups(char* str);

struct ListNode {
	ListNode *prev = nullptr;
	ListNode *next = nullptr;
	ListNode *rand = nullptr;
	std::string data;

	ListNode() = default;

	explicit ListNode(std::string data, ListNode *randNode = nullptr)
	{
		this->rand = randNode;
		this->data = std::move(data);
	};
};

class List {
public:
	List() = default;

	void Append(ListNode *node, int ID = 0)
	{
		++count;
		int curID = ID > 0? ID: count;
		nodeID[node] = curID;
		idNode[curID] = node;
		if (head == nullptr)
		{
			head = node;
			count = 1;
		}
		else if (tail == nullptr)
		{
			head->next = node;
			node->prev = head;
			tail = node;
		}
		else
		{
			ListNode *curNode = tail;
			while (curNode->next != nullptr)
				curNode = curNode->next;
			node->prev = curNode;
			curNode->next = node;
		}
	};
	void Free()
	{
		head = nullptr;
		tail = nullptr;
		count = 0;
		nodeID = {{nullptr, 0}};
		idNode = {{0, nullptr}};
	}

	void Serialize(FILE *file);
	void Deserialize(FILE *file);
private:
	ListNode *head = nullptr;
	ListNode *tail = nullptr;
	int count = 0;
	std::map<ListNode*, int> nodeID = {{nullptr, 0}};
	std::map<int, ListNode*> idNode = {{0, nullptr}};
};
