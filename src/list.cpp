#include "list.hpp"
#include <list>
#include <memory>
#include <algorithm>
#include <iterator>


int main()
{
    /********  MY List **********/
    try{
        List<int> List;

        std::cout<<"CHECKS IF INSERT METHODS, CONST ITERATOR WORKS \n \n";
        std::cout << "asdasd";
        List.push_back(4);
        List.push_back(3);
        List.push_front(1);
        List.push_front(2);
        List.insert(9,2);
        std::cout<<"output should be: 2 1 9 4 3 \n";
        std::cout<<"real output: ";

        for(auto it = List.cbegin(); it!=List.cend(); ++it)
            std::cout<<*it<<"  ";


        std::cout<<"\n\nCHECKS IF [] OPERATOR WORKS \n";
        std::cout<<"List[3] = 0;"<<std::endl;
        List[3] = 0;
        for(auto it = List.cbegin(); it!=List.cend(); ++it)
            std::cout<<*it<<"  ";

        std::cout<<"\nList[1] = "<<List[1]<<std::endl;

        std::cout<<"\n\nCHECKS IF REMOVE METHOD WORKS \n";
        List.remove(2);
        for(auto it = List.cbegin(); it!=List.cend(); ++it)
            std::cout<<*it<<"  ";


        std::cout<<"\n\nCHECKS IF ITERATOR WORKS (TO EACH ELEMENT OF COLLECTION SHOULD BE ADDED 2) \n";
        for(auto it =List.begin() ; it != List.end(); ++it)
            *it+=2;


        for(auto it = List.cbegin(); it!=List.cend(); ++it)
            std::cout<<*it<<"  ";

        std::cout << "" << '\n';
        std::cout << "My list: ***************** " << list.print() << '\n';

    }
    catch(std::out_of_range const& ex)
    {
        std::cerr<<"out_of_range: "<<ex.what()<<std::endl;
    }

    /****** STL *****/

    std::list<int> List;
    List.push_back(4);
    List.push_back(3);
    List.push_front(1);
    List.push_front(2);
    auto it = List.begin();
    std::advance(it,2);
    List.insert(it,9);

    std::cout<<"\n\nCHECKS HOW INSERT METHODS IN STL WORK \n \n";
    std::cout<<"output should be: 2 1 9 4 3 \n";
    std::cout<<"real output: ";

    std::copy(List.begin(), List.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout<<"\n\nCHECKS HOW ITERATOR WORKS (TO EACH ELEMENT OF COLLECTION SHOULD BE ADDED 2) \n";

    for(auto it =List.begin() ; it != List.end(); ++it)
        *it+=2;

    std::copy(List.begin(), List.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout<<"\n\nCHECKS HOE REMOVE METHOD WORKS \n";
    List.remove(4);
    std::copy(List.begin(), List.end(), std::ostream_iterator<int>(std::cout, " "));


    return 0;
}
