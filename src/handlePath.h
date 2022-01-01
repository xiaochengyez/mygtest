//
// Created by gongxc on 2021/12/10.
//
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include<fstream>
#include <string>
#include<fstream>
#include <cstring>
#ifndef MISYSTEST_HANDLE_H
#define MISYSTEST_HANDLE_H


class handlePath {
public:


    static int CreateFolder(const std::string& path, const std::string& folder_name);

    static int handle(const std::string &file_name, std::string pathFinal);

    static void mutex_lock();

    static void mutex_unlock();
};


#endif //MISYSTEST_HANDLE_H
