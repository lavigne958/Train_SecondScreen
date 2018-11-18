#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>
#include <QWindow>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow (parent),
    ui(new Ui::MainWindow),
  dialog(new Dialog(this))
{
    ui->setupUi(this);
    connect(this->dialog, SIGNAL(finished(int)), this, SLOT(on_dialog_close(int)));
}
MainWindow::MainWindow(QWidget *parent, Dialog *d) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    dialog(d)
{
    ui->setupUi(this);
    connect(this->dialog, SIGNAL(finished(int)), this, SLOT(on_dialog_close(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toggleSecondWindow_clicked()
{
    QList<QScreen *> screens = qApp->screens();

    if (screens.size() < 2) {
        qWarning() << "Wrong number of screens actually detected";
        return;
    }

    if (this->dialog->isHidden()) {
        QRect second_geo = qApp->screens()[1]->geometry();

        this->dialog->showFullScreen();
        this->dialog->setGeometry(second_geo);
        this->ui->toggleSecondWindow->setText(QString("Deactivate"));
    } else {
        this->dialog->hide();
        this->ui->toggleSecondWindow->setText(QString("Activate"));
    }
}

void MainWindow::on_dialog_close(int status)
{
    qDebug() << "dialog closed with status: " << status;

    this->ui->toggleSecondWindow->setText("Activate");
}
