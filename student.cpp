#include<iostream>
#include<string>
using namespace std;

/*
*  类继承标准写法：默认构造，含参构造，拷贝构造，析构函数（基虚）
*  const 成员函数
*  函数参数值传递，将自动调用对象的拷贝构造函数创建复件
*  更优的函数参数传递方式为：pass-by-reference-to-const
*/

class Person{
public:
    Person(){
        cout << "person constructed by default. pointer: "<< this << endl;
    }
    Person(string sn, string sa):name(sn),address(sa){
        cout << "Person constructed. pointer: "<< this << endl;
    }
    virtual ~Person(){
        cout << "Person destructed. pointer: "<<this << endl;
    }
    string getName() const{
        return this->name;
    }
    string getAddress() const{
        return this->address;
    }
private:
    string name;
    string address;
};

class Student: public Person{
public:
    Student(){
        cout << "Student constructed by default. pointer: "<< this << endl;
    }
    Student(string sn, string sa, string ssn, 
    string ssa):Person(sn, sa), schoolName(ssn), schoolAddress(ssa){
        cout << "Student constructed. pointer: "<< this << endl;
    }
    Student(const Student& cs):Person(cs.getName(), cs.getAddress()), 
    schoolName(cs.schoolName), schoolAddress(cs.schoolAddress){
        cout << "Student constructed by copying. pointer: " << this << endl;
    }
    ~Student(){
        cout << "Student destructed. pointer: "<< this << endl;
    }
    string getSchoolName() const{
        return this->schoolName;
    }
private:
    string schoolName;
    string schoolAddress;
};

bool validStudent(Student s){
    return s.getSchoolName() == "HUST";
}

bool validStudentRef(const Student& cs){
    return cs.getSchoolName() == "HUST";
}

int main(){
    Student wlz("wlz", "An Hui", "HUST", "Hu Bei");
    // 值传递
    //cout << wlz.getName() << " is a HUSTer? " << (validStudent(wlz) ? "YES" : "NO") << endl;
    // 引用传递
    cout << wlz.getName() << " is a HUSTer? " << (validStudentRef(wlz) ? "YES" : "NO") << endl;
}