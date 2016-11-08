//
// Created by 蜗牛 on 2016/11/8.
//

#ifndef COMPOSITE_FILEEXCEPTION_H
#define COMPOSITE_FILEEXCEPTION_H

//#include <exception>
//#include <string>
//#include <sstream>
//using namespace std;
//
//class FileException: public exception {
//private:
//    string name;
//    int size;
//public:
//    FileException(string fname, int fsize) {
//        this->name = fname;
//        this->size = fsize;
//    }
//
//    const char* what() const{
//        ostringstream ex_msg;
//        static string msg;
//        ex_msg << "Internal error: size of file is "
//               << size << " ,it isn't reasonable!" << endl;
//
//        msg = ex_msg.str();
//        return msg.c_str();
//    }
//};

#endif //COMPOSITE_FILEEXCEPTION_H
