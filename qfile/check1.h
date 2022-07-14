#ifndef CHECK1_H
#define CHECK1_H

#include <QWidget>
#include <QStringList>
namespace Ui {
class Check1;
}

class Check1 : public QWidget
{
    Q_OBJECT

public:
    explicit Check1(QWidget *parent = 0);
    ~Check1();
    void reboot();
protected:
        void closeEvent(QCloseEvent* ev);
private slots:
    void on_pushButton_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_listWidget_customContextMenuRequested(const QPoint &pos);

    void on_menu_click1(bool);

    void on_menu_click2(bool);

    void on_pushButton_2_clicked();

    void LoadList();

    QStringList findFiles(const QString &startDir, QStringList filters);

private:
    Ui::Check1 *ui;
};

#endif // CHECK1_H
