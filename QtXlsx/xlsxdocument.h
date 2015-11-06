/****************************************************************************
** Copyright (c) 2013-2014 Debao Zhang <hello@debao.me>
** All right reserved.
**
** Permission is hereby granted, free of charge, to any person obtaining
** a copy of this software and associated documentation files (the
** "Software"), to deal in the Software without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Software, and to
** permit persons to whom the Software is furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be
** included in all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
** NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
** LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
** OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
** WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**
****************************************************************************/

#ifndef QXLSX_XLSXDOCUMENT_H
#define QXLSX_XLSXDOCUMENT_H

#include "xlsxglobal.h"
#include "xlsxformat.h"
#include <QObject>
#include <QVariant>
class QIODevice;
class QImage;

namespace QXlsx {

class Workbook;
class Worksheet;
class Cell;
class CellRange;
class DataValidation;
class ConditionalFormatting;

class DocumentPrivate;
class Document : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Document)

public:
    explicit Document(QObject *parent = 0);
    Document(const QString &xlsxName, QObject *parent=0);
    Document(QIODevice *device, QObject *parent=0);
    ~Document();

    int write(const QString &cell, const QVariant &value, const Format &format=Format());
    int write(int row, int col, const QVariant &value, const Format &format=Format());
    QVariant read(const QString &cell) const;
    QVariant read(int row, int col) const;
    int insertImage(int row, int column, const QImage &image, double xOffset=0, double yOffset=0, double xScale=1, double yScale=1);
    int mergeCells(const CellRange &range, const Format &format=Format());
    int mergeCells(const QString &range, const Format &format=Format());
    int unmergeCells(const CellRange &range);
    int unmergeCells(const QString &range);
    bool setRow(int row, double height, const Format &format=Format(), bool hidden=false);
    bool setColumn(int colFirst, int colLast, double width, const Format &format=Format(), bool hidden=false);
    bool setColumn(const QString &colFirst, const QString &colLast, double width, const Format &format=Format(), bool hidden=false);
    bool groupRows(int rowFirst, int rowLast, bool collapsed = true);
    bool groupColumns(int colFirst, int colLast, bool collapsed = true);
    bool addDataValidation(const DataValidation &validation);
    bool addConditionalFormatting(const ConditionalFormatting &cf);

    Cell *cellAt(const QString &cell) const;
    Cell *cellAt(int row, int col) const;

    bool defineName(const QString &name, const QString &formula, const QString &comment=QString(), const QString &scope=QString());

    CellRange dimension() const;

    QString documentProperty(const QString &name) const;
    void setDocumentProperty(const QString &name, const QString &property);
    QStringList documentPropertyNames() const;

    QStringList worksheetNames() const;
    bool addWorksheet(const QString &name = QString());
    bool insertWorkSheet(int index, const QString &name = QString());
    bool selectWorksheet(const QString &name);
    bool renameWorksheet(const QString &oldName, const QString &newName);
    bool copyWorksheet(const QString &srcName, const QString &distName = QString());
    bool moveWorksheet(const QString &srcName, int distIndex);
    bool deleteWorksheet(const QString &name);

    Workbook *workbook() const;
    Worksheet *worksheet(const QString &sheetName) const;
    Worksheet *currentWorksheet() const;
    Q_DECL_DEPRECATED bool setSheetName(const QString &name);
    Q_DECL_DEPRECATED void setCurrentWorksheet(int index);
    Q_DECL_DEPRECATED void setCurrentWorksheet(const QString &name);

    bool save() const;
    bool saveAs(const QString &xlsXname) const;
    bool saveAs(QIODevice *device) const;

private:
    Q_DISABLE_COPY(Document)
    DocumentPrivate * const d_ptr;
};

} // namespace QXlsx

#endif // QXLSX_XLSXDOCUMENT_H