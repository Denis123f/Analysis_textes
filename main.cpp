#include <iostream>

// #include <unordered_map>
// #include <unordered_set>

// #include <map>
// #include <iomanip>

// #include <type_traits>
// #include <hash_map> устарел и требуется использовать unordered_map
// #include <hash_set> устарел и требуется использовать unordered_set

#include <array> //Статический массив  
#include <vector> // Массив динамический
// #include <set>  Множество, упорядочивает элементы.
#include <deque> //Двустороний список
// #include <stack> // LIFO - Посл вошел Первый вышел

// #include <boost/asio.hpp>
#include <functional>
//#include <forward_list>
//#include <vector>
// #include <algorithm>

// #include <boost/program_options.hpp>

// namespace opt = boost::program_options;
//using namespace std;


/*
Компоновка

пропроцесор
компилятор
линкер

*/
// functional bind & std::placeholders
// #include <boost/variant.hpp>
// #include <string_view>
//#include <type_traits>
// #include <cassert>
// #include <iomanip>
//#include <algorithm>
#include <string>
#include <utility>

using namespace std;
namespace user{

//   void print(){}

//   template <typename T, typename... Types>
//   constexpr bool isTypesVariadic(T, Types...){
//     return (std::is_same_v<T, Types> && ...);
//   }

//   template <typename... Types>
//   void print(Types const&... args){
//     (std::cout << ...  << args);
//   }

//   template <typename... Types>
//   void addOne(Types const&... args){
//     if(isTypesVariadic(args...)) print((args + 1) ...);
//     else{std::cout << "Типы разные";}
//   }

//   template <typename T, typename... Idx>
//   void PrintElems(T const& coll, Idx... idx){
//     print(coll[idx]...);
//   }

//   template<std::size_t... Idx, typename T>
//   void Printelms(T const& coll){
//     print(coll[Idx]...);
//   }

   template <typename Y>
   void foo(){
    Y f{};
   }
   

   template <typename T>
   class Stack
   {
    private:
    std::deque<T> elems;

    public:
    Stack() = default;
    Stack(const T& value) : elems{value}
    {}
    void push(T const&);
    void pop(){
      elems.pop_back();
    }
    T const& top() const{
      return elems.back();
    }
    bool empty() const{
      return elems.empty();
    }
    template<typename Y>
    Stack& operator=(Stack<Y> const&);
   };

   template<typename T>

template<typename T2>
   Stack<T>& Stack<T>::operator= (Stack<T2> const& op2){

    Stack<T2> tmp(op2);
    // Создание копии присваиваемого стека
    elems.clear();
    // Удаление существующих элементов
    while (tmp.empty()) // Копирование всех элементов
    {
      elems.push_front(tmp.top());
      tmp.pop();
    }
return *this;
   }

  template <typename T>
  struct Cpec_str
  {
    private:
    std::string str;
    T other_str{};
    public:
    Cpec_str() = delete;
    Cpec_str(const char& values) : str(values)
      {}
    Cpec_str(const T& value) : other_str(value)
      {}
    
    template <typename Y = std::string>
    Y get() const {
      return str.empty() ? other_str : str;
    }

    
    inline bool get() const {
      return str.empty() ? 1 : 0;
    }
  };
  
  class X{};

  void g(X&){
    cout << "Для переменной"; 
  }
  void g(const X&){
    cout << "Для const переменной"; 
  }
  void g(X&&){
    cout << "Для move"; 
  }

  template <typename T>
  void f(T&& val){
    g(forward<T>(val));
  }

class Person
{
private:
std::string name;
public:
// Обобщенный конструктор для передачи начального имени:

template <typename STR, typename = enable_if_t<is_convertible_v<STR, std::string>>>
explicit Person(STR&& N) : name(std::forward<STR>(N))
    {cout << "Шаблонный конструктор для " << name << '\n';}

// Копирующий и перемещающий конструкторы:
Person(Person const& p) : name(p.name)
{
std::cout << "Копирующий конструктор Person " << name << "\n";
}
Person(Person&& p) : name(std::move(p.name))
{
std::cout << "Перемещающий конструктор Person " << name << "\n";
}
};
/*
template <typename T>
using EnableIfSizeGreater4 = std::enable_if_t<(sizeof(T) > 4)>;
*/
template<typename T, typename = std::enable_if_t<(sizeof(T) > 4)>>
void foo(){
    return T();
}


template <typename T>
void printV(const T& arg){
    
}

template <typename T>

void outR(T& arg){
    static_assert(!std::is_const<T>::value, "f");
    if(is_array<T>::value){
        cout << "mas: " << extent<T>::value << " elements\n";
    }
    if(is_class<T>::value){
        cout << "class: " << is_destructible<T>::value;
    }
}


template <unsigned p, unsigned d>
struct DoIsPrime{
    static constexpr bool value = (p%d != 0) && DoIsPrime<p, d-1>::value;
}; 

template <unsigned p>
struct DoIsPrime<p, 2>{
    static constexpr bool value = (p % 2 != 0);
};
template <unsigned p>
struct IsPrime{
    static constexpr bool value = DoIsPrime<p, p/2>::value;
};

// Частные случаи
template<>
struct IsPrime<0>
{ static constexpr bool value = false;};
template<>
struct IsPrime<1>
{static constexpr bool value = false;};
template<>
struct IsPrime<2>
{static constexpr bool value = true;};
template<>
struct IsPrime<3>
{ static constexpr bool value = true;};

// Или используя constexpr с с++ 11

constexpr bool doIsPrime(unsigned p, unsigned d){
    
    return d != 2 ? (p%d != 0) && doIsPrime(p, d-1): (p%2 != 0);
}

// constexpr bool isPrime(unsigned p){
//     return p < 4 ? !(p<2): doIsPrime(p, p/2);
// }

// Или используя улучшенный constexpr с с++ 14

constexpr bool isPrime(unsigned int p){
    for(unsigned d = 2; d <= p / 2; ++d){
        if(p % d == 0){
            return false;
        }
    }
    return p > 1;
}

// Можно уйти в специализацию

template <int SZ, bool = isPrime(SZ)>
struct helper;

// Реализация для составного числа
template <int SZ>
struct helper<SZ, false>;

// Реализация для простого числа
template <int SZ>
struct helper<SZ, true>;

template <typename T, size_t SZ>
long foo(array<T, SZ> const& coli){
    helper<SZ> h;
}

// SFINAE

template<typename T, unsigned N>
size_t len(T(&)[N]){
    return N;
}
template <typename T>
typename T::size_type len(T const& t){
    return t.size();
}

std::size_t len(...){
    return 0;
}

template<typename T>
auto len(T const& t) -> decltype((void) (t.size ()), T::size_type()){
    return t.size();
}

// Переделаем начальную функцию print с использованием if constexpr
template<typename T, typename... Types>
void print(T const& FirstArg, Types const&... args){
    cout << FirstArg << '\t';
    if constexpr(sizeof...(args)){
        print(args...);
    }else{
    cout << endl;
    }
} 

template<typename T>
void foo(T t){
    if constexpr(is_integral_v<T>){
        if(t > 0){
            foo(t - 1);
        }
    }
    else{
        static_assert(!is_integral_v<T>, "No int");
    }
}

template <typename Iter, typename Callable, typename... Args >
void foreach(Iter current, Iter end, Callable op, Args const&... args){
    
    while(current != end){
        invoke(op, args..., *current);
        ++current;
    }

}
    // 220 СТР.
}// end NS user

//#include <variant>
//#include <any>
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
namespace React_prorg{
    void obj_witg_lX11(){
        Display* display;
    Window window;
    XEvent event;
    char *msg = "Hello, world!";
    int s;
    display = XOpenDisplay(NULL);
    if(display == NULL){
        fprintf(stderr, "Cannot open display");
        exit(1);
    }

    s = DefaultScreen(display);

    window = XCreateSimpleWindow(display, RootWindow(display, s), 10, 10, 200, 200, 1, BlackPixel(display, s), WhitePixel(display, s));
    
    XSelectInput(display, window, ExposureMask | KeyPressMask);

    XMapWindow(display, window);

    while(true){
        XNextEvent(display, &event);

        if(event.type == Expose){
            XFillRectangle(display, window, DefaultGC(display, s), 20, 20,10,10);
            XDrawString(display, window, DefaultGC(display, s), 50, 50,msg, strlen(msg));
        }
        if(event.type == KeyPress){
            break;
        }
    }
    XCloseDisplay(display);
    
    }
}// end NS RP 



int main()
{   
   
}   


// #include <boost/asio.hpp>
// #include <functional>
// #include <thread>
// #include <mutex>
// #include <atomic>
// #include <condition_variable>

//#include <set>
//#include <unordered_set>
//#include <unordered_map>
//#include <functional>

//#include <string_view>