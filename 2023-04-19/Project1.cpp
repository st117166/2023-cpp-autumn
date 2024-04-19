#include <iostream>

struct Node
{
	int data;
	Node* next;
	Node(int data, Node* next = nullptr) : data(data), next(next) {}
	Node(const Node& node) : data(node.data), next(nullptr) {}
	~Node() { data = 0; next = nullptr; }
	friend std::ostream& operator<<(std::ostream& stream, Node*& node)
	{
		stream << node->data << " ";
		return stream;
	}
};

class LinkedList
{
public:
	LinkedList() : head(nullptr) {}
	~LinkedList() { dispose(); }
	int Length();
	bool IsEmpty() { return head = nullptr; }
	void PushHead(int data);
	void Insert(int index, int data);
	void PushTail(int data);
	int PopHead();
	int Extract(int index);
	int PopTail();
	int Data(int index);
	void swap(int a, int b);
	void swapWithHead(int index);
	void sort();
	friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list)
	{
		Node* tmp = list.head;
		while (tmp != nullptr)
		{
			stream << tmp << " ";
			tmp = tmp->next;
		}
		return stream;
	}

private:
	void dispose();
	int PopData(Node* node);
	void InsertNode(int index, Node* node);
	Node* ExtractNode(int index);
	bool indexValid(int index);
	Node* head;
};

int main(int argc, char* argv[])
{
	LinkedList list;
	std::cout << list << std::endl;
	list.PushHead(1);
	std::cout << list << std::endl;
	list.PushTail(3);
	std::cout << list << std::endl;
	list.Insert(1, 2);
	std::cout << list << std::endl;
	list.Insert(3, 4);
	std::cout << list << std::endl << std::endl;
	std::cout << list << std::endl;
	std::cout << list.PopHead() << " ";
	std::cout << list.Extract(1) << " ";
	std::cout << list.PopTail() << " ";
	std::cout << list.Extract(0) << std::endl;
	std::cout << list << std::endl << std::endl;

	list.PushHead(3); list.PushHead(4); list.PushHead(1); list.PushHead(2);
	list.PushHead(7); list.PushHead(5); list.PushHead(8); list.PushHead(6);
	std::cout << list << std::endl;
	list.sort();
	std::cout << list << std::endl;

	return 0;
}

void LinkedList::PushHead(int data)
{
	head = new Node(data, head);
}

void LinkedList::Insert(int index, int data)
{
	if (index == 0)
	{
		return PushHead(data);
	}
	if (index == Length())
	{
		return PushTail(data);
	}
	if (indexValid(index))
	{
		Node* tmp = head;
		for (int i = 0; i < index - 1; ++i)
		{
			tmp = tmp->next;
		}
		tmp->next = new Node(data, tmp->next);
	}
}

int LinkedList::PopHead()
{
	if (head == nullptr)
	{
		return -1;
	}
	Node* tmp = head;
	head = head->next;
	int res = tmp ->data;
	
	return res;
}

int LinkedList::Extract(int index)
{
	if (index == 0)
	{
		return PopHead();
	}
	if (index == Length() - 1)
	{
		return PopTail();
	}
	if (!indexValid(index))
	{
		return -1;
	}
	Node* tmp = head;
	for (int i = 0; i < index - 1; ++i) 
	{
		tmp = tmp->next;
	}
	Node* nres = tmp->next; 
	tmp->next = tmp->next->next; 
	int res = nres->data;
	delete nres;      
	return res;
}

int LinkedList::PopTail()
{
	if (IsEmpty())
	{
		return -1;
	}
	if (head->next == nullptr)
	{
		return PopHead();
	}
	Node* tmp = head;
	while (tmp->next->next != nullptr) 
	{
		tmp = tmp->next;
	}
	int res = tmp->next->data; 
	delete tmp->next; 
	tmp->next = nullptr; 
	return res;
}

int LinkedList::Length()
{
	int len = 0;
	Node* tmp = head;
	while (tmp != nullptr)
	{
		tmp = tmp->next;
		++len;
	}
	return len;
}

void LinkedList::swap(int a, int b)
{
	if (a == b)
	{
		return;
	}
	if (a > b)
	{
		return swap(b, a);
	}
	if (a == 0)
	{
		return swapWithHead(b);
	}
}

void LinkedList::dispose()
{
	while (!IsEmpty())
	{
		PopHead();
	}
}

bool LinkedList::indexValid(int index)
{
	return (0 <= index && index < Length());
}

void LinkedList::swapWithHead(int index)
{
	Node* tmpHead = head;
	head = head->next;
	Node* tmp = head;
	for (int i = 0; i < index - 1; ++i)
	{
		tmp = tmp->next;
	}
	tmpHead->next = tmp->next;
	tmp->next = tmpHead;
	if (index != 1)
	{
		tmp = head;
		for (int i = 0; i < index - 2; ++i)
		{
			tmp = tmp->next;
		}
		Node* newHead = tmp->next;
		tmp->next = tmp->next->next;
		newHead->next = head;
		head = newHead;
	}
}

void LinkedList::PushTail(int data)
{
	if (IsEmpty)
	{
		return PushHead(data);
	}
	Node* tmp = head;
	while (tmp->next != nullptr)
	{
		tmp->next;
	}
	tmp->next = new Node(data);
}

int LinkedList::PopData(Node* node)
{
	if (node == nullptr)
	{
		return -1;
	}
	int res = node->data;
	delete node;
	return res;
}
int LinkedList::Data(int index)
{
	if (indexValid(index) || head == nullptr)
	{
		return -1;
	}
	Node* tmp = head;
	while (index > 0)
	{
		tmp = tmp->next;
		--index;
	}
	return tmp->data;
}

void LinkedList::sort()
{
	if (head == nullptr || Length() == 1)
	{
		return;
	}
	for (int i = 0; i < Length(); ++i)
	{
		for (int j = 0; j < Length() - 1 - i; ++j)
		{
			if (Data(j) > Data(j + 1))
			{
				swap(j, j + 1);
			}
		}
	}
}

void LinkedList::InsertNode(int index, Node* node)
{
	if (head == nullptr || !indexValid(index) && index != Length() && index != 0)
	{
		return;
	}
	if (index == 0)
	{
		if (head != nullptr)
		{
			node->next = head;
		}
		head = node;
		return;
	}
	if (index == Length())
	{
		Node* tmp = head;
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		tmp->next = node;
		return;
	}
	Node* tmp = head;
	while (index > 1)
	{
		tmp = tmp->next;
		--index;
	}
	node->next = tmp->next;
	tmp->next = node;
}

Node* LinkedList::ExtractNode(int index)
{
	if (!indexValid(index) || head == nullptr)
	{
		return nullptr;
	}
	Node* tmp = head;
	if (index == 0)
	{
		Node* res = head;
		head = head->next;
		return res;
	}
}
