#!/bin/bash
set -eux

BINARY="usr/local/bin/matrix"

if [ ! -f "$BINARY" ]; then
  echo "Ошибка: бинарник не найден по пути $BINARY"
  exit 1
fi

# Размерность матрицы
N=5

# Матрица A (построчно)
MATRIX_A="1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25"

# Матрица B — транспонированная по главной диагонали
MATRIX_B="1 6 11 16 21
2 7 12 17 22
3 8 13 18 23
4 9 14 19 24
5 10 15 20 25"

# Формируем ввод для программы
INPUT="$N
$MATRIX_A
$MATRIX_B"

EXPECTED="YES"

# Запуск программы с вводом через here-document
RESULT=$(echo "$INPUT" | "$BINARY" | tail -n 1)

if [ "$RESULT" == "$EXPECTED" ]; then
  echo "Тест пройден"
else
  echo "Тест не пройден"
  echo "Ожидалось: $EXPECTED"
  echo "Получено:  $RESULT"
  exit 1
fi

