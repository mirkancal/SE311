#ifndef ITERATOR_H_
#define ITERATOR_H_

#include <iostream>
#include <vector>
using namespace std;

// Our concrete collection consists of Items.
class Item {
public:
	Item(string name, int type) : _name(name), _type(type) {};
	string getName() { return _name; };
	int getType() { return _type; }
protected:
	string _name;
	int _type;
};

class Book : public Item {
public:
	Book(string name):Item(name,1) {}
};

class CD : public Item {
public:
	CD(string name) :Item(name,2) {}
};

class Toy : public Item {
public:
	Toy(string name) :Item(name,3) {}
};

// This is the abstract "Iterator".
class AbstractIterator {
public:
    virtual ~AbstractIterator() {};
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() const = 0;
	virtual Item* CurrentItem() const = 0;
protected:
	AbstractIterator() {};
};

// This is the abstract "Aggregate".
class AbstractAggregate {
public:
	virtual ~AbstractAggregate() {};
	virtual AbstractIterator* CreateIterator(int type) = 0;
	virtual void add(Item *) = 0; 		// Not needed for iteration.
	virtual int getCount() const = 0; // Needed for iteration.
	virtual Item * get(int) const = 0; // Needed for iteration.
protected:
	AbstractAggregate() {};
};

// This is the abstract generic Collection Iterator
class CollectionIterator : public AbstractIterator {
public:
	CollectionIterator(const AbstractAggregate *collection);
	void First();
	void Next();
	Item* CurrentItem() const;
	bool IsDone()const;
	virtual int getType() = 0;
private:
	const AbstractAggregate *_collection;
	int _current;
	int _type;
};

// This is the Concrete Iterator
class CDIterator : public CollectionIterator {
public:
    CDIterator(const AbstractAggregate *collection);
    int getType();
};

class ToyIterator : public CollectionIterator {
public:
    ToyIterator(const AbstractAggregate *collection);
    int getType();
};

class BookIterator : public CollectionIterator {
public:
    BookIterator(const AbstractAggregate *collection);
    int getType();
};

// This is the concrete Aggregate. Collection
class Collection : public AbstractAggregate {
private:
	vector<Item*> _items;
public:
	AbstractIterator* CreateIterator(int type);
	int getCount() const;
	void add(Item *item);
	Item * get(int index) const;
};

#endif /* ITERATOR_H_ */