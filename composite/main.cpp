#include <iostream>
#include "Entry.h"
#include "File.h"
#include "Directory.h"
using namespace std;

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
    return 0;
}