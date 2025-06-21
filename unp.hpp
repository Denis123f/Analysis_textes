// Создаем observer and servearble. 
#ifndef UNP_HPP
#define UNP_HPP

struct CustomException : public std::exception{

    const char* what()const throw(){
        return "c++ Exc";
    }
};

template <typename T>
class IEnumerator{

public:
    virtual bool HasMore() = 0;
    virtual T next() = 0;
};

template <typename T>
class IEnumerable{

public:
    virtual IEnumerator<T>*  GetEnumerator() = 0;
};

template<class T> class IObserver
{
public:
    virtual void OnCompleted() = 0;
    virtual void OnError(CustomException *exception) = 0;
    virtual void OnNext(T value) = 0;
};
template<typename T>
class IObservable
{
public:
    virtual bool Subscribe(IObserver<T>& observer) = 0;
};
#endif // _UNP_HPP