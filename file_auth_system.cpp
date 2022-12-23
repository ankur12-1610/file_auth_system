#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main() {

  int t = 0;
  string p, o, p1, p2, pass;
  cout << "*****************************************" << endl
       << "Welcome to the File Authentication system" << endl
       << "*****************************************" << endl
       << endl;
  while (t != 3) {
    cout << "1. Change the password" << endl;
    cout << "2. Login to see the contents of the file" << endl;
    cout << "3. Exit" << endl;
    cin >> t;
    switch (t) {
    case 1: {
      string fileLine;
      vector<string> lines;
      ifstream read("password.txt");
      cout << endl << "Enter you old password: ";
      cin >> o;
      if (read.is_open()) {
        while (getline(read, fileLine)) {
          lines.push_back(fileLine);
        }
      }
      if (o == lines[0]) {
        read.close();
        ofstream write("password.txt", ofstream::trunc);
        cout << endl << "Enter your new password : ";
        cin >> p1;
        cout << "Confirm your new password: ";
        cin >> p2;
        if (p1 == p2) {
          lines[0] = p1;
          for (int i = 0; i < lines.size(); i++) {
            if (i == lines.size() - 1)
              write << lines[i];
            else {
              write << lines[i] << endl;
            }
          }
          cout << endl << "Password changed successfully ;)" << endl;
        }
        write.close();
        break;
      } else {
        cout << endl << lines[0] << "Please enter a valid password :/" << endl;
      }
      break;
    }
    case 2: {
      ifstream read("password.txt");
      cout << endl << "Enter your password: ";
      cin >> pass;
      while (read >> p) {
        if (pass == p) {
          cout << "Access granted!" << endl
               << endl
               << "Content of file" << endl
               << "-----------------------------------------" << endl;
          ifstream f("password.txt");
          if (f.is_open())
            std::cout << f.rdbuf() << endl
                      << "-----------------------------------------" << endl;
          ;
          cout << endl;
          break;
        } else {
          cout << "Sorry! Wrong Password  :/" << endl << endl;
        }
      }
      read.close();
      break;
    }
    case 3: {
      cout << endl << "Thank you for using this program :)" << endl;
      break;
    }
    }
  }
  return 0;
}
