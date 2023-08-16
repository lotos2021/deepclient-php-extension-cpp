#ifndef DEEPCLIENT_PHP_EXTENSION_CPP_DEEPCLIENT_H
#define DEEPCLIENT_PHP_EXTENSION_CPP_DEEPCLIENT_H

#include <boost/python.hpp>
#include <map>
#include <vector>
#include <php.h>

class DeepClient {
public:
    DeepClient();

    boost::python::dict select(boost::python::object exp, boost::python::dict options = boost::python::dict());
    boost::python::dict insert(boost::python::object objects, boost::python::dict options = boost::python::dict());
    boost::python::dict update(boost::python::dict exp, boost::python::dict value, boost::python::dict options = boost::python::dict());
    boost::python::dict remove(boost::python::object exp, boost::python::dict options = boost::python::dict());

    boost::python::dict serial(boost::python::dict asyncSerialParams);

    void reserve();
    void wait_for();

    int id(boost::python::object start, boost::python::object path);
    int id_local();

    boost::python::dict guest();
    boost::python::dict jwt();
    boost::python::dict whoami();
    boost::python::dict login();
    boost::python::dict logout();
    boost::python::dict can();
    boost::python::dict name();
    boost::python::dict name_local();

private:
    std::map<int, std::string> _ids;
    std::map<std::string, std::string> _serialize;

    // Здесь могут быть дополнительные поля и методы
};

#endif //DEEPCLIENT_PHP_EXTENSION_CPP_DEEPCLIENT_H