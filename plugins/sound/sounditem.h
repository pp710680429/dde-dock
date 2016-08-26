#ifndef SOUNDITEM_H
#define SOUNDITEM_H

#include "soundapplet.h"
#include "dbus/dbussink.h"

#include <QWidget>

class SoundItem : public QWidget
{
    Q_OBJECT

public:
    explicit SoundItem(QWidget *parent = 0);

    QWidget *tipsWidget();
    QWidget *popupApplet();

protected:
    QSize sizeHint() const;
    void resizeEvent(QResizeEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *e);

private slots:
    void refershIcon();
    void refershTips(const bool force = false);
    void sinkChanged(DBusSink *sink);

private:
    QLabel *m_tipsLabel;
    SoundApplet *m_applet;
    DBusSink *m_sinkInter;
    QPixmap m_iconPixmap;
};

#endif // SOUNDITEM_H
