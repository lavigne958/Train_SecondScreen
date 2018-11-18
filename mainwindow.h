#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    explicit MainWindow(QWidget *parent = nullptr, Dialog *d = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Dialog *dialog;

private slots:
    void on_toggleSecondWindow_clicked();
    void on_dialog_close(int status);
};

#endif // MAINWINDOW_H
