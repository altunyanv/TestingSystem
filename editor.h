#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QTextBlock>
#include <QMessageBox>
#include "highlighter.h"
#include "python.h"
#include "dbconnection.h"

namespace Ui {
class Editor;
}

class Editor : public QWidget
{
    Q_OBJECT

public:
    explicit Editor(QWidget *parent = 0);
    ~Editor();
    void prepare(int, int);

private slots:
    void on_plainTextEdit_2_updateRequest(const QRect &rect, int dy);
    void on_back_to_problem_clicked();
    void on_submit_solution_clicked();

signals:
    void goToProblem(int);

private:
    Ui::Editor *ui;
    Highlighter *hgh;
    int problemId, userId;
    void update_width(int);
};

class PublicPlainTextEdit : public QPlainTextEdit {
    Q_OBJECT

public:
    explicit PublicPlainTextEdit(QWidget* parent = 0) : QPlainTextEdit(parent) {}

public:
    QTextBlock firstVisible() {
        return firstVisibleBlock();
    }
};

#endif // EDITOR_H

