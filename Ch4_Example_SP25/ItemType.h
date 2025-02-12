#ifndef ITEMTYPE_H
#define ITEMTYPE_H

enum RelationType { LESS, GREATER, EQUAL };

const int MAX_ITEMS = 100;

class ItemType
{
public:
	ItemType();
	~ItemType();

	RelationType ComparedTo(const ItemType& otherItem) const;

	void setValue(int value_) { value = value_; };
	int getValue() const { return value; };

private:
	int value;
};

#endif // !ITEMTYPE_H


