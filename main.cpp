#include <QCoreApplication>
#include <QFile>
#include <QDebug>

// Функция, которая сравнивает json-файлы через байтовое представление
bool compareBinaryFiles(const QString &filePath1, const QString &filePath2)
{
    QFile file1(filePath1);
    QFile file2(filePath2);

    if (!file1.open(QIODevice::ReadOnly))
    {
        qDebug() << "Не удалось открыть файл:" << filePath1;
        return false;
    }

    if (!file2.open(QIODevice::ReadOnly))
    {
        qDebug() << "Не удалось открыть файл:" << filePath2;
        return false;
    }

    if (file1.size() != file2.size())
    {
        return false;
    }

    QByteArray data1 = file1.readAll();
    QByteArray data2 = file2.readAll();

    file1.close();
    file2.close();

    return data1 == data2;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filePath1 = "../compare_json/json_path/final_points.json";
    QString filePath2 = "../compare_json/json_path/final_points_3.json";

    if (compareBinaryFiles(filePath1, filePath2))
    {
        qDebug() << "Файлы идентичны.";
    } else {
        qDebug() << "Файлы не идентичны.";
    }

    return a.exec();
}
