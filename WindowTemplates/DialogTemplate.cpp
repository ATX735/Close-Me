#include "DialogTemplate.h"

#include "GlobalData.h"
#include "ui_DialogTemplate.h"

DialogTemplate::DialogTemplate(QWidget *parent) : QDialog(parent), ui(new Ui::DialogTemplate) {
    ui->setupUi(this);

    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    resize(QSize(GlobalData::GetInstance().dialog_width, GlobalData::GetInstance().dialog_height));
}

DialogTemplate::~DialogTemplate() { delete ui; }
