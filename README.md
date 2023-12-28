# Змейка на C++
Это классическая игра, реализованная на языке программирования C++. Игра была создана нашей командой, как проект, для изучения языка программирования C++.

## Описание
В этой игре игрок управляет змейкой, которая передвигается по экрану. Цель игры - собирать еду, появляющуюся в разных частях игрового поля, при этом избегая столкновений со своим собственным хвостом.
Каждый раз, когда змейка есть еду, - она становится длиннее.

## Требования
Для запуска игры вам потребуется:

-Компилятор C++, поддерживающий стандарт C++11 или выше.
-Среда запуска программ на C++.
-Установленная библиотека SFML.

## Установка и запуск

1. Клонируйте репозиторий на свой компьютер(Обязательно на диск C:/snake/):
https://github.com/Vvvmmp/Project_OPI_snake.git

2. Перейдите в папку с проектом.

3. Перейдите в свойства проекта -> C/C++ -> Общие -> Дополнительные каталоги включаемых файлов -> указать точный путь до /SFML-2.6.1/include

4. Перейдите в свойства проекта -> Компоновщик -> Общие -> Дополнительные каталоги библиотек -> указать точный путь до /SFML-2.6.1/lib

5. Перейдите в свойства проекта -> Компоновщик -> Ввод -> Дополнительные зависимости -> Вставить: "sfml-graphics-d.lib
sfml-window-d.lib
sfml-system-d.lib"

6. Перейдите в свойства проекта -> Компоновщик -> Дополнительно -> Точка входа -> Вставить: "mainCRTStartup"

7. Компилируйте исходный код.

8. Запустите игру.

## Управление
- Кнопки "W", "A", "S", "D" для управления змейкой.

- Кнопка "R" для перезапуска игры при смерти.

- Кнопка "I" для передачи управления змейкой ИИ.


## Контрибуции
Любые предложения и улучшения приветствуются!

## Авторы
- Пузанко Иван Владимирович(ivanpuzanko@gmail.com)

- Лужецкий Владислав Константинович(vladluzhecki@gmail.com)

- Статько Герман Вячеславович(statkog@gmail.com)

- Семёнов Даниил Вячеславович(semenovdaniil@gmail.com)

- Александрович Иван Александрович(xdarsad@gmail.com)

- Федорович Вадим Геннадьевич(fedorovich.1705@mail.ru)
