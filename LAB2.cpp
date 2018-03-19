//============================================================================
// Name        : LAB2.cpp
// Description : Lab2 Solution. The shorter version. Code Re Use through Inheritance.
//============================================================================
#include "LAB2.h"
#include <string>

using namespace std;

// CollectionIterator Class Definitions
CollectionIterator::CollectionIterator(const AbstractAggregate *collection) : _collection(collection){
    _current = 0;
}
void CollectionIterator::First() {
	_current = 0;
	while ((_collection->get(_current)->getType() != getType()) &&
          ((_current < _collection->getCount()))) {
		_current++;
	}
}
void CollectionIterator::Next() {
	_current++;
	while ((_current < _collection->getCount()) &&
           (_collection->get(_current)->getType() != getType())) {
		_current++;
	}
}
Item *CollectionIterator::CurrentItem() const {	return (IsDone() ? NULL : _collection->get(_current));}
bool CollectionIterator::IsDone() const { return _current >= _collection->getCount();}

// BookIterator Class Definitions
BookIterator::BookIterator(const AbstractAggregate *collection) : CollectionIterator (collection) {};
int BookIterator::getType() {return 1;}

// CDIterator Class Definitions
CDIterator::CDIterator(const AbstractAggregate *collection) : CollectionIterator (collection) {};
int CDIterator::getType() {return 2;}

ToyIterator::ToyIterator(const AbstractAggregate *collection) : CollectionIterator (collection) {};
int ToyIterator::getType() {return 3;}

// Collection Class Definitions
AbstractIterator* Collection::CreateIterator(int type) {
    if (type == 1 )
        return new BookIterator(this);
    else if (type == 2 )
        return new CDIterator(this);
    else if (type == 3 )
        return new ToyIterator(this);
    else
        return NULL;
}
int Collection::getCount() const { return _items.size(); }
void Collection::add(Item *item) { _items.push_back(item); };
Item * Collection::get(int index) const { return _items[index]; };

void printAggregate(AbstractIterator& i) {
	cout << "Iterating over collection:" << endl;
	for (i.First(); !i.IsDone(); i.Next()) {
		cout << (i.CurrentItem()->getName()) << endl;
	}
	cout << endl;
}
int main()
{
	// Create Aggregate.
	AbstractAggregate *aggregate = new Collection();
	aggregate->add(new Toy("Item 0-Toy"));
	aggregate->add(new Toy("Item 1-Toy"));
	aggregate->add(new Toy("Item 2-Toy"));
	aggregate->add(new Book("Item 3-Book"));
	aggregate->add(new Toy("Item 4-Toy"));
	aggregate->add(new Book("Item 5-Book"));
	aggregate->add(new Book("Item 6-Book"));
	aggregate->add(new CD("Item 7-CD"));
	aggregate->add(new Book("Item 8-Book"));
	aggregate->add(new CD("Item 9-CD"));
	aggregate->add(new CD("Item 10-CD"));
	aggregate->add(new Book("Item 11-Book"));

	//Book - 1
	//CD - 2
	//Toy - 3

	// Create Iterator
	cout << "Finding books......" << '\n';
	AbstractIterator *iterator = aggregate->CreateIterator(1);
	if (iterator) {
        printAggregate(*iterator);
        delete iterator;
	}

	cout << "Finding CDs......" << '\n';
	iterator = aggregate->CreateIterator(2);
	if (iterator) {
        printAggregate(*iterator);
        delete iterator;
	}
	cout << "Finding Toys......" << '\n';
	iterator = aggregate->CreateIterator(3);
	if (iterator) {
        printAggregate(*iterator);
        delete iterator;
	}
}