#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "root.hpp"

#include <QApplication>

class Application : public QApplication {

public:
    Application(int argc, char *argv[]);
    int start();
private:
    Root windows;
};

#endif
