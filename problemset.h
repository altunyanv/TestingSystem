#ifndef PROBLEMSET_H
#define PROBLEMSET_H

#include <QWidget>
#include "dbconnection.h"
#include <QGridLayout>
#include <QScrollArea>
#include <QLabel>
#include <QPainter>
#include <QStyledItemDelegate>
#include <QTableView>

namespace Ui {
class ProblemSet;
}

class ProblemSet : public QWidget
{
    Q_OBJECT

public:
    explicit ProblemSet(QWidget *parent = 0);
    ~ProblemSet();
    void setUser(int = -1);


private:
    Ui::ProblemSet *ui;
    int userId;
    void updateContent();
    void loadProblemSet();

private slots:
    void onProblemIdClick(int);
    void on_pushButton_3_clicked();

signals:
    void openProblem(int);
    void logOut();
};

class IndexLabel : public QLabel {
    Q_OBJECT

public:
    explicit IndexLabel(const QString& text, QWidget * parent) : QLabel(text, parent) {
        setStyleSheet("QLabel {background-color: white}");
    }

    void mousePressEvent(QMouseEvent *ev) override {
        emit clicked(text().toInt());
    }

signals:
    void clicked(int);
};

class StatusDelegate : public QStyledItemDelegate
{
public:
    StatusDelegate(QObject *parent = 0) : QStyledItemDelegate(parent) {}

public:
    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        drawBackground(painter, option, index);
        QStyleOptionViewItem alignedOption(option);
        alignedOption.displayAlignment = Qt::AlignCenter;
        QStyledItemDelegate::paint(painter, alignedOption, index);
    }

    virtual QString displayText(const QVariant & value, const QLocale & locale ) const
    {
        Q_UNUSED(locale);
        int status = value.toInt();
        switch(status) {
        case -1:    return "Compile Error";
        case 0:     return "Wrong Answer";
        case 1:     return "Accepted";
        default:    return "";
        }
     }

protected:
    virtual void drawBackground(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        Q_UNUSED(index);
        int status = index.data().toInt();
        QColor backColor;
        switch(status) {
        case -1:    { backColor = QColor(253, 106, 2); break; }
        case 0:     { backColor = Qt::red; break; }
        case 1:     { backColor = QColor(0, 192, 48); break; }
        default: break;
        }
        painter->fillRect(option.rect, backColor);
    }
};


class DateTimeDelegate : public QStyledItemDelegate {
public:
    DateTimeDelegate(QObject *parent = 0) : QStyledItemDelegate(parent) {}

    virtual QString displayText(const QVariant & value, const QLocale & locale ) const
    {
        Q_UNUSED(locale);
        uint unixTime = value.toUInt();
        return QDateTime::fromTime_t(unixTime, QTimeZone::systemTimeZone()).toString("hh:mm:ss dd/MMM/yyyy");
     }
};

#endif // PROBLEMSET_H
