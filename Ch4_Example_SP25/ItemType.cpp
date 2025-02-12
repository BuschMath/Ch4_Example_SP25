#include "ItemType.h"

ItemType::ItemType()
{
	value = 0;
}

ItemType::~ItemType()
{
}

RelationType ItemType::ComparedTo(const ItemType& otherItem) const
{
	if (value < otherItem.value)
		return LESS;
	else if (value > otherItem.value)
		return GREATER;
	else
		return EQUAL;
}