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

template<typename keyType>
int hash(const keyType& key)
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

template<typename keyType, typename valType>
class Map{

    std::vector<valType> vector;
public:
    Map();
    void insert(const keyType& key, const valType& value);
    void remove(const keyType& key);
    valType& operator [] (const keyType& key);

};



template<typename keyType, typename valType>
Map<keyType,valType>::Map()
{
    if (!(std::is_same<keyType,std::string>::value
          || std::is_same<keyType,int>::value))
    {
        throw std::invalid_argument("you've chosen wrong type of key");
    }
    vector.resize(100);
}


template<typename keyType, typename valType>
void Map<keyType,valType>::insert(const keyType& key, const valType& value)
{
    vector[hash<keyType>(key)] = value;
}

template<typename keyType, typename valType>
void Map<keyType,valType>::remove(const keyType &key)
{
    auto iter = vector.begin();
    std::advance(iter,hash<keyType>(key));
    vector.erase(iter);
}

template<typename keyType, typename valType>
valType& Map<keyType,valType>::operator [](const keyType& key)
{
   return vector[hash<keyType>(key)];
}
