#include "Textbook.h"
#include "Header.h"
int Textbook::File_To_Vector() {
    std::string tmpStr;
    std::ifstream file;
    file.open(FILE_NAME);
    if (!file.is_open()) {
        return 1;
    }

    while (getline(file, tmpStr)) {
        vect_task.push_back(tmpStr);
    }
    file.close();
    return 0;
}
void Textbook::viewTasks() {
    int cursorPosY = 0;
    bool loop = true;
    std::string update_task;
    int j{};

    while (loop)
    {
    Beggining:
        taskEmpty();
        int size = vect_task.size();
        if (GetAsyncKeyState(VK_DOWN) & 1)
            cursorPosY++;
        if (GetAsyncKeyState(VK_UP) & 1)
            cursorPosY--;
        if (GetAsyncKeyState(VK_ESCAPE) & 1)
           // Vector_To_File();
            break;
        for (int i = 0; i < size; i++)
        {
            if (i == 0) {
                std::cout << "Tasks: " << std::endl << std::endl;
            }
            std::cout << vect_task[i];
            if (cursorPosY < 0)
            {
                cursorPosY = 0;
            }

            if (cursorPosY > size - 1)
            {
                cursorPosY = size - 1;
            }
            if (i == cursorPosY)
            {
                std::cout << "<--";
                j = i;
            }

            std::cout << std::endl;
            if (i == size - 1) {
                std::cout << std::endl;
                std::cout << "[ESC] Exit the program" << std::endl;
                std::cout << "[F1] Select task" << std::endl;
                std::cout << "[F3] Add a new task" << std::endl;
                std::cout << "[F5] Save changes" << std::endl;

            }
            if (GetAsyncKeyState(VK_F1) & 1)
            {
                system("cls");
                std::cout << "Task: " << vect_task[j] << std::endl;
                std::cout << "What do you want to do with this task?\n";
                std::cout << "[1] Delete the task \n[2] Change description of the task \n[3] Go back\n[4] End the program\n";
                std::cout << "Your choice: ";
                int n{};
                do
                {
                    std::cin >> n;
                    if (!std::cin) // If the previous extraction failed
                    {
                        // Handle the failure
                        std::cin.clear(); // Put back into 'normal' operation mode
                        ignoreLine();     // Remove the bad input
                    }
                } while (n < 1 || n > 4);
                std::cout << "\b";
                switch (n)
                {
                case 1:
                    if (!vect_task.empty())
                    {
                        vect_task.erase(vect_task.begin() + j);
                    }
                    else
                    {
                        Create_Task();
                    }
                    system("CLS");
                    goto Beggining;
                    break;
                case 2:
                    std::cout << "Type text: ";
                    update_task.clear();
                    ignoreLine();
                    if (std::getline(std::cin, update_task))
                    {
                        vect_task[j] = update_task;
                    }
                    else
                    {
                        std::cerr << "Error reading the input";
                    }
                    break;
                case 3:
                    system("cls");
                    break;
                case 4:
                    system("cls");
                    loop = false;
                    break;

                default:
                    break;
                }

            }
            if (GetAsyncKeyState(VK_F3) & 1) { // Create a new task
                system("CLS");
                std::cout << "Type in your task: ";
                Create_Task();
            }
            if (GetAsyncKeyState(VK_F5) & 1) { // Save the changes
                Vector_To_File();
            }
        }
        Sleep(200);
        system("CLS");
    }
}
int Textbook::Vector_To_File() {
    std::ofstream file;
    int rasyti = 0;
    std::string tmpStr;

    file.open(::FILE_NAME);

    if (!file.is_open()) //  Return 1 - if the file isnt open
    {
        std::cout << "ERROR OPENING FILE!";
        Sleep(500);
        return 1;
    }
    else
    {
        for (int i = 0; i < vect_task.size(); i++) // Write changes to the file
            // 
        {
            file << vect_task[i] << std::endl;
        }
    }
    file.close();
    return 0;
}

void Textbook::Create_File() // Create a file
{
    std::ofstream MyFile(::FILE_NAME);
}
int Textbook::Check_Vector_Size()
{
    if (vect_task.empty())
    {
        return 1; // Return 1 if Vector is empty
    }
    return 0;
}
void Textbook::Create_Task() // Create a new task
{
    std::string task;
    std::getline(std::cin, task);
    vect_task.push_back(task);
}
void Textbook::taskEmpty()
{
    for (int i = 0; i < vect_task.size(); ++i)
    {
        if (vect_task.at(i).empty())
        {
            vect_task.erase(vect_task.begin() + i);
        }
    }
}
