#include "SortedListA.h"
#include <iostream>

using namespace std;

int main()
{
	SortedListA list;

	ItemType item;
	item.setValue(5);
	list.PutItem(item);
	item.setValue(3);
	list.PutItem(item);
	item.setValue(9);
	list.PutItem(item);
	item.setValue(1);
	list.PutItem(item);
	item.setValue(7);
	list.PutItem(item);

	cout << "List length: " << list.GetLength() << endl;
	for (int i = 0; i < list.GetLength(); i++)
	{
		cout << "Item " << i + 1 << ": " << list.GetNextItem().getValue() << endl;
	}

	cout << "Deleting item 3..." << endl;
	item.setValue(3);
	list.DeleteItem(item);
	list.ResetList();
	for (int i = 0; i < list.GetLength(); i++)
	{
		cout << "Item " << i + 1 << ": " << list.GetNextItem().getValue() << endl;
	}

	return 0;
}