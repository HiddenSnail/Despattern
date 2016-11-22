#include <iostream>
#include "Entry.h"
#include "File.h"
#include "Directory.h"
using namespace std;

class A{
public:
    virtual void print() {
        cout << "I am A" << endl;
    }
};

class B:public A {
    virtual void print() {
        cout << "I am B" << endl;
    }
};

class C:public A {
    virtual void print() {
        cout << "I am C" << endl;
    }
};

int main() {
    cout << "Making root entries..." << endl;
    Directory* rootdir = new Directory("root");
    Directory* bindir = new Directory("bin");
    Directory* tmpdir = new Directory("tmp");
    Directory* usrdir = new Directory("usr");

    rootdir->add(bindir);
    rootdir->add(tmpdir);
    rootdir->add(usrdir);

    bindir->add(new File("vi.html", 10000));
    bindir->add(new File("latex.cpp", 20000));
    bindir->add(new File("vi.html", 0));
    rootdir->printList();

    rootdir->remove("bin");
    rootdir->printList();

//    A a;
//    a.print();
//
//    B b;
//    C c;

    return 0;
}