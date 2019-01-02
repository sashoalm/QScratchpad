#include "scratchpadedit.h"

#include <QDateTime>
#include <QStandardPaths>

ScratchpadEdit::ScratchpadEdit(QWidget *parent) : QPlainTextEdit(parent)
{
    auto fn = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    backupFile.setFileName(fn + "/scratchpad-backup.txt");
    backupFile.open(QFile::Append);
}

ScratchpadEdit::~ScratchpadEdit()
{
    backup(toPlainText());
}

void ScratchpadEdit::backup(const QString &_text)
{
    if (_text.isEmpty()) {
        return;
    }

    auto text = _text.trimmed();

    if (text.isEmpty()) {
        return;
    }

    QString s;
    if (backupFile.size() > 0) {
        s += "\n\n";
    }
    s += "=== " + QDateTime::currentDateTime().toString() + "\n\n";
    s += text;

    backupFile.write(s.toUtf8());
    backupFile.flush();
}

void ScratchpadEdit::backupSelection()
{
    // Note: If the selection obtained from an editor spans a line break, the
    // text will contain a Unicode U+2029 paragraph separator character instead
    // of a newline \n character. Use QString::replace() to replace these
    // characters with newlines.
    backup(textCursor().selectedText().replace("\u2029", "\n"));
}

void ScratchpadEdit::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Delete || e->key() == Qt::Key_Backspace) {
        backupSelection();
    }

    QPlainTextEdit::keyPressEvent(e);
}
