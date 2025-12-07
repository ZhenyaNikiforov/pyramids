/*-- Путешествие по пирамиде
(задача №2 в домашней работе)--*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> Array1{1, 3, 6, 5, 9, 8};

void show(int i, vector<int> &originalPyramide) // отображает свойства элемента массива
{
  int level = floor(log2(i + 1)); // рассчитываем уровень...
  cout << level << " ";           // ...отображаем уровень;

  string position = ""; // рассчитываем позицию...
  if (i == 0)
  {
    position = "root";
  }
  else
  {
    if (i % 2 == 0)
    {
      position = "right";
    }
    else
    {
      position = "left";
    };
  };
  std::cout << position << " "; //...отображаем позицию;

  if (i != 0) // если текущий индекс не 0, то...
  {
    int parentIndex = 0;
    if (i % 2 == 0)
    {
      parentIndex = (i - 2) / 2;
    }
    else
    {
      parentIndex = (i - 1) / 2;
    }
    cout << "(" << originalPyramide[parentIndex] << ") "; //...рассчитываем и отображаем его предка;
  }

  cout << originalPyramide[i] << endl; // рассчитываем и отбражаем значение текущего элемента;
  return;
}

void travel(std::vector<int> &originalPyramide)
{
  for (int i = 0; i < originalPyramide.size(); ++i) // проходим массив...
  {
    show(i, originalPyramide); //...отображаем каждый элемент.
  };

  int index = 0; // начальное значение - стартовая точка;
  while (true)   // циклическое звено подпрограммы;
  {
    std::cout << "Eto zdes`: ";    // о нашем местоположении;
    show(index, originalPyramide); // свойства и координаты нашего места;
    std::string command = "";      // переменная команды;
    std::cout << "COMMAND: ";      // запрос команды;
    std::cin >> command;           // ввод команды;
    if (command == "exit")         // если команда на выход, то...;
    {
      return; // сбрасываем всю подпрограмму;
    }
    else if (command == "up") //...иначе, если команда вверх...;
    {
      if (index == 0) //...если команда вверх и индекс 0, то...;
      {
        cout << "Net predka!" << std::endl; //...нет предка.;
      }
      else // если команда вверх и индекс не 0, то...;
      {
        cout << "Yes" << endl; // да.;
        if (index % 2 == 0)    // если элемент правый;
        {
          index = (index - 2) / 2;
        }
        else // если элемент левый;
        {
          index = (index - 1) / 2;
        }
      }
    }
    else if (command == "left") // если команда влево...;
    {
      int i = index * 2 + 1;           //...считаем левого потомка..;
      if (i < originalPyramide.size()) //...если левый потомок меньше длины массива...;
      {
        cout << "Yes" << endl; //...да,;
        index = i;             // меняем индекс;
      }
      else //;
      {
        cout << "Net levogo potomka!" << endl; // если больше длины массива.;
      }
    }
    else if (command == "right") // если команда вправо...;
    {
      int i = index * 2 + 2;           // считаем правого потомка;
      if (i < originalPyramide.size()) // если правый потомок меньше длины массива...;
      {
        cout << "Yes" << endl; // да,;
        index = i;             // меняем индекс;
      }
      else // если больше длины массива;
      {
        cout << "Net pravogo potomka" << endl; // нет правого потомка;
      }
    }
    else // если команда не входит в эти четыре,...;
    {
      cout << "Unknow command!" << endl; // сообщение;
    };
  }
  return;
}

int main()
{
  travel(Array1);
  return 0;
}