# linked-structures-c

Учебная библиотека на языке C для работы со списочными структурами данных.

## Реализованные структуры

- двунаправленный связный список;
- стек;
- очередь;
- дек.

## Основные функции

- `list_create`, `list_free`;
- `list_push_front`, `list_push_back`;
- `list_pop_front`, `list_pop_back`;
- `list_find`, `list_remove`, `list_print`;
- `stack_push`, `stack_pop`;
- `queue_enqueue`, `queue_dequeue`;
- `deque_push_front`, `deque_push_back`, `deque_pop_front`, `deque_pop_back`.

## Сборка

```bash
make
make run
make test
make clean
```

Проект использует динамическое выделение памяти через `malloc` и освобождение через `free`.
