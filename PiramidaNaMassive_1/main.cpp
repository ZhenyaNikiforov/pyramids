/*-Пирамида на массиве
(задание №1 в домашней работе)-*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> Array1{1, 3, 6, 5, 9, 8};
vector<int> Array2{94, 67, 18, 44, 55, 12, 6, 42};
vector<int> Array3{16, 11, 9, 10, 5, 6, 8, 1, 2, 4};

int raise(int number, int degree) // повышение в степень
{
  if (degree == 0) // если степень 0, то...
  {
    return 1; // врзвр. 1
  };
  if (degree == 1) // если степень 1, то...
  {
    return number; //...возвр. число
  };
  int multNumber = number;               // переменная-накопитель
  for (int i = 0; i < (degree - 1); ++i) // знаков умножения на 1 меньше чем степень
  {
    multNumber = multNumber * number; // накопление * на число = накопление
  }
  return multNumber; // возвр. накопление
};

void printsPyramid(std::vector<int> &originalArray) // печатает пирамиду
{
  vector<int> beginningRange{};              // начала диапазонов
  vector<int> rangeSize{};                   // размеры диапазонов
  int rangeCount = 0;                        // счёт диапазонов
  int nextElement = 0;                       // след. элемент после диапазона
  while (nextElement < originalArray.size()) // пока след. элем. меньше длины масс-ва
  {
    if (rangeCount == 0) // если первый элемент, то...
    {
      beginningRange.push_back(0);                                      // начало диапазона 0,
      rangeSize.push_back(raise(2, 0));                                 // размер диапазона 2^0
      nextElement = beginningRange[rangeCount] + rangeSize[rangeCount]; // перв. элем. след. диап. = начало + длина
      rangeCount++;                                                     // след. итерация
      continue;                                                         // новый пробег
    };
    beginningRange.push_back(beginningRange[rangeCount - 1] + rangeSize[rangeCount - 1]); // начало нов.= нач.пред. + длина пред.
    rangeSize.push_back(raise(2, rangeCount));                                            // длина нового= степень 2-йки
    nextElement = beginningRange[rangeCount] + rangeSize[rangeCount];                     // след. элем. (в. нов. диап.)
    rangeCount++;                                                                         // след. диап.
  };

  cout << endl;                                    // пустая строчка сверху
  cout << "[0] ROOT " << originalArray[0] << endl; // единств. потомок. 0-го диап.
  int currentRange = 0;                            // текущ. диап.
  while (true)                                     // циклическое звено подпрограммы
  {
    int currentRangeStartPoint = beginningRange[currentRange]; // старт. точка текущ. диап. (индекс мас-ва)
    int currentRangeSize = rangeSize[currentRange];            // размер текущ. диап.

    int nextRange = currentRange + 1; // начало след. диап-на

    if (nextRange >= beginningRange.size()) // если начало нов. диапазона выходит за длину мас-ва, то...
    {
      break; // рвём цикл.
    };

    int nextRangeStartPoint = beginningRange[nextRange]; // начало нов. диап-на (старт. тчк. это индкс в массиве)
    int nextRangeCounter = nextRangeStartPoint - 1;      // счёт элементов и длины след. диап-на

    for (int i = currentRangeStartPoint; i < (currentRangeStartPoint + currentRangeSize); ++i) // проход текущ. диап-на
    {
      int itemCurrentRange = originalArray[i];      // текущий элемент (из ориг. масс-ва)
      nextRangeCounter++;                           // наращиваем (поэтому брали -1) индекс след. диап-на
      if (nextRangeCounter >= originalArray.size()) // если индекс выходит из массива, то...
      {
        break; // ...прерываем
      }
      cout << "[" << currentRange + 1 << "] LEFT [" << itemCurrentRange << "] " << originalArray[nextRangeCounter] << endl;

      nextRangeCounter++;                           // это уже второй (или n + след.) элем. след. диап-на, ...
      if (nextRangeCounter >= originalArray.size()) //...на один элемент текущего, два элемента следующего.
      {
        break; //---
      }
      cout << "[" << currentRange + 1 << "] RIGHT [" << itemCurrentRange << "] " << originalArray[nextRangeCounter] << endl;
    }
    currentRange++; // переходим к след. диапазону
  };
}

int main()
{
  printsPyramid(Array1);
  printsPyramid(Array2);
  printsPyramid(Array3);
  return 0;
}