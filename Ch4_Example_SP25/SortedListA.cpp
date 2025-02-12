#include "SortedListA.h"

SortedListA::SortedListA()
{
	length = 0;
	currentPos = -1;
}

SortedListA::~SortedListA()
{
	MakeEmpty();
}

void SortedListA::MakeEmpty()
{
	length = 0;
}

bool SortedListA::IsFull() const
{
	if (length == MAX_ITEMS)
		return true;
	else
		return false;
}

bool SortedListA::IsEmpty() const
{
	if (length == 0)
		return true;
	else
		return false;
}

int SortedListA::GetLength() const
{
	return length;
}

ItemType SortedListA::GetItem(ItemType item, bool& found)
{
	if (IsEmpty())
	{
		found = false;
		return item;
	}

	int first = 0;
	int last = length - 1;
	int mid;

	found = false;  // Default: not found

	while (first <= last)
	{
		mid = (first + last) / 2;
		RelationType result = info[mid].ComparedTo(item);

		if (result == EQUAL)
		{
			found = true;
			return info[mid];
		}
		else if (result == GREATER)
		{
			// Since list is sorted, if info[mid] > item, then item must be in the left half.
			last = mid - 1;
		}
		else  // result == LESS
		{
			// If info[mid] < item, then item must be in the right half.
			first = mid + 1;
		}
	}

	// Item was not found
	return item;
}

bool SortedListA::PutItem(ItemType item)
{
	if (IsFull())
	{
		return false;
	}

	// Use binary search to find the insertion index.
	// 'low' will end up as the index where the item should be inserted.
	int low = 0;
	int high = length;  // high is set to 'length' so that the search space is [0, length)

	while (low < high)
	{
		int mid = (low + high) / 2;
		// If info[mid] is less than item, search in the right half.
		if (info[mid].ComparedTo(item) == LESS)
		{
			low = mid + 1;
		}
		else  // info[mid] is greater than or equal to item
		{
			high = mid;
		}
	}

	// 'low' is the correct insertion index.
	// Shift items to the right to create space for the new item.
	for (int i = length; i > low; i--)
	{
		info[i] = info[i - 1];
	}

	// Insert the new item and update the length.
	info[low] = item;
	length++;
	return true;
}


// Needs to be updated.
bool SortedListA::DeleteItem(ItemType item)
{
	if (IsEmpty())
	{
		return false;
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			if (info[i].ComparedTo(item) == EQUAL)
			{
				info[i] = info[length - 1];
				length--;
				return true;
			}
		}
	}

	return false;
}

void SortedListA::ResetList()
{
	currentPos = -1;
}

ItemType SortedListA::GetNextItem()
{
	currentPos++;
	currentPos = currentPos % length;
	return info[currentPos];
}
