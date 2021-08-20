#include <iostream>
#include <codecvt>
#include <exception>

#include "Dictionary.hpp"

void test();

int main()
{
  // для корректной работы на Linux
  // std::locale::global(std::locale(""));

  // для корректной работы на macOS
  std::wcout.imbue(std::locale(std::locale(""), new std::codecvt_utf8<wchar_t>));
  std::wcin.imbue(std::locale(std::locale(""), new std::codecvt_utf8<wchar_t>));

  std::wcout << L"Англо-русский словарь. Бинарное дерево поиска" << '\n' << '\n';
  std::wcout << L"Выберите режим работы: 1 - автоматический, 2 - ручной" << '\n';

  size_t t;
  std::wcin >> t;

  if (!std::wcin)
  {
    throw std::invalid_argument("Incorrect input");
  }

  if (t == 1)
  {
    test();
  }
  else if (t == 2)
  {
    try
    {
      Dictionary dict;
      std::wstring word;
      std::wstring translation;
      std::wcout << L"Введите связку слово - перевод через пробел. По окончании введите 0" << '\n';
      while (true)
      {
        std::wcin >> word;
        if (word.empty())
        {
          throw std::invalid_argument("Incorrect input");
        }

        if (word == L"0")
        {
          break;
        }

        std::wcin >> translation;
        if (translation.empty())
        {
          throw std::invalid_argument("Incorrect input");
        }

        dict.insert(word, translation);
      }
      dict.print(std::wcout);
    }
    catch (const std::exception &e)
    {
      std::cerr << e.what() << '\n';
      return 1;
    }
  }

  return 0;
}

void test()
{
  Dictionary dict;
  std::wcout << L"Заносим пары слово - перевод" << '\n';
  dict.insert(L"dog", L"собака");
  dict.insert(L"cat", L"кот");
  dict.insert(L"book", L"книга");
  dict.insert(L"headphones", L"наушники");
  dict.insert(L"key", L"ключ");
  dict.insert(L"key", L"пароль");
  dict.print(std::wcout);
  std::wcout << '\n' << L"Применяем метод remove(headphones)" << '\n';
  dict.remove(L"headphones");
  dict.print(std::wcout);
  std::wcout << '\n' << L"Применяем метод find(dog)" << '\n';
  dict.find(L"dog");
}
