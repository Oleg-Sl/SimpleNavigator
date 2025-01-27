# SimpleNavigator


## Описание проекта
Этот проект представляет собой реализацию основных алгоритмов работы с графами, таких как обход в глубину и ширину, поиск кратчайших путей, построение минимального остовного дерева и решение задачи коммивояжера. В проекте разработана библиотека, содержащая все необходимые алгоритмы работы с графами.


## Функциональные возможности
- Загрузка и экспорт графа:
    - загрузка графа из файла в формате матрицы смежности
    - экспорт графа в файл в формате dot

- Обход графа:
    - поиск в глубину (DFS)
    - поиск в ширину (BFS)

- Поиск кратчайших путей:
    - алгоритм Дейкстры (поиск кратчайшего пути между двумя вершинами)
    - алгоритм Флойда-Уоршелла (поиск кратчайших путей между всеми парами вершин)

- Построение минимального остовного дерева:
    алгоритм Прима (построение наименьшего остовного дерева)
    
- Задача коммивояжера:
    - муравьиный алгоритм
    - генетический алгоритм
    - метод отжига

- Дополнительно:
    - сравнение производительности различных алгоритмов для задачи коммивояжера


## Представление графа
Графы в проекте представлены в виде матрицы смежности, где каждая ячейка [i][j] содержит вес ребра между вершинами i и j. Если ребра нет, вес равен нулю.


## Консольный интерфейс
Консольный интерфейс предоставляет следующие возможности:
- загрузка исходного графа из файла
- обход графа в ширину с выводом результата обхода в консоль
- обход графа в глубину с выводом результата обхода в консоль
- поиск кратчайшего пути между произвольными двумя вершинами с выводом результата в консоль
- поиск кратчайших путей между всеми парами вершин в графе с выводом результирующей матрицы в консоль
- поиск минимального остовного дерева в графе с выводом результирующей матрицы смежности в консоль
- решение задачи комивояжера с выводом результирующего маршрута и его длины в консоль
- загрузка исходного графа из файла
- обход графа в ширину с выводом результата обхода в консоль
- обход графа в глубину с выводом результата обхода в консоль
- поиск кратчайшего пути между произвольными двумя вершинами с выводом результата в консоль
- поиск кратчайших путей между всеми парами вершин в графе с выводом результирующей матрицы в консоль
- поиск минимального остовного дерева в графе с выводом результирующей матрицы смежности в консоль
- решение задачи комивояжера с использованием муравьиного алгоритма, генетического алгоритма и методом отжига с выводом результирующего маршрута и его длины в консоль
- сравнение скорости работы трёх алгоритмов решение задачи комивояжера: муравьиного алгоритма, генетического алгоритма и методом отжига


## Сборка и установка

Для сборки и установки программы используется Makefile со стандартным набором целей для GNU-программ:
  - **all** - сборка основных библиотек.
  - **clean** - удаляет сгенерированные файлы и директории сборки.
  - **test** - сборка и запуск тестов.
  - **s21_graph.a** - собирает библиотеку s21_graph.
  - **s21_graph_algorithms.a** - собирает библиотеку s21_graph_algorithms.
  - **cli** - cобирает и запускает консольный интерфейс.
  - **leaks** - запуск тестов с проверкой утечек памяти.
  - **report** - генерирует отчет о покрытии кода тестами и открывает его в браузере.
