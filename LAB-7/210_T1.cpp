#include<iostream>
#include<string>
using namespace std;

class Person{
protected:
    string name;
    int age;
    int personID;
    static int count;
public:
    Person() : name("John Doe"), age(0), personID(count) {count++;}
    Person(string n, int a) : name(n), age(a), personID(count) {
        count++;
    } 
    ~Person(){
        cout << "~Person() is called." << endl;
    }
    string getName() const {return name; }
    int getAge() const {return age; }
    int getID() const {return personID; }
    
    void displayDetails(){
        cout << name << "," << "Age: " << age << ", P_ID: " << personID << endl; 
    }
    void setName(int n){
        name = n;
    }
    void setAge(int a){
        age = a;
    }
    void setID(int id){
        personID = id;
    }
    bool operator==(Person &p) {
        return (this->getAge() == p.getAge() && this->getName() == p.getName());
    }

};
int Person ::count = 1;
ostream& operator<<(ostream& os, Person &p){
    os << p.getName() << "," << "Age: " << p.getAge() << ", P_ID: " << p.getID() << endl;
    return os;
}

class Student : public Person{
private:
    int sid;
public:
    int getSID() const{ return sid; }
    void setSID(int id){
        sid = id;
    }

};

class Faculty : public Person{
private:
    string designation;
public:
    Faculty() : Person() {
        name = "Mr. X";
        age = 22;
        designation = "Lecturer";
    }
    Faculty(string n, int age, string des) : Person(n, age), designation(des) {}
    ~Faculty(){
        cout << "~Faculty() is called." << endl;
    }
    string getDesignation() const{return designation; }
    void setDesignation(string d){
        designation = d;
    }
};

class Visitor : private Person{
private:
    string visitingPurpose;
public:
    string getvisitingPuporse() const{ return visitingPurpose; }
    void setvisitingPurpose(const string vp){
        visitingPurpose = vp;
    }
};


void TestPerson()
{
    Person p1, p2("Faisal",30);

    if(p1.getName()=="John Doe" && p1.getAge() == 0 &&p1.getID()==1) cout<< "Zero Arg Constructor - Passed"<<endl;
    else  cout<< "Zero Arg Constructor - Failed!!!!"<<endl;

    if(p2.getName()=="Faisal" && p2.getAge() == 30 &&p2.getID()==2) cout<< "Argumented Constructor - Passed"<<endl;
    else  cout<< "Argumented Constructor - Failed!!!!"<<endl;

    if(p1==p1) cout<< " operator == - Passed"<<endl;
    else cout<< " operator == - Failed!!!!"<<endl;

}

void TestStudent(){
    Student s1;
}
void TestFaculty(){
    Faculty f;
    if(f.getName()=="Mr. X"&&f.getAge()==22&&f.getDesignation()=="Lecturer") cout<< "Zero Arg Constructor Faculty - Passed"<<endl;
    else cout<< "Zero Arg Constructor Faculty - Failed!!!!"<<endl;
}
void TestVisitor()
{
    Visitor v;
}

int main()
{
    TestPerson();
    TestStudent();
    TestFaculty();
    TestVisitor();
}
