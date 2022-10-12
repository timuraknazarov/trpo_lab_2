#include "observer.h"
#include <QTextStream>

ObFile::ObFile(QString _name) // Конструктор для файла
{
    name=_name; // Имя файла
    fileExist = false; // Существует ли файл
    size = 0;  // Размер файла
}

void ObFile::Update(bool _fileExist, int _size) // Обновление файла
{
    QTextStream cout(stdout); // Поток для вывода в консоль

    if(_fileExist) // Проверка существует ли файл
    {
        if (size == _size) // Если существует изменился ли его размер? (Если размеры одинаковые -> не изменился)
        {
            if(_size!=0) // => Проверяем пустой файл или нет
            {
                cout<< "File: " << name << " exists and is not empty"<<'\n';
                cout<< "Size: " << _size<< '\n';
            }
        }
        else
        {
            cout<< "File: " << name << " exists and has been modified"<<'\n';
            cout<< "New size: " << _size<<'\n';
        }
    }
    else
    {
        cout<< "File: " << name << " does not exist"<<'\n';
    }

    size=_size;
    fileExist=_fileExist;
}
