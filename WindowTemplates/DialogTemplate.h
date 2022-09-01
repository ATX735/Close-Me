#ifndef DIALOGTEMPLATE_H
#define DIALOGTEMPLATE_H

#include <QDialog>

namespace Ui {
class DialogTemplate;
}

class DialogTemplate : public QDialog {
    Q_OBJECT

public:
    explicit DialogTemplate(QWidget *parent = nullptr);
    ~DialogTemplate();

    // filtering qApp event
    virtual bool eventFilter(QObject *obj, QEvent *event) override;

private:
    Ui::DialogTemplate *ui;

    // disable close event
    void closeEvent(QCloseEvent *event) override;
};

#endif  // DIALOGTEMPLATE_H
