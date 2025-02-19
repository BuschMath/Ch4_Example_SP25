#ifndef SORTEDLISTA_H
#define SORTEDLISTA_H

#include "ItemType.h"

class SortedListA
{
public:
	SortedListA(int size);
	~SortedListA();
	void MakeEmpty();
	bool IsFull() const;
	bool IsEmpty() const;
	int GetLength() const;
	ItemType GetItem(ItemType item, bool& found);
	bool PutItem(ItemType item);
	bool DeleteItem(ItemType item);
	void ResetList();
	ItemType GetNextItem();

private:
	int length;
	ItemType* info;
	int currentPos;
	int maxSize;
};

#endif // !SORTEDLISTA_H


