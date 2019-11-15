#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <stdexcept>
#include <type_traits>
#include <vector>

namespace
{
    const int hashingNumber = 100;
}

template<typename KeyType>
int hash(const KeyType& key)
{
    return key % hashingNumber;
}

template <>
int hash(const std::string& key)
{
    int hash = 0;
    for(const auto& letter: key)
    {
        hash+=letter;
    }
    return hash % hashingNumber;
}

template<typename KeyType, typename ValType>
class Map{

    std::vector<ValType> vector;
public:
    Map();
    void insert(const KeyType& key, const ValType& value);
    void remove(const KeyType& key);
    ValType& operator [] (const KeyType& key);

};

template<typename KeyType, typename ValType>
Map<KeyType,ValType>::Map()
{
    if (!(std::is_same<KeyType,std::string>::value
          || std::is_same<KeyType,int>::value))
    {
        throw std::invalid_argument("you've chosen wrong type of key");
    }
    vector.resize(100);
}


template<typename KeyType, typename ValType>
void Map<KeyType,ValType>::insert(const KeyType& key, const ValType& value)
{
    vector.at(hash<KeyType>(key)) = value;
}

template<typename KeyType, typename ValType>
void Map<KeyType,ValType>::remove(const KeyType &key)
{
    auto iter = vector.begin();
    std::advance(iter,hash<KeyType>(key));
    vector.erase(iter);
}

template<typename KeyType, typename ValType>
ValType& Map<KeyType,ValType>::operator [](const KeyType& key)
{
   return vector.at(hash<KeyType>(key));
}
