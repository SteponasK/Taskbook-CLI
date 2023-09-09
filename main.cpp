#include "Header.h"
#include "Textbook.h"
#include "ignoreLine.h"
std::string FILE_NAME = "tasks.txt";
int main() {

    Textbook textbook;

    if (textbook.File_To_Vector()) // Return 1 - File not created
    {
        textbook.Create_File();
    }

    if (textbook.Check_Vector_Size()) // Return 1 - Vector Empty 
    {
        std::cout << "Type in your first task: ";
        textbook.Create_Task();
    }

    textbook.viewTasks();

    textbook.Vector_To_File();

    return 0;
}

