# Индивидуальное домашнее задание №4

#### Студент: Нечесов Андрей Львович
#### Группа: БПИ217
#### Вариант: 14


## Содержание
- [Условие к варианту](#условие-к-варианту)
- [Критерии на 4 балла](#критерии-на-4-балла)
  - [Модель вычислений](#модель-вычислений)
  - [Консольное приложение]()

## Условие к варианту
>Задача о гостинице - 3 (дамы и джентльмены).
> В гостинице 10 номеров рассчитаны на одного человека и 15 номеров рассчитаны на двух человек.
> В гостиницу случайно приходят клиенты дамы и клиенты джентльмены,
и конечно они могут провести ночь в номере только с представителем своего
пола. Если для клиента не находится подходящего номера, он уходит искать
ночлег в другое место. Клиенты порождаются динамически и уничтожаются
при освобождении номера или уходе из гостиницы при невозможности поселиться.
> Создать многопоточное приложение, моделирующее работу гостиницы

## Критерии на 4 балла
### Модель вычислений 
При разработке многопоточной программы использовалась модель **Итеративный параллелизм**

Каждый из потоков решает одну и ту же задачу &mdash; ищет свободную комнату в гостинице.

### Консольное приложение
Реализовано консольное приложение на C++, исходные коды которого расположены в следующей директории: [src/](src/)

Скопмилировать программу можно следущей командой:
```console
g++ -std=c++17 main.cpp gender.h person.h room.h -lpthread 
```

### Ввод данных
Реализован консольный ввод и вывод данных.
<p align="center">
<img src=screenshots/console_io.jpg>
<em>Пример консольного ввода и вывода.</em>
</p>

## Критерии на 5 баллов
### Комментарии к исходному коду программы

### Сценарий поведения сущностей

## Критерии на 6 баллов
### Описание обощенного алгоритма
### Ввод из командной строки

## Критерии на 7 баллов
### Файловый ввод и вывод
### Примеры входных и выходных файлов
### Комбинации форматов ввода и вывода

## Критерии на 8 баллов
### Генератор случайных данных
### Примеры входных и выходных файлов
