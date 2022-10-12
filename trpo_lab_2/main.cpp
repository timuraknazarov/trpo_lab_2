#include <QCoreApplication>
#include "observer.h"
#include "subject.h"
#include <chrono>
#include <thread>

int main()
{
    QString fileName = "test.txt"; // Создаём файл
    ConcreteProduct test(fileName); // Создаём объект ConcreteProduct

    ObFile Ob1(fileName), Ob2(fileName); // Создаём 2 наблюдателя

    test.Attach(&Ob1); // Добавляем 1ого наблюдателя
    test.Attach(&Ob2); // Добавляе 2ого

    test.updateObservers(); // Обновляем данные в наболюдателях

    test.Detach(&Ob2); // Отвязываем 2ого

    test.updateObservers(); // Обновляем данные в наболюдателе

    for(int i = 0; i < 1000; i++) // Отслеживаем состояние файла
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            test.updateObservers();
        }

    return 0;
}
