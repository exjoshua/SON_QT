#ifndef CONFIG_MAINWINDOW_H
#define CONFIG_MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>


namespace Ui {
class config_mainwindow;
}

class config_mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit config_mainwindow(QWidget *parent = 0);
    ~config_mainwindow();

signals:
    void close_cg();

private:
    Ui::config_mainwindow *ui;

protected:
    void closeEvent(QCloseEvent *);
private slots:
    void on_pushButton_clicked();
};

#endif // CONFIG_MAINWINDOW_H
