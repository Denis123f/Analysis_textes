#include <iostream>
// #include "unp.hpp"
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
#include <algorithm>
#include <initializer_list>
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
#include <algorithm>
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

#include <variant>
//#include <any>

namespace React_prorg{
    // void obj_witg_lX11(){
    //     Display* display;
    // Window window;
    // XEvent event;
    // char *msg = "Hello, world!";
    // int s;
    // display = XOpenDisplay(NULL);
    // if(display == NULL){
    //     fprintf(stderr, "Cannot open display");
    //     exit(1);
    // }

    // s = DefaultScreen(display);

    // window = XCreateSimpleWindow(display, RootWindow(display, s), 10, 10, 200, 200, 1, BlackPixel(display, s), WhitePixel(display, s));
    
    // XSelectInput(display, window, ExposureMask | KeyPressMask);

    // XMapWindow(display, window);

    // while(true){
    //     XNextEvent(display, &event);

    //     if(event.type == Expose){
    //         XFillRectangle(display, window, DefaultGC(display, s), 20, 20,10,10);
    //         XDrawString(display, window, DefaultGC(display, s), 50, 50,msg, strlen(msg));
    //     }
    //     if(event.type == KeyPress){
    //         break;
    //     }
    // }
    // XCloseDisplay(display);
    
    // }

    class SmartFloat
    {
        double _value;
    public:
        
        SmartFloat(double value) : _value(value) {}
        SmartFloat() : _value(0) {}
        SmartFloat(const SmartFloat& other) : _value(other._value) {}
        SmartFloat& operator=(const SmartFloat& other){
            if(this != &other) _value = other._value;
            return *this;
        }
        SmartFloat& operator=(double value){
            _value = value; return *this;
        }
        ~SmartFloat() = default;

        SmartFloat& operator++(){_value++; return *this;}
        SmartFloat& operator++(int){++_value; return *this;}
        SmartFloat& operator--(){_value--; return *this;}
        SmartFloat& operator--(int){--_value; return *this;}

        SmartFloat& operator+=(double x){ _value += x; return *this;}
        SmartFloat& operator-=(double x){ _value -= x; return *this;}
        SmartFloat& operator*=(double x){ _value *= x; return *this;}
        SmartFloat& operator/=(double x){ _value /= x; return *this;}

        bool operator<(const SmartFloat& other){
            return _value < other._value;
        }
        bool operator>(const SmartFloat& other){
            return _value > other._value;
        }
        bool operator==(const SmartFloat& other){
            return _value == other._value;
        }
        bool operator!=(const SmartFloat& other){
            return _value != other._value;
        }
        bool operator<=(const SmartFloat& other){
            return _value <= other._value;
        }
        bool operator>=(const SmartFloat& other){
            return _value >= other._value;
        }
        operator int(){return _value;}
        operator double(){return _value;}
     };


    //  double accumulate(double a[], int count){
    //     double value = 0;
    //     for(int i = 0; i < count; ++i) value += a[i];
    //     return value;
    //  }

    // double accumulate(SmartFloat a[], int count){
    //     SmartFloat value = 0;
    //     for(int i = 0; i < count; ++i) value += a[i];
    //     return value;
    // }


    template<typename T>
    double accumulate(T a[], int count){
        SmartFloat value = 0;
        for(int i = 0; i < count; ++i) value += a[i];
        return value;
    }


    void vivod_types(){
        vector<string> vt = {"first", "second", "third", "fourth"};
        for(vector<string>::iterator it = vt.begin(); it != vt.end(); it++) cout << *it << " ";

        for(auto it = vt.begin(); it != vt.end(); it++) cout << *it << " ";

        vector<double> vtdbl = {0 , 3.14, 2.718, 10.00};
        auto vt_dbl1 = vtdbl; // vector<double>
        auto size = vtdbl.size(); // size_t
        auto &rvec = vtdbl; // vector<double>&
        cout << size << endl;

        cout << rvec[0];
        string res = "da";
        for(int i = 0; i < 1000; ++i){
            vt.push_back(res);
        }
        
        struct A {double X;};
        const A* a = new A();
        decltype(a->X) z; // double 
        decltype ((a->X)) zz = z; // const double& 
    }


    template<typename T>
    struct Vector_Wrapper{
        vector<T> vctr;
        Vector_Wrapper(initializer_list<T> l) : vctr(l) {}
        void Append(initializer_list<T> l){
            vctr.insert(vctr.end(), l.begin(), l.end());
        }
    };

    void Vec_Wr_start(){
        Vector_Wrapper<int> vcw = {1, 2, 3, 4, 5};
        vcw.Append({6, 7, 8});
        for(auto n : vcw.vctr) cout << n << ' ';
    }

    // Печать простых значений

    void EmitConsole(int value){
        cout << "Interger: " << value << endl;
    }
    void EmitConsole(double value){
        cout << "Double: " << value << endl;
    }
    void EmitConsole(string value){
        cout << "String: " << value << endl;
    }
    template <typename T>
    void EmitValues(T&& args){
        EmitConsole(forward<T>(args));
    }
    template<typename T, typename... Tn>
    void EmitValues(T&& args, Tn&&... values){
        EmitConsole(forward<T>(args));
        EmitValues(forward<Tn>(values)...);
    }

    void Tst_Emit(){
        EmitValues(12, 312.41, "dsa");
    }
}// end NS RP 

using VarRes = variant<int, string>;
// template <template T = VarRes>
// T result(T res) {return res;}



namespace Grokaem_algorithms{ 

    // Бинарный поиск - базовый
int binary_search(vector<int>& mas, int find){
    int start = 0, end = mas.size() - 1;
    int middle;
    int values_try = 0;
    while(start <= end){
        ++values_try;
        middle = start + (end - start) / 2;
        if(mas[middle] == find){
            return values_try;
        }
        if(mas[middle] < find){
            start = middle + 1;
        }else{
            end = middle - 1;
        }
    }
    return -1;
}
// рекурсивный бинарный поиск
int recursive_bin_search(vector<int> mas, int find, int start, int end){

    if(start > end) return -1;

    int middle = start + (end - start) / 2;

    if(mas[middle] == find) return middle;

    if(mas[middle] > find){
        return recursive_bin_search(mas, find, start, middle-1);
    }else{
        return recursive_bin_search(mas, find, middle-1, end);
    } 
}

    template <typename T> // Сортировка выбором
    struct selection_Sort{
    private:
        int Find_Smallest(vector<T>& mass){
            T smallest = mass[0];
            int smallest_index = 0;

            for(int i = 1; i < mass.size(); ++i){
                if(mass[i] < smallest){
                    smallest = mass[i];
                    smallest_index = i;
                }
            }
            return smallest_index;
    }
    public:

        vector<T> selectionSort(vector<T> mass){
            vector<T> result;

            for(int i = 0; 0 != mass.size(); ++i){
                int small_pos = Find_Smallest(mass);
                result.push_back(mass[small_pos]);
                mass.erase(mass.begin() + small_pos);
            }
            return result;
        }
    };

    long long factorial(int a){
        if(a == 1) return 1;
        return a * factorial(a - 1);
    }

    // Алгоритм Евклида для поиска большего НОДа


    int sum_mas_with_pos(vector<int> a, int pos=0){
        if(pos - 1 == a.size()) return a[pos];
        return a[pos] + sum_mas_with_pos(a, pos + 1);
    }
    int High_num_in_mass(vector<int> a){
        
        int ab=a[0];

        for(int i = 1; i < a.size(); ++i){
            if(ab < a[i]) ab=a[i];
        }
        return ab;
    }

    // Доделать реализацию сортировки
    void quick_sort_helper(vector<int>& a){
        
        
    }

    vector<int> quick_sortt(vector<int> a){
        if(a.size() < 2) return a;

        int opora = a[0];
        vector<int> left, right, result;
        
        copy_if(a.begin(), a.end(), back_inserter(left), [&opora](const int& a){return a < opora;});
        copy_if(a.begin(), a.end(), back_inserter(right), [&opora](const int& a){return a > opora;});

        sort(left.begin(), left.end()); sort(right.begin(), right.end());
        
        for(const auto& a : left) result.push_back(a);
        result.push_back(opora);
        for(const auto& a : right) result.push_back(a);
        
        return result;
    }
} // end GA

int main()
{   
   

   return 0;
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