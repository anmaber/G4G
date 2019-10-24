#include "list.hpp"
#include <list>
#include <memory>
#include <algorithm>
#include <iterator>


int main()
{
    /********  MY DoublyLinkedList **********/
    try{
        DoublyLinkedList<int> DoublyLinkedList;

        std::cout<<"CHECKS IF INSERT METHODS, CONST ITERATOR WORKS \n \n";
        DoublyLinkedList.push_back(4);
        DoublyLinkedList.push_back(3);
        DoublyLinkedList.push_front(1);
        DoublyLinkedList.push_front(2);
        DoublyLinkedList.insert(9,2);
        std::cout<<"output should be: 2 1 9 4 3 \n";
        std::cout<<"real output: ";

        for(auto it = DoublyLinkedList.cbegin(); it!=DoublyLinkedList.cend(); ++it)
            std::cout<<*it<<"  ";


        std::cout<<"\n\nCHECKS IF [] OPERATOR WORKS \n";
        std::cout<<"DoublyLinkedList[3] = 0;"<<std::endl;
        DoublyLinkedList[3] = 0;
        for(auto it = DoublyLinkedList.cbegin(); it!=DoublyLinkedList.cend(); ++it)
            std::cout<<*it<<"  ";

        std::cout<<"\nDoublyLinkedList[1] = "<<DoublyLinkedList[1]<<std::endl;

        std::cout<<"\n\nCHECKS IF REMOVE METHOD WORKS \n";
        DoublyLinkedList.remove(2);
        for(auto it = DoublyLinkedList.cbegin(); it!=DoublyLinkedList.cend(); ++it)
            std::cout<<*it<<"  ";


        std::cout<<"\n\nCHECKS IF ITERATOR WORKS (TO EACH ELEMENT OF COLLECTION SHOULD BE ADDED 2) \n";
        for(auto it =DoublyLinkedList.begin() ; it != DoublyLinkedList.end(); ++it)
            *it+=2;


        for(auto it = DoublyLinkedList.cbegin(); it!=DoublyLinkedList.cend(); ++it)
            std::cout<<*it<<"  ";

        std::cout << "" << '\n';
        std::cout << "My list: ***************** " << list.print() << '\n';

    }
    catch(std::out_of_range const& ex)
    {
        std::cerr<<"out_of_range: "<<ex.what()<<std::endl;
    }

    /****** STL *****/

    std::list<int> DoublyLinkedList;
    DoublyLinkedList.push_back(4);
    DoublyLinkedList.push_back(3);
    DoublyLinkedList.push_front(1);
    DoublyLinkedList.push_front(2);
    auto it = DoublyLinkedList.begin();
    std::advance(it,2);
    DoublyLinkedList.insert(it,9);

    std::cout<<"\n\nCHECKS HOW INSERT METHODS IN STL WORK \n \n";
    std::cout<<"output should be: 2 1 9 4 3 \n";
    std::cout<<"real output: ";

    std::copy(DoublyLinkedList.begin(), DoublyLinkedList.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout<<"\n\nCHECKS HOW ITERATOR WORKS (TO EACH ELEMENT OF COLLECTION SHOULD BE ADDED 2) \n";

    for(auto it =DoublyLinkedList.begin() ; it != DoublyLinkedList.end(); ++it)
        *it+=2;

    std::copy(DoublyLinkedList.begin(), DoublyLinkedList.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout<<"\n\nCHECKS HOE REMOVE METHOD WORKS \n";
    DoublyLinkedList.remove(4);
    std::copy(DoublyLinkedList.begin(), DoublyLinkedList.end(), std::ostream_iterator<int>(std::cout, " "));


    return 0;
}
