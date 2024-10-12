#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Address {
private:
    string _street;
    string _city;
    string _country;

public:
    Address(string street = "", string city = "", string country = "")
        : _street(street), _city(city), _country(country) {}

    void Input() {
        cout << "Введiть вулицю: ";
        getline(cin, _street);
        cout << "Введiть мiсто: ";
        getline(cin, _city);
        cout << "Введiть країну: ";
        getline(cin, _country);
    }

    void Output() const {
        cout << "\nАдреса: " << _street << ", " << _city << ", " << _country << endl;
    }
};

class Skill {
private:
    string _skillName;
    int _level;

public:
    Skill(string skillName = "", int level = 0)
        : _skillName(skillName), _level(level) {}

    void Input() {
        cout << "Введiть навичку: ";
        getline(cin, _skillName);
        cout << "Введiть рівень навички (від 1 до 10): ";
        cin >> _level;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void Output() const {
        cout << "\nНавичка: " << _skillName << ", рiвень: " << _level;
    }
};

class Item {
private:
    string _name;
    double _weight;
    string _type;
    string _description;
    double _value;
    string _material;

public:
    Item(string name = "", double weight = 0, string type = "", string description = "", string material = "", double value = 0)
        : _name(name), _weight(weight), _type(type), _description(description), _material(material), _value(value) {}

    void Input() {
        cout << "Введiть назву речi: ";
        getline(cin, _name);
        cout << "Введiть опис речi: ";
        getline(cin, _description);
        cout << "Введiть вагу речi: ";
        cin >> _weight;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Введiть тип речi: ";
        getline(cin, _type);
        cout << "Введiть матерiал речi: ";
        getline(cin, _material);
        cout << "Введiть цiну речi: ";
        cin >> _value;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void Input1(string name, string description, double weight, string type, string material, double value) {
        if (name == "0") {
            cout << "Введiть назву речi: ";
            getline(cin, _name);
        }
        else _name = name;

        if (description == "0") {
            cout << "Введiть опис речi: ";
            getline(cin, _description);
        }
        else _description = description;

        if (weight == 0) {
            cout << "Введiть вагу речi: ";
            cin >> _weight;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else _weight = weight;

        if (type == "0") {
            cout << "Введiть тип речi: ";
            getline(cin, _type);
        }
        else _type = type;

        if (material == "0") {
            cout << "Введiть матерiал речi: ";
            getline(cin, _material);
        }
        else _material = material;

        if (value == 0) {
            cout << "Введiть цiну речi: ";
            cin >> _value;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else _value = value;
    }

    void Output() const {
        cout << _name << " - " << _description << ". Важить " << _weight
            << " кг, тип: " << _type << ", матерiал: " << _material
            << ", цiна: " << _value << " грн." << endl;
    }
};

class Person {
protected:
    string _work;
    string _firstName;
    string _secondName;
    string _fatherName;
    int _age;

public:
    Person(string firstName = "", string secondName = "", string fatherName = "", int age = 0)
        : _firstName(firstName), _secondName(secondName), _fatherName(fatherName), _age(age) {}

    virtual ~Person() = default;

    virtual void Input() {
        cout << "Введiть прiзвище: ";
        getline(cin, _firstName);
        cout << "Введiть iм'я: ";
        getline(cin, _secondName);
        cout << "Введiть по батьковi: ";
        getline(cin, _fatherName);
        cout << "Введiть вiк: ";
        cin >> _age;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    virtual void Output() const {
        cout << "Прiзвище: " << _firstName << "\nIм'я: " << _secondName
            << "\nПо батьковi: " << _fatherName << "\nВiк: " << _age << endl;
    }
};

class Employee : public Person {
private:
    int _experience;
    double _salary;
    string _education;
    string _profession;
    Address _address;

public:
    Employee(string firstName = "", string secondName = "", string fatherName = "", int age = 0,
        int experience = 0, double salary = 0.0, string education = "",
        string profession = "", Address address = Address())
        : Person(firstName, secondName, fatherName, age), _experience(experience),
        _salary(salary), _education(education), _profession(profession), _address(address) {}

    void Input() override {
        _work = "Працiвник";
        Person::Input();
        cout << "Введiть стаж: ";
        cin >> _experience;
        cout << "Введiть зарплату: ";
        cin >> _salary;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Введiть освiту: ";
        getline(cin, _education);
        cout << "Введiть професiю: ";
        getline(cin, _profession);
        _address.Input();
    }

    void Output() const override {
        Person::Output();
        cout << "Освiта: " << _education << "\nПрофесiя: " << _profession
            << "\nСтаж: " << _experience << "\nЗарплата: " << _salary;
    }
};

class Engineer : public Employee {
private:
    string _specialization;
    int _projectsCompleted;
    Skill* _mainSkill;

public:
    Engineer(string firstName = "", string secondName = "", string fatherName = "", int age = 0,
        int experience = 0, double salary = 0.0, string education = "", string profession = "",
        string specialization = "", int projectsCompleted = 0, string skillName = "", int skillLevel = 0)
        : Employee(firstName, secondName, fatherName, age, experience, salary, education, profession),
        _specialization(specialization), _projectsCompleted(projectsCompleted) {
        _mainSkill = new Skill(skillName, skillLevel);
    }

    ~Engineer() override {
        delete _mainSkill;
    }

    void Input() override {
        _work = "Iнженер";
        Employee::Input();
        cout << "Введiть спецiалiзацiю: ";
        getline(cin, _specialization);
        cout << "Введiть кiлькiсть завершених проєктiв: ";
        cin >> _projectsCompleted;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        _mainSkill->Input();
    }

    void Output() const override {
        Employee::Output();
        cout << "\nСпецiалiзацiя: " << _specialization
            << "\nКiлькiсть завершених проєктiв: " << _projectsCompleted;
        _mainSkill->Output();
    }
};

class Official : public Employee {
private:
    string _militaryDep;
    string _title;
    Item _item;

public:
    Official(string firstName = "", string secondName = "", string fatherName = "", int age = 0,
        int experience = 0, double salary = 0.0, string education = "", string profession = "",
        string militaryDep = "", string title = "", Item item = Item())
        : Employee(firstName, secondName, fatherName, age, experience, salary, education, profession),
        _militaryDep(militaryDep), _title(title), _item(item) {}

    void Input() override {
        _work = "Службовець";
        Employee::Input();
        cout << "Введiть вiйськову кафедру: ";
        getline(cin, _militaryDep);
        cout << "Введiть звання: ";
        getline(cin, _title);
        _item.Input();
    }

    void Output() const override {
        Employee::Output();
        cout << "\nВiйськова кафедра: " << _militaryDep << "\nЗвання: " << _title << endl;
        cout << "Предмет що має: "; _item.Output();
    }
};

int main() {
    setlocale(LC_ALL, "ukr");
    Address ad("Vysneva, 7", "v. Moroziv", "Ukraine");
    ad.Output();

    cout << endl;

    Employee* em = new Employee("Andrii", "Pyrohovskyi", "Vitaliovych", 16, 0, 0,
        "Educational complex \"Moroziv general education school I - III degrees\" - Preschool educational institution", "-", ad);
    em->Output();

    cout << endl << endl;

    Item it("Javelin", 1, "Weapon",
        "Krestianin s kop\'em eto samii opasnii voin na svete. Ti emy daesh kop\'io, obychaesh' eho nedeliu, i vsio, on gotov.",
        "wood, iron", 1000 - 7);
    it.Output();

    cout << endl;

    Official* of = new Official("Vitalii", "Tsal\'", "Olegovych", 29, 15, 1000000,
        "-", "Streamer", "1win", "Pro Dota2 player", it);
    of->Output();

    cout << endl;

    Engineer* en = new Engineer("Andrii", "Pyrohovskyi", "Vitaliovych", 16, 0, 0,
        "Educational complex \"Moroziv general education school I - III degrees\" - Preschool educational institution", "-",
        "Projecting", 12, "Thinking", 9);
    en->Output();
    cout << endl;
    delete em;
    delete of;
    delete en;

    return 0;
}
