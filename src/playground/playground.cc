#include <iostream>

class MyClass {
 public:
  void setBoolValue(bool newValue) { myBool = newValue; }

  bool getBoolValue() const { return myBool; }

 private:
  static bool myBool;
};

// MyClass::MyClass() { myBool = false; }

int main() {
  MyClass obj1;  // Create an object with initial value true
  MyClass obj2;  // Create an object with initial value true

  std::cout << "Initial value: " << obj1.getBoolValue() << std::endl;
  std::cout << "Initial value: " << obj2.getBoolValue() << std::endl;

  obj1.setBoolValue(false);  // Change the value to false
  obj2.setBoolValue(false);  // Change the value to false

  std::cout << "New value: " << obj1.getBoolValue() << std::endl;
  std::cout << "New value: " << obj2.getBoolValue() << std::endl;

  return 0;
}
