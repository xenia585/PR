#!/bin/bash
set -eux

BINARY="usr/local/bin/matrix"

if [ ! -f "$BINARY" ]; then
  echo "Ошибка: бинарник не найден по пути $BINARY"
  exit 1
fi

# Имитация ввода: сначала размерность, затем матрицы построчно
INPUT="5
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
2 2 2 2 2
2 2 2 2 2
2 2 2 2 2
2 2 2 2 2
2 2 2 2 2
"

# Ожидаемый результат (последняя строка программы)
EXPECTED="YES"

# Передаём ввод программе и берём последнюю строку вывода
RESULT=$(echo "$INPUT" | "$BINARY" | tail -n 1)

if [ "$RESULT" == "$EXPECTED" ]; then
  echo "Тест пройден"
else
  echo "Тест не пройден"
  echo "Ожидалось: $EXPECTED"
  echo "Получено:  $RESULT"
  exit 1
fi

