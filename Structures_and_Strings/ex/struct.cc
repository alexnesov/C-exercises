#include <iostream>
using namespace std;

struct Person {
    string name;
    double height;
    int age;
    char gender;
};


Person birth() {
    Person p;

    cout << "Adding a new person" << endl;
    cout << " Enter the name : ";
    cin >> p.name;
    cout << " Enter the height (m) : ";
    cin >> p.height;
    cout << " Enter the age : ";
    cin >> p.age;
    do {
        cout << " Male [M] or Female [F] : ";
        cin >> p.gender;
    }while((p.gender != 'F') and (p.gender != 'M'));

    return p;
}

void anniversary(Person&p ){
    ++(p.age);
}

void display(Person const& p){
    cout << p.name << ", ";
    switch (p.gender){
        case 'M': cout << "male"; break;
        case 'F': cout << "female"; break;
        default : cout << "na"   ; break;
    }
    cout << ", "
         << p.height << "m, "
         << p.age;
}

int main()
{
    Person untel( birth() );

    anniversary(untel);
    // one additional year

    display(untel);
    cout << endl;

    return 0;
}