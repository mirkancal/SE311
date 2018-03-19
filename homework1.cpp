#include <iostream>

class ExpressionTree{};
class ComponentNode : public ExpressionTree {};
class LeafNode : public ComponentNode {};
class CompositeBinaryNode : public ComponentNode{};
class CompositeAddNode : public CompositeBinaryNode{};
class CompositeSubstractNode : public CompositeBinaryNode{};
class CompositeMultiplyNode : public CompositeBinaryNode{};
class CompositeDivideNode : public CompositeBinaryNode{};

int main() {
    std::cout << "Fuck HW1" << std::endl;
    return 0;
}
