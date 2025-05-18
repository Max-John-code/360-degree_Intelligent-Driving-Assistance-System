#ifndef VIDEOLISTITEM_H
#define VIDEOLISTITEM_H

#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QLabel>
#include <QPushButton>
#include <QDebug>

namespace Ui {
class VideoListItem;
}

class VideoListItem : public QWidget
{
    Q_OBJECT

public:
    explicit VideoListItem(QWidget *parent = nullptr);
    VideoListItem(const QString &title, const QString &description,
                  const QPixmap &icon, QWidget *parent = nullptr);
    ~VideoListItem();

private:
    Ui::VideoListItem *ui;
};

#endif // VIDEOLISTITEM_H
