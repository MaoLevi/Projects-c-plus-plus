 #include<iostream>
using namespace std;
class X
{
public:
virtual void F1() { cout << "X::F1 "; };
void F2() { cout << "X::F2 "; };
};
class Y : public X
 {
 public:
 virtual void F1() override  { cout << "Y::F1 "; };
 void F2()  { cout << "Y::F2 "; };
 };
 class Z : public Y
 {
 public:
 void F1() { cout << "Z::F1 "; };
 void F2() { cout << "Z::F2 "; };
 };
 int main()
 {
 X * px1 = new Y;
 px1->F1();
 px1->F2();
 Y * px2 = new Z;
 px2->F1();
 px2->F2();
 }