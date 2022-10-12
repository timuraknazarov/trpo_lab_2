#ifndef SUBJECT_H
#define SUBJECT_H
#include <iostream>
#include <vector>
#include "observer.h"
#include <QFile>
#include <QString>

class ASubject
{
    std::vector<IObserver*> list; // Список всех файлов (наблюдателей)
public:
    void Attach(IObserver *product); // Добавление наблюдателя
    void Detach(IObserver *product); // Отвязка наблюдателя
    void Notify(bool fileExist, int size); // Обновление данных в наблюдателях

};

#endif // SUBJECT_H

class ConcreteProduct : public ASubject
{
    QFile File; // Объект файла

public:
    ConcreteProduct(const QString& fileName): File(fileName) {}; // Конструктор файла
    void updateObservers(); // Обновление данных в наблюдателях
};
