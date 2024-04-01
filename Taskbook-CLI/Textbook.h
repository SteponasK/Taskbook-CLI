#pragma once
#include "Header.h"
class Textbook
{
public:
    int File_To_Vector();
    void Create_File();
    int Check_Vector_Size();
    void Create_Task();
    void viewTasks();
    int Vector_To_File();
    void taskEmpty();
private:
    std::vector <std::string> vect_task;
};

void ignoreLine();
