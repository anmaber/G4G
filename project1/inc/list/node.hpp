#pragma once

template<typename Type>
class Node
{
public:
    Node(const Type& v);
    Node* next;
    Node* previous;
    Type value;
};

template<typename Type>
Node<Type>::Node(const Type& v)
     :next(nullptr),
      previous(nullptr),
      value(v)
{}
