#include <iostream>
#include <vector>
using namespace std;


class Component
{
  public:
    virtual void traverse() = 0;
};

class Leaf: public Component
{

    string value;
  public:
    Leaf(string val)
    {
        value = val;
    }
    void traverse()
    {
        cout << value << ' ';
    }
};

class Composite: public Component
{

    vector < Component * > children;
  public:

    void add(Component *ele)
    {
        children.push_back(ele);
    }
    void traverse()
    {
        for (int i = 0; i < children.size(); i++)
        // 5. Use polymorphism to delegate to children
          children[i]->traverse();
    }
};

int main()
{
  Composite containers;


      containers.add(new Leaf("5"));
      containers.add(new Leaf("-"));
      containers.add(new Leaf("4"));
      containers.add(new Leaf("/"));
      containers.add(new Leaf("2"));




    containers.traverse();
    cout << endl;

}
