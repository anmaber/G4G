#pragma once

template<typename Type>
class Node
{
public:
    Node(const Type& v);
    Node* previous;
    Node* next;
    Type value;
};

template<typename Type>
Node<Type>::Node(const Type& v)
     :previous(nullptr),
      next(nullptr),
      value(v)
{}
