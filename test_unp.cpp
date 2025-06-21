#include <iostream>
#include <vector>
#include <memory>
#include <iterator>
#include "unp.hpp"
using namespace std;

class ConcreateEnumberable : public IEnumerable<int> 
{
    int *number_list;
    int _count;
    friend class Enumerator;

public:

    ConcreateEnumberable(int numbers[], int count) : number_list(numbers), _count(count)
    {}
    ~ConcreateEnumberable() = default;

    class Enumerator : public IEnumerator<int>
    {
        int *inumbers, icount, index;
    
    public:
        
        Enumerator(int* numbers, int count) : inumbers(numbers), icount(count), index(0) {}

        bool HasMore() {return index < icount;}
        int next(){
            return (index < icount) ? inumbers[index++] : -1;
        }
    };
    IEnumerator <int> *GetEnumerator(){
        return new Enumerator(number_list, _count);
    }
};

class EvenNumberObsevable : public IObservable<int>
{
    int *_numbers;
    int _count;

public:

    EvenNumberObsevable(int numbers[], int count) : _numbers(numbers), _count(count) {}
    bool Subscribe (IObserver<int>& observer){
        for(int i = 0; i < _count; ++i){
            if(_numbers[i] % 2 == 0) observer.OnNext(_numbers[i]);
        }
        observer.OnCompleted();
        return true;
    }
};
class SimpleObserver : public IObserver<int>
{
public:
    void OnNext(int value) {cout << value << '\n';}
    void OnCompleted(){cout << "all ready!" << endl;}
    void OnError(CustomException* ex){}
};

int main(){
    int x[] = {1, 2, 3, 4 ,5};

    EvenNumberObsevable* t = new EvenNumberObsevable(x, 5);

    IObserver<int>* xy = new SimpleObserver();
    
    t->Subscribe(*xy);

    delete t; delete xy;

    return 0;
}