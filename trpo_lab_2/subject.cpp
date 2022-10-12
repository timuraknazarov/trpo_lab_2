#include "subject.h"
#include <algorithm>

void ASubject::Attach(IObserver *product) // Добавление наблюдателя
{
    list.push_back(product);
}


void ASubject::Detach(IObserver *product) // Отвязка наблюдателя
{
    list.erase(std::remove(list.begin(), list.end(), product), list.end());
}

void ASubject::Notify(bool fileExist, int size) // Обновление данных в наблюдателях
{
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i] != nullptr)
        {
            list[i]->Update(fileExist, size);
        }
    }
}

void ConcreteProduct::updateObservers() // Обновление данных в наблюдателях
{
    Notify(File.exists(),File.size());
}
