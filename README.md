# minishell

#### Проект о создании командной (терминальной) оболочки. За основу была взята реализация оболочки Bash.

Условия: мы должны обработать '>', '|', одинарные кавычки и двойные кавычки.

Мы реализуем следующие команды: 

1. echo
2. cd
3. pwd
4. export
5. unset
6. env
7. exit

Остальные команды запускаются посредством интерпретаторов командной строки (создается процесс в котором исполняется интепретатор).

Поведение нашего проекта:

![Screen](https://raw.githubusercontent.com/atomatoe/minishell/master/screenshot/minishell.png?token=ARB66CG43QVUA46L7S3S2GTALIZ72)

Поведение Bash:

![Screen](https://raw.githubusercontent.com/atomatoe/minishell/master/screenshot/bash.png?token=ARB66CCWXZYZDBEC5S2H5LLALI2BA)

Проект написан по стандарту Си 98 и по [norme 42](https://github.com/andreevgy/42-norme-ru "Ссылка").
