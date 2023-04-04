#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void showChildDialog();
protected:
        void closeEvent(QCloseEvent* ev);

private slots:
        void on_newmemo_clicked();

        void on_viewmemo_clicked();

        void on_backpackbt_clicked();

        void on_browse_clicked();

        void on_setting_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
