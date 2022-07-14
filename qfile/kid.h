#ifndef KID_H
#define KID_H

#include <QWidget>

namespace Ui {
class kid;
}

class kid : public QWidget
{
    Q_OBJECT
protected:
        void closeEvent(QCloseEvent* ev);
public:
    explicit kid(QWidget *parent = 0);
    ~kid();
    void reboot();
private slots:
        void on_pushButton_clicked();

private:
    Ui::kid *ui;
};

#endif // KID_H
