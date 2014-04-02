#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QDialog>
#include <QVector>
#include <QCheckBox>
#include <QComboBox>

class OptionsDialog : public QDialog
{
    QVector<QCheckBox*> m_checkBoxes;
    QComboBox m_xCombo;
    QComboBox m_yCombo;

    QVector<bool>      *m_pResults;
    int* m_pXAxis;
    int* m_pYAxis;
public:
    OptionsDialog(QVector<bool> *results, int *x, int *y);
    ~OptionsDialog();
};

#endif // OPTIONSDIALOG_H
