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
При разработке многопоточной программы использовалась модель **итеративного параллелизма**

Каждый из потоков решает одну и ту же задачу &mdash; ищет свободную комнату в гостинице. Поиск такой комнаты происходит обходом всех номеров в цикле. Взаимодействие потоков происходит через общий ресурс &mdash; массив всех комнат гостиницы. 

### Описание входных данных

На вход программе подается два целых неотрицательных числа &mdash; количество клиентов мужского пола и количество клиентов женского пола, причем суммарное количество клиентов не превышает 150.

### Консольное приложение
Реализовано консольное приложение на C++, исходные коды которого расположены в следующей директории: [src/](src/)

Скомпилировать программу можно следующей командой:
```console
g++ -std=c++17 main.cpp gender.h person.h room.h -lpthread 
```

### Ввод данных
Реализован консольный ввод и вывод данных.
<p align="center">
<img src=screenshots/console_io.jpg alt="alt of image">
</p>
<p align="center">
<em>Пример консольного ввода и вывода.</em>
</p>

## Критерии на 5 баллов
### Комментарии к исходному коду программы
Исходный код прокомментирован: [src/](src/)
### Сценарий поведения сущностей
Сначала все клиенты собираются у дверей гостиницы и ожидают её открытия. После того как гостиница открывается, все клиенты в спешке несутся к портье, чтобы заселиться в первый свободный номер. Портье же, человек аккуратный и неторопливый, поэтому работает только с одним клиентом, из-за чего ажиотаж среди возможных постояльцев настолько велик, что клиенты не выстраиваются в очередь, а конкурируют за возможность как можно раньше попасть к портье.  

Попав в номер, клиент некоторое время отдыхает, а затем снова возвращается к портье, чтобы выселиться: внести плату за проживание и вернуть ключи.
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
