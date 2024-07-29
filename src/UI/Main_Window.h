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

// Основное окно приложения, содержит элементы интерфейса и управляет отображением данных.

#pragma once
#include <QMainWindow>
#include "../Core/Settings_Manager.h"
#include "../Database/Database_Manager.h"
#include "../Data_Models/Data_Model.h"
#include "../Core/Logger.h"

namespace Ui
{
    class Main_Window;
}

class Main_Window final : public QMainWindow
{
    Q_OBJECT

public:
    Main_Window(QWidget *parent = nullptr) : QMainWindow(parent), Ui(new Ui::Main_Window)
    {
        ui->setupUi(this); // метод, который генерируется Qt Designer и используется для инициализации пользовательского интерфейса, созданного в файле .ui.
    }
    ~Main_Window() override { delete Ui; }

    private slots: // Слоты — это специальные функции в Qt, которые могут быть вызваны при срабатывании соответствующих сигналов.
    void Create_Card();
    void View_Card();
    void Update_Card();
    void Delete_Card();
    void handleLabelClick();

    // from QT
    void on_btn_start_clicked(); // Тренировка

    // работа с карточками
    void on_btn_add_card_clicked();
    void on_btn_change_card_clicked();
    void on_btn_del_card_clicked();

    // работа с группами
    void on_btn_add_deck_clicked();
    void on_btn_change_deck_clicked();
    void on_btn_del_deck_clicked();

private:
    ASettings_Manager Settings_Manager;
    ADatabase_Manager Database_Manager;
    AData_Model Data_Model;
    ALogger Logger;

    Ui::Main_Window *Ui;
};