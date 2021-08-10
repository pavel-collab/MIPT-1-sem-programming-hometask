# Readme

Данный репозиторий подготовлен студентом 1 курса МФТИ факультета радиотехники и кибергетики.
Контакты:

[VK](https://vk.com/id436243157)
[Telegram](@skfhs_45)
[Github](https://github.com/pavel-collab)

В репозитории представлены задачи по информатике за 1 семестр 2020-2021 учебного года к контестам Винокурова Никиты Алексеевича.

[Ссылка на викиФизтех](http://wikimipt.org/wiki/Винокуров_Никита_Алексеевич)

## User Instruction.

## Stack reverse.

Первый контест состоит из двух программ. В первой программе необходимо ввести строку символов и получить на выходе реверсированную строку. Переворот строки необходимо осуществлять спомощью рекурсии.

**Sample input**:
```
```
**Sample output**:
```
```

Чтобы понять рекурсию, нужно сначала понять рекурсию.

Вторая программа является усложненной версией первой программы, необходимо ввести последовательность слов, разделенных знаками пробела, тубуляции и переноста строки, на выходе необходимо получить последовательность реверсированных слов.

**Sample input**:
```
```
**Sample output**:
```
```
## Merge sort.

Во втором контесте вам придется ознакомиться с понятиями односвязных списков и сортировки слиянием. В программе необходимо ввести последовательность календарных дат в формате **дд мм гггг**, после этого программа далжа вывести последовательность отсортированных дат.

**Sample input**:
```
```
**Sample output**:
```
```

## AVL tree.

В третьем контесте вы познакомитесь с понятием AVL деревьев. Вам необходимо написать собственное AVL дерево с алгоритмом балансировки. На вход программы подается последовательность целых чисел, на выходе программа выдает параметры *сбалансированного* дерева: количество детей в правом и левом поддеревьях основного корня.


**Sample input**:
```
```
**Sample output**:
```
```

Для более детального ознакомления с AVL деревьями, а так же алгоритмом балансировки советую воспользоваться []().

## Quantilies.

В данном контесте мы вновь возвращаемся к использованию односвязных списков для решения задач, кроме того задача требует использования аргументов командной строки.

В агрументах командной строки приграмме передается значение квантили q (рациональное число от 0 до 1).

```
./quantilies 0,8
```
На вход программе подается последовательность целых чисел, на выход программа выдает целое число из введенной последовательности, которое делит ее в отношении, задаваемом значением q.

**Sample input**:
```
```
**Sample output**:
```
```

## Queue.

В последнем контесте будет использоваться структура данных, называемая очередью.

Дословный текст задачи:

**Линия задержки**

РЕализуйте линию задержки сигнала с переменным временем задержки.

На вход поступает последовательность пар чисел: целое число -- время задержки, заданное в отсчетах сигнала и число с плавающей точкой -- значение сигнала.

На выходе должна появиться последовательность чисел с плавающей точкой в соответствии с временем задржки. Если число *x(t)* было дано в отсчет *t*, то оно должно появиться на месте *t' = t + z(t)*, где *z(t)* -- время задержки, заданное в отсчет с номером *t*.

Время задержки не может меняться больше, чем на единицу за отсчет. Если в момент *t'* должны появиться нескольно чисел (если время задержки уменьшилось), то они должны суммироваться. Если время задержки увеличилось, то должно повториться предыдущее значение отсчета.

Начальное значение выходного сигнала равно 0. Количество выводимых отсчетов должно быть равно количеству отсчетов, поданных на ввод + значение последней задержки.

Длинна последоветельности не ограничена. Время задержки < 10e8.

**Sample input**:
```
```
**Sample output**:
```
```

# Conclusoin.

Для удобства большинство проектов разделено на несколько файлов. В отдельные файлы вынесены структуры, прототипы функций, тела самих функций и main. Заголовочные файлы включены в файлы программ спомощью дерективы include.

```
#include "Tree.h"
```

Для сдачи контестов вам придется все структуры и функции перенести в один файл.

Для сборки и оинковки проектов автор использует Makefiles, для более детального ознакомления с этой темой, советую воспользоваться статьями [Makefile для самых маленьких](https://habr.com/ru/post/155201/), а так же [Просто о make](https://habr.com/ru/post/211751/).