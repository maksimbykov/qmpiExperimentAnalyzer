#ifndef RUNEXPERIMENTDIALOG_H
#define RUNEXPERIMENTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QLabel>

class RunExperimentDialog : public QDialog
{
    Q_OBJECT

    QLineEdit* m_mpichAppLine;
    QLineEdit* m_expAppLine;
    QLineEdit* m_freqTxtLine;
    QLineEdit* m_lengthTxtLine;

    QPushButton* m_mpichAppButton;
    QPushButton* m_expAppButton;
    QPushButton* m_freqTxtButton;
    QPushButton* m_lengthTxtButton;

    QLabel*    m_numOfProcLine;
    QSpinBox* m_numOfProcSpin;

    QPushButton* m_runButton;

    QStringList m_runArguments;
    QString     m_mpichAppPath;

    //TODO: progress bar
public:
    RunExperimentDialog();

private slots:
    void openMpich();
    void openExperiment();
    void openFrequency();
    void openLength();
    void numProcChanged(int);
    void run();
};

#endif // RUNEXPERIMENTDIALOG_H
