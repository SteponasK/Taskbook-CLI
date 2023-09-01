#include <iostream> // CIA YRA PAGRINDINIS FAILAS
#include <fstream>
#include <vector>
#include <windows.h>
#include <string>
#include <vector>
#include <string.h>
int File_To_Vector(std::vector <std::string>& vect1, std::string filename);
void viewTasks(std::vector <std::string>& vect1);
int Vector_To_File(std::vector <std::string>& vect1, std::string filename);
void Create_File(std::vector <std::string>& vect1);
int Check_Vector_Size(std::vector <std::string>& vect1);
void Make_Task(std::vector <std::string>& vect1);
std::string FILE_NAME = "tasks_file.txt";

int main() {

    std::vector <std::string> vect_task;

    if (File_To_Vector(vect_task, FILE_NAME)) // jeigu failo nera
    {
        Create_File(vect_task);
    }

    if (Check_Vector_Size(vect_task)) // jeigu vektorius yra tuscias
    {
        std::cout << "Type in your first task: ";
        Make_Task(vect_task);
    }

    viewTasks(vect_task);

    Vector_To_File(vect_task, FILE_NAME);


    return 0;
}
int File_To_Vector(std::vector <std::string>& vect1, std::string filename) {
    std::string tmpStr;
    std::ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        return 1;
    }

    while (getline(file, tmpStr)) {
        vect1.push_back(tmpStr);
    }
    file.close();
    return 0;
}
void viewTasks(std::vector <std::string>& vect1) {
    int cursorPosY = 0;
    bool loop = true;
    int j;
    std::string textas;
    std::string new_task;

    while (loop)
    {
        int size = vect1.size();
        if (GetAsyncKeyState('S') & 1)
            cursorPosY++;
        if (GetAsyncKeyState('W') & 1)
            cursorPosY--;
        if (GetAsyncKeyState('X') & 1)
            break;
        for (int i = 0; i < size; i++)
        {
            if (i == 0) {
                std::cout << "Tasks: " << std::endl << std::endl;
            }
            std::cout << vect1[i];
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
            if (i == vect1.size() - 1) {
                std::cout << std::endl;
                std::cout << "[X] Exit the program" << std::endl;
                std::cout << "[G] Select task" << std::endl;
                std::cout << "[Q] Add a new task" << std::endl;
                std::cout << "[Z] Save changes" << std::endl;

            }
            if (GetAsyncKeyState('G') & 1)
            {
                system("cls");
                int n;
                std::cout << "Task: " << vect1[j] << std::endl;
                std::cout << "What do you want to do with this task?\n";
                std::cout << "[1] Delete the task \n[2] Change description of the task \n[3] Go back\n[4] End the program\n";
                std::cin >> n;
                switch (n)
                {
                case 1:
                    vect1.erase(vect1.begin() + j);
                    break;
                case 2:
                    std::cout << "Type text: ";
                    std::cin >> textas;
                    vect1[j] = textas;
                    Sleep(1000);
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
            if (GetAsyncKeyState('Q') & 1) { // sukurti new task
                std::cout << "Type in your task: ";
                Make_Task(vect1);
            }
            if (GetAsyncKeyState('Z') & 1) { // save changes
                Vector_To_File(vect1, ::FILE_NAME);
            }
        }
        Sleep(200);
        system("CLS");

    }
}
int Vector_To_File(std::vector <std::string>& vect1, std::string filename) {
    std::ofstream file;
    int rasyti = 0;
    std::string tmpStr;

    file.open(filename);

    if (!file.is_open()) { // jeigu failo nera returninam true
        std::cout << "ERORR OPENING FILE!";
        Sleep(500);
        return 1;
    }
    for (int i = 0; i < vect1.size(); i++) // jeigu failas yra tai vektoriaus duomenis pervedame i faila
    {
        file << vect1[i] << std::endl;
    }

    file.close();
    return 0;
}

void Create_File(std::vector <std::string>& vect1) { // sukuriame faila
    std::ofstream MyFile(::FILE_NAME);
}
int Check_Vector_Size(std::vector <std::string>& vect1)
{
    if (vect1.size() == 0)
    {
        return 1;  // jeigu vektorius tuscias return 1 (true)
    }
    return 0;
}
void Make_Task(std::vector <std::string>& vect1) // sukurti task
{
    std::string task;
    std::getline(std::cin, task);
    vect1.push_back(task);
}