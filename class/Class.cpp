#include <iostream> //dzięki tej linijce możemy używać klasy zewnętrznej o nazwie "iostream"
#include <sstream> //od teraz możemy używać klasy zewnętrznej o nazwie sstream - przydała się podczas konkatenacji łańcuchów znaków
using namespace std; //dzięki tej linijce nie musimy pisać słowa "std" przed każdą metodą standardową

class Student { //tworzymy nową klasę o nazwie "Student"
	//definiujemy pola, czyli stany obiektu klasy Student, poniżej:
    private: //słowo kluczowe "private" zapewnia, że poniższe pola są prywatne, czyli nie będziemy mieli do tych pól bezpośredniego dostępu spoza klasy
        int age, standard; //dwa pola typu integer - liczba całkowita: wiek i standard
        string first_name, last_name; //dwa pola typu string - łańcuch znaków: imię i nazwisko
	//do powyższych, prywatnych pól, umożliwiamy dostęp za pośrednictwem publicznych metod: akcesorów i modyfikatorów 
	//do każdego pola tworzymy dwie metody: akcesor i modyfikator (zaczynające się na get_ i set_)
	//akcesor będzie umożliwiał zwracanie wartości przechowywanej w danym polu
	//modyfikator będzie umożliwiał modyfikację wartości przechowywanej w danym polu
	//poniżej wypisujemy typy, nazwy i argumenty tych metod:
    public: //słowo kluczowe "public" mówi o tym, że do tych metod będziemy mieli nieograniczony dostęp
        int get_age(); //akcesor, który zwraca dane typu integer - liczba całkowita
        void set_age(int age); //modyfikator; "void" oznacza, że ta metoda nie będzie nic zwracała; przyjmuje w parametrze liczbę całkowitą
        int get_standard(); //akcesor, który zwraca dane typu integer - liczba całkowita
        void set_standard(int standard); //modyfikator, przyjmujący, jako parametr, liczbę całkowitą
        string get_first_name(); //akcesor, zwraca łańcuch znaków
        void set_first_name(string first_name); //modyfikator, który przyjmuje w parametrze łańcuch znaków
        string get_last_name(); //akcesor - zwraca łańcuch znaków
        void set_last_name(string last_name); //modyfikator - przyjmuje w parametrze łańcuch znaków
        string to_string(); //metoda to_string zwracająca łańcuch znaków
};

//poniżej implementujemy metody publiczne klasy Student:
//wzór każdego nagłówka metod to: zwracany_typ nazwa_klasy_do_której_należy::nazwa_metody(typ_parametru parametr)
int Student::get_age() { //w tym przypadku metoda zwraca liczbę całkowitą, należy do klasy Student, jest akcesorem i nie ma żadnych parametrów
    return age; //zwraca daną, która zapisana jest w polu o nazwie "age" klasy Student
}

void Student::set_age(int age) { //ta metoda nie zwraca żadnej wartości, dlatego oznaczona jest słowem "void"; posiada parametr, w którym spodziewamy się liczby całkowitej
    this->age = age; //modyfikujemy wartość pola "age" klasy Student; słowo kluczowe "this" wskazuje na pole klasy student, a nie na parametr, który nazywa się tak samo jak pole
} //przypisujemy nową wartość operatorem "=", która jest podana w parametrze; parametr nazywa się tak samo, więc koniecznie musimy użyć słowa "this", aby odróżnić te dwie zmienne

int Student::get_standard() { //ta metoda działa identycznie jak "get_age", natomiast odnosi się do pola "standard"
    return standard;
}

void Student::set_standard(int standard) { //ta metoda działa tak samo jak "set_age", natomiast odnosi się do pola "standard"
    this->standard = standard;
}

string Student::get_first_name() { //ta metoda działa identycznie jak "get_age", natomiast odnosi się do pola "first_name"
    return first_name;
}

void Student::set_first_name(string first_name) { //ta metoda działa tak samo jak "set_age", natomiast odnosi się do pola "first_name"
    this->first_name = first_name;
}

string Student::get_last_name() { //ta metoda działa identycznie jak "get_age", natomiast odnosi się do pola "last_name"
    return last_name;
}

void Student::set_last_name(string last_name) { //ta metoda działa tak samo jak "set_age", natomiast odnosi się do pola "last_name"
    this->last_name = last_name;
}

string Student::to_string() { //implementacja metody "to_string", która zwraca łańcuch znaków; w rezultacie otrzymamy wypisane po przecinku wartości wszystkich pól klasy Student
    stringstream result; //do tworzenia łańcucha znaków używam obiekt typu "stringstream", który zapewnia rzutowanie typów innych niż "string" na łańcuch znaków
    result << age << ','; //konkatenacja wartości pola "age" i przecinka - w rezultacie otrzymamy np. "25,"
    result << first_name << ','; //do powyższego rezultatu "doklejamy" kolejne wartości i przecinki
    result << last_name << ',';
    result << standard; //tutaj przecinka już nie dokładamy, ponieważ to ostatnia wartość, po której, zgodnie z wymaganiami w zadaniu, przecinka ma nie być
    return result.str(); //używamy metody "str()", która zwraca wszystkie wartości, jakie podaliśmy obiektowi "stringstream", czyli wartości pól klasy Student oddzielone przecinkami
}

int main() { //główna klasa, która wykonuje się pierwsza po starcie programu (nie pisałem jej osobiście, została podana automatycznie w zadaniu przez hackerrank, jako część rozwiązania)
    int age, standard; //tworzymy dwie zmienne: age oraz standard - obie typu liczby całkowitej
    string first_name, last_name; //tworzymy dwie zmienne: first_name oraz last_name - obie typu string, czyli łańcucha znaków
    
    cin >> age >> first_name >> last_name >> standard;  //przypisujemy zmiennym dane wprowadzone przez użytkownika
    
    Student st; //tworzymy obiekt klasy Student - będziemy odnosili się do niego za pomocą  zmiennej "st"
    st.set_age(age); //na obiekcie mamy dostęp do zdefiniowanych i zaimplementowanych wyżej metod klasy Student - dzięki słowie "public" w klasie Student
    st.set_standard(standard); //już w tym momencie nie mamy dostępu bezpośredniego do pól, musimy koniecznie używać modyfikatorów
    st.set_first_name(first_name); //używamy modyfikatorów do przypisywania wartości do pól
    st.set_last_name(last_name); //czyli takie dane, jakie wprowadził użytkownik, będą przechowywane w polach klasy Student dla tego obiektu "st"
    
    cout << st.get_age() << "\n"; //ta linijka powoduje drukowanie w konsoli rezultatu wykonania metody "get_age()" na obiekcie "st", czyli wartości przechowywanej w polu "age"
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n"; //drukowanie wartości pól "last_name" oraz "first_name" klasy Student dla obiektu "st" - oddzielone przecinkiem i spacją
    cout << st.get_standard() << "\n"; //drukowanie wartości pola "standard" klasy Student dla obiektu "st"
    cout << "\n"; //"\n" oznacza przejście do kolejnej linii w konsoli, alternatywnym wyjściem jest "endl"
    cout << st.to_string(); //wydrukowanie na konsoli rezultatu metody "to_string" klasy Student dla obiektu "st", czyli wydrukowanie wartości wszystkich pól
    
    return 0; //jako że metoda "main()" zwraca liczbę całkowitą, musimy zapewnić return; domyslnie zwracamy 0;
}

