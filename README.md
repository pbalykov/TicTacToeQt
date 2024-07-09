# TicTacToeQt

## Об игре
Класическая игра крестки нолики написаная на qt. Играйте в одиночку против умного компьютера или вдвоем с другом. Простой интерфейс, захватывающий геймплей и возможность начать игру заново в любой момент!  

## Видио игры

<div id="header" align="center">
     <img src="./gif/gameplay.gif" height="250" width="250" /><br><br>
</div>

## Версия 
1.0.0.0

## Зависимости ПО
* QMake 3.1
* GNU Make 3.81
* C++17

## Сборка и запуск

### Сборка в Qt Creator

1. Откройте проект в Qt Creator:
2. Выберите пункт меню "Сборка" -> "Собрать проект".
3. Запустите приложение:
* Нажмите кнопку "Запустить" на панели инструментов.
* Выберите пункт меню "Сборка" -> "Запустить".

### Сборка в терминале 
Перходим в папку с проектом и выполняем следущие действия
```
    mkdir build
    cd build
    qmake ../tic_tac_toe_qt.pro 
    make 
    ./TicTacToeQt #Linux 
    ./TicTacToeQt.app/Contents/MacOS/TicTacToeQt # MacOs
```

## Авторы

* **pbalykov** - *разработчик* - [github](https://github.com/pbalykov)
