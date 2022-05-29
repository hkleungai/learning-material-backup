#include <iostream>
using namespace std;

class Base {
public:
  void f() {cout << "Base::f()" << endl;}
protected:
  void g() {cout << "Base::g()" << endl;}
};

class public_derived: public Base {
};

class protected_derived: protected Base {
public:
  void h(){
    f(); g(); // Able to call both Base's public and protected members 
  }
};
  
class private_derived: private Base {
public:
  void h(){
    f(); g(); // Able to call Base's public and protected members 
  }
};

class protpd: protected private_derived{
public:
  void k(){
    h(); // ok as it is a public function in private_derived
    // f();  error: 'void Base::f()' is inaccessible within this context
    // g(); error: 'Base' is not an accessible base of 'protpd'
  }
};


int main(){

  Base b;
  public_derived pub_d;
  protected_derived prot_d;
  private_derived priv_d;
  protpd ppd;

  b.f();
  //  b.g();  error: 'void Base::g()' is protected

  pub_d.f();
  //  pub_d.g(); error: 'void Base::g()' is protected

  //  prot_d.f(); error: 'void Base::f()' is inaccessible
  //  prot_d.g(); error: 'Base' is not an accessible base of 'protected_derived'
  prot_d.h();  
  
  //  priv_d.f(); similar error as above
  //  priv_d.g(); similar error as above
  priv_d.h();

  ppd.k();

  return 1;
}
