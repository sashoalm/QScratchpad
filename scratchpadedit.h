#ifndef SCRATCHPADEDIT_H
#define SCRATCHPADEDIT_H

#include <QPlainTextEdit>

class ScratchpadEdit : public QPlainTextEdit
{
public:
    ScratchpadEdit(QWidget *parent);
    virtual ~ScratchpadEdit();

private:
    void backup(const QString &text);
    void backupSelection();
    virtual void keyPressEvent(QKeyEvent *e);
    QFile backupFile;
};

#endif // SCRATCHPADEDIT_H
