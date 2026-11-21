#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;
class Staff {
protected: string name; int id; double basic;
public:
 Staff(string n,int i,double b):name(move(n)),id(i),basic(b){}
 virtual double pay() const=0;
 virtual string role() const=0;
 virtual ~Staff()=default;
 void print() const { cout<<role()<<": "<<name<<" ("<<id<<") = "<<pay()<<'\\n'; }
};
class Professor:public Staff {
 double research;
public: Professor(string n,int i,double b,double r):Staff(move(n),i,b),research(r){}
 double pay()const override{return basic*1.42+research;}
 string role()const override{return "Professor";}
};
class LabAssistant:public Staff {
public: using Staff::Staff;
 double pay()const override{return basic*1.42;}
 string role()const override{return "LabAssistant";}
};
class GuestFaculty:public Staff {
 double hours,rate;
public: GuestFaculty(string n,int i,double h,double r):Staff(move(n),i,0),hours(h),rate(r){}
 double pay()const override{return hours*rate;}
 string role()const override{return "GuestFaculty";}
};
int main(){
 vector<unique_ptr<Staff>> team;
 team.push_back(make_unique<Professor>("Anita",101,50000,8000));
 team.push_back(make_unique<LabAssistant>("Bala",102,30000));
 team.push_back(make_unique<GuestFaculty>("Charan",103,20,900));
 for(const auto& s:team)s->print();
}