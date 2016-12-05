#include <iostream>
#include "Entry.h"
#include "File.h"
#include "Directory.h"
#include <vector>
using namespace std;

int main() {
    cout << "Making root entries..." << endl;
    Directory* rootdir = new Directory("root");
    Directory* bindir = new Directory("bin");
    Directory* tmpdir = new Directory("tmp");
    Directory* usrdir = new Directory("usr");
    Directory* localdir = new Directory("local");

    rootdir->add(bindir);
    rootdir->add(tmpdir);
    rootdir->add(usrdir);
    bindir->add(localdir);

    localdir->add(new File("vi.html", 10000));
    localdir->add(new File("latex.cpp", 20000));
    localdir->add(new File("vi.html", 0));
    rootdir->printList();

    rootdir->remove("bin");
    rootdir->printList();
    return 0;
}