#include "videolistitem.h"
#include "ui_videolistitem.h"

VideoListItem::VideoListItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoListItem)
{
    ui->setupUi(this);
}

VideoListItem::VideoListItem(const QString &title, const QString &description, const QPixmap &icon, QWidget *parent)
    : QWidget(parent),
      ui(new Ui::VideoListItem)
{
     ui->setupUi(this);
//     qDebug() << "icon = " << icon;
     ui->label->setPixmap(icon);
     ui->label_2->setText(title);
     ui->label_3->setText(description);
//     ui->label_3->setStyleSheet("QLabel { color: yellow; }");

//    this->setStyleSheet(
//                 "QWidget {"
//                 "    border-top: 2px solid black;"
//                 "    border-bottom: 4px solid black;"
//                 "    border-left: 2px solid black;"
//                 "    border-right: 4px solid black;"
//                 "}"
//             );
}

VideoListItem::~VideoListItem()
{
    delete ui;
}
