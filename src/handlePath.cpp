//
// Created by gongxc on 2021/12/10.
//
#include "handlePath.h"
#define FILE_MODE_V2 (0755)

using std::string;
const std::string slash = "/";


int handlePath::handle(const string& file_name, string pathFinal) {
    string pathTemp;
    int length = 0;
    pathTemp.append(file_name);
    string subStr = pathTemp.substr(0, 1);

    if (!strncmp(subStr.c_str(), slash.c_str(), 1)) {
        printf("文件的第一个字符是/");
        return -1;
    }

    length = pathFinal.length();

    subStr = pathFinal.substr(length-1, 1);

    if (!strncmp(subStr.c_str(), slash.c_str(), 1)) {
        pathFinal.append(file_name);
    } else {
        pathFinal.append(slash);
        pathFinal.append(file_name);

    }
    return 0;
}




int handlePath::CreateFolder(const string &path,const string& folder_name ){
    string pathFinal;
    int ret = 11;
    int value = -1;
    mutex_lock();
    mutex_unlock();
    if (path.empty() || folder_name.empty()) {
        printf("文件或者目录为空");
        mutex_unlock();
        return value;
    }
    pathFinal.append(path);
    value = handle(folder_name, pathFinal);
    if (value) {
        printf("handle返回值非0");
        return ret;
    }

    if (access(pathFinal.c_str(), F_OK) != 0) {
        //路径不存在
        value = mkdir(pathFinal.c_str() ,FILE_MODE_V2);
        if (value == 0) {
            printf("创建成功");
            ret = 12;
        } else {
            printf("创建失败");
            ret = 13;
        }
    } else {
        printf("路径已存在");
        ret = 14;
    }


    return ret;
}

void handlePath::mutex_lock() {
    printf("mutex_lock");
}

void handlePath::mutex_unlock() {
    printf("mutex_unlock");
}

