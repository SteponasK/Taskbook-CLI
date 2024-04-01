#include "Header.h"
#include "Textbook.h"
#include "ignoreLine.h"

std::string FILE_NAME = "tasks.txt";

int main() {
  Textbook textbook;
  // Return 1 - File not created
  if (textbook.File_To_Vector()) {
    textbook.Create_File();
  }
  // Return 1 - Vector Empty
  if (textbook.Check_Vector_Size()) {
    std::cout << "Type in your first task: ";
    textbook.Create_Task();
  }

  textbook.viewTasks();

  textbook.Vector_To_File();

  return 0;
}
