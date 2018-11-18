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

public slots:
    void on_dialog_close(int status);

private:
    Ui::MainWindow *ui;
    Dialog *dialog;
    void setupConnects();
    void closeEvent(QCloseEvent *event);

private slots:
    void on_toggleSecondWindow_clicked();
};

#endif // MAINWINDOW_H
