#include <iostream>
#include "Entry.h"
#include "File.h"
#include "Directory.h"
using namespace std;

int main() {
    File f = File("test", 56);
    File t;
    Directory d1 = Directory("root");
    Directory d2 = Directory("usr");
    Directory d3 = Directory("temp");
    Directory d4 = Directory("local");
    d1.add(&f);
    d1.add(&d2);
    d1.add(&d3);
    d1.add(&d4);
    d4.add(&t);

    File c1 = File("root", 30);
    Directory g1 = Directory("usr");
    d1.add(&c1);
    d1.add(&g1);
    d1.add(&f);
    d1.printList();
    return 0;
}