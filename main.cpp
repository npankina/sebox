/*
MIT License

Copyright (c) 2024 Natal'ya Pankina

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <QApplication>
#include <QWidget>
#include <QListView>
#include <QStringListModel>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Создаем главное окно
    QWidget window;
    window.setWindowTitle("SeBox");
    window.resize(700, 500);


    // Создаем модель данных
    QStringListModel *model = new QStringListModel;
    QStringList items;
    items << "Item 1" << "Item 2" << "Item 3";
    model->setStringList(items);

    // Создаем ListView
    QListView *listView = new QListView;
    listView->setModel(model);

    // Обработка кликов по элементам
    QObject::connect(listView->selectionModel(), &QItemSelectionModel::currentChanged,
                     [&](const QModelIndex &current, const QModelIndex &previous) {
         QString itemText = model->data(current, Qt::DisplayRole).toString();
         QMessageBox::information(&window, "Item Clicked", "You clicked: " + itemText);
    });

    // Создаем layout и добавляем ListView
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(listView);

    // Устанавливаем layout для главного окна
    window.setLayout(layout);

    window.show();

    return app.exec();
}