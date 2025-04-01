# Сапёр

> Консольная версия классической игры «Сапёр», реализованная на языке C++.

## 📌 Описание

Данный проект представляет собой текстовую версию популярной игры «Сапёр». Игроку предлагается поле с замаскированными ячейками, под некоторыми из которых скрыты мины. Цель игры — открыть все ячейки, не содержащие мин, и пометить ячейки с минами флажками.

## 🧠 Используемые технологии

- **Язык программирования:** C++
- **Стандарт:** C++11 и выше
- **Среда разработки:** Microsoft Visual Studio (файл проекта: `Сапер.vcxproj`)

## 🚀 Установка и запуск

1. **Клонирование репозитория:**

```bash
git clone https://github.com/Serphome/Sapper.git
cd Sapper/Сапер
```

2. **Сборка проекта:**

- **Через командную строку:**
```bash
g++ Source.cpp Game.cpp -o sapper
```

- **Через Microsoft Visual Studio:**
  - Открой файл `Сапер.vcxproj`.
  - Собери и запусти проект через IDE.

3. **Запуск игры:**

```bash
./sapper
```

## 🎮 Правила игры

- Ввод координат для открытия ячейки.
- Установка/снятие флажков.
- Победа: открыть все безопасные клетки и найти все мины.
- Проигрыш: если открыть клетку с миной.

## 🛠️ Структура проекта

- `Source.cpp`: Точка входа.
- `Game.cpp` / `Game.h`: Вся логика игры, работа с полем и минами.

## 🏆 Особенности

- Случайная генерация минного поля
- Интерактивный текстовый интерфейс
- Проверка ввода пользователя
