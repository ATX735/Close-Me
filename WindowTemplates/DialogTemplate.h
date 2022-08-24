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

private:
    Ui::DialogTemplate *ui;
};

#endif  // DIALOGTEMPLATE_H
