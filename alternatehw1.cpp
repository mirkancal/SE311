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
          children[i]->traverse();
    }
};

int main()
{

    Leaf *root = new Leaf("expression");
    Leaf *expr_left = new Leaf("expression");
    Leaf *term_left = new Leaf("term");
    Leaf *const_left = new Leaf("5");
    Leaf *term = new Leaf("-");
    Leaf *right_right_term = new Leaf("term");
    Leaf *right_left_const = new Leaf("4");
    Leaf *right_term= new Leaf("/");
    Leaf *right_right_const = new Leaf("2");

      Composite containers;

      containers.add(const_left);
      containers.add(term);
      containers.add(right_left_const);
      containers.add(right_term);
      containers.add(right_right_const);

      containers.traverse();
      cout << endl;

}
